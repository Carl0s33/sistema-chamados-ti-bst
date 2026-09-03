#include "Chamado.h"
#include <random>

// Construtor Padrão
Chamado::Chamado() {}

// Construtor Parametrizado utilizando Lista de Inicialização
Chamado::Chamado(int id)
    : id(id),
      solicitante(gerarSolicitanteAleatorio()),
      descricao(gerarDescricaoAleatoria()),
      categoria(gerarCategoriaAleatoria()),
      prioridade(gerarPrioridadeAleatoria()),
      status(gerarStatusAleatorio()) {}

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



string Chamado::gerarSolicitanteAleatorio() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static const string solicitantes[] = {
        "João Silva", "Maria Oliveira", "Carlos Souza", "Ana Lima", "Pedro Santos"
    };
    constexpr std::size_t quantidadeSolicitantes =
        sizeof(solicitantes) / sizeof(solicitantes[0]);
    std::uniform_int_distribution<std::size_t> dist(0, quantidadeSolicitantes - 1);
    return solicitantes[dist(gen)];
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
        0, static_cast<int>(Categoria::OUTROS));
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
    std::uniform_int_distribution<> dist(0, 3); // Ajuste conforme a quantidade de itens do Enum Status
    return static_cast<Status>(dist(gen));
}