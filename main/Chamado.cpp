#include "Chamado.h"

// Construtor Padrão
Chamado::Chamado() 
    : id(0), solicitante(""), descricao(""), 
      categoria(Categoria::OUTROS), prioridade(Prioridade::BAIXA), status(Status::ABERTO) {}

// Construtor Parametrizado utilizando Lista de Inicialização
Chamado::Chamado(int id, string solicitante, string descricao, Categoria categoria, Prioridade prioridade, Status status)
    : id(id), solicitante(solicitante), descricao(descricao), 
      categoria(categoria), prioridade(prioridade), status(status) {}

// --- GETTERS ---

int Chamado::getId() const {
    return id;
}

string Chamado::getSolicitante() const {
    return solicitante;
}

string Chamado::getDescricao() const {
    return descricao;
}

Categoria Chamado::getCategoria() const {
    return categoria;
}

Prioridade Chamado::getPrioridade() const {
    return prioridade;
}

Status Chamado::getStatus() const {
    return status;
}

// --- SETTERS ---

void Chamado::setId(int id) {
    this->id = id;
}

void Chamado::setSolicitante(const string& solicitante) {
    this->solicitante = solicitante;
}

void Chamado::setDescricao(const string& descricao) {
    this->descricao = descricao;
}

void Chamado::setCategoria(Categoria categoria) {
    this->categoria = categoria;
}

void Chamado::setPrioridade(Prioridade prioridade) {
    this->prioridade = prioridade;
}

void Chamado::setStatus(Status status) {
    this->status = status;
}