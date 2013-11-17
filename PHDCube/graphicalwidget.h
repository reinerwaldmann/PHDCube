#ifndef GRAPHICALWIDGET_H
#define GRAPHICALWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QShortcut>
#include "consolemsg.h"
#include <QGraphicsLineItem>
#include <QGraphicsItem>

namespace Ui {
class GraphicalWidget;
}

struct dot {double x; double y;};
struct rectangleRecord { dot rt; dot lt; dot rb; dot lb; double S;};



class GraphicalWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GraphicalWidget(QWidget *parent = 0);
    ~GraphicalWidget();
    void drawStuff ();

    void paintEvent(QPaintEvent *);

    void generate ();

    void generateEllipse();

    bool belongsToEllipse (int x, int y);  //does it belong to ellipse border? 1 - yeah 0 - nope

    void search();



    QGraphicsScene  * scene;


    //cordinates of the extremes
    double  xleft;
    double xright;
    double ylow;
    double yhigh;


    //coeffs of the ellipse (at this version the area is an ellipse
    double a;
    double b;





    //border of the desired area
    QHash <int, double>  dots;
    int left, right;



    QList <rectangleRecord> records;


    //writing 'magic buttons' is an extremely bad habit

private slots:
    void on_pushButton_clicked();

    void on_scaleMinus_clicked();

    void on_scalePlus_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GraphicalWidget *ui;
};

#endif // GRAPHICALWIDGET_H
