# wordle-task
Задание для вакансии

# Собрать
#### Запустить сборку в docker. Образ debian 10 из DockerHub.

```bash
git clone https://github.com/alec-chicherini/wordle-task.git
cd wordle-task
mkdir result #Тут будет инсталятор wordle-task_24.12_amd64.deb
docker build . -t wordle-task-build
docker run -v ./result:/result wordle-task-build
```

# Играть
#### Запустить игру
Пуск - Стандартные - wordle-task
 
#### Добавить слова в игру
```bash
echo "УЕЫАО ЭЯИЮЙ" > /usr/etc/wordle-task/words/new_words.txt
``` 
