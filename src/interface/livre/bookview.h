#ifndef BOOKVIEW_H
#define BOOKVIEW_H

#include <QWidget>
#include <QTextBrowser>
#include "../../librairie/livre.h"

class BookView : public QWidget
{
    Q_OBJECT
public:
    explicit BookView(QWidget *parent = nullptr);
    void updateDisplay(Livre *livre);
    void clean();

private:
    Livre* livre;
    QTextBrowser* affichage;
signals:

};

#endif // BOOKVIEW_H
