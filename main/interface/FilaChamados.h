#pragma once
#include "NoFila.h"

class FilaChamados {
private:
    NoFila* frente; 
    NoFila* tras;   
    int quantidade; 
public:
    FilaChamados();
    ~FilaChamados();

    void enfileirar(Chamado* c);
    Chamado* desenfileirar();
    Chamado* getFrente() const;
    bool estaVazia() const;
    int getQuantidade() const;
};
