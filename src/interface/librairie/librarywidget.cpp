#include "librarywidget.h"
#include "../../librairie/bibliotheque.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>

LibraryWidget::LibraryWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout layout(this);
    QLabel titre("Choix de la Bibliothèque");
    layout.addWidget(&titre,Qt::AlignmentFlag::AlignTop | Qt::AlignmentFlag::AlignHCenter);

    QGridLayout bibliotheques;
    biblios = &bibliotheques;
    layout.addLayout(biblios);

    QPushButton ajoutBiblio("Ajouter Bibliothèque");
    // connect(ajoutBiblio,&QPushButton::clicked,this, CALL CHANGEMENT PAGE); TODO
    layout.addWidget(&ajoutBiblio);
}


void LibraryWidget::afficherBiblios(){
    clean();
    for (Bibliotheque *biblio : Bibliotheque::getBibliotheques()){
        QPushButton detail_biblio(biblio->getNom(),this);
        connect(&detail_biblio,&QPushButton::clicked,this, [=]() {
            this->parent();
        });
        biblios->addWidget(&detail_biblio);
    }
}


void LibraryWidget::clean(){
    QLayoutItem *item;
    while ((item = layout()->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
}
