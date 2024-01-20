#include "bookwidget.h"
#include <QVBoxLayout>
#include <QLabel>

BookWidget::BookWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout layout(this);
    QLabel header_label("Détail Livre",this);
        layout.addWidget(&header_label,0,Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignTop);

    QTextBrowser affichage_widget;
    affichage = &affichage_widget;
    layout.addWidget(&affichage_widget,0,Qt::AlignmentFlag::AlignCenter);
}


void BookWidget::updateDisplay(Livre *livre){
    this->livre = livre;
    if (livre != nullptr){
        affichage->setText(livre->getInformations().join("\n"));
    }
    else {
        clean();
    }
}


void BookWidget::clean(){
    affichage->setText("");
}
