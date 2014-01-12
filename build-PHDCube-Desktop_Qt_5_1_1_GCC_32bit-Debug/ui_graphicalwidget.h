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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicalWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *scaleMinus;
    QPushButton *pushButton;
    QLabel *label;
    QSpinBox *spinBoxSpread;
    QPushButton *pushButton_2;
    QPushButton *scalePlus;
    QTextEdit *textEdit;
    QGraphicsView *graphicsView;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *GraphicalWidget)
    {
        if (GraphicalWidget->objectName().isEmpty())
            GraphicalWidget->setObjectName(QStringLiteral("GraphicalWidget"));
        GraphicalWidget->resize(912, 283);
        gridLayout = new QGridLayout(GraphicalWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
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
        spinBoxSpread->setMinimum(0);
        spinBoxSpread->setMaximum(100);
        spinBoxSpread->setValue(0);

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


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        textEdit = new QTextEdit(GraphicalWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 1, 1, 1);

        graphicsView = new QGraphicsView(GraphicalWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        textEdit_2 = new QTextEdit(GraphicalWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        gridLayout->addWidget(textEdit_2, 0, 2, 1, 1);


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
