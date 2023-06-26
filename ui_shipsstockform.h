/********************************************************************************
** Form generated from reading UI file 'shipsstockform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHIPSSTOCKFORM_H
#define UI_SHIPSSTOCKFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShipsStockForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_4;

    void setupUi(QWidget *ShipsStockForm)
    {
        if (ShipsStockForm->objectName().isEmpty())
            ShipsStockForm->setObjectName("ShipsStockForm");
        ShipsStockForm->resize(200, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ShipsStockForm->sizePolicy().hasHeightForWidth());
        ShipsStockForm->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ShipsStockForm);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName("horizontalLayout");

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");

        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(ShipsStockForm);

        QMetaObject::connectSlotsByName(ShipsStockForm);
    } // setupUi

    void retranslateUi(QWidget *ShipsStockForm)
    {
        ShipsStockForm->setWindowTitle(QCoreApplication::translate("ShipsStockForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShipsStockForm: public Ui_ShipsStockForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHIPSSTOCKFORM_H
