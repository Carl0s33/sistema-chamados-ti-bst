#pragma once 

#include <string>
#include "enums/Categoria.h"
#include "enums/Prioridade.h"
#include "enums/Status.h"
#include "ListaHistorico.h"

using namespace std;

class Chamado {

    private:
    int id;
    string solicitante;
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

    public:
    Chamado();
    Chamado(int id);

    // Getters (marcados como const por não alterarem o estado do objeto)
    int getId() const;
    string getSolicitante() const;
    string getDescricao() const;
    Categoria getCategoria() const;
    Prioridade getPrioridade() const;
    Status getStatus() const;

    // Setters
    void setId(int id);
    void setSolicitante(const string& solicitante);
    void setDescricao(const string& descricao);
    void setCategoria(Categoria categoria);
    void setPrioridade(Prioridade prioridade);
    void setStatus(Status status);

};