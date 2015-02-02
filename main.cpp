#include "mainwindow.h"
#include <QApplication>

#include "graph.h"
#include <iostream>

#include <QDebug>
#include <QString>

using std::string;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
