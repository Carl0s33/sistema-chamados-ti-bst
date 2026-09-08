#include "interface/ArvoreBusca.h"
#include <iostream>
#include <queue>

// Construtor
ArvoreBusca::ArvoreBusca() {
    this->raiz = nullptr;
}

// Destrutor
ArvoreBusca::~ArvoreBusca() {
    
    destruirArvore(this->raiz);
}

 NoBST* ArvoreBusca::cadastrar(NoBST* no, const Chamado& chamado, bool& inserido) {
    if (no == nullptr) {
        inserido = true;
        return new NoBST(chamado);
    }

    if (chamado.getId() < no->chamado.getId()) {
        no->esquerda = cadastrar(no->esquerda, chamado, inserido);
    } else if (chamado.getId() > no->chamado.getId()) {
        no->direita = cadastrar(no->direita, chamado, inserido);
    } else {
        inserido = false;
    }
    return no;
 }

bool ArvoreBusca::inserir(Chamado chamado) {
    bool inserido = false;
    this->raiz = cadastrar(this->raiz, chamado, inserido);
    return inserido;
    return false;
}

Chamado* ArvoreBusca::localizar(int identificador) {
    // TODO: Implementar busca por identificador
    return nullptr;
}

bool ArvoreBusca::remover(int identificador) {
    // TODO: Implementar remoção por identificador
    return false;
}

void ArvoreBusca::listarOrdemCrescente() {
    // TODO: Implementar percurso em-ordem (In-Order) para listar chamados
}

Chamado* ArvoreBusca::obterMenorIdentificador() {
    // TODO: Implementar busca do nó mais à esquerda
    return nullptr;
}

Chamado* ArvoreBusca::obterMaiorIdentificador() {
    // TODO: Implementar busca do nó mais à direita
    return nullptr;
}

int ArvoreBusca::obterAltura() {
    // TODO: Implementar cálculo da altura da árvore
    return 0;
}

int ArvoreBusca::determinarNumeroDeChamados() {
    // TODO: Implementar contagem total de nós
    return 0;
}

void ArvoreBusca::listarPorIntervalo(int min, int max) {
    // TODO: Implementar listagem de chamados cujo ID esteja entre min e max
}

void ArvoreBusca::percursoPreOrdem() {
    // TODO: Implementar percurso pré-ordem exibindo apenas os IDs
}

void ArvoreBusca::percursoPosOrdem() {
    // TODO: Implementar percurso pós-ordem exibindo apenas os IDs
}

void ArvoreBusca::percursoEmLargura() {
    // TODO: Implementar percurso em largura (BFS) usando fila exibindo apenas os IDs
}