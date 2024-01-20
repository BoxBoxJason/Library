#ifndef LIBRARYWIDGET_H
#define LIBRARYWIDGET_H

#include <QGridLayout>
#include <QWidget>

class LibraryWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LibraryWidget(QWidget *parent = nullptr);
    void afficherBiblios();
    void clean();

private:
    QGridLayout* biblios;
signals:

};

#endif // LIBRARYWIDGET_H
