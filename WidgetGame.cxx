#include <WidgetGame.h>
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>

WidgetGame::WidgetGame()
{
    m_state = new GameState();
    WidgetKeyboard * widgetKeyboard = new WidgetKeyboard(m_state);
    WidgetButtons * widgetButtons = new WidgetButtons(m_state);

    QVBoxLayout* qVBoxLayout = new QVBoxLayout(this);
    qVBoxLayout->addWidget(widgetButtons);
    qVBoxLayout->addWidget(widgetKeyboard);

    QObject::connect(m_state, &GameState::signalMsgBox,
                     this,    [=](QString msg){
                                                QMessageBox msgBox(this);
                                                msgBox.setText(msg);
                                                msgBox.exec();
                                               });
    QObject::connect(m_state, &GameState::signalQuitOrRestart,
                     this,    [=](){
                                                QMessageBox msgBox(this);
                                                msgBox.setText(QString("Играть ещё?"));
                                                msgBox.addButton(QMessageBox::Yes);
                                                msgBox.addButton(QMessageBox::No);
                                                int result = msgBox.exec();
                                                if(result == QMessageBox::No)
                                                {
                                                    qApp->exit(1);
                                                }
                                                else
                                                {
                                                    m_state->Reset();
                                                }
                                               });
};


void WidgetGame::keyPressEvent(QKeyEvent* event)
{
    quint32 code = event->nativeScanCode();

    QString charToSend;
    bool needToSend = true;
    if(code == 36)
    {
        charToSend = "Enter";
    }
    else if(code == 22)
    {
        charToSend = "<-";
    }
    else if(code>=24 && code<=35)
    {
        QString row1("ЙЦУКЕНГШЩЗХЪ");
        charToSend = QString(row1[code-24]);
    }
    else if(code>=38 && code<=48)
    {
        QString row2("ФЫВАПРОЛДЖЭ");
        charToSend = QString(row2[code-38]);
    }
    else if(code>=52 && code<=60)
    {
        QString row3("ЯЧСМИТЬБЮ");
        charToSend = QString(row3[code-52]);
    }
    else
    {
        needToSend = false;
    }

    if(needToSend)
    {
        m_state->InputChar(charToSend);
    }
};
