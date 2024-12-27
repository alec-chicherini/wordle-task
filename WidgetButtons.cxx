#include <WidgetButtons.h>

WidgetButtons::WidgetButtons(GameState* state):m_state(state)
{
    auto createBtnGameField = []()
    {
        QPushButton* btn;
        btn = new QPushButton(" ");
        btn->setFixedSize(60,60);
        return btn;
    };

    QGridLayout* qGridLayout = new QGridLayout();
    qGridLayout->setSpacing(2);
    qGridLayout->setContentsMargins(0, 0, 0, 0);
    qGridLayout->setAlignment(Qt::AlignCenter);

    for(int i = 0; i < ROWS_NUM; i++)
    {
        for(int j = 0; j < COLS_NUM; j++)
        {
            QPushButton * widgetField = createBtnGameField();
            m_btns[i][j] = widgetField;
            qGridLayout->addWidget(widgetField,i,j);
            QObject::connect(m_state, &GameState::signalUpdate,
                             this, [=](int row){
                                                QString rowString = m_state->GetRow(row);
                                                for(int k = 0; k < COLS_NUM; k++)
                                                {
                                                    if(k != rowString.length())
                                                    {
                                                        m_btns[row][k]->setText(QString(rowString[k]));
                                                    }
                                                    else
                                                    {
                                                        m_btns[row][k]->setText("");
                                                    }
                                                }
                                                });
            QObject::connect(m_state, &GameState::signalUpdateRowColors,
                             this, [=](int row, QVector<QColor> colors){
                                                QString rowString = m_state->GetRow(row);
                                                for(int k = 0; k < COLS_NUM; k++)
                                                {
                                                    auto btn = m_btns[row][k];
                                                    QPalette pal = btn->palette();
                                                    pal.setColor(QPalette::Button, colors[k]);
                                                    btn->setAutoFillBackground(true);
                                                    btn->setPalette(pal);
                                                    btn->update();
                                                }
                                                });
            QObject::connect(m_state, &GameState::signalReset,
                             this, [=](){
                                            QPalette pal = widgetField->palette();
                                            pal.setColor(QPalette::Button, QColor(239,239,239,255));
                                            widgetField->setAutoFillBackground(true);
                                            widgetField->setPalette(pal);
                                            widgetField->update();
                                         });

        }
    }

    this->setLayout(qGridLayout);
};
