#include "interface/ArvoreBusca.h"
#include <iostream>
#include <queue>

// Construtor
ArvoreBST::ArvoreBST() {
    this->raiz = nullptr;
}

// Destrutor
ArvoreBST::~ArvoreBST() {
    // Implementar liberação de memória recursiva aqui
}

bool ArvoreBST::cadastrar(Chamado chamado) {
    // TODO: Implementar inserção mantendo as propriedades da BST
    return false;
}

Chamado* ArvoreBST::localizar(int identificador) {
    // TODO: Implementar busca por identificador
    return nullptr;
}

bool ArvoreBST::remover(int identificador) {
    // TODO: Implementar remoção por identificador
    return false;
}

void ArvoreBST::listarOrdemCrescente() {
    // TODO: Implementar percurso em-ordem (In-Order) para listar chamados
}

Chamado* ArvoreBST::obterMenorIdentificador() {
    // TODO: Implementar busca do nó mais à esquerda
    return nullptr;
}

Chamado* ArvoreBST::obterMaiorIdentificador() {
    // TODO: Implementar busca do nó mais à direita
    return nullptr;
}

int ArvoreBST::obterAltura() {
    // TODO: Implementar cálculo da altura da árvore
    return 0;
}

int ArvoreBST::determinarNumeroDeChamados() {
    // TODO: Implementar contagem total de nós
    return 0;
}

void ArvoreBST::listarPorIntervalo(int min, int max) {
    // TODO: Implementar listagem de chamados cujo ID esteja entre min e max
}

void ArvoreBST::percursoPreOrdem() {
    // TODO: Implementar percurso pré-ordem exibindo apenas os IDs
}

void ArvoreBST::percursoPosOrdem() {
    // TODO: Implementar percurso pós-ordem exibindo apenas os IDs
}

void ArvoreBST::percursoEmLargura() {
    // TODO: Implementar percurso em largura (BFS) usando fila exibindo apenas os IDs
}