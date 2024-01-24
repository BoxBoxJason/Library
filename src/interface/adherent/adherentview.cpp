#include "adherentview.h"
#include <QVBoxLayout>
#include <QLabel>

AdherentView::AdherentView(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Profil Adhérent",this),0,Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignTop);

        affichage = new QTextBrowser(this);
    layout->addWidget(affichage,0,Qt::AlignmentFlag::AlignCenter);

    setLayout(layout);
}


void AdherentView::updateDisplay(Adherent *adherent){
    this->adherent = adherent;
    if (adherent != nullptr){
        affichage->setText(adherent->getInformations().join("\n"));
    }
    else {
        clean();
    }
}


void AdherentView::clean(){
    affichage->setText("");
}
