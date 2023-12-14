#include "interface/librairie.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Librairie librairie_window;
    librairie_window.show();
    return a.exec();
}
