
# 1- Introdução

## 1.1 Conceitos básicos de processos e threads

O que é um processo? 
Um processo é uma abstração de um software em execução.
Segundo Tanenbaum (2016, p. 60), "Um processo é apenas uma instância de um programa em execução,
incluindo os valores atuais do contador do programa, registradores e variáveis". 
De forma simples, um processo é um programa em execução. Em outras palavras, é um programa ativo, realizando suas atividades pelo qual foi desenvolvido, é um software em execução, em atividade.

Cada processo tem um ID, que é atribuido pelo sistema operacional, cujo valor máximo em sistemas Linux é 32768. 
Para vermos o ID dos processos em execução, podemos utilizar a ferramente `ps`. 
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

### Criação de processos 

Tanenbaum (2016, p. 61), aponta quatro eventos principais em que os processos são criados:
1. Inicialização do sistema.
2. Execução de uma chamada de sistema de criação de processo por um processo em execução.
3. Solicitação de um usuário para criar um novo processo.
4. Início de uma tarefa em lote

Em termos de código, para se criar um processo em ambiente Linux, fazemos uma chamada ao kernel, por meio da _syscall_ `fork()` que criará um clone do processo que a chamou. Em seguida, é chamada uma das funções da família `exec()` que substitui a imagem do processo atual pela imagem do novo processo.  

Também, podemos utilizar a função `system()`. Essa forma é mais direta e simples, porém não muito eficiente, pois faz uma chamada para o shell `sh -c` antes de iniciar um processo com o programada desejado. 

O processo que deu origem ao novo processo é chamado de **processo pai** e o novo processo é chamado de **processo filho**. 

**Exemplo: **
Um exemplo ximples da criação de um novo processo.


http://www.inf.ufes.br/~rgomes/so_fichiers/roteiro1.pdf

http://www.inf.ufes.br/~rgomes/so_fichiers/roteiro2.pdf


### Término de processos 

Um processo poderá terminar de forma voluntária ou involuntária. Ensina Tanenbaum (2016, p. 63) as quatros formas que um processo poderá terminar:

1. Saída normal (voluntária): encerra a execução após realizar o seu trabalho;
2. Erro fatal (involuntário): ocorre quando processo tenta acessar um recurso não disponível;
3. Saída por erro (voluntária): ocorre um erro na execução do programa, a exemplo, dividir por zero;
4. Morto por outro processo (involuntário): um outro processo pede ao sistema operacional interromper a execução de outro processo. 

### Estados do processo

Um processo em execução pode se encontrar em um dos três estados: em execução, pronto e bloqueado. 

1. Em execução: o processo está executando suas instruções; 
2. Pronto: o processo está pronto para ser executado, aguardando a decisão do sistema operacional de o colocar em execução;
3. Bloquado: está a espera de um evento para seja possível continuar a sua execução. 

Anota-se que todos os estados de um processo é determinado pelo sistama operacional, por meio do escalonador de processos. 

## Exemplos de código 

Penso em deixar este tópico para exemplos de código


## Process API 

Referências:
https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf 

http://www.inf.ufes.br/~rgomes/so_fichiers/roteiro1.pdf

http://www.inf.ufes.br/~rgomes/so_fichiers/roteiro2.pdf

Texto gerado pelo claud.ia

Agora vamos conhecer a API  de processos em sistemas Linux. 

A process API (Application Programming Interface) em sistemas Linux é um conjunto de chamadas de sistema e recursos fornecidos pelo kernel do Linux que permitem que programas interajam com processos em execução no sistema operacional. Ela oferece uma interface para criar, monitorar, controlar e terminar processos.

Algumas das principais funcionalidades fornecidas pela process API do Linux incluem:

1. **Criação de Processos**: A API permite criar novos processos através de chamadas de sistema como `fork()`, `vfork()`, `clone()` e `execve()`. Essas chamadas permitem que um processo crie uma cópia de si mesmo ou execute um novo programa.

2. **Gerenciamento de Processos**: A API fornece chamadas de sistema para obter informações sobre processos em execução, como `getpid()` (obter o ID do processo atual), `getppid()` (obter o ID do processo pai) e `waitpid()` (aguardar a finalização de um processo filho).

3. **Controle de Processos**: Chamadas de sistema como `kill()` permitem enviar sinais para processos, o que pode ser usado para interromper, pausar ou retomar a execução de um processo.

4. **Agendamento de Processos**: O kernel Linux utiliza algoritmos de agendamento para determinar qual processo deve ser executado em um determinado momento. A API fornece chamadas de sistema como `sched_setscheduler()` e `sched_getparam()` para ajustar as prioridades e políticas de agendamento de processos.

5. **Gerenciamento de Recursos**: A API inclui chamadas de sistema para limitar e controlar os recursos consumidos por um processo, como memória (`brk()`, `mmap()`), arquivos abertos (`open()`, `close()`) e permissões (`setuid()`, `setgid()`).

6. **Sincronização de Processos**: A API fornece mecanismos de sincronização, como semáforos (`sem_init()`, `sem_wait()`), mutexes (`pthread_mutex_init()`, `pthread_mutex_lock()`) e variáveis de condição (`pthread_cond_init()`, `pthread_cond_wait()`), que permitem a coordenação de processos e threads concorrentes.

7. **Comunicação entre Processos**: A API fornece mecanismos para a comunicação entre processos, como pipes (`pipe()`), filas de mensagens (`msgget()`, `msgsnd()`, `msgrcv()`), memória compartilhada (`shmget()`, `shmat()`) e sockets (`socket()`, `bind()`, `connect()`).

A process API do Linux é amplamente utilizada por programadores de aplicações, bibliotecas de sistema e ferramentas de desenvolvimento para criar, gerenciar e interagir com processos em ambientes Linux. Ela é fundamental para a construção de aplicações robustas e eficientes que aproveitam os recursos do sistema operacional.




## 1.2 Motivos para a comunicação entre processos



##  1.3 Benefícios e desafios da comunicação entre processos