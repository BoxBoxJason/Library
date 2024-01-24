#ifndef ADHERENTWIDGET_H
#define ADHERENTWIDGET_H

#include <QWidget>
#include <QTextBrowser>
#include <QStackedLayout>
#include <QComboBox>
#include <QHash>
#include "adherentview.h"
#include "../../librairie/adherent.h"

class AdherentWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AdherentWidget(QWidget *parent = nullptr);
    void updateDisplay(Adherent *adherent);
    void clean();

private:
    QStackedLayout* stacked_layout;
    QComboBox* choix_adherent_box;
    QHash<QString,Adherent*> adherents;
    AdherentView* adherent_view;
    bool updating_adherents;
signals:

};

#endif // ADHERENTWIDGET_H
