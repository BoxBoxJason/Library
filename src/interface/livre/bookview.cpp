#include "bookview.h"
#include <QVBoxLayout>
#include <QLabel>

BookView::BookView(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Détail Livre",this),0,Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignTop);

        affichage = new QTextBrowser(this);
    layout->addWidget(affichage,0,Qt::AlignmentFlag::AlignCenter);

    setLayout(layout);
}


void BookView::updateDisplay(Livre *livre){
    this->livre = livre;
    if (livre != nullptr){
        affichage->setText(livre->getInformations().join("\n"));
    }
    else {
        clean();
    }
}


void BookView::clean(){
    affichage->setText("");
}
