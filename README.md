# wordle-task
Задание для вакансии

# Запустить сборку в docker. Образ debian 10 из DockerHub
```bash
git clone https://github.com/alec-chicherini/wordle-task.git
cd wordle-task
docker build . -t wordle-task-build
docker run -t -i wordle-task-build bash
```
