#include "graphicalwidget.h"
#include "ui_graphicalwidget.h"

GraphicalWidget::GraphicalWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicalWidget)

{
    drawShapes=0;
    ui->setupUi(this);


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

    QPainter painter (this);

 if (drawShapes) //or when smf changes in the program, like button pressed
 {
            QRectF rectangle(10.0, 20.0, 80.0, 60.0);
            int startAngle = 30 * 16;
            int spanAngle = 120 * 16;
            painter.drawArc(rectangle, startAngle, spanAngle);


 }

}

void GraphicalWidget::on_pushButton_clicked()
{//in this case button toggles whether stuff would be displayed


    drawShapes = !drawShapes;
  update();
}
