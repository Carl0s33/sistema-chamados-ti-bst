#pragma once
#include "NoHistorico.h"

class ListaHistorico {
private:
    NoHistorico* inicio;

public:
    ListaHistorico();
    ListaHistorico(const ListaHistorico& outra);
    ListaHistorico& operator=(const ListaHistorico& outra);
    ~ListaHistorico();

    void inserir(std::string descricao);
    void listarHistorico() const;
};
