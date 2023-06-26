#ifndef SHIPFORM_H
#define SHIPFORM_H

#include "cellbtn.h"
#include <QWidget>

namespace Ui {
class ShipForm;
}

class ShipForm : public QWidget
{
    Q_OBJECT

public:
    explicit ShipForm(QWidget *parent = nullptr, int* width = nullptr, int* height = nullptr, bool isVertical = false);

    int* getWidth();
    int* getHeight();
    bool getOrientation();


    bool isVertical;
    bool isOnField = false;

    ~ShipForm();


protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void disableChildMouseEvent(QWidget* childWidget);
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    Ui::ShipForm *ui;
    int* _width;
    int* _height;
    QVector<CellBtn*> _cells;
    bool isDragging = false;
    QPointF startPos;

    bool checkEdge(int grid_i, int grid_j, int width, int height, bool isVertical);
    bool checkAnotherShip(int grid_i, int grid_j, int width, int height, bool isVertical);

};

#endif // SHIPFORM_H
