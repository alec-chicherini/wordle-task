#include <GameState.h>

#include <QApplication>
#include <QMessageBox>

QString GameState::GetRow(int row)
    {
        return m_game_state_array[row];
    };

void GameState::InputChar(const QString& ch)
    {
        if(m_row == ROWS_NUM)
        {
            emit signalGameOver();
            qDebug()<<"Game Over";
            qApp->exit(0);
            return;
        }

        QString & qStr = m_game_state_array[m_row];
        qDebug()<<"GameState::InputChar "<<qStr<<qStr.length();

        if(ch == "<-")
        {
            if(qStr.length())
            {
                qStr.remove(qStr.length()-1,1);
                emit signalUpdate(m_row);
            }
        }
        else if(ch == "Enter" && qStr.length() == COLS_NUM)
        {
            emit signalProcessRow(qStr);
            if(m_row != ROWS_NUM)
            {
                m_row++;
            }
        }
        else if(ch == "Enter" && qStr.length() != COLS_NUM)
        {
            //do nothing
        }
        else
        {
            if(qStr.length() != COLS_NUM)
            {
                qStr.push_back(ch);
                emit signalUpdate(m_row);
            }
        }
   qDebug()<<"GameState::InputChar "<<qStr;
    };

    GameState::GameState() { };
