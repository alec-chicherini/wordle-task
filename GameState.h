#pragma once
#include <QDebug>
#include <QObject>
#include <QHash>
#include <array>
#include <unordered_set>

namespace std {
  template<> struct hash<QString> {
    std::size_t operator()(const QString& s) const noexcept {
      return (size_t) qHash(s);
    }
  };
}

constexpr int ROWS_NUM = 6;
constexpr int COLS_NUM = 5;

class GameState : public QObject
{
    Q_OBJECT

public:
    void InputChar(const QString& ch);
    GameState();
    QString GetRow(int);
    enum class eProcessRowResult
    {
        WORD_DO_NOT_EXISTS,
        WORD_EXISTS,
        WORD_IS_ANSWER
    };
    eProcessRowResult ProcessRow();

signals:
    void signalMsgBox(QString);
    void signalUpdate(int);

private:
    std::array<QString,ROWS_NUM> m_game_state_array;
    int m_row{0};
    QString m_word_hidden;
    std::unordered_set<QString> m_set_of_words;
};
