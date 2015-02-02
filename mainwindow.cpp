#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    Nodes * n = new Nodes();
        Graph * gr = new Graph();
        Node * n1 = new Node("kroosh");
        Node * n2 = new Node("mykhalko");

        gr->addNode(n1);
        gr->addNode(n2);
        gr->addEdge(n1, n2);
//        gr->removeEdge(n1, n2);
        gr->removeNode(n1);
        qDebug() << QString::fromStdString(gr->toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}
