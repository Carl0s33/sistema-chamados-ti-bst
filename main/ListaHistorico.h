#pragma once
#include "NoHistorico.h"

class ListaHistorico {
private:
    NoHistorico* inicio;

public:
    ListaHistorico();
    ~ListaHistorico();

    void inserir(std::string dataHorario, std::string descricao);
    void listarHistorico() const;
};
