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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QLabel *label;
    QSpinBox *spinBoxSpread;
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

        label = new QLabel(GraphicalWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBoxSpread = new QSpinBox(GraphicalWidget);
        spinBoxSpread->setObjectName(QStringLiteral("spinBoxSpread"));
        spinBoxSpread->setMinimum(1);
        spinBoxSpread->setMaximum(100);

        horizontalLayout->addWidget(spinBoxSpread);

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
        pushButton->setText(QApplication::translate("GraphicalWidget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        label->setText(QApplication::translate("GraphicalWidget", "\320\240\320\260\320\267\320\261\321\200\320\276\321\201", 0));
        pushButton_2->setText(QApplication::translate("GraphicalWidget", "\320\246\320\270\320\272\320\273", 0));
        scalePlus->setText(QApplication::translate("GraphicalWidget", "+", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphicalWidget: public Ui_GraphicalWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICALWIDGET_H
