#ifndef PAGESNAVIGATIONWIDGET_H
#define PAGESNAVIGATIONWIDGET_H

#include <QWidget>
#include "../../librairie/bibliotheque.h"
#include "../adherent/adherentwidget.h"
#include "../livre/bookwidget.h"
#include "../librairie/librarywidget.h"

class PagesNavigationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PagesNavigationWidget(QWidget *parent = nullptr);
    void changePage(int numero_page=0);
    void setBiblioView(Bibliotheque *bibliotheque);

private:
    AdherentWidget* adherent_widget;
    BookWidget* book_widget;
    LibraryWidget* library_widget;

signals:

};

#endif // PAGESNAVIGATIONWIDGET_H
