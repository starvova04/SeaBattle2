#ifndef SHIPSSTOCKFORM_H
#define SHIPSSTOCKFORM_H

#include <QWidget>

namespace Ui {
class ShipsStockForm;
}

class ShipsStockForm : public QWidget
{
    Q_OBJECT

public:
    explicit ShipsStockForm(QWidget *parent = nullptr);
    ~ShipsStockForm();

public:
    Ui::ShipsStockForm *ui;

    void restoreShips();
};

#endif // SHIPSSTOCKFORM_H
