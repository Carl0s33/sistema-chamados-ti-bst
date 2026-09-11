#include "interface/NoFila.h"

NoFila::NoFila(Chamado* c) : chamado(c), proximo(nullptr) {}

Chamado* NoFila::getChamado() const {
    return chamado;
}

NoFila* NoFila::getProximo() const {
    return proximo;
}

void NoFila::setProximo(NoFila* prox) {
    proximo = prox;
}