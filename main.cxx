#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <vector>
int main(int argc, char **argv)
{
QApplication app (argc, argv);

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

for(int i = 0; i < 6; i++)
{
    for(int j = 0; j < 5; j++)
    {
        qGridLayout->addWidget(createBtnGameField(),i,j);
    }
}

constexpr int KEY_SIZE = 50;
using strQSize_T = std::pair<std::string,QSize>;
auto createKeyboardRow = [](const std::vector<strQSize_T>& btnAttribute)
{
    QWidget* gameKeyboardRow = new QWidget();
    QHBoxLayout* qHBoxLayout = new QHBoxLayout(gameKeyboardRow);
    qHBoxLayout->setSpacing(2);
    for(const auto & attr:btnAttribute)
    {
        auto btn = new QPushButton(attr.first.c_str());
        btn->setMinimumWidth(attr.second.width());
	btn->setFixedHeight(attr.second.height());
        qHBoxLayout->addWidget(btn);
    }
    return gameKeyboardRow;
};

auto key = [](const std::string& name, QSize size = QSize{KEY_SIZE,KEY_SIZE})
{
	return strQSize_T{name,size};
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


QWidget game;
QVBoxLayout* qVBoxLayout = new QVBoxLayout(&game);
qVBoxLayout->addLayout(qGridLayout);
qVBoxLayout->addLayout(qVBoxLayoutKeyboard,1);


 game.show();

 return app.exec();
}
