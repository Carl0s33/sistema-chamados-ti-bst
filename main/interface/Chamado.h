#pragma once 

#include <string>
#include "../enums/Categoria.h"
#include "../enums/Prioridade.h"
#include "../enums/Status.h"
#include "../models/Solicitante.h"
#include "ListaHistorico.h"

using namespace std;

class Chamado {

    private:
    int id;
    Solicitante solicitante;
    string descricao;
    Categoria categoria;
    Prioridade prioridade;
    Status status;
    ListaHistorico historico;

    static string gerarSolicitanteAleatorio();
    static string gerarDescricaoAleatoria();
    static Categoria gerarCategoriaAleatoria();
    static Prioridade gerarPrioridadeAleatoria();
    static Status gerarStatusAleatorio();

    string categoriaParaTexto() const;
    string prioridadeParaTexto() const;
    string statusParaTexto() const;

    public:
    Chamado();
    Chamado(int id);
    void imprimir() const;


    int getId() const;
    Solicitante getSolicitante() const;
    string getDescricao() const;
    Categoria getCategoria() const;
    Prioridade getPrioridade() const;
    Status getStatus() const;

    // Setters
    void setId(int id);
    void setDescricao(string& descricao);
    void setCategoria(Categoria categoria);
    void setPrioridade(Prioridade prioridade);
    void setStatus(Status status);

};