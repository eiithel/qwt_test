#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qwt/qwt_series_data.h>
#include <qwt/qwt_point_data.h>
#include <qwt/qwt_plot.h>
#include <qlabel.h>
#include <QVBoxLayout>
#include <qwt/qwt_plot_curve.h>
#include <qvector.h>
#include "myplot.h"
#include <qwt/qwt_plot_zoomer.h>
#include <QFile>

//network
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    MyPlot *plot = new MyPlot(this);




    //zoomer = new QwtPlotZoomer( plot );
    //    zoomer->setKeyPattern( QwtEventPattern::KeyRedo, Qt::Key_I, Qt::ShiftModifier );
    //    zoomer->setKeyPattern( QwtEventPattern::KeyUndo, Qt::Key_O, Qt::ShiftModifier );
    //QwtPlot *plot = new QwtPlot(this);
    //Splot->setTitle("History");

    ui->verticalLayout->addWidget(plot);
    connect(ui->pushButton, SIGNAL(clicked(bool)), plot,SLOT(hideplot()));
    connect(ui->zoombtn, SIGNAL(clicked(bool)), plot, SLOT(zoomoff()));


    //    QwtPlotCurve *curve = new QwtPlotCurve();
    //    QPen pen;
    //    pen.setColor(Qt::blue);
    //    pen.setWidth(2);

    //    curve->setPen(pen);

    //    curve->setSamples(xData, yData);
    //    curve->attach(plot);
    //curve->hide();
    //connect(ui->pushButton,on_pushButton_clicked(),curve);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

//    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
//    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
//    connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));

//    mgr->get(QNetworkRequest(QUrl("http://www.google.com")));

}
