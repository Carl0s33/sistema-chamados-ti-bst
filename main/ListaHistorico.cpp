#include "ListaHistorico.h"
#include <iostream>

ListaHistorico::ListaHistorico() : inicio(nullptr) {}

ListaHistorico::~ListaHistorico() {
    NoHistorico* atual = inicio;
    while (atual != nullptr) {
        NoHistorico* proximo = atual->getProximo();
        delete atual;
        atual = proximo;
    }
}

void ListaHistorico::inserir(std::string dataHorario, std::string descricao) {
    NoHistorico* novoNo = new NoHistorico(dataHorario, descricao);
    if (inicio == nullptr) {
        inicio = novoNo;
    } else {
        NoHistorico* atual = inicio;
        while (atual->getProximo() != nullptr) {
            atual = atual->getProximo();
        }
        atual->setProximo(novoNo);
    }
}

void ListaHistorico::listarHistorico() const {
    NoHistorico* atual = inicio;
    while (atual != nullptr) {
        std::cout << "[" << atual->getDataHorario() << "] " << atual->getDescricao() << std::endl;
        atual = atual->getProximo();
    }
}
