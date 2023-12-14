#include <QStackedLayout>
#include "pagesnavigationwidget.h"

PagesNavigationWidget::PagesNavigationWidget(QWidget *parent)
    : QWidget{parent}
{
    QStackedLayout layout(this);
}
