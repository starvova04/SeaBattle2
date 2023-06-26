/********************************************************************************
** Form generated from reading UI file 'shipform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHIPFORM_H
#define UI_SHIPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShipForm
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *ShipForm)
    {
        if (ShipForm->objectName().isEmpty())
            ShipForm->setObjectName("ShipForm");
        ShipForm->resize(28, 28);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ShipForm->sizePolicy().hasHeightForWidth());
        ShipForm->setSizePolicy(sizePolicy);
        ShipForm->setStyleSheet(QString::fromUtf8("background: transparent;"));
        horizontalLayout = new QHBoxLayout(ShipForm);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(ShipForm);

        QMetaObject::connectSlotsByName(ShipForm);
    } // setupUi

    void retranslateUi(QWidget *ShipForm)
    {
        ShipForm->setWindowTitle(QCoreApplication::translate("ShipForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShipForm: public Ui_ShipForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHIPFORM_H
