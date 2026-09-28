#include "interface/Chamado.h"
#include <random>
#include <iostream>
using namespace std;

Chamado::Chamado(const Solicitante& solicitante, const std::string& descricao,
                 Categoria categoria, Prioridade prioridade)
    : id(gerarIdAleatorio()), solicitante(solicitante), descricao(descricao),
      categoria(categoria), prioridade(prioridade), status(Status::ABERTO) {}

Chamado::Chamado(int id)
    : id(id),
      solicitante(),
      descricao(gerarDescricaoAleatoria()),
      categoria(gerarCategoriaAleatoria()),
      prioridade(gerarPrioridadeAleatoria()),
      status(gerarStatusAleatorio()) {}

// construtor parametrizado utilizando lista de inicializacao
Chamado::Chamado()
    : id(gerarIdAleatorio()),
      solicitante(),
      descricao(gerarDescricaoAleatoria()),
      categoria(gerarCategoriaAleatoria()),
      prioridade(gerarPrioridadeAleatoria()),
      status(gerarStatusAleatorio()),
      historico()
       {
        historico.inserir("Chamado aberto no sistema.");
       }

// getters

int Chamado::getId() const {
    return id;
}

Solicitante Chamado::getSolicitante() const {
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
ListaHistorico& Chamado::getHistorico() {
    return historico;
}
// setters

void Chamado::setId(int id) {
    this->id = id;
}



void Chamado::setDescricao( string& descricao) {
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

void Chamado::imprimir() const {
    std::cout << "========================================" << std::endl;
    std::cout << "               CHAMADO #" << id          << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Solicitante : " << solicitante.getNome() 
              << " (Matrícula: " << solicitante.getMatricula() << ")" << std::endl;
    std::cout << "Descrição   : " << descricao << std::endl;
    std::cout << "Categoria   : " << categoriaParaTexto()  << std::endl;
    std::cout << "Prioridade  : " << prioridadeParaTexto() << std::endl;
    std::cout << "Status      : " << statusParaTexto()     << std::endl;
    std::cout << "========================================" << std::endl;
}

void Chamado::imprimirHistorico() const {
    std::cout << "----------- HISTÓRICO DO CHAMADO #" << id << " -----------" << std::endl;
    historico.listarHistorico();
    std::cout << "-------------------------------------------------" << std::endl;
}



string Chamado::gerarDescricaoAleatoria() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static const string descricoes[] = {
        "Impressora não responde", "Sem acesso à rede local", 
        "Erro ao atualizar o sistema", "Solicitação de novo periférico", "Falha de autenticação"
    };
    constexpr std::size_t quantidadeDescricoes =
        sizeof(descricoes) / sizeof(descricoes[0]);
    std::uniform_int_distribution<std::size_t> dist(0, quantidadeDescricoes - 1);
    return descricoes[dist(gen)];
}

Categoria Chamado::gerarCategoriaAleatoria() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(
        0, static_cast<int>(Categoria::ACESSO));
    return static_cast<Categoria>(dist(gen));
}

Prioridade Chamado::gerarPrioridadeAleatoria() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(
        0, static_cast<int>(Prioridade::CRITICA));
    return static_cast<Prioridade>(dist(gen));
}

Status Chamado::gerarStatusAleatorio() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 3); 
    return static_cast<Status>(dist(gen));
}

int Chamado::gerarIdAleatorio() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1000, 9999); 
    return dist(gen);
}


// conversao dos enums

string Chamado::categoriaParaTexto() const {
    switch (categoria) {
        case Categoria::HARDWARE: return "Hardware";
        case Categoria::SOFTWARE: return "Software";
        case Categoria::REDE:     return "Rede";
        case Categoria::SISTEMA:  return "Sistema";
        case Categoria::ACESSO:   return "Acesso";
        default:                  return "Outros";
    }
}

string Chamado::prioridadeParaTexto() const {
    switch (prioridade) {
        case Prioridade::BAIXA:   return "Baixa";
        case Prioridade::MEDIA:   return "Média";
        case Prioridade::ALTA:    return "Alta";
        default:                  return "Crítica";
    }
}

string Chamado::statusParaTexto() const {
    switch (status) {
        case Status::ABERTO:       return "Aberto";
        case Status::EM_ANDAMENTO: return "Em Andamento";
        case Status::RESOLVIDO:    return "Resolvido";
        default:                   return "Cancelado";
    }
}
