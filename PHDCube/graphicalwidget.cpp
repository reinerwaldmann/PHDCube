#include "graphicalwidget.h"
#include "ui_graphicalwidget.h"



GraphicalWidget::GraphicalWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicalWidget)

{

    ui->setupUi(this);



    xleft=-100;
    xright=100;
     ylow=-50;
     yhigh=50;
    a = 100;
     b = 50;


    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Plus+Qt::KeypadModifier), this);
        QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(on_scalePlus_clicked()));
        QShortcut *shortcut1 = new QShortcut(QKeySequence(Qt::Key_Minus+Qt::KeypadModifier ), this);
            QObject::connect(shortcut1, SIGNAL(activated()), this, SLOT(on_scaleMinus_clicked()));


            QShortcut *shortcut2 = new QShortcut(QKeySequence(Qt::Key_Space), this);
            QObject::connect(shortcut2, SIGNAL(activated()), this, SLOT(on_pushButton_2_clicked()));

            scene = new QGraphicsScene(this);



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


    generateEllipse();





//QGraphicsLineItem* rect = scene->addLine(-10, 0, 500,500);
//QGraphicsItem * item * scene.itemAt()
//эта штука может помочь найти айтем

ui->graphicsView->setScene(scene);
ui->graphicsView->show();

QGraphicsLineItem* line = scene->addLine(0, -100, 0, 100, QPen (Qt::blue));
QGraphicsLineItem* line1 = scene->addLine(-300, 0, 300, 0, QPen (Qt::blue));

/*QGraphicsLineItem* line2 = scene->addLine(40, -70+80/2, 40+200, -70+80/2, QPen (Qt::blue));
QGraphicsLineItem* line3 = scene->addLine(40+200/2, -70, 40+200/2, -70+80, QPen (Qt::blue));
*/
//in this branch we use ellipse as a range,
//itemAt to detect stuff
//we can use elliptical equations to determine if a point
//belongs to our area

//border is included in the area!




//QGraphicsEllipseItem  *  ellipse = scene->addEllipse(-40,-20,80,40);





//MIND THAT 40-70 IS TO TL ANGLE OF A RECT CONTAINING THE ELLIPSE!
/*left: 40;-70+80/2
 *right: 40+200; -70+80/2
 *top: 40+200/2, -70
 *bottom:  40+200/2, -70+80
 *center point is: 40+200/2  ; -70+80/2    [140; -30]
 *though may be deduced from the edge points
 *
 **/

/*
for (int t=-20; t<20; t+=2)


{

    QGraphicsLineItem* lineX = scene->addLine(-40, t, -35, t, QPen (Qt::red));

int k=-40;
while (1)
{
k++;
    if (k>100)
    {
        qDebug  ("Process of searching broken 'cause went out of all borders");
        break; //if k>right.x , that's for breaking the process if all went wrong
    }

    lineX->setLine(-40, t, k, t);

    //if (k*k/(160  )   )

    if ( belongsToEllipse(k,t) ) break;



}

qDebug (QString::number(t).toUtf8() );

qDebug (QString::number(k).toUtf8() );


}

*/




//magic of creating polygons

QPolygonF  polygon;

polygon<< QPointF(xleft, 0);



for (int x=xleft+1; x<xright; x++)
{

    //qDebug (QString::number(i).toUtf8() );


    if (!dots.count(x))
    {

        QString ggg= QString ("Polygon Building UPPER: Error accessing key").append(QString::number(x)) ;
        qDebug (ggg.toUtf8());
           continue;
    }



    polygon <<QPointF(x, dots.values(x)[1] );
}

polygon << QPointF (xright, 0);

for (int x=xright-1; x>xleft; x--)
{

    if (!dots.count(x))
    {

        QString ggg= QString ("Polygon Building LOWER: Error accessing key").append(QString::number(x)) ;
        qDebug (ggg.toUtf8());
           continue;
    }


    polygon <<QPointF(x, dots.values(x)[0] );

}



QGraphicsPolygonItem * polygonitem = scene->addPolygon(polygon);


/*

if ( QGraphicsItem *item =ui->graphicsView->itemAt(40+200+10, -70+80/2)  )
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



void GraphicalWidget::generateEllipse()
{


for (int x=xleft; x<xright; x+=1)
{

    dots.insertMulti(x,   sqrt( fabs( ((double) 1-(x*x)/(a*a))*(b*b) ))  );
    dots.insertMulti(x, -1 *    sqrt(  fabs(    (((double) 1-(x*x)/(a*a))*(b*b) ) ) ) );

}





}






void GraphicalWidget::on_pushButton_2_clicked()
{
search();
}


bool GraphicalWidget::belongsToEllipse (int x, int y)  //does it belong to ellipse border? 1 - yeah 0 - nope
{

    int x1 = x;
    int y1= y;


//    return (   x1  *x1  /10000+  y1*y1/1600==1);
      double t = (x1*x1) / (a*a) + (y1*y1) / (b*b);
      qDebug (QString::number(t).toUtf8());

      return ((t>0.99)&&(t<1.01))  ;





}



void GraphicalWidget::search()
{
dot rt, lt, rb, lb;

double S (0);
int y =20; //начнём с этого



QGraphicsLineItem   * linesearchtr = scene->addLine(0, y, 1,y);
QGraphicsLineItem   * linesearchtl = scene->addLine(0, y, 1,y);


QGraphicsLineItem   * linesearchb = scene->addLine(0, y, 1,y);
QGraphicsLineItem   * linesearchr = scene->addLine(0, y, 1,y);
QGraphicsLineItem   * linesearchl = scene->addLine(0, y, 1,y);



//go right
for (int x=0; x<xright+10; x++)
{
    linesearchtr->setLine(0,y,x,y);

    if (belongsToEllipse(x,y))
    {
    rb.x=x;
    rb.y=y;
    break;
    }

}




    //go left
        for (int x=0; x>xleft-10; x--)
        {
            linesearchtl->setLine(0,y,x,y);

            if (belongsToEllipse(x,y))
            {
            lb.x=x;
            lb.y=y;
            break;
            }

        }

//left-top

        for (int y=lb.y-2; y>lb.y-100;y--)  //граничное условие - ЛАЖОВОЕ ПЕРЕДЕЛАТЬ БЫСТРОА!!!!!!
        {
                linesearchl->setLine(lb.x, lb.y, lb.x, y);
                lt.x=lb.x;




                if (belongsToEllipse(lb.x,y))
                {

                    lt.y=y;
                    break;
                }

        }



        for (int y=rb.y-2; y>rb.y-100;y--)   //граничное условие - ЛАЖОВОЕ ПЕРЕДЕЛАТЬ БЫСТРОА!!!!!!
        {
                linesearchr->setLine(rb.x, rb.y, rb.x, y);
                rt.x=rb.x;




                if (belongsToEllipse(rb.x,y))
                {

                    rt.y=y;
                    break;
                }

        }




        double ymin = qMax (rt.y, lt.y );     //так как экранные координаты повёрнуты наоборот по оси y
         rt.y=ymin;
         lt.y=ymin;

linesearchb->setLine(rt.x, rt.y, lt.x, lt.y);

S =fabs ( (rb.y - rt.y) * (rt.x-lt.x) );


         qDebug ("current S: ");
         qDebug (QString::number(S).toUtf8());

}









/*

  QGraphicsLineItem   * linesearch = scene->addLine(0, 10, 1,10);

for (int  x =0; x<400; x++ )
{
    linesearch->setLine(0,10,x,10);

    if (belongsToEllipse(x,10))
    {
        qDebug ("ss");


        return;

    }

}
*/


