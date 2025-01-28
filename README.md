# wordle-task
Это pet project с игрой Вордли(Wordle).

# Plan
| # | What | Platform | Stack | State | Comment |
|-|-|-|-|-|-|
|1|Desktop application|Ubuntu 24.04|C++, Qt 6|In Progress|Собирается и запускается в Ubuntu 24.04. Работает в Ubuntu 20.04 и 24.04|
|2|Web application|Web browsers|C++, Qt Latest, Web Assembly|Planning|Приложение в Web Assembly, работает в Google Chrome|
|3|Web Application|Telegramm App|C++, TDLib|Planning|Можно поиграть в официальных приложениях Telegramm Desktop и Telegramm Android|
|4|Web Application|VK Mini Apps|????|Planning|Можно поиграть в VK|
|5|Backend|Ubuntu 24.04|C++, userver, postgres|Planning|IAM Service|
|6|Backend|Ubuntu 24.04|C++, userver, redis|Planning|Сервер статистики|

# 1 2
Протестировано Ubuntu 20.04, 24.04

### Собрать на чистой машине Ubuntu 24.04
```bash
git clone https://github.com/alec-chicherini/wordle-task.git
cd wordle-task
bash ./scripts/install_docker.sh #Внимательно! Удаляет старый докер, устанавливает новый rootless
mkdir result #Тут будет инсталятор
docker build . -t wordle-task-build
docker run -v ./result:/result wordle-task-build
```

### Подготовить чистую машину для тестов Ubuntu 20.04, 22.04, 24.04
```
apt update
apt install ubuntu-desktop
apt install xrdp
#passwd

dpkg -i wordle-task_24.12_amd64.deb
apt-get install -f -y
```

### Играть
#### Запустить игру
Пуск - Стандартные - wordle-task
 
#### Добавить слова в игру
```bash
echo "УЕЫАО ЭЯИЮЙ" > /usr/etc/wordle-task/words/new_words.txt
``` 

# 3
TODO:

# 4
TODO:

# 5
TODO:

# 6
TODO:

# 7
TODO:
