# File Descritors 

# O que são?

*File Descriptos* ou FD são utilizados pelo sistema operacional para referenciar todos os tipos de arquivos abertos (lembrando que em Linux tudo é um arquivo), incluindo *pipes*, terminais, dispositivos e arquivos arquivos regulares. 

Eles são utilizados pelo processo para realizar operações de I/O (Input/Output). Tem a característica de serem inteiros não negativos e baixo valor (0, 1, 2). 

Quando um um processo se inicia, há uma conjunto de *file descriptos* associado a ele. A quantidade de FD pode variar, mas por convenção (POSIX), cada processo tem um conjunto mínimo de FD's, quais são três. 

Eles são: 

- 0: Standard input (stdin) => entrada padrão (via de regra é o teclado)
- 1: Standard output (stdout) => saída padrão (via de regra é o terminal)
- 2: Standard error (stderr) => saída de erro padrão (via de regra é o terminal)


Uma nota do Michael Kerrisk, no livro The Linux programming interface, é *One of the distinguishing features of the UNIX I/O model is the concept of universality of I/O. This means that the same four system calls—open(), read(), write(), and close()—are used to perform I/O on all types of files, including devices such as
terminals.*.

Em outras palavras, podemos utilizar o mesmo modelo de *file descriptors* para lidar com as diversas formas de entrada e saídas de dados de um processo. Com este modelo, podemos ler de um arquivo regular para um termninal ou dispositivos, ou vice e versa. 

## Função open()

Vimos que um processo já se inicia com um conjunto de três *file descriptors* padrão. E caso quisermos acessar um arquivo arquivo específico? Nesse caso utilizamos a função `open()`. 

Segundo o Linux Programmer's Manual, a função `open()` abre um arquivo específicado pelo seu *pathname*. Caso o arquivo não exista, há possibilidade definida por *flags* específicas, de criar um novo arquivo.

Esta é assinatura da função `open()`

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```

A chamada desta função, em caso de sucesso, retorna o FD do arquivo aberto. Aqui não vou me adentrar nas *flags*, nem nos modos de abertura do arquivo. 

Um nota que para ver a documentação desta função, devemos fazer a seguinte chamada 
```shel 
man 2 open 
```


# Redirecionamento entre files descritors 


# Katas

*Sugeridos pelo Gemini*

Katas para Praticar File Descriptors em Linux:

## Nível Fácil:
1. Criar um novo arquivo e escrever uma mensagem nele.
2. Ler o conteúdo de um arquivo e imprimir na tela.
3. Copiar o conteúdo de um arquivo para outro.
4. Apagar um arquivo.

## Nível Médio:
Concatenar dois arquivos em um único arquivo.
Contar o número de linhas em um arquivo.
Procurar uma palavra específica em um arquivo e imprimir a linha onde ela aparece.
Redirecionar a entrada padrão (stdin) de um comando para um arquivo.

## Nível Difícil:
Redirecionar a saída padrão (stdout) de um comando para um arquivo.
Criar um pipe e usar dois comandos para comunicar-se através do pipe.
Duplicar um file descriptor e usar o duplicado para realizar uma operação em um arquivo.
Utilizar o comando flock para bloquear o acesso a um arquivo.


# Referências 

- https://aljensencprogramming.wordpress.com/tag/dup2/

- https://www.cs.loyola.edu/~jglenn/702/S2005/Examples/dup2.html