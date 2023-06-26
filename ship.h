#ifndef SHIP_H
#define SHIP_H

#include "cellbtn.h"
#include <QGraphicsItem>

class Ship : public QGraphicsItem
{
public:
    Ship(QWidget* parent = nullptr, int* width = nullptr);

private:
    int* _width;
    QVector<CellBtn> _cells;
};

#endif // SHIP_H
