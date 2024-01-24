#ifndef LIBRARYWIDGET_H
#define LIBRARYWIDGET_H

#include <QGridLayout>
#include <QWidget>
#include <QStackedLayout>
#include <QComboBox>
#include "../../librairie/bibliotheque.h"
#include "libraryview.h"

class LibraryWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LibraryWidget(QWidget *parent = nullptr);
    void clean();

private:
    QStackedLayout* stacked_layout;
    QComboBox* choix_biblio_box;
    QHash<QString,Bibliotheque*> bibliotheques;
    LibraryView* library_view;
    bool updating_biblios;

signals:

};

#endif // LIBRARYWIDGET_H
