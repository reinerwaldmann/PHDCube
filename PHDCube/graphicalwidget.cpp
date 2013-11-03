#include "graphicalwidget.h"
#include "ui_graphicalwidget.h"



GraphicalWidget::GraphicalWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicalWidget)

{

    ui->setupUi(this);


    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Plus+Qt::KeypadModifier), this);
        QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(on_scalePlus_clicked()));
        QShortcut *shortcut1 = new QShortcut(QKeySequence(Qt::Key_Minus+Qt::KeypadModifier ), this);
            QObject::connect(shortcut1, SIGNAL(activated()), this, SLOT(on_scaleMinus_clicked()));




    on_pushButton_clicked();
}

GraphicalWidget::~GraphicalWidget()
{
    delete ui;


}
/*
Scratch that, from the docs for QPainter..
"Warning: When the paintdevice is a widget,
QPainter can only be used inside a paintEvent()
 function or in a function called by paintEvent();
 that is unless the Qt::WA_PaintOutsidePaintEvent
widget attribute is set. On Mac OS X and Windows,
 you can only paint in a paintEvent() function
regardless of this attribute's setting."
*/

void GraphicalWidget::drawStuff()
{


}


void GraphicalWidget::paintEvent(QPaintEvent *)
{




}

void GraphicalWidget::on_pushButton_clicked()
{


//    generate();
    QGraphicsScene  * scene = new QGraphicsScene(this);

//QGraphicsLineItem* rect = scene->addLine(-10, 0, 500,500);
//QGraphicsItem * item * scene.itemAt()
//эта штука может помочь найти айтем

ui->graphicsView->setScene(scene);
ui->graphicsView->show();

QGraphicsLineItem* line = scene->addLine(0, left-100, 0, right+100, QPen (Qt::blue));
QGraphicsLineItem* line1 = scene->addLine(-300, 0, 300, 0, QPen (Qt::blue));


//in this branch we use ellipse as a range,
//itemAt to detect stuff
//we can use elliptical equations to determine if a point
//belongs to our area

//border is included in the area!




QGraphicsEllipseItem  *  ellipse = scene->addEllipse(40,-70,200,80);

//anchor points are:
/*left: 40-100=-60;-70
 *right:
 *
 *
 **/





/*



//magic of creating polygons

QPolygonF  polygon;

polygon<< QPointF(left, 0);





for (int i=left+1; i<right; i++)
{

    //qDebug (QString::number(i).toUtf8() );


    if (!dots.count(i))
    {

        QString ggg= QString ("Polygon Building UPPER: Error accessing key").append(QString::number(i)) ;
        qDebug (ggg.toUtf8());
           continue;
    }



    polygon <<QPointF(i, dots.values(i)[1] );
}

polygon << QPointF (right, 0);

for (int i=right-1; i>left; i--)
{

    if (!dots.count(i))
    {

        QString ggg= QString ("Polygon Building LOWER: Error accessing key").append(QString::number(i)) ;
        qDebug (ggg.toUtf8());
           continue;
    }


    polygon <<QPointF(i, dots.values(i)[0] );

}



//QGraphicsPolygonItem * polygonitem = scene->addPolygon(polygon);


if ( QGraphicsItem *item   =ui->graphicsView->itemAt(0,0)  )
{

    qDebug ("zero-zero is in a polygon" );
}

*/
}


void GraphicalWidget::on_scaleMinus_clicked()
{
ui->graphicsView->scale(1/1.2, 1/1.2);
}

void GraphicalWidget::on_scalePlus_clicked()
{
ui->graphicsView->scale(1.2, 1.2);
}

void GraphicalWidget::generate()
{
    //random borders are same at this stage
    double highborder=200;
    double lowborder=170;


    //first stage: edge points
    qsrand(QTime::currentTime().msec()); //seeding random generator

    left = lowborder+ qrand() % (int) (highborder-lowborder);
    left*=-1;
    qDebug (QString::number(left).toUtf8());
    //myMessageOutput(1, QtDebugMsg, QString::number(left));

    right = lowborder+ qrand() % (int) (highborder-lowborder);
    qDebug (QString::number(right).toUtf8());


    //2nd stage: generating anchor points

    //note that we should interpolate the last pass as well

    for (int i=left; i<right; i+=20)
    {


        dots.insertMulti(i,   lowborder+ qrand() % (int) (highborder-lowborder));
        dots.insertMulti(i, -1*  (lowborder+ qrand() % (int) (highborder-lowborder)));



    }

return;
    //3rd stage: interpolating
    for (int i=left; i<right-10; i+=10)
    {
        for (int f = i; f<i+10; f++)
        {

            ///- negative part
            int a = ( dots.values(i+10)[0] - dots.values(i)[0] ) /10;
            dots.insertMulti(f, dots.values(i)[0]+a);



//            qDebug (QString::number(f).toUtf8());
            ///+ positive part
            int b = ( dots.values(i+10)[1] - dots.values(i)[1] ) /10;
            dots.insertMulti(f, dots.values(i)[1]+b);
        }

    }
    //outputting
    for (int t = left; t<right; t++)
    {

        if (!dots.count(t))
        {

            QString ggg= QString ("Error accessing key").append(QString::number(t)) ;
            qDebug (ggg.toUtf8());
               continue;
        }


        QString sss = QString::number( t).append("\t").append (  QString::number( dots.values(t)[0]).append("\t").append(QString::number( dots.values(t)[1])  ));
        qDebug (sss.toUtf8());

    }



}



void GraphicalWidget::on_pushButton_2_clicked()
{

}
