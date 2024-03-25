# Comunicação entre processos Linux

Roteiro de estudo produzido pelo Claude.ai.

1. **Processos**
   - Conceitos básicos de processos

2. **Conceitos básicos de file descriptors**
   - O que são file descriptors e sua finalidade
   - Operações com file descriptors (abrir, ler, escrever, fechar)
   - Duplicação de file descriptors
   - Redirecionamento de entrada/saída padrão

3. **Pipes**
   - Pipes anônimos
   - Pipes nomeados (FIFOs)
   - Criação, leitura e escrita em pipes

## Futuramente

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

Para cada tópico, é recomendado:

- Ler material de referência, como livros, documentação oficial e tutoriais
- Praticar com exemplos de código e exercícios práticos
- Entender os conceitos teóricos por trás de cada mecanismo de IPC
- Explorar as chamadas de sistema e funções relacionadas à IPC
- Analisar os casos de uso e as vantagens/desvantagens de cada mecanismo

