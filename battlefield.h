#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "cellbtn.h"
#include <QWidget>

namespace Ui {
class BattleField;
}

class BattleField : public QWidget
{
    Q_OBJECT

public:
    explicit BattleField(QWidget *parent = nullptr, BattleField* copy = nullptr);

    void enable(bool isEnabled);

    CellBtn* lastPressed = nullptr;

    BattleField* deepCopy();

    ~BattleField();

public slots:
    void handleBtn();



public:
    Ui::BattleField *ui;
};

#endif // BATTLEFIELD_H
