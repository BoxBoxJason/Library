#ifndef ADHERENTWIDGET_H
#define ADHERENTWIDGET_H

#include <QWidget>
#include <QTextBrowser>
#include "../../librairie/adherent.h"

class AdherentWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AdherentWidget(QWidget *parent = nullptr);
    void updateDisplay(Adherent *adherent);
    void clean();

private:
    Adherent* adherent;
    QTextBrowser* affichage;
signals:

};

#endif // ADHERENTWIDGET_H
