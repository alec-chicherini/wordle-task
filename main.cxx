#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QObject>

#include <vector>
#include <memory>

#include <GameState.h>
#include <WidgetKeyboard.h>
#include <WidgetButtons.h>

int main(int argc, char **argv)
{
QApplication app (argc, argv);

GameState * state = new GameState();

QWidget game;
WidgetKeyboard widgetKeyboard(state);
WidgetButtons widgetButtons(state);

QVBoxLayout* qVBoxLayout = new QVBoxLayout(&game);
qVBoxLayout->addWidget(&widgetButtons);
qVBoxLayout->addWidget(&widgetKeyboard);

game.show();

return app.exec();
}
