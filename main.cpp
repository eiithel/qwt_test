#include "mainwindow.h"
#include <QApplication>
#include <qwt/qwt_plot.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //QwtPlot *plot = new QwtPlot();


    return a.exec();
}
