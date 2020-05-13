#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedWidth(480);
    w.setFixedHeight(280);

    w.show();
    return a.exec();
}
