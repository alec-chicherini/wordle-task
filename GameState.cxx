#include <GameState.h>
#include <QApplication>
#include <QRandomGenerator>
#include <QColor>

#include <filesystem>
#include <fstream>
GameState::eProcessRowResult GameState::ProcessRow()
{
    GameState::eProcessRowResult result;

    QString& word = m_game_state_array[m_row];
    if(word == m_word_hidden)
    {
        result = GameState::eProcessRowResult::WORD_IS_ANSWER;
    }
    else if(m_set_of_words.find(word) != m_set_of_words.end())
    {
        result = GameState::eProcessRowResult::WORD_EXISTS;
    }
    else
    {
        result = GameState::eProcessRowResult::WORD_DO_NOT_EXISTS;
    }
    return result;
};

QString GameState::GetRow(int row)
{
    return m_game_state_array[row];
};

void GameState::InputChar(const QString& ch)
    {
        if(m_row == ROWS_NUM)
        {
        //    emit signalGameOver();
            qDebug()<<"Game Over";
            qApp->exit(0);
            return;
        }

        QString & qStr = m_game_state_array[m_row];

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
            auto processRowColors = [&]()
                {
                    QVector<QColor> result(COLS_NUM);
                    for(qsizetype i=0; i<qsizetype(COLS_NUM); i++)
                    {
                        if(qStr.at(i) == m_word_hidden.at(i))
                        {
                            result[i] = Qt::green;
                        }
                        else if(m_word_hidden.contains(qStr.at(i)))
                        {
                            result[i] = Qt::yellow;
                        }
                        else
                        {
                            result[i] = Qt::lightGray;
                        }
                    }
                    return result;
                };

            eProcessRowResult processRowResult = ProcessRow();
            if(processRowResult == eProcessRowResult::WORD_IS_ANSWER)
            {
                emit signalUpdateRowColors(m_row, processRowColors());
                emit signalMsgBox(QString("Вы победили.\nВы отгадали слово:\n%1").arg(m_word_hidden));
            }
            else if(processRowResult == eProcessRowResult::WORD_EXISTS)
            {
                emit signalUpdateRowColors(m_row, processRowColors());
                if(m_row != ROWS_NUM-1)
                {
                    m_row++;
                }
                else
                {
                    emit signalMsgBox(QString("Вы проиграли.\nБыло загадано слово:\n%1").arg(m_word_hidden));
                }
            }
            else if(processRowResult == eProcessRowResult::WORD_DO_NOT_EXISTS)
            {
                emit signalMsgBox(QString("Такого слова не существует"));
            }
        }
        else if(ch == "Enter" && qStr.length() != COLS_NUM)
        {
            emit signalMsgBox(QString("Букв меньше чем надо"));
        }
        else
        {
            if(qStr.length() != COLS_NUM)
            {
                qStr.push_back(ch);
                emit signalUpdate(m_row);
            }
        }

    };

GameState::GameState()
{
    try
    {
        namespace fs = std::filesystem;
        const fs::path defaultWordsPath(fs::current_path()/"words.txt");
        if(fs::exists(defaultWordsPath))
        {
            std::ifstream stream{defaultWordsPath};
            std::string word;
            while(stream >> word)
            {
                QString qStrWord = QString::fromStdString(word).toUpper();
                if(qStrWord.length()==5)
                {
                    m_set_of_words.insert(QString::fromStdString(word).toUpper());
                }
            }
        }
        else
        {
            throw std::logic_error("words.txt do not exists");
        }

        if(m_set_of_words.size() == 0)
        {
            throw std::logic_error("set of words size is zero");
        }
        else
        {
            int pos = QRandomGenerator::global()->bounded(quint32(m_set_of_words.size()));
            m_word_hidden = *std::next(m_set_of_words.begin(), pos);
            qDebug()<<"Word hidden:"<<m_word_hidden;
        }
    }
    catch(std::exception& ex)
    {
        qDebug()<<QString("GameState std::exception(%1)\nExit 1").arg(ex.what());
        qApp->exit(1);
    }
};
