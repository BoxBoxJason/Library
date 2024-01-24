#ifndef PAGESNAVIGATIONWIDGET_H
#define PAGESNAVIGATIONWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include "../adherent/adherentwidget.h"
#include "../livre/bookwidget.h"
#include "../librairie/librarywidget.h"

class PagesNavigationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PagesNavigationWidget(QWidget *parent = nullptr);
    void changePage(int numero_page=0);

private:
    AdherentWidget* adherent_widget;
    BookWidget* book_widget;
    LibraryWidget* library_widget;
    QStackedLayout* stacked_layout;

signals:

};

#endif // PAGESNAVIGATIONWIDGET_H
