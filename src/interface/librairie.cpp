#include <QVBoxLayout>
#include "librairie.h"
#include "navigation/navigationtopbar.h"

Librairie::Librairie(QWidget *parent)
    : QWidget{parent} {
    QVBoxLayout layout(this);
    NavigationTopBar navigation_bar(this);
    layout.addWidget(&navigation_bar,0,Qt::AlignmentFlag::AlignTop | Qt::AlignmentFlag::AlignHCenter);
}
