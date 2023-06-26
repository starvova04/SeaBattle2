#include "cellbtn.h"

CellBtn::CellBtn(QWidget* parent, std::string color) : QPushButton(parent)
{
    this->setFixedWidth(28);
    this->setFixedHeight(28);
    this->setStyleSheet(QString::fromStdString("QPushButton { background: " + color + "; border: 2px solid #1FA3AB; border-radius: 5px;}"
                                               "QPushButton:hover {border: 4px solid #1FA3AB;}"));
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void CellBtn::makeShip() {
    this->isShip = true;
    this->setStyleSheet(QString::fromStdString("QPushButton { background: #F8F275; border: 2px solid #1FA3AB; border-radius: 5px;}"
                                               "QPushButton:hover {border: 4px solid #1FA3AB;}"));
}

void CellBtn::makeKilled() {
    this->isKilled = true;
    this->isShip = false;
    this->setStyleSheet(QString::fromStdString("QPushButton { background: #74B683; border: 2px solid #1FA3AB; border-radius: 5px;}"
                                               "QPushButton:hover {border: 4px solid #1FA3AB;}"));
}

void CellBtn::makeMissed() {
    this->isMissed = true;
    this->setStyleSheet(QString::fromStdString("QPushButton { background: pink; border: 2px solid #1FA3AB; border-radius: 5px;}"
                                               "QPushButton:hover {border: 4px solid #1FA3AB;}"));
}
