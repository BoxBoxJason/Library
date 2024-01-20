#include <QVBoxLayout>
#include <QLabel>
#include "adherentwidget.h"

AdherentWidget::AdherentWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout layout(this);
    QLabel header_label("Profile Adhérent",this);
    layout.addWidget(&header_label,0,Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignTop);

    QTextBrowser affichage_widget;
    affichage = &affichage_widget;
    layout.addWidget(&affichage_widget,0,Qt::AlignmentFlag::AlignCenter);
}

void AdherentWidget::updateDisplay(Adherent *adherent){
    this->adherent = adherent;
    if (adherent != nullptr){
        affichage->setText(adherent->getInformations().join("\n"));
    }
    else {
        clean();
    }
}


void AdherentWidget::clean(){
    affichage->setText("");
}
