#include <WidgetKeyboard.h>

WidgetKeyboard::WidgetKeyboard(GameState* state) : m_state(state)
{
    constexpr int KEY_SIZE = 50;
    using strQSize_T = std::pair<QString,QSize>;
    auto createKeyboardRow = [&](const std::vector<strQSize_T>& btnAttribute)
    {
        QWidget* gameKeyboardRow = new QWidget();
        gameKeyboardRow->setContentsMargins(0,0,0,0);

        QHBoxLayout* qHBoxLayout = new QHBoxLayout(gameKeyboardRow);
        qHBoxLayout->setSpacing(2);
        for(const auto & attr:btnAttribute)
        {
            auto btn = new QPushButton(attr.first);
            btn->setMinimumWidth(attr.second.width());
    	    btn->setFixedHeight(attr.second.height());
            qHBoxLayout->addWidget(btn);
            QObject::connect(btn,    &QPushButton::pressed,
                             m_state,  [=](){ m_state->InputChar(btn->text()); });
        }
        return gameKeyboardRow;
    };

    auto key = [](const std::string& name, QSize size = QSize{KEY_SIZE,KEY_SIZE})
    {
	    return strQSize_T{QString::fromUtf8(name.c_str()),size};
    };

    QVBoxLayout* qVBoxLayoutKeyboard = new QVBoxLayout();

    qVBoxLayoutKeyboard->setSpacing(2);
    qVBoxLayoutKeyboard->setContentsMargins(0, 0, 0, 0);
    qVBoxLayoutKeyboard->setAlignment(Qt::AlignCenter);
    qVBoxLayoutKeyboard->addWidget(createKeyboardRow(
    {
    key("Й"),key("Ц"),key("У"),key("К"),key("Е"),key("Н"),key("Г"),key("Ш"),key("Щ"),key("З"),key("Х"),key("Ъ")
    } ));
    qVBoxLayoutKeyboard->addWidget(createKeyboardRow(
    {
    key("Ф"),key("Ы"),key("В"),key("А"),key("П"),key("Р"),key("О"),key("Л"),key("Д"),key("Ж"),key("Э")
    } ));
    qVBoxLayoutKeyboard->addWidget(createKeyboardRow(
    {
    key("<-",QSize(KEY_SIZE,KEY_SIZE)),key("Я"),key("Ч"),key("С"),key("M"),key("И"),key("Т"),key("Ь"),key("Б"),key("Ю"),key("Enter",QSize(KEY_SIZE*2,KEY_SIZE))
    } ));
    this->setLayout(qVBoxLayoutKeyboard);
};
