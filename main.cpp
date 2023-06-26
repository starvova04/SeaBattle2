#include "gamepage.h"
#include "mainwindow.h"
#include "placeshipsform.h"
#include "startpage.h"

#include <QApplication>
#include <QStackedWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QStackedWidget* widgets = new QStackedWidget();

    StartPage* page1 = new StartPage(&w, widgets);
    PlaceShipsForm* page2 = new PlaceShipsForm(&w, widgets);
    GamePage* page3 = new GamePage(&w, widgets);

    widgets->addWidget(page1);
    widgets->addWidget(page2);
    widgets->addWidget(page3);

    BattleField::connect(page2, SIGNAL(dataPassed(BattleField*)), page3, SLOT(receiveData(BattleField*)));
    BattleField::connect(page3, SIGNAL(dataPassed(bool)), page2, SLOT(receiveData(bool)));

    w.setCentralWidget(widgets);

    w.show();
    return a.exec();
}
