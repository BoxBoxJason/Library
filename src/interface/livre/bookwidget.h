#ifndef BOOKWIDGET_H
#define BOOKWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include <QHash>
#include <QComboBox>
#include "bookview.h"
#include "../../librairie/livre.h"

class BookWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BookWidget(QWidget *parent = nullptr);
    void updateDisplay(Livre *livre);
    void clean();

private:
    QStackedLayout* stacked_layout;
    QComboBox* choix_livre_box;
    QHash<QString,Livre*> livres;
    BookView* book_view;
    bool updating_livres;

signals:

};

#endif // BOOKWIDGET_H
