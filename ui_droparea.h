/********************************************************************************
** Form generated from reading UI file 'droparea.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DROPAREA_H
#define UI_DROPAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DropArea
{
public:

    void setupUi(QWidget *DropArea)
    {
        if (DropArea->objectName().isEmpty())
            DropArea->setObjectName("DropArea");
        DropArea->resize(386, 386);
        DropArea->setStyleSheet(QString::fromUtf8("background: yellow;"));

        retranslateUi(DropArea);

        QMetaObject::connectSlotsByName(DropArea);
    } // setupUi

    void retranslateUi(QWidget *DropArea)
    {
        DropArea->setWindowTitle(QCoreApplication::translate("DropArea", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DropArea: public Ui_DropArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DROPAREA_H
