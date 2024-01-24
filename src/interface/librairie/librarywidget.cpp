#include "librarywidget.h"
#include "../../librairie/bibliotheque.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

LibraryWidget::LibraryWidget(QWidget *parent)
    : QWidget{parent}, bibliotheques(), updating_biblios(false)
{
    stacked_layout = new QStackedLayout(this);

    // Choix bilbio
    QWidget* choix_biblio = new QWidget(this);
    QVBoxLayout* choix_biblio_layout = new QVBoxLayout(choix_biblio);
    choix_biblio_layout->addWidget(new QLabel("Choix de la Bibliothèque"),0,Qt::AlignmentFlag::AlignTop | Qt::AlignmentFlag::AlignHCenter);

    choix_biblio_box = new QComboBox(choix_biblio);
    connect(choix_biblio_box, &QComboBox::currentTextChanged, this, [=](const QString& text) {
        if(! (text.isEmpty()  || updating_biblios) ){
            library_view->updateDisplay(bibliotheques.value(text));
            stacked_layout->setCurrentIndex(1);
        }
    });
    choix_biblio_layout->addWidget(choix_biblio_box,0,Qt::AlignmentFlag::AlignCenter);

    stacked_layout->addWidget(choix_biblio);

    library_view = new LibraryView(this);
    stacked_layout->addWidget(library_view);

    setLayout(stacked_layout);
}


void LibraryWidget::clean(){
    updating_biblios = true;
    choix_biblio_box->clear();
    bibliotheques.clear();
    for (Bibliotheque *biblio : Bibliotheque::getBibliotheques()){
        choix_biblio_box->addItem(biblio->getNom());
        bibliotheques.insert(biblio->getNom(),biblio);
    }
    updating_biblios = false;
    stacked_layout->setCurrentIndex(0);
}
