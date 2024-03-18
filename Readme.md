# Comunicação entre processos Linux

Roteiro de estudo produzido pelo Claude.ai.

1. **Introdução**
   - Conceitos básicos de processos e threads
   - Motivos para a comunicação entre processos
   - Benefícios e desafios da comunicação entre processos

2. **Conceitos básicos de file descriptors**
   - O que são file descriptors e sua finalidade
   - Operações com file descriptors (abrir, ler, escrever, fechar)
   - Duplicação de file descriptors
   - Redirecionamento de entrada/saída padrão

3. **Pipes**
   - Pipes anônimos
   - Pipes nomeados (FIFOs)
   - Criação, leitura e escrita em pipes
   - Limitações dos pipes

------

4. **Sockets Unix**
   - Visão geral de sockets Unix
   - Criação de sockets Unix
   - Ligação de sockets Unix a endereços
   - Estabelecimento de conexões
   - Comunicação através de sockets Unix

5. **Integração de file descriptors e sockets Unix**
   - Uso de file descriptors para representar sockets Unix
   - Operações de leitura e escrita em sockets Unix usando file descriptors
   - Controle de acesso e permissões em sockets Unix
   - Fechamento de sockets Unix

5. **Sinais**
   - Visão geral dos sinais no Unix
   - Envio e captura de sinais
   - Manipuladores de sinais
   - Sinais e comunicação entre processos


Os demais serão estudados em tópico próprio de concorrência e paralelismo

https://fidelissauro.dev/concorrencia-paralelismo/

Processos, Threads, Mutex e Semáfaros  


5. **Memória Compartilhada**
   - Criação de segmentos de memória compartilhada
   - Acesso à memória compartilhada
   - Sincronização de acesso à memória compartilhada
   - Remoção de segmentos de memória compartilhada

6. **Semáforos**
   - Conceito de semáforos
   - Semáforos sem nome
   - Semáforos nomeados
   - Operações com semáforos (inicialização, bloqueio, desbloqueio)
   - Uso de semáforos para sincronização




10. **Sincronização e Concorrência**
   - Condições de corrida
   - Deadlocks
   - Estratégias de sincronização

13. 14. **Exemplos e Exercícios Práticos**
   - Implementar programas que criam e utilizam sockets Unix
   - Usar sockets Unix para comunicação entre processos
   - Explorar casos de uso, como comunicação entre servidores e clientes
   - Comparar sockets Unix com outros mecanismos de IPC
   - Implementar programas que utilizem pipes, sinais, memória compartilhada, semáforos, filas de mensagens e sockets
   - Resolver problemas clássicos, como o problema do produtor-consumidor e o problema dos filósofos jantando
   - Explorar bibliotecas e ferramentas de IPC (Comunicação Entre Processos) no Unix

Para cada tópico, é recomendado:

- Ler material de referência, como livros, documentação oficial e tutoriais
- Praticar com exemplos de código e exercícios práticos
- Entender os conceitos teóricos por trás de cada mecanismo de IPC
- Explorar as chamadas de sistema e funções relacionadas à IPC
- Analisar os casos de uso e as vantagens/desvantagens de cada mecanismo

