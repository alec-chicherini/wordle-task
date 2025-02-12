# wordle-task
Это pet project с игрой Вордли(Wordle).

# Plan
| # | What | Platform | Stack | State | Comment |
|-|-|-|-|-|-|
|1|Desktop application|Ubuntu 20.04|C++, Qt5|Done|Собирается в Ubuntu 20.04. Работает в Ubuntu 20.04|
|2|Web application|Web browsers|C++, Qt Latest, Web Assembly|In Progress|Приложение в Web Assembly, работает в Google Chrome|
|3|Web Application|Telegramm App|C++, TDLib|Planning|Можно поиграть в официальных приложениях Telegramm Desktop и Telegramm Android|
|4|Web Application|VK Mini Apps|????|Planning|Можно поиграть в VK|
|5|Backend|Ubuntu 24.04|C++, userver, postgres|Planning|IAM Service|
|6|Backend|Ubuntu 24.04|C++, userver, redis|Planning|Сервер статистики|
|7|GUI|Ubuntu|C++, Qt 6|Planning|Использовать Qt Virtual Keyboard|
|8|Desktop application|Ubuntu|C++, Qt6 latest|Planning|Сделать новый таргет сборки в Docker где Qt latest, сборка на ubuntu:25.04. Qt собирается из latest исходников или из репозитория. Сборка статическая где всё вкомпилено в бинарник и Qt и системные либы. |
|9|Desktop application|Linux|C++, Qt 6|Planning|Сделать консольную версию. Чтобы всё работало в bash с минимальным интерфейсом вроде dialog.|

# 0
Все сборки в докере.

Установить docker 
```bash
source <(curl https://raw.githubusercontent.com/alec-chicherini/wordle-task/refs/heads/main/scripts/install_docker.sh)
```
# 1
### Собрать на чистой машине Ubuntu
Собрать в docker
```bash
git clone https://github.com/alec-chicherini/wordle-task.git
cd wordle-task
docker build --target=qt_from_repo . -t wordle-task-build
#docker build --target=qt_from_source . -t wordle-task-build #другая опция взять собрать Qt из исходников.
mkdir result #Тут будет инсталятор 
docker run -v ./result:/result wordle-task-build
```

### Подготовить чистую машину для тестов Ubuntu 20.04
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
echo "УЕЫАО ЭЯИЮЙ" > /opt/wordle-task/words/new_words.txt
``` 

# 2
Собрать в docker и запустить python http.server для дебага
```bash
git clone https://github.com/alec-chicherini/wordle-task.git
cd wordle-task
docker build --target=qt_wasm_build_from_source . -t wordle-task-build-wasm
docker run --rm -d -p 80:8000 wordle-task-build-wasm
```

# 4
TODO:

# 5
TODO:

# 6
TODO:

# 7
TODO:
