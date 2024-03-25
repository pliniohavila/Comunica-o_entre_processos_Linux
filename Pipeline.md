# Pipelines

https://github.com/perusio/linux-programming-by-example/blob/master/book/ch09/ch09-pipeline.c

[systemsprogrammingbook.com - Chapter 5. Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf )
|-> Estudar melhor o tópico Pipe and Input/Output Redirection in Your Shell


https://blog.devgenius.io/lets-build-a-linux-shell-part-i-954c95911501

## Casos de teste 

```shel 

cat < _wc.c
ls -l -r > ls.log
ls -l -r | sort
ps aux | grep zsh
ls -l | wc > wc.log
cat < ls.log | sort | wc
ls -l -r >> ls2.log
cat < ls2.log | sort >> ls2.log
rm ls.log; rm ls2.log; rm wc.log

 ``` 


# Para implementar a pipeline:

### 1 - Análise de comandos:

Divida a linha de comando em tokens (palavras).
Identifique os comandos e os operadores de redirecionamento.

### 2 - Gerenciamento de redirecionamentos:

Antes de executar o comando, configure os redirecionamentos de acordo com os operadores <, > e >>.
Utilize a função dup2() para duplicar os descritores de arquivo padrão (stdin, stdout) para os arquivos especificados.

### 3 - Criação de pipes:

Utilize a função pipe() para criar um pipe.
O pipe é um canal de comunicação bidirecional entre dois processos.

### 4 - Execução dos comandos:

Utilize fork() para criar um novo processo filho para cada comando na pipeline.
No processo filho, utilize exec() para executar o comando especificado.
No processo pai, configure o pipe como entrada ou saída do próximo comando, se necessário.


### 5 - Gerenciamento de processos:

Espere que todos os processos na pipeline terminem.
Libere os recursos do sistema utilizados pelos processos.