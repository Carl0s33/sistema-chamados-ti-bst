#include "interface/FilaChamados.h"

FilaChamados::FilaChamados() : frente(nullptr), tras(nullptr), quantidade(0) {}

int FilaChamados::getQuantidade() const {
    return quantidade;
}

FilaChamados::~FilaChamados() {
    while (!estaVazia()) {
        desenfileirar();
    }
}

bool FilaChamados::estaVazia() const {
    return frente == nullptr;
}

// coloca o chamado no fim da fila pra esperar a vez dele
bool FilaChamados::enfileirar(Chamado* c) {
    // so entra quem esta aberto e ainda nao esta esperando na fila
    if (c == nullptr || c->getStatus() != Status::ABERTO) {
        return false;
    }

    for (NoFila* atual = frente; atual != nullptr; atual = atual->getProximo()) {
        if (atual->getChamado() == c) {
            return false;
        }
    }

    NoFila* novoNo = new NoFila(c);
    ++quantidade;
    
    if (estaVazia()) {
        frente = novoNo;
        tras = novoNo;
    } else {
        tras->setProximo(novoNo);
        tras = novoNo;
    }
    return true;
}

// tira o primeiro da fila e devolve nulo se ela estiver vazia
Chamado* FilaChamados::desenfileirar() {
    // fifo de verdade sai sempre o primeiro que entrou
    if (estaVazia()) {
        return nullptr;
    }
    
    NoFila* temp = frente;
    Chamado* c = temp->getChamado();
    
    frente = frente->getProximo();
    
    // se a fila ficou vazia depois de remover o elemento ajustamos o tras
    if (frente == nullptr) {
        tras = nullptr;
    }
    
    delete temp; // libera apenas o no da fila e nao o chamado que esta na bst
    --quantidade;

    return c;
}

// so olha quem e o proximo sem tirar da fila
Chamado* FilaChamados::getFrente() const {
    if (estaVazia()) {
        return nullptr;
    }
    return frente->getChamado();
}
