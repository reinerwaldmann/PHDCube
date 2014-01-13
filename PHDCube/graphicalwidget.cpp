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
     yhigh=-50;
    a = 100;
     b = 50;


    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Plus+Qt::KeypadModifier), this);
        QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(on_scalePlus_clicked()));
        QShortcut *shortcut1 = new QShortcut(QKeySequence(Qt::Key_Minus+Qt::KeypadModifier ), this);
            QObject::connect(shortcut1, SIGNAL(activated()), this, SLOT(on_scaleMinus_clicked()));


            QShortcut *shortcut2 = new QShortcut(QKeySequence(Qt::Key_Space), this);
            QObject::connect(shortcut2, SIGNAL(activated()), this, SLOT(on_pushButton_2_clicked()));

            scene = new QGraphicsScene(this);




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


    saveAsImage();
    return;


}



void GraphicalWidget::transformToRingList()
{
//from ellipse list to the ring list

    ringList.clear();
/*
    ringList.append (dot  (-30,30  )  );
            ringList.append (dot  (50,15  )  );
            ringList.append (dot  (20,-20  )  );
            ringList.append (dot  (-13,-11  )  );


    return;


*/

    ringList.append(dot(xleft,0));


    for (int x=xleft+1; x<xright; x++)
    {
         if (!dots.count(x))
        {
            QString ggg= QString ("transformToRingList: Error accessing key").append(QString::number(x)) ;
            qDebug (ggg.toUtf8());
               continue;
        }

         ringList.append(dot(x, dots.values(x)[1]));
    }


    ringList.append(dot(xright,0));




    for (int x=xright-1; x>xleft; x--)
    {

        if (!dots.count(x))
        {

            QString ggg= QString ("transformToRingList: Error accessing key").append(QString::number(x)) ;
            qDebug (ggg.toUtf8());
               continue;
        }

        ringList.append(dot (x, dots.values(x)[0]));


    }




}





void GraphicalWidget::pregen()

{



//QGraphicsLineItem* rect = scene->addLine(-10, 0, 500,500);
//QGraphicsItem * item * scene.itemAt()
//эта штука может помочь найти айтем

ui->graphicsView->setScene(scene);
ui->graphicsView->show();

QGraphicsLineItem* line = scene->addLine(0, -100, 0, 100, QPen (Qt::blue));
QGraphicsLineItem* line1 = scene->addLine(-100, 0, 100, 0, QPen (Qt::blue));



//MIND THAT 40-70 IS TO TL ANGLE OF A RECT CONTAINING THE ELLIPSE!
/*left: 40;-70+80/2
 *right: 40+200; -70+80/2
 *top: 40+200/2, -70
 *bottom:  40+200/2, -70+80
 *center point is: 40+200/2  ; -70+80/2    [140; -30]
 *though may be deduced from the edge points
 *
 **/



//magic of creating polygons

QPolygonF  polygon;

foreach (dot d, ringList)
{
    //polygon<<QPointF(d.x, d.y);

    //отобразим полигон  в привычных координатах

    polygon<<QPointF(d.x, -1*d.y);


}


/*polygon<< QPointF(xleft, 0);



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
*/


QGraphicsPolygonItem * polygonitem = scene->addPolygon(polygon);


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
        qDebug( QString::number( dots.values(i)[0]).toUtf8()  );

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
          //  qDebug (ggg.toUtf8());
               continue;
        }


        QString sss = QString::number( t).append("\t").append (  QString::number( dots.values(t)[0]).append("\t").append(QString::number( dots.values(t)[1])  ));
       // qDebug (sss.toUtf8());

    }



}



void GraphicalWidget::generateEllipse()
{

    //int spread=50;
    int spread=ui->spinBoxSpread->value();

    //double lowborder=20;


    //first stage: edge points
    qsrand(QTime::currentTime().msec()); //seeding random generator

    double shuffle;



for (int x=xleft; x<xright+1; x+=1)
{



    shuffle = spread?qrand() %  spread : 0;

    dots.insertMulti(x,    shuffle+  sqrt( fabs( ((double) 1-(x*x)/(a*a))*(b*b) ))  );
    dots.insertMulti(x, -1 *  (shuffle+  sqrt(  fabs(    (((double) 1-(x*x)/(a*a))*(b*b) ) ) ) ));


/*    qDebug( QString::number( dots.values(x)[0]).toUtf8()  );
    qDebug( QString::number( dots.values(x)[1]).toUtf8()  );
*/



}


}






void GraphicalWidget::on_pushButton_2_clicked()
{
    scene->clear(); //очистка сцены

    qDebug ("Scene cleared");

    generateEllipse(); //генерация эллипса

     qDebug ("Ellipse generated");

    transformToRingList(); //записываем все точки эллипса в кольцевой список

    qDebug ("Transformed to ring list");

    interpolation(); //интерполируем

      foreach (dot t, ringList)

      {
          con1 (tr ("x=%1 y=%2").arg(QString::number(t.x)).arg (QString::number(t.y) ) );



      }


    findExtremes(); //находим границы

  /*  foreach (dot t, dotslist)

    {
        qDebug( QString::number( t.x).toUtf8() + "\t" + QString::number( t.y).toUtf8()       );

    }
*/

    qDebug ("Interpolated");

    pregen();  //всё рисуем на экране

    qDebug ("Pregen successful");

    supersearch(); //производим поиск

    qDebug ("Supersearched successful");

}


bool GraphicalWidget::belongsToEllipse (int x, int y)  //does it belong to ellipse border? 1 - yeah 0 - nope
{
//радиус, в котором считаем, что точка принадлежит эллипсу - 1, так как дискрет 1
    //это соответствует floor


    /*ещё вариант, на сей раз с идеей, что, если данная точка оказывается на одной
     *прямой с двумя соседними точками из ringList, то она находится на границе полигона
     *
     */

    for (int i=0; i<ringList.size()-2; i++)
    {

        if (fabs(   ((double) y-ringList.at(i).y)/(ringList.at(i+1).y-ringList.at(i).y) -  ((double)x-ringList.at(i).x)/(ringList.at(i+1).x-ringList.at(i).x))<=0.1 )
        {
            return 1;
        }

    }


    if ((y-ringList.at(  ringList.size()-1   ).y)/(ringList.at(0).y-ringList.at(ringList.size()-1).y) ==(x-ringList.at(ringList.size()-1).x)/(ringList.at(0).x-ringList.at(ringList.size()-1).x))
    return 1;


    return 0;

/*


    foreach  (dot t, dotslist)
    {
        if ( (qFloor(t.x)==x ) && (qFloor(t.y)==y)) return 1;

    }

    return 0 ;
*/


    //прямое сравнение такого типа производит кирпич
    //if (dotslist.contains(dot (x,y   ))) return 1; return 0;


/*

    int paranoid=4;
    if (!dots.contains(x))
    {
        return 0;
    }
    if  (( (double)y>dots.values(x)[0]-paranoid )&&( (double)y<dots.values(x)[0]+paranoid )) return 1;
    if (dots.values(x).size()>1)
    {
        if  (( (double)y>dots.values(x)[1]-paranoid )&&( y<dots.values(x)[1]+paranoid )) return 1;
    }
return 0;
*/


/* qDebug ("shit happens");
 qDebug (QString::number(x).toUtf8());
*/

}



bool GraphicalWidget::dotBelongsToRect (dot lt, dot rt, dot lb, dot rb)
//1 - mean, that some point from dots belongs to the rectangular area
//0 - means not
{
QList <int > keys = dots.keys();
int key;
double val;
foreach  (key, keys)
{


    foreach (val, dots.values(key))

    {
        if (((key<=rt.x)&&(key>=lt.x)) && ( (val>=rb.y)&&(val<=rt.y)))
        {
            return 1;
        }
    }
}

return 0;
}





void GraphicalWidget::search(double iy)
{
    int prn=0; //paranoid when limiting the movement

dot rt, lt, rb, lb;
double S (0);

double y = iy;
//int y = 20;



con1(tr("search y=%1").arg(iy));


//int y =20; //начнём с этого

//for (y = ylow+1; y<yhigh; y++)
//{

//go right
for (int x=0; x<rightmost.x+prn; x++)
//    for (int x=0; x<xright+10; x++)
{
    linesearchtr->setLine(0,-1*y,x,-1*y);

    //linesearchtr->setLine(0,y,x,y);

    if (belongsToEllipse(x,y))
    {
        rb.x=x;
        rb.y=y;

        break;
    }
}

    //go left
        for (int x=0; x>leftmost.x-prn; x--)
            //for (int x=0; x>xleft-10; x--)
        {
//            linesearchtl->setLine(0,y,x,y);
            linesearchtl->setLine(0,-1*y,x,-1*y);

            if (belongsToEllipse(x,y))
            {
            lb.x=x;
            lb.y=y;
            break;
            }

        }

//left-top

        for (int y=lb.y-1; y>bottommost.y-prn;y--)  //граничное условие - ЛАЖОВОЕ ПЕРЕДЕЛАТЬ БЫСТРОА!!!!!!

                    //for (int y=lb.y-2; y>lb.y-100;y--) //граничное условие - ЛАЖОВОЕ ПЕРЕДЕЛАТЬ БЫСТРОА!!!!!!


        {
                //linesearchl->setLine(lb.x, lb.y, lb.x, y);
                linesearchl->setLine(lb.x, -1*lb.y, lb.x, -1*y);




                lt.x=lb.x;




                if (belongsToEllipse(lb.x,y))
                {

                    lt.y=y;
                    break;
                }

        }

//right-top

        for (int y=rb.y-1; y>bottommost.y-prn;y--)   //граничное условие - ЛАЖОВОЕ ПЕРЕДЕЛАТЬ БЫСТРОА!!!!!!

         //                   for (int y=rb.y-2; y>rb.y-100;y--) //граничное условие - ЛАЖОВОЕ ПЕРЕДЕЛАТЬ БЫСТРОА!!!!!!
        {
                linesearchr->setLine(rb.x, -1*rb.y, rb.x, -1*y);
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

linesearchb->setLine(rt.x, -1*rt.y, lt.x, -1*lt.y);

S =fabs ( (rb.y - rt.y) * (rt.x-lt.x) );

/*
qDebug ("current y: ");
qDebug (QString::number(y).toUtf8());

qDebug ("current S: ");
qDebug (QString::number(S).toUtf8());
*/
//struct rectangleRecord { dot rt; dot lt; dot rb; dot lb; double S;};

rectangleRecord rr;
rr.rt=rt;
rr.lt=lt;
rr.rb=rb;
rr.lb=lb;

rr.S = S;

records.append(rr);



con1(tr("Found rect: rt=%1 %2  lt= %3 %4 rb=%5 %6 lb=%7 %8").arg(rt.x).arg(rt.y).arg(lt.x).arg(lt.y).arg(rb.x).arg(rb.y).arg(lb.x).arg(lb.y));



//break;



//sleep(1);




//}




if (y==ylow)
{

    //максимально возможная площадь, хто больше - невалиден
    double maxS= ( fabs    (yhigh - ylow) ) * (fabs (xright - xleft) );
   qDebug (QString::number(maxS).toUtf8());
    // в нашем случае это площадь, которая примерно ограничивает нашу область

    double Smax(0);
    rectangleRecord maxsrecord;
    rectangleRecord var;
    foreach (var, records) {
        if (var.S > Smax)
        {

            //if (var.S< maxS  )
            if (1)
            {   Smax = var.S;
                maxsrecord = var; }
        }
    }

    qDebug ("Biggest S ");
    qDebug (QString::number(Smax).toUtf8());

    QPointF tlQ (maxsrecord.lt.x, -1*maxsrecord.lt.y);
    QPointF brQ (maxsrecord.rb.x, -1*maxsrecord.rb.y);
    QGraphicsRectItem * rrrect =   scene->addRect(QRectF (tlQ, brQ), QPen (Qt::red));

update();
}




}




 void GraphicalWidget::supersearch()
 {




     timer = new QTimer (this);
     connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTicked()));


//     y=bottommost.y; //категорически неправильно!!!!


     double toppoint=0;

     foreach (dot t, dotslist)
     {


         if (t.x==0) { toppoint=qMax(t.y, toppoint);  }

     }


     con (tr("Toppoint.y=%1").arg(QString::number(toppoint)));


     y=toppoint;





     timer->start(100);



 linesearchtr = scene->addLine(0, -1*y, 1,-1*y);
     linesearchtl = scene->addLine(0, -1*y, 1,-1*y);
      linesearchb = scene->addLine(0, -1*y, 1,-1*y);
     linesearchr = scene->addLine(0, -1*y, 1,-1*y);
     linesearchl = scene->addLine(0, -1*y, 1,-1*y);





 }


 void GraphicalWidget::onTimerTicked()
 {

     search(y);
     y--;
     if (y<ylow)

        {

         con1(tr("Timer stopped, yhigh=%1 reached").arg(QString::number(yhigh)));

         timer->stop();


        }

 }

 bool GraphicalWidget::saveAsImage()
 {

     QImage img(1024,768,QImage::Format_ARGB32_Premultiplied);
     QPainter p(&img);
     scene->render(&p);
     p.end();




     img.save(QString("images/img")+QDateTime::currentDateTime().toString("dd.MM.yyyy_hh:mm:ss") +".png");
     //img.save("sheisse.png");


return 1;
 }



 void GraphicalWidget::interpolation()
 /* делает границу области непрерывной и по x и по y в дискрете 1 */
 {
     /*
    QHash <int, double>  dots;
    QList <dot> dotslist; //mising y points interpolized
*/
//ringList - список кольцевой, от левой точки по часовой стрелке.

     double i; //это станет х при интерполяции
     double fi; //это станет f(x) опять же при интерполяции

     dotslist.clear();

  for (int index=0; index<ringList.size()-1; index++)
     {
        dotslist.append(ringList.at(index));//добавить точку

        //список - кольцевой, и  значения х там изменяются на 1, что в положительной, что в отрицательной
          //части. Стало быть, у у там должен быть тоже дискрет 1. Если это не так, то
          //интерполируем линейно.

        ///!!!!!! при интерполяции  в данном случае x и y  меняются местами!!!!!

        if (  fabs( qFloor ( ringList.at(index).y)  - qFloor(ringList.at(index+1).y)  )>1 ) //если модуль разности между двумя соседними значениями y более 1
          {
                i=ringList.at(index).y; //принимаем первую точку за начало интерполяции
            do
               {
                   i++;
                   fi=ringList.at(index).x +  (i- ringList.at(index).y) * (ringList.at(index+1).x-ringList.at(index).x)/(ringList.at(index+1).y-ringList.at(index).y);
                   dotslist.append(dot (fi,i));


            }
                //while (fabs (qFloor (i)  -  qFloor ( ringList.at(index+1).y) )>1);

                while (i  <    ringList.at(index+1).y );

            }
     }

return;


 }




 //searches for rightmost, leftmost, topmost, bottommost dots.
     /**they are used as the limiters while searching for the edges
TO BE LAUCHED ONLY AFTER THE INTERPOLATION!!!!!!!!!!!!!!!!
*/
 void GraphicalWidget::findExtremes()
 {
     topmost=bottommost=leftmost=rightmost=dot(0,0);


     foreach (dot d, dotslist)
     {
         if (d.y>topmost.y) {topmost=d;}
         if (d.y<bottommost.y) {bottommost=d;}
         if (d.x>rightmost.x) {rightmost=d;}
         if (d.x<leftmost.x) {leftmost=d;}

     }

     qDebug ("topmost");
    qDebug (topmost.o().toUtf8());

    qDebug ("bottommost");
    qDebug (bottommost.o().toUtf8());


    qDebug ("leftmost");
    qDebug (leftmost.o().toUtf8());

    qDebug ("rightmost");
    qDebug (rightmost.o().toUtf8());


 }

 void GraphicalWidget::con(QString msg)
 {

     ui->textEdit->append(msg);

 }

 void GraphicalWidget::con1(QString msg)
 {

     ui->textEdit_2->append(msg);

 }


