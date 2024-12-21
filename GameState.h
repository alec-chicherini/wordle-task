#pragma once
#include <QDebug>
#include <QObject>
#include <array>

constexpr int ROWS_NUM = 6;
constexpr int COLS_NUM = 5;

class GameState : public QObject
{
    Q_OBJECT

public:
    void InputChar(const QString& ch);
    GameState();
    QString GetRow(int);
signals:
    void signalProcessRow(const QString);
    void signalGameOver();
    void signalUpdate(int);

private:
    std::array<QString,ROWS_NUM> m_game_state_array;
    int m_row{0};
};
