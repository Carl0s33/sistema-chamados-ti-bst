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

void FilaChamados::enfileirar(Chamado* c) {
    NoFila* novoNo = new NoFila(c);
    ++quantidade;
    
    if (estaVazia()) {
        frente = novoNo;
        tras = novoNo;
    } else {
        tras->setProximo(novoNo);
        tras = novoNo;
    }
}

Chamado* FilaChamados::desenfileirar() {
    if (estaVazia()) {
        return nullptr;
    }
    
    NoFila* temp = frente;
    Chamado* c = temp->getChamado();
    
    frente = frente->getProximo();
    
    // Se a fila ficou vazia após remover o elemento, ajustamos o 'tras'
    if (frente == nullptr) {
        tras = nullptr;
    }
    
    delete temp; // Libera apenas o nó da fila, não o Chamado em si (que está na BST)
    --quantidade;
    return c;
}

Chamado* FilaChamados::getFrente() const {
    if (estaVazia()) {
        return nullptr;
    }
    return frente->getChamado();
}
