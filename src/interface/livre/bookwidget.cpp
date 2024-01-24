#include "bookwidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include "../../librairie/bd.h"
#include "../../librairie/theatre.h"
#include "../../librairie/recueil.h"
#include "../../librairie/album.h"
#include "../../librairie/roman.h"

BookWidget::BookWidget(QWidget *parent)
    : QWidget{parent}, livres(), updating_livres(false)
{
    stacked_layout = new QStackedLayout(this);

    // Choix livre
    QWidget* choix_livre = new QWidget(this);
    QVBoxLayout* choix_livre_layout = new QVBoxLayout(choix_livre);
    choix_livre_layout->addWidget(new QLabel("Choix du livre"),0,Qt::AlignmentFlag::AlignTop | Qt::AlignmentFlag::AlignHCenter);

        choix_livre_box = new QComboBox(choix_livre);
    connect(choix_livre_box, &QComboBox::currentTextChanged, this, [=](const QString& text) {
        if(! (text.isEmpty()  || updating_livres) ){
            book_view->updateDisplay(livres.value(text));
            stacked_layout->setCurrentIndex(1);
        }
    });
    choix_livre_layout->addWidget(choix_livre_box,0,Qt::AlignmentFlag::AlignCenter);

    stacked_layout->addWidget(choix_livre);

    book_view = new BookView(this);
    stacked_layout->addWidget(book_view);

    setLayout(stacked_layout);
}


void BookWidget::clean(){
    updating_livres = true;
    choix_livre_box->clear();
    livres.clear();
    for (Livre *livre : Livre::getLivres() | BD::getLivres() | Theatre::getLivres() | Roman::getLivres() | Album::getLivres() | Recueil::getLivres()){
        choix_livre_box->addItem(livre->getTitre() + " (" + livre->getAuteur() + ")");
        livres.insert(livre->getTitre() + " (" + livre->getAuteur() + ")",livre);
    }

    updating_livres = false;
    stacked_layout->setCurrentIndex(0);
}
