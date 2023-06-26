/********************************************************************************
** Form generated from reading UI file 'battlefield.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLEFIELD_H
#define UI_BATTLEFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BattleField
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *BattleField)
    {
        if (BattleField->objectName().isEmpty())
            BattleField->setObjectName("BattleField");
        BattleField->resize(386, 386);
        BattleField->setStyleSheet(QString::fromUtf8("background: transparent"));
        gridLayout = new QGridLayout(BattleField);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(BattleField);

        QMetaObject::connectSlotsByName(BattleField);
    } // setupUi

    void retranslateUi(QWidget *BattleField)
    {
        BattleField->setWindowTitle(QCoreApplication::translate("BattleField", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BattleField: public Ui_BattleField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLEFIELD_H
