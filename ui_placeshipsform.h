/********************************************************************************
** Form generated from reading UI file 'placeshipsform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLACESHIPSFORM_H
#define UI_PLACESHIPSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "battlefield.h"
#include "droparea.h"
#include "shipsstockform.h"

QT_BEGIN_NAMESPACE

class Ui_PlaceShipsForm
{
public:
    QLabel *TurnLabel;
    BattleField *widget;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    ShipsStockForm *widget_2;
    DropArea *widget_3;

    void setupUi(QWidget *PlaceShipsForm)
    {
        if (PlaceShipsForm->objectName().isEmpty())
            PlaceShipsForm->setObjectName("PlaceShipsForm");
        PlaceShipsForm->resize(860, 500);
        PlaceShipsForm->setStyleSheet(QString::fromUtf8("QLabel#TurnLabel {\n"
"	color: #008af8;\n"
"	font-size: 30px;\n"
"	height: 30px;\n"
"	font-weight: bold;\n"
"}\n"
"QWidget#PlaceShipsForm {\n"
"	background: white\n"
"}"));
        TurnLabel = new QLabel(PlaceShipsForm);
        TurnLabel->setObjectName("TurnLabel");
        TurnLabel->setGeometry(QRect(20, 10, 225, 40));
        TurnLabel->setStyleSheet(QString::fromUtf8(""));
        TurnLabel->setAlignment(Qt::AlignCenter);
        widget = new BattleField(PlaceShipsForm);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 70, 280, 280));
        widget->setStyleSheet(QString::fromUtf8("background: transparent"));
        pushButton = new QPushButton(PlaceShipsForm);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(600, 400, 171, 41));
        pushButton->setStyleSheet(QString::fromUtf8("height: 35px;\n"
"background: #869cff;\n"
"border-radius: 15px;\n"
"font-size: 16px;\n"
"color: white;\n"
"font-weight: 600;\n"
""));
        pushButton->setFlat(false);
        layoutWidget = new QWidget(PlaceShipsForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(390, 70, 401, 171));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("margin: 15px;\n"
"font-size: 18px;\n"
"color: rgb(59, 50, 124);\n"
"font-weight: 600;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        widget_2 = new ShipsStockForm(layoutWidget);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(0, QFormLayout::FieldRole, widget_2);

        widget_3 = new DropArea(PlaceShipsForm);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(20, 70, 280, 280));
        widget_3->setAcceptDrops(true);
        widget_3->setStyleSheet(QString::fromUtf8("background: yellow;"));
        widget->raise();
        TurnLabel->raise();
        pushButton->raise();
        layoutWidget->raise();
        widget_3->raise();

        retranslateUi(PlaceShipsForm);

        QMetaObject::connectSlotsByName(PlaceShipsForm);
    } // setupUi

    void retranslateUi(QWidget *PlaceShipsForm)
    {
        PlaceShipsForm->setWindowTitle(QCoreApplication::translate("PlaceShipsForm", "Form", nullptr));
        TurnLabel->setText(QCoreApplication::translate("PlaceShipsForm", "Place your ships", nullptr));
        pushButton->setText(QCoreApplication::translate("PlaceShipsForm", "Start game", nullptr));
        label->setText(QCoreApplication::translate("PlaceShipsForm", "Ships left", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaceShipsForm: public Ui_PlaceShipsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLACESHIPSFORM_H
