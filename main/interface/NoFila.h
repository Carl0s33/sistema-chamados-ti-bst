#pragma once
#include "Chamado.h"

class NoFila {
private:
    Chamado* chamado;
    NoFila* proximo;

public:
    NoFila(Chamado* c);
    
    Chamado* getChamado() const;
    NoFila* getProximo() const;
    
    void setProximo(NoFila* prox);
};