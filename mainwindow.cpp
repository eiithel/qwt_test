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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    MyPlot *plot = new MyPlot(this);

    ui->verticalLayout->addWidget(plot);
    connect(ui->pushButton, SIGNAL(clicked(bool)), plot,SLOT(hideplot()));
    connect(ui->zoombtn, SIGNAL(clicked(bool)), plot, SLOT(zoomoff()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


}
