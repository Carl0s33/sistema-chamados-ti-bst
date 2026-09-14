#pragma once
#include "ArvoreBusca.h"
#include "FilaChamados.h"

class SistemaDeSuporte {
private:
    ArvoreBusca arvore;
    FilaChamados fila;

    void exibirMenu() const;

public:
    SistemaDeSuporte();
    void executar();
};