#include <qwt/qwt_math.h>
#include <qwt/qwt_scale_engine.h>
#include <qwt/qwt_symbol.h>
#include <qwt/qwt_plot_grid.h>
#include <qwt/qwt_plot_marker.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_legend.h>
#include <qwt/qwt_text.h>
#include <qwt/qwt_scale_engine.h>
#include <qvector.h>
#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <QDebug>
#include <QtGlobal>
#include <QTextStream>


#include "myplot.h"

bool ishiden =false;


MyPlot::MyPlot(QWidget *parent):
    QwtPlot(parent)
{
    setAutoReplot(false);

    setTitle("Humidity");

    setCanvasBackground(QColor(Qt::darkBlue));

    // legend
    QwtLegend *legend = new QwtLegend;
    legend->setFrameStyle(QFrame::Box|QFrame::Sunken);
    insertLegend(legend, QwtPlot::BottomLegend);

    // grid
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin(true);

    grid->setMajorPen(QPen(Qt::white, 0, Qt::DotLine));
    grid->setMinorPen(QPen(Qt::gray, 0 , Qt::DotLine));
    grid->attach(this);

    // axes
    //enableAxis(QwtPlot::yRight);
    setAxisTitle(QwtPlot::xBottom, "Time");
    //setAxisTitle(QwtPlot::yRight, "Phase [deg]");

    setAxisMaxMajor(QwtPlot::xBottom, 7);
    setAxisMaxMinor(QwtPlot::xBottom, 10);
    //setAxisScaleEngine(QwtPlot::xBottom, new QwtLogScaleEngine);

    // curves
    d_crv1 = new QwtPlotCurve("Amplitude");

    d_crv1->setPen(QPen(Qt::yellow));
    d_crv1->setYAxis(QwtPlot::yLeft);
    d_crv1->attach(this);


    zoomer[0] = new QwtPlotZoomer( QwtPlot::xBottom, QwtPlot::yLeft,
                                   this->canvas());
    zoomer[0]->setRubberBand(QwtPicker::RectRubberBand);
    zoomer[0]->setRubberBandPen(QColor(Qt::green));
    zoomer[0]->setTrackerMode(QwtPicker::ActiveOnly);
    zoomer[0]->setTrackerPen(QColor(Qt::white));


    QVector<double> xData;
    QVector<double> yData;
    QVector<double> zData = readFile();

    for(int i=0; i<39;i++){
        xData.push_back(i+1);
    }//revoir axe des temps: mesure prises toutes les 3h pendant 5 jours.

    yData.push_back(5);
    yData.push_back(4);
    yData.push_back(200);

    d_crv1->setSamples(xData, zData);

    setAutoReplot(true);
}



void MyPlot::hideplot(){

    if(ishiden){
        d_crv1->setVisible(true);

        ishiden =false;
    }else{
        d_crv1->setVisible(false);

        ishiden = true;
    }

}


void MyPlot::zoomoff(){

    zoomer[0]->zoom(0);
    d_crv1->setVisible(true);

}

QVector<double> MyPlot::readFile(){

    QFile file;
    file.setFileName("/home/ethel/qwt-5.2/test-ethel/test3/result.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text| QIODevice::ReadWrite);

    QVector<double> humidity;

    QTextStream in(&file);
    QByteArray line;


    double buffer;
    qDebug() << file.canReadLine();
    file.seek(0);

    while(!in.atEnd()){

        in.readLine();
        in >> buffer;
        humidity.push_back(buffer);
    }

    file.close();
    qWarning() << humidity.size();
    return humidity;

}
