#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GraphicalWidget * wdg = new GraphicalWidget (this);
   setCentralWidget(wdg);

}

MainWindow::~MainWindow()
{
    delete ui;
}
