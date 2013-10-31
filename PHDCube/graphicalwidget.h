#ifndef GRAPHICALWIDGET_H
#define GRAPHICALWIDGET_H

#include <QWidget>
#include <QPainter>

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

    bool drawShapes;
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::GraphicalWidget *ui;
};

#endif // GRAPHICALWIDGET_H
