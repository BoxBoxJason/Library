#include "library.h"
#include <QAction>
#include <QToolBar>

Library::Library(QWidget *parent)
    : QMainWindow{parent}
{
    navigation_widget = new PagesNavigationWidget(this);
    setCentralWidget(navigation_widget);

    QToolBar *toolbar = addToolBar("MyToolbar");
    QAction *action1 = toolbar->addAction("Accueil");
    QAction *action2 = toolbar->addAction("Bibliothèques");
    QAction *action3 = toolbar->addAction("Adhérents");
    QAction *action4 = toolbar->addAction("Livres");

    connect(action1, &QAction::triggered, this, [=]() {
        navigation_widget->changePage(0);
    });
    connect(action2, &QAction::triggered, this, [=]() {
        navigation_widget->changePage(1);
    });
    connect(action3, &QAction::triggered, this, [=]() {
        navigation_widget->changePage(2);
    });
    connect(action4, &QAction::triggered, this, [=]() {
        navigation_widget->changePage(3);
    });

    toolbar->setFloatable(false);
    toolbar->setMovable(false);
}

