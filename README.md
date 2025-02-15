# wordle-task
Это pet project с игрой Вордли(Wordle).

<!--Структура репозитория-->
## Структура репозитория
| # | Описание |
|-|-|
|client_qt|Клиент для GUI Linux и Wasm(Web Assembly)|
|server_http|HTTP сервер|
|server_iam|Identity and Access Managment service|
|server_statistics|Сервер статистики для игры|
|client_bash|Клиент для игры в bash/sh|
|site_repotest_ru|Главная страница repotest.ru|

<!--План развития проекта-->
## План развития проекта:
| What | Platform | Stack | State | Comment |
|-|-|-|-|-|
|Desktop application|Ubuntu 20.04|C++, Qt5|Done|client_qt Собирается в Ubuntu 20.04. Работает в Ubuntu 20.04|
|Web application|Web browsers|C++, Qt Latest, Web Assembly|Done|client_qt для Web Assembly, работает в Google Chrome|
|Backend|Ubuntu 24.04|C++, userver|In Progress|server_http для запуска клиента в wasm в поддомене www.wordle-task.repotest.ru. Добавить tls https, чтобы каждый сервер в handler-subdomain-static подписывался. |
|repotest.ru|Web browser|c++, html|In Progress|Сделать главную страницу для repotest.ru со ссылками на мои проекты в github|
|Backend|Ubuntu 24.04|C++, userver, postgres|Planning|IAM Service|
|Backend|Ubuntu 24.04|C++, userver, redis|Planning|Сервер статистики|
|Desktop application|Linux|C++, Qt 6|Planning|Сделать консольную версию. Чтобы всё работало в bash с минимальным интерфейсом вроде dialog.|
|Web Application|Telegramm App|C++, TDLib|Planning|Можно поиграть в официальных приложениях Telegramm Desktop и Telegramm Android|
|Web Application|VK Mini Apps|????|Planning|Можно поиграть в VK|
|GUI|Ubuntu|C++, Qt 6|Planning|Использовать Qt Virtual Keyboard|
|Desktop application|Ubuntu|C++, Qt6 latest|Planning|Сделать новый таргет сборки в Docker где Qt latest, сборка на ubuntu:25.04. Qt собирается из latest исходников или из репозитория. Сборка статическая где всё вкомпилено в бинарник и Qt и системные либы. |
|pet-game-cpp-backend.repotest.ru|c++, javascript|Planning|Добавить на https://github.com/alec-chicherini/ на repotest.ru|

<!--Подготовить хост-->
## Подготовить хост для сборки.

Установить docker 
```bash
source <(curl https://raw.githubusercontent.com/alec-chicherini/wordle-task/refs/heads/main/scripts/install_docker.sh)
```

<!--Собрать клиент и deb пакет для linux-->
## 1 client_qt linux
### Собрать клиент и deb пакет для linux ubuntu
Собрать в docker
```bash
git clone https://github.com/alec-chicherini/wordle-task.git
cd wordle-task
docker build --target=qt_from_repo . -t wordle-task-build
#TODO docker build --target=qt_from_source . -t wordle-task-build-source #другая опция собрать Qt из исходников.
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

<!--Собрать клиент wasm и запустить для дебага-->
## 2 client_qt wasm
Собрать wasm в docker и запустить python http.server для дебага
```bash
git clone https://github.com/alec-chicherini/wordle-task.git
cd wordle-task
docker build --target=qt_wasm_build_from_source . -t wordle-task-build-wasm
docker run --rm -d -p 80:8000 wordle-task-build-wasm
```

<!--Собрать и запустить http сервер и добавить в него wasm подпроект-->
## 3 server_http
### Собрать и запустить. Добавить в него wasm подпроект по адресу www.wordle-task.repotest.ru
TODO:
```bash
git clone https://github.com/alec-chicherini/wordle-task.git
cd wordle-task
docker build --target=http_server_build . -t http_server_build
docker run --rm -d -p 80:8080 http_server_build
```

### repotest.ru
Актуальная версия Игры в Web Assembly по адресу:
http://www.wordle-task.repotest.ru/wordle-task.html 


## 4
TODO:

## 5
TODO:

## 6
TODO:
