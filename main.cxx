#include <QApplication>
#include <WidgetGame.h>
int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    WidgetGame game;
    game.show();

    return app.exec();
}
