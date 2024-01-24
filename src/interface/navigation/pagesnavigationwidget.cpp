#include <QStackedLayout>
#include <QLabel>
#include <QHBoxLayout>
#include "pagesnavigationwidget.h"

PagesNavigationWidget::PagesNavigationWidget(QWidget *parent)
    : QWidget{parent}
{
    stacked_layout = new QStackedLayout(this);
    QWidget* welcome_widget = new QWidget(this);
    QHBoxLayout* welcome_layout = new QHBoxLayout(welcome_widget);
    welcome_layout->addWidget(new QLabel("Bienvenue sur Librair.io",this),0,Qt::AlignmentFlag::AlignCenter);
    welcome_widget->setLayout(welcome_layout);
    stacked_layout->addWidget(welcome_widget);

    library_widget = new LibraryWidget(this);
    stacked_layout->addWidget(library_widget);

    adherent_widget = new AdherentWidget(this);
    stacked_layout->addWidget(adherent_widget);

    book_widget = new BookWidget(this);
    stacked_layout->addWidget(book_widget);

    setLayout(stacked_layout);
}


void PagesNavigationWidget::changePage(int numero_page){
    if (numero_page >= 0 && numero_page < stacked_layout->count()){
        switch (numero_page) {
        case 1:
            library_widget->clean();
            break;
        case 2:
            adherent_widget->clean();
            break;
        case 3:
            book_widget->clean();
            break;
        default:
            break;
        }
        stacked_layout->setCurrentIndex(numero_page);
    }
    else {
        stacked_layout->setCurrentIndex(0);
    }
}
