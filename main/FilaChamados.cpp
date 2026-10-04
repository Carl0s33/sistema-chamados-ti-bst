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


bool FilaChamados::enfileirar(Chamado* c) {
   
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


Chamado* FilaChamados::desenfileirar() {
   
    if (estaVazia()) {
        return nullptr;
    }
    
    NoFila* temp = frente;
    Chamado* c = temp->getChamado();
    
    frente = frente->getProximo();
    
    
    if (frente == nullptr) {
        tras = nullptr;
    }
    
    delete temp; 
    --quantidade;

    return c;
}


Chamado* FilaChamados::getFrente() const {
    if (estaVazia()) {
        return nullptr;
    }
    return frente->getChamado();
}
