#ifndef CELLBTN_H
#define CELLBTN_H

#include <QPushButton>

class CellBtn : public QPushButton
{
public:
    CellBtn(QWidget* parent = nullptr, std::string color = "");

    bool isShip = false;
    bool isMissed = false;
    bool isKilled = false;

    void makeShip();
    void makeKilled();
    void makeMissed();   
};

#endif // CELLBTN_H
