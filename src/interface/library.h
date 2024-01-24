#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include "navigation/pagesnavigationwidget.h"

class Library : public QMainWindow
{
    Q_OBJECT
public:
    explicit Library(QWidget *parent = nullptr);

private:
    PagesNavigationWidget* navigation_widget;

signals:

};

#endif // LIBRARY_H
