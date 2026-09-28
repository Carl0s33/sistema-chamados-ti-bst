#include "interface/ListaHistorico.h"
#include <iostream>
#include <ctime>
#include <string>
#include <utility>

ListaHistorico::ListaHistorico() : inicio(nullptr) {}

ListaHistorico::ListaHistorico(const ListaHistorico& outra) : inicio(nullptr) {
    for (NoHistorico* atual = outra.inicio; atual != nullptr; atual = atual->getProximo()) {
        NoHistorico* novoNo = new NoHistorico(atual->getDataHorario(), atual->getDescricao());
        if (inicio == nullptr) {
            inicio = novoNo;
        } else {
            NoHistorico* fim = inicio;
            while (fim->getProximo() != nullptr) fim = fim->getProximo();
            fim->setProximo(novoNo);
        }
    }
}

ListaHistorico& ListaHistorico::operator=(const ListaHistorico& outra) {
    if (this == &outra) return *this;

    ListaHistorico copia(outra);
    std::swap(inicio, copia.inicio);
    return *this;
}

ListaHistorico::~ListaHistorico() {
    // cada registro foi criado com new entao a lista limpa um por um aqui
    NoHistorico* atual = inicio;
    while (atual != nullptr) {
        NoHistorico* proximo = atual->getProximo();
        delete atual;
        atual = proximo;
    }
}

void ListaHistorico::inserir(std::string descricao) {
    // Pega a data/hora atual
    std::time_t agora = std::time(nullptr);
    std::tm* tempoLocal = std::localtime(&agora);

    // Formata como "dd/mm/aaaa HH:MM:SS"
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", tempoLocal);
    std::string dataHorario(buffer);

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
