#ifndef LIBRARYVIEW_H
#define LIBRARYVIEW_H

#include <QWidget>
#include <QTextBrowser>
#include "../../librairie/bibliotheque.h"

class LibraryView : public QWidget
{
    Q_OBJECT
public:
    explicit LibraryView(QWidget *parent = nullptr);
    void clean();
    void updateDisplay(Bibliotheque* bibliotheque);

private:
    QTextBrowser* affichage;
    Bibliotheque* bibliotheque;

signals:

};

#endif // LIBRARYVIEW_H
