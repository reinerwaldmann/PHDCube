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

struct dot {

    //dot(double ix, double iy){x=ix; y=iy;  }
    template  <class Type, class Type2> dot (Type ix, Type2 iy )
    {
        x=(double)ix;
        y=(double) (iy);

    }

    dot ()
    {
    x=0;
    y=0;
    }

            double x; double y;};

struct rectangleRecord { dot rt; dot lt; dot rb; dot lb; double S;};



class GraphicalWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GraphicalWidget(QWidget *parent = 0);
    ~GraphicalWidget();
    void drawStuff ();

    void paintEvent(QPaintEvent *);

    void pregen();

    void generate ();

    void generateEllipse();

    bool belongsToEllipse (int x, int y);  //does it belong to ellipse border? 1 - yeah 0 - nope

    bool dotBelongsToRect (dot lt, dot rt, dot lb, dot rb);
    //1 - mean, that some point from dots belongs to the rectangular area
    //0 - means not




    void search(double iy);

    void supersearch();
    QTimer  * timer;

    bool saveAsImage();

    void interpolation();
    /* делает границу области непрерывной и по x и по y в дискрете 1 */




    QGraphicsLineItem   * linesearchtr;
    QGraphicsLineItem   * linesearchtl;
    QGraphicsLineItem   * linesearchb;
    QGraphicsLineItem   * linesearchr;
    QGraphicsLineItem   * linesearchl;










    //current y
    double y;



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

    QList <dot> dotslist; //mising y points interpolized



    int left, right;



    QList <rectangleRecord> records;


    //writing 'magic buttons' is an extremely bad habit

private slots:
    void on_pushButton_clicked();

    void on_scaleMinus_clicked();

    void on_scalePlus_clicked();

    void on_pushButton_2_clicked();


    void onTimerTicked();

private:
    Ui::GraphicalWidget *ui;
};

#endif // GRAPHICALWIDGET_H
