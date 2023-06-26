#include "shippcellbtn.h"


ShippCellBtn::ShippCellBtn(QWidget* parent, std::string color) : CellBtn(parent, color)
{
    this->setFixedWidth(28);
    this->setFixedHeight(28);
    this->setStyleSheet(QString::fromStdString("QPushButton { background: " + color + "; border: 2px solid #1FA3AB; border-radius: 5px;}"
                                                                                      "QPushButton:hover {border: 4px solid #1FA3AB;}"));
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
