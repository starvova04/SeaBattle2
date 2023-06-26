#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class StartPage;
}

class StartPage : public QWidget
{
    Q_OBJECT

public:
    explicit StartPage(QWidget *parent = nullptr, QStackedWidget* nav = nullptr);
    ~StartPage();

private slots:
    void on_pushButton_clicked();

private:
    QStackedWidget* _navigation;
    Ui::StartPage *ui;
};

#endif // STARTPAGE_H
