#ifndef PLACESHIPSFORM_H
#define PLACESHIPSFORM_H

#include "battlefield.h"
#include <QStackedWidget>
#include <QWidget>
#include <QDragEnterEvent>
#include <QMimeData>

namespace Ui {
class PlaceShipsForm;
}

class PlaceShipsForm : public QWidget
{
    Q_OBJECT

public:
    explicit PlaceShipsForm(QWidget *parent = nullptr, QStackedWidget* nav = nullptr);
    ~PlaceShipsForm();
public:
    Ui::PlaceShipsForm *ui;
    QStackedWidget* _navigation;
signals:
    void dataPassed(BattleField* fieldData);
public slots:
    void on_pushButton_clicked();
    void sendDataToGameWidget();
    void receiveData(bool newGame);
};

#endif // PLACESHIPSFORM_H
