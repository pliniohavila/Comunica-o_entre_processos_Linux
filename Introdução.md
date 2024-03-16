
# 1- Introdução

## 1.1 Conceitos básicos de processos

O que é um processo? Respondendo diretamente: um processo é um binário em execução. O qual pode ser dito, em outras palavras, é uma abstração de um software em execução. Segundo Tanenbaum (2016, p. 60), "*Um processo é apenas uma instância de um programa em execução,
incluindo os valores atuais do contador do programa, registradores e variáveis*". 

De forma simples, um processo é um programa em execução. Em outras palavras, é um programa ativo, realizando suas atividades pelo qual foi desenvolvido, é um software em execução, em atividade.

Cada processo tem um ID, que é atribuido pelo sistema operacional, cujo valor máximo em sistemas Linux é 32768. 
Para vermos o ID dos processos em execução, podemos utilizar a ferramenta `ps`. 

Exemplo:

```shell
> ps
  PID TTY          TIME CMD
 1479 pts/3    00:00:01 zsh
 1483 pts/3    00:00:00 zsh
 1491 pts/3    00:00:00 zsh
 1493 pts/3    00:00:00 zsh
 1494 pts/3    00:00:00 gitstatusd-linu
 3816 pts/3    00:00:00 ps
```

Quando estamos programando na linguagem C, um ID de um processo é representado pelo tipo `pid_t`. O qual é definido no cabeçalho `<sys/types.h>`.

### 1.1.1 Criação de processos 

Tanenbaum (2016, p. 61), aponta quatro eventos principais em que os processos são criados:
1. Inicialização do sistema.
2. Execução de uma chamada de sistema de criação de processo por um processo em execução.
3. Solicitação de um usuário para criar um novo processo.
4. Início de uma tarefa em lote

Em termos de código, para se criar um processo em ambiente Linux, fazemos uma chamada ao kernel, por meio da _syscall_ `fork()` que criará um clone do processo que a chamou. Em seguida, é chamada uma das funções da família `exec()` que substitui a imagem do processo atual pela imagem do novo processo.  

Também, podemos utilizar a função `system()`. Essa forma é mais direta e simples, porém não muito eficiente, pois faz uma chamada para o shell `sh -c` antes de iniciar o novo processo com o programada desejado. 

O processo que deu origem ao novo processo é chamado de **processo pai** e o novo processo é chamado de **processo filho**. 

**Exemplo:**
Um exemplo simples da criação de um novo processo.

### 1.1.2 Término de processos 

Um processo poderá terminar de forma voluntária ou involuntária. Ensina Tanenbaum (2016, p. 63) as quatros formas que um processo poderá terminar:

1. Saída normal (voluntária): encerra a execução após realizar o seu trabalho;
2. Erro fatal (involuntário): ocorre quando processo tenta acessar um recurso não disponível;
3. Saída por erro (voluntária): ocorre um erro na execução do programa, a exemplo, dividir por zero;
4. Morto por outro processo (involuntário): um outro processo pede ao sistema operacional interromper a execução de outro processo. 

### 1.1.3 Estados do processo

Um processo em execução pode se encontrar em um dos três estados: em execução, pronto e bloqueado. 

1. Em execução: o processo está executando suas instruções; 
2. Pronto: o processo está pronto para ser executado, aguardando a decisão do sistema operacional de o colocar em execução;
3. Bloquado: está a espera de um evento para seja possível continuar a sua execução. 

Anota-se que todos os estados de um processo é determinado pelo sistama operacional, por meio do escalonador de processos. 

### 1.1.4 Exemplos de código 

Neste tópico será destinado para exemplos de códigos utilizando a API do Linux para manusear processos. 

#### Função fork()

No primeiro exemplo vamos criar um processo com a utilização da função `fork()` para criar um processo filho.

A função `fork()` cria um clone do processo pai, compartilhando mesmo trecho de código e recursos do processo criador. 

É a assinatura da função. 

```c
#include <sys/types.h>
#include <unistd.h>
pid_t fork(void);
```

Esta função retorna o seguinte: 
Em caso  de sucesso, retornar o PID do processo filho para o pai, e `0` para o processo criado. Em caso de falha, `-1` é retornado. 

Outro detalhe, o processo filho inicia a sua execução a partir do `fork()`. O processo filho não inicia a sua execução a partir da função `main`.  

No exemplo seguinte, o processo pai declara a variável `x`, a assinala um valor para ela. Posteriormente faz uma chamada para a criação de novo processo, e, respectivamente, cada um alterar o valor da variável e o imprimi na tela. 

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>

int     main(void) 
{
    pid_t   cpid;
    int     x;

    x = 100;
    printf("Initial x value: %d\n", x);
    cpid = fork();
    if (cpid == 0)
    {
        x = 50;
        printf("Child x value: %d\n", x);
    }
    else 
    {
        x = 500;
        printf("Parent x value: %d\n", x);
    }
    return (0);
}
```
No exemplo seguinte, temos um caso onde processos pai e filho compartilham o mesmo *file descritor*, escrevendo no mesmo arquivo, o qual foi aberto pelo pai. 

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <assert.h>

int     main(void) 
{
    pid_t   cpid;
    int     fd;

    fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd == -1) 
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    if ((cpid = fork()) == -1) 
    {
        perror("Fork error\n");
        exit(1);
    }
    if (cpid == 0) 
    {
        dprintf(fd, "Child writed!\n");
    }
    else 
    {
        dprintf(fd, "Parent writed!\n");
        close(fd);
    }
    return (0);
} 
```

#### Funções wait() e waitpid()

Vemos no primeiro exemplo acima, que o processo pai imprimi o valor de `x` antes do filho. E caso for necessário que o processo criador aguardasse e execução de um ou mais processos filhos. 

Para esses casos, temos as funções `wait()` e `waitpid()`. 

São as suas assinaturas:

```c 
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int *wstatus, int options);

```

Segundo ensinam STEVENS, W. Richard e RAGO, Stephen (2013), quando um processo termina, seja normalmente e não, o kernel informa o processo pai enviando o sinal (SIGCHLD). O envio desse sinal é assíncrono, o que pode ocorrer com o processo pai em execução ou não. O processo criador pode escolher entre ignorar o sinal, via de regra, ou executar alguma outra ação. 

Há outros sinais que podem serem enviados, mas, por ora, se atermos ao SIGCHLD. 
Como o envio do sinal é assíncrono, temos situação que devemos suspender a execução do processo pai, enquanto aguarda o término de um ou mais processos filhos. 

Nesse cenário, que entra em cena as funções `wait()` e `waitpid()`.

Sendo direto o MAN relata que as funções esperam por uma mudança de *status* no processo.

Coleciono os dizeres do Prof. Eduardo Zambon
"*A chamada wait() é usada para esperar por mudanças de estado nos filhos do processo chamador (pai) e obter informações sobre aqueles filhos cujos estados tenham sido alterados (ex: morte de um filho). Quando o pai executa o wait(), se o filho já teve o seu estado alterado (ex: já morreu) no momento da chamada, ela retorna imediatamente; caso contrário, o processo chamador é bloqueado até que ocorra uma mudança de estado do filho ou então um “signal handler” interrompa a chamada (isso será explicado mais adiante)*"

fonte: http://www.inf.ufes.br/~rgomes/so_fichiers/roteiro2.pdf





Exemplo com `wait()`

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int     main(void) 
{
    pid_t   cpid1;
    pid_t   cpid2;

    cpid1 = fork();
    if (cpid1 == -1 ) 
        exit(EXIT_FAILURE);

    if (cpid1 == 0)
    {
        printf("Processo filho um\n");
        exit(EXIT_SUCCESS);
    }
    cpid2 = fork();
    if (cpid2 == -1 ) 
        exit(EXIT_FAILURE);
    if (cpid2 == 0)
    {
        printf("Processo filho dois\n");
        exit(EXIT_SUCCESS);
    }
    wait(NULL);
    printf("Processo pai\n");
    exit(EXIT_SUCCESS);
}
```

Exemplo com `waitpid()` 

trocarmos parte final do código acima, pelo seguinte 

```c
  waitpid(cpid1, NULL, 0);
  printf("Processo filho um terminou\n");
  waitpid(cpid2, NULL, 0);
  printf("Processo filho dois terminou\n");
  exit(EXIT_SUCCESS);
```

Diferenças entre `wait()` e `waitpid`


FORK EXEC 






https://www.educative.io/answers/wait-vs-waitpid-in-c


Referências:
https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf 
http://www.inf.ufes.br/~rgomes/so_fichiers/roteiro1.pdf
http://www.inf.ufes.br/~rgomes/so_fichiers/roteiro2.pdf



## 1.1.2 Motivos para a comunicação entre processos



##  1.3 Benefícios e desafios da comunicação entre processos

## 1.2 Conceitos básicos de threads