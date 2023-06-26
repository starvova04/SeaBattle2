/********************************************************************************
** Form generated from reading UI file 'startpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTPAGE_H
#define UI_STARTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *StartPage)
    {
        if (StartPage->objectName().isEmpty())
            StartPage->setObjectName("StartPage");
        StartPage->resize(860, 500);
        StartPage->setStyleSheet(QString::fromUtf8("background: #fffcff;"));
        verticalLayout = new QVBoxLayout(StartPage);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(StartPage);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Algerian")});
        font.setPointSize(40);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #008af8;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(StartPage);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"	height: 40px;\n"
"	width: 100px;\n"
"	background: #869cff;\n"
"	border-radius: 10px;\n"
"	margin: 0 100px;\n"
"	font-size: 20px;\n"
"	color: white;\n"
"	font-weight: bold;"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(StartPage);

        QMetaObject::connectSlotsByName(StartPage);
    } // setupUi

    void retranslateUi(QWidget *StartPage)
    {
        StartPage->setWindowTitle(QCoreApplication::translate("StartPage", "Form", nullptr));
        label->setText(QCoreApplication::translate("StartPage", "Sea Battle", nullptr));
        pushButton->setText(QCoreApplication::translate("StartPage", "New Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartPage: public Ui_StartPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGE_H
