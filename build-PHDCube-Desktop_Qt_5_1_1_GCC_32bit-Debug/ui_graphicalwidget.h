/********************************************************************************
** Form generated from reading UI file 'graphicalwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICALWIDGET_H
#define UI_GRAPHICALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicalWidget
{
public:
    QPushButton *pushButton;
    QSlider *rightLeftMove;
    QDial *dialScale;
    QSlider *topbottomMove;

    void setupUi(QWidget *GraphicalWidget)
    {
        if (GraphicalWidget->objectName().isEmpty())
            GraphicalWidget->setObjectName(QStringLiteral("GraphicalWidget"));
        GraphicalWidget->resize(400, 300);
        pushButton = new QPushButton(GraphicalWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 240, 75, 30));
        pushButton->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(14);
        pushButton->setFont(font);
        rightLeftMove = new QSlider(GraphicalWidget);
        rightLeftMove->setObjectName(QStringLiteral("rightLeftMove"));
        rightLeftMove->setGeometry(QRect(100, 270, 160, 16));
        rightLeftMove->setOrientation(Qt::Horizontal);
        dialScale = new QDial(GraphicalWidget);
        dialScale->setObjectName(QStringLiteral("dialScale"));
        dialScale->setGeometry(QRect(30, 210, 50, 64));
        topbottomMove = new QSlider(GraphicalWidget);
        topbottomMove->setObjectName(QStringLiteral("topbottomMove"));
        topbottomMove->setGeometry(QRect(370, 20, 16, 160));
        topbottomMove->setOrientation(Qt::Vertical);

        retranslateUi(GraphicalWidget);

        QMetaObject::connectSlotsByName(GraphicalWidget);
    } // setupUi

    void retranslateUi(QWidget *GraphicalWidget)
    {
        GraphicalWidget->setWindowTitle(QApplication::translate("GraphicalWidget", "Form", 0));
        pushButton->setText(QApplication::translate("GraphicalWidget", "\320\237\320\253\320\251\320\254!", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphicalWidget: public Ui_GraphicalWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICALWIDGET_H
