#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::CustomizeWindowHint |
                         Qt::WindowMinimizeButtonHint |
                         Qt::WindowMaximizeButtonHint);
    w.setFixedSize(800,600);
    w.show();
    return a.exec();
}
