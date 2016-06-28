#ifndef MYPLOT_H
#define MYPLOT_H

#include <QObject>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_marker.h>
#include <qwt/qwt_plot_zoomer.h>
#include <QVector>

class MyPlot : public QwtPlot
{
    Q_OBJECT
public:
    MyPlot(QWidget *parent);
    QVector<double> readFile();

public slots:
    void hideplot();
    void zoomoff();

private:

    QwtPlotCurve *d_crv1;
    QwtPlotCurve *d_crv2;
    QwtPlotMarker *d_mrk1;
    QwtPlotMarker *d_mrk2;
    QwtPlotZoomer *zoomer[2];

};

#endif // MYPLOT_H
