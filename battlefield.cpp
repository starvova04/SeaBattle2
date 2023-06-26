#include "battlefield.h"
#include "ui_battlefield.h"

#include <QPushButton>
#include <QStyleOptionButton>
#include <QDragEnterEvent>
#include <QMimeData>

BattleField::BattleField(QWidget *parent, BattleField* copy) :
    QWidget(parent),
    ui(new Ui::BattleField)
{
    ui->setupUi(this);
    this->lastPressed = new CellBtn();
    this->lastPressed->makeKilled();
    if (copy == nullptr) {
        for (int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                CellBtn* btn = new CellBtn(this);
                connect(btn, &CellBtn::clicked, this, &BattleField::handleBtn);
                ui->gridLayout->addWidget(btn, i, j);
            }
        }
    }
    else {
        QObjectList list = copy->children();
        for (int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                qDebug() << dynamic_cast<CellBtn*>(list[i * 10 + j + 1]);
                ui->gridLayout->addWidget(dynamic_cast<CellBtn*>(list[i * 10 + j + 1]), i, j);

            }
        }
    }
}

BattleField* BattleField::deepCopy() {
    BattleField* newField = new BattleField;
    for (QWidget* child : findChildren<QWidget*>()) {
        QWidget* childCopy = this->deepCopy(); // Рекурсивно копируем дочерний элемент
        childCopy->setParent(newField); // Устанавливаем нового родителя для копии
    }
}

void BattleField::handleBtn() {
    CellBtn* senderBtn = dynamic_cast<CellBtn*>(sender());
    if (senderBtn->isShip)
        senderBtn->makeKilled();
    else if (!senderBtn->isKilled)
        senderBtn->makeMissed();

    this->lastPressed = senderBtn;
}

void BattleField::enable(bool isEnabled) {
    qDebug() << (isEnabled?"enebled":"disa"
                                         "bled");
    QObjectList children = this->children();

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            CellBtn* btn = dynamic_cast<CellBtn*>(children[i * 10 + j]);
            if (btn)
                btn->setEnabled(isEnabled);
        }
    }
}

BattleField::~BattleField()
{
    delete ui;
}
