#include "libraryview.h"
#include <QVBoxLayout>
#include <QLabel>

LibraryView::LibraryView(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Détail Bibliothèque",this),0,Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignTop);

        affichage = new QTextBrowser(this);
    layout->addWidget(affichage,0,Qt::AlignmentFlag::AlignCenter);

    setLayout(layout);
}


void LibraryView::updateDisplay(Bibliotheque *bibliotheque){
    this->bibliotheque = bibliotheque;
    if (bibliotheque != nullptr){
        affichage->setText(bibliotheque->getInformations().join("\n"));
    }
    else {
        clean();
    }
}


void LibraryView::clean(){
    affichage->setText("");
}
