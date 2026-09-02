# Sistema de Atendimento de Chamados de TI

## Descrição do Projeto

Este projeto consiste em um **Sistema de Atendimento de Chamados de TI**, desenvolvido como Trabalho de Implementação para a disciplina de Estrutura de Dados Não Lineares. O sistema é capaz de gerenciar chamados de suporte técnico desde a sua abertura até a conclusão do atendimento, utilizando estruturas de dados adequadas para garantir eficiência e organização.

## Estruturas de Dados Utilizadas

Para o gerenciamento eficiente dos chamados, o sistema integra três estruturas de dados principais:

*   **Árvore Binária de Busca (BST):** Utilizada como armazenamento principal dos chamados, permitindo operações rápidas de cadastro, localização, remoção e listagem.
*   **Fila (Queue):** Gerencia a ordem de atendimento. Chamados com status `ABERTO` entram na fila e aguardam para serem processados.
*   **Lista Encadeada (Linked List):** Cada chamado possui uma lista simplesmente encadeada dedicada a armazenar o seu histórico de tramitação (data, horário e descrição de cada evento).

## Funcionalidades Principais

O sistema oferece as seguintes operações através de um menu interativo:

1.  Abrir chamado
2.  Buscar chamado
3.  Remover chamado
4.  Listar chamados (ordem crescente de identificador)
5.  Consultar chamados por intervalo de identificadores
6.  Encaminhar chamado para atendimento (inserção na fila)
7.  Atender próximo chamado (remoção da fila)
8.  Consultar histórico de tramitação de um chamado
9.  Alterar status do chamado
10. Exibir estatísticas do sistema (Total de chamados, Altura da BST, etc.)
0.  Sair

## Como Rodar o Projeto

Siga as instruções abaixo para compilar e executar o sistema em sua máquina local.

### Pré-requisitos

*   Compilador C++ (como GCC/g++, Clang ou MSVC) instalado.
*   Terminal, Prompt de Comando ou IDE de sua preferência.

### Passos para Execução

1.  **Clone o repositório:**
    ```bash
    git clone https://github.com/seu-usuario/sistema-chamados-ti-bst.git
    ```

2.  **Acesse o diretório do projeto:**
    ```bash
    cd sistema-chamados-ti-bst
    ```

3.  **Compile os arquivos de código-fonte:**
    No diretório raiz do projeto (onde os arquivos `.cpp` estão localizados), execute o comando:
    ```bash
    g++ *.cpp -o sistema
    ```

4.  **Execute o sistema:**
    Após a compilação bem-sucedida, inicie a aplicação:
    
    No Windows (Prompt de Comando ou PowerShell):
    ```bash
    .\sistema.exe
    ```
    
    No Linux ou macOS:
    ```bash
    ./sistema
    ```

## Arquitetura do Sistema

O sistema é composto pelas seguintes classes principais, conforme diagrama UML:

*   `SistemaDeSuporte`: Classe principal que integra as estruturas e fornece o menu.
*   `Chamado`: Representa a entidade de negócio.
*   `ArvoreBST` e `NoBST`: Implementação da Árvore Binária de Busca.
*   `FilaAtendimento` e `NoFila`: Implementação da fila de pendentes.
*   `ListaHistorico` e `NoHistorico`: Implementação do histórico de cada chamado.

---
**Instituto Federal de Educação, Ciência e Tecnologia do Rio Grande do Norte (IFRN)**
Campus Nova Cruz - Curso de Tecnologia em Análise e Desenvolvimento de Sistemas
