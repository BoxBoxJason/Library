#ifndef BOOKWIDGET_H
#define BOOKWIDGET_H

#include <QWidget>
#include <QTextBrowser>
#include "../../librairie/livre.h"

class BookWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BookWidget(QWidget *parent = nullptr);
    void updateDisplay(Livre *livre);
    void clean();

private:
    Livre* livre;
    QTextBrowser* affichage;
signals:

};

#endif // BOOKWIDGET_H
