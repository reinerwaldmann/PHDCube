#ifndef GRAPHICALWIDGET_H
#define GRAPHICALWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QShortcut>
#include "consolemsg.h"

namespace Ui {
class GraphicalWidget;
}

class GraphicalWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GraphicalWidget(QWidget *parent = 0);
    ~GraphicalWidget();
    void drawStuff ();

    void paintEvent(QPaintEvent *);

    void generate ();



    QHash <int, int>  dots;
    int left, right;


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
