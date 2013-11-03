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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicalWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QPushButton *scaleMinus;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *scalePlus;

    void setupUi(QWidget *GraphicalWidget)
    {
        if (GraphicalWidget->objectName().isEmpty())
            GraphicalWidget->setObjectName(QStringLiteral("GraphicalWidget"));
        GraphicalWidget->resize(551, 464);
        verticalLayout = new QVBoxLayout(GraphicalWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(GraphicalWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scaleMinus = new QPushButton(GraphicalWidget);
        scaleMinus->setObjectName(QStringLiteral("scaleMinus"));
        scaleMinus->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(14);
        scaleMinus->setFont(font);

        horizontalLayout->addWidget(scaleMinus);

        pushButton = new QPushButton(GraphicalWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(GraphicalWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        scalePlus = new QPushButton(GraphicalWidget);
        scalePlus->setObjectName(QStringLiteral("scalePlus"));
        scalePlus->setMinimumSize(QSize(0, 30));
        scalePlus->setFont(font);

        horizontalLayout->addWidget(scalePlus);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GraphicalWidget);

        QMetaObject::connectSlotsByName(GraphicalWidget);
    } // setupUi

    void retranslateUi(QWidget *GraphicalWidget)
    {
        GraphicalWidget->setWindowTitle(QApplication::translate("GraphicalWidget", "Form", 0));
        scaleMinus->setText(QApplication::translate("GraphicalWidget", "-", 0));
        pushButton->setText(QApplication::translate("GraphicalWidget", "\320\237\320\253\320\251\320\254!", 0));
        pushButton_2->setText(QApplication::translate("GraphicalWidget", "\320\237\320\253\320\251\320\25411!", 0));
        scalePlus->setText(QApplication::translate("GraphicalWidget", "+", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphicalWidget: public Ui_GraphicalWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICALWIDGET_H
