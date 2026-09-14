#pragma once 

#include <string>
#include "../enums/Categoria.h"
#include "../enums/Prioridade.h"
#include "../enums/Status.h"
#include "../models/Solicitante.h"
#include "ListaHistorico.h"


class Chamado {

    private:
    int id;
    Solicitante solicitante;
    std::string descricao;
    Categoria categoria;
    Prioridade prioridade;
    Status status;
    ListaHistorico historico;

    static std::string gerarSolicitanteAleatorio();
    static std::string gerarDescricaoAleatoria();
    static Categoria gerarCategoriaAleatoria();
    static Prioridade gerarPrioridadeAleatoria();
    static Status gerarStatusAleatorio();
    static int gerarIdAleatorio();

    std::string categoriaParaTexto() const;
    std::string prioridadeParaTexto() const;
    std::string statusParaTexto() const;

    public:
    Chamado();
    Chamado(int id);
    Chamado(const Solicitante& solicitante, const std::string& descricao,
            Categoria categoria, Prioridade prioridade);
    void imprimir() const;

   ListaHistorico& getHistorico();
    int getId() const;  
    
    Solicitante getSolicitante() const;
    std::string getDescricao() const;
    Categoria getCategoria() const;
    Prioridade getPrioridade() const;
    Status getStatus() const;
  

    // Setters
    void setId(int id);
    void setDescricao(std::string& descricao);
    void setCategoria(Categoria categoria);
    void setPrioridade(Prioridade prioridade);
    void setStatus(Status status);

};
