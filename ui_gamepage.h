/********************************************************************************
** Form generated from reading UI file 'gamepage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPAGE_H
#define UI_GAMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePage
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *GamePage)
    {
        if (GamePage->objectName().isEmpty())
            GamePage->setObjectName("GamePage");
        GamePage->resize(860, 500);
        horizontalLayoutWidget = new QWidget(GamePage);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(39, 49, 781, 291));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(GamePage);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(5, 38, 851, 221));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_2 = new QWidget(GamePage);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(39, -1, 781, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("margin: 0 0 0 80px;"));

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("margin: 0 0 0 50px;\n"
"font-weight: 500;"));
        label_3->setMargin(0);

        horizontalLayout_2->addWidget(label_3);

        pushButton = new QPushButton(GamePage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(610, 420, 161, 41));
        pushButton->setStyleSheet(QString::fromUtf8("height: 35px;\n"
"background: #869cff;\n"
"border-radius: 15px;\n"
"font-size: 16px;\n"
"color: white;\n"
"font-weight: 600;\n"
""));
        horizontalLayoutWidget->raise();
        horizontalLayoutWidget_2->raise();
        label->raise();
        pushButton->raise();

        retranslateUi(GamePage);

        QMetaObject::connectSlotsByName(GamePage);
    } // setupUi

    void retranslateUi(QWidget *GamePage)
    {
        GamePage->setWindowTitle(QCoreApplication::translate("GamePage", "Form", nullptr));
        label->setText(QCoreApplication::translate("GamePage", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("GamePage", "Your ships", nullptr));
        label_3->setText(QCoreApplication::translate("GamePage", "Make your move here", nullptr));
        pushButton->setText(QCoreApplication::translate("GamePage", "New Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GamePage: public Ui_GamePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
