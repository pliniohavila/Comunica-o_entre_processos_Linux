# Pipelines


https://medium.com/devquicktips/what-are-linux-pipelines-e2cff11a0f2d

https://github.com/perusio/linux-programming-by-example/blob/master/book/ch09/ch09-pipeline.c

## 1. Redirecionamentos de Arquivos:

Entrada (stdin): < redireciona a entrada de um comando para um arquivo.
Saída (stdout): > redireciona a saída de um comando para um arquivo.
Saída com acréscimo (stderr): >> redireciona a saída de um comando para um arquivo, anexando o conteúdo ao final do arquivo existente.

https://www.redhat.com/sysadmin/linux-shell-redirection-pipelining

https://ricardo-reis.medium.com/redirecionamento-e-pipes-no-linux-stdin-stdout-etderr-e-tee-952cd59a16c6



## 2. Pipes:

Pipes são um mecanismo de comunicação entre processos (IPC) que permite que os comandos se comuniquem entre si, enviando dados de um para o outro.

## Para implementar a pipeline:

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