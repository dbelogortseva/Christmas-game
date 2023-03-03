#include "mainwindow.h"
#include "menu.h"
#include <QPixmap>
#include <QWidget>
#include <QApplication>
#include <QCursor>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow b;
    b.show();
    QObject::connect(&b, SIGNAL(exitApp()), &a, SLOT(quit()));
    return a.exec();
}
