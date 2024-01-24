#ifndef ADHERENTVIEW_H
#define ADHERENTVIEW_H

#include <QWidget>
#include <QTextBrowser>
#include "../../librairie/adherent.h"

class AdherentView : public QWidget
{
    Q_OBJECT
public:
    explicit AdherentView(QWidget *parent = nullptr);
    void updateDisplay(Adherent *adherent);
    void clean();

private:
    Adherent* adherent;
    QTextBrowser* affichage;
signals:

};

#endif // ADHERENTVIEW_H
