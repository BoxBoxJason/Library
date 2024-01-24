#include <QVBoxLayout>
#include <QLabel>
#include "adherentwidget.h"

AdherentWidget::AdherentWidget(QWidget *parent)
    : QWidget{parent}, adherents(), updating_adherents(false)
{
    stacked_layout = new QStackedLayout(this);

    // Choix bilbio
    QWidget* choix_adherent = new QWidget(this);
    QVBoxLayout* choix_adherent_layout = new QVBoxLayout(choix_adherent);
    choix_adherent_layout->addWidget(new QLabel("Choix de l'adhérent"),0,Qt::AlignmentFlag::AlignTop | Qt::AlignmentFlag::AlignHCenter);

        choix_adherent_box = new QComboBox(choix_adherent);
    connect(choix_adherent_box, &QComboBox::currentTextChanged, this, [=](const QString& text) {
        if(! (text.isEmpty()  || updating_adherents) ){
            adherent_view->updateDisplay(adherents.value(text));
            stacked_layout->setCurrentIndex(1);
        }
    });
    choix_adherent_layout->addWidget(choix_adherent_box,0,Qt::AlignmentFlag::AlignCenter);

    stacked_layout->addWidget(choix_adherent);

    adherent_view = new AdherentView(this);
    stacked_layout->addWidget(adherent_view);

    setLayout(stacked_layout);
}


void AdherentWidget::clean(){
    updating_adherents = true;
    choix_adherent_box->clear();
    adherents.clear();
    for (Adherent *ad : Adherent::getAdherents()){
        choix_adherent_box->addItem(ad->getFullname());
        adherents.insert(ad->getFullname(),ad);
    }
    updating_adherents = false;
    stacked_layout->setCurrentIndex(0);
}
