#ifndef DROPAREA_H
#define DROPAREA_H

#include "shipform.h"
#include <QWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QMimeData>
#include <QDragMoveEvent>

namespace Ui {
class DropArea;
}

class DropArea : public QWidget
{
    Q_OBJECT

public:
    explicit DropArea(QWidget *parent = nullptr);
    ~DropArea();

protected:
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
    void dragMoveEvent(QDragMoveEvent* event);
private:
    Ui::DropArea *ui;
    ShipForm* droppedItem;
public:
    bool checkEdge(int grid_i, int grid_j, int width, int height, bool isVertical);
    bool checkAnotherShip(int grid_i, int grid_j, int width, int height, bool isVertical);

};

#endif // DROPAREA_H
