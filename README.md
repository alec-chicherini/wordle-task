# wordle-task
Это pet project с актуальным на 2025 год.

# Plan
| # | What | Platform | Stack | State | Comment |
|-|-|-|-|-|-|
|1|Desktop application|Debian 10|C++, Qt 5.11|Done|Собирается и запускается в Debian:buster|
|2|Desktop application|other Linuxes|C++, Qt Latest|Planning|Cобираться и запускается в других версиях линукса(Ubuntu 24.04,...)|
|3|Web application|Web browsers|C++, Qt Latest, Web Assembly|Planning|Приложение в Web Assembly, работает в Google Chrome|
|4|Web Application|Telegramm App|C++, TDLib|Planning|Можно поиграть в официальных приложениях Telegramm Desktop и Telegramm Android|
|5|Web Application|VK Mini Apps|????|Planning|Можно поиграть в VK|
|6|Backend|Ubuntu 24.04|C++, userver, postgres|Planning|IAM Service|
|7|Backend|Ubuntu 24.04|C++, userver, redis|Planning|Сервер статистики|

# 1
### Собрать
#### Запустить сборку в docker. Образ debian 10 из DockerHub.

```bash
git clone https://github.com/alec-chicherini/wordle-task.git
cd wordle-task
mkdir result #Тут будет инсталятор wordle-task_24.12_amd64.deb
docker build . -t wordle-task-build
docker run -v ./result:/result wordle-task-build
```

### Играть
#### Запустить игру
Пуск - Стандартные - wordle-task
 
#### Добавить слова в игру
```bash
echo "УЕЫАО ЭЯИЮЙ" > /usr/etc/wordle-task/words/new_words.txt
``` 

# 2
TODO:

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
