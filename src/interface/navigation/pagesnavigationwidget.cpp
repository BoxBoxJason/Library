#include <QStackedLayout>
#include <QLabel>
#include "pagesnavigationwidget.h"

PagesNavigationWidget::PagesNavigationWidget(QWidget *parent)
    : QWidget{parent}
{
    QStackedLayout layout(this);

    QLabel welcome_widget("Bienvenue sur Librair.io",this);
    layout.addWidget(&welcome_widget);
    LibraryWidget librairy(this);
    layout.addWidget(&librairy);
    library_widget = &librairy;

    AdherentWidget adherent(this);
    layout.addWidget(&adherent);
    adherent_widget = &adherent;

    BookWidget book(this);
    layout.addWidget(&book);
    book_widget = &book;
}


void PagesNavigationWidget::changePage(int numero_page){
    QStackedLayout *stacked_layout = dynamic_cast<QStackedLayout*>(layout());
    if (numero_page >= 0 && numero_page < stacked_layout->count()){
        stacked_layout->setCurrentIndex(numero_page);
    }
    else {
        stacked_layout->setCurrentIndex(0);
    }
}


void PagesNavigationWidget::setBiblioView(Bibliotheque *bibliotheque){

}
