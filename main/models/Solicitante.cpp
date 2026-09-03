#include "Solicitante.h"
#include <random>


// Construtor invocando os métodos privados na lista de inicialização
Solicitante::Solicitante()
    : nome(gerarNomeAleatorio()), 
      matricula(gerarMatriculaAleatoria()), 
      tipo(gerarTipoAleatorio()) {}

// Construtor Parametrizado
Solicitante::Solicitante(string nome, string matricula, tipoSolicitante tipo)
    : nome(nome), matricula(matricula), tipo(tipo) {}


// --- MÉTODOS PRIVADOS AUXILIARES ---

string Solicitante::gerarNomeAleatorio() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static const string nomes[] = {
        "João Pedro", "Ana Julia", "Carlos Eduardo", "Maria Clara", "Lucas Gabriel"
    };
    std::uniform_int_distribution<int> dist(0, 4);
    return nomes[dist(gen)];
}

string Solicitante::gerarMatriculaAleatoria() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    // Gera um número no formato de matrícula acadêmica (ex: 20260001 a 20269999)
    std::uniform_int_distribution<> dist(20260000, 20269999);
    return std::to_string(dist(gen));
}

tipoSolicitante Solicitante::gerarTipoAleatorio() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    // Ajuste o "2" para a quantidade máxima de opções menos 1 que existem no seu enum tipoSolicitante
    std::uniform_int_distribution<> dist(0, 2); 
    return static_cast<tipoSolicitante>(dist(gen));
}

// --- GETTERS ---

string Solicitante::getNome() const {
    return nome;
}

string Solicitante::getMatricula() const {
    return matricula;
}

tipoSolicitante Solicitante::getTipo() const {
    return tipo;
}

// --- SETTERS ---

void Solicitante::setNome(const string& nome) {
    this->nome = nome;
}

void Solicitante::setMatricula(const string& matricula) {
    this->matricula = matricula;
}

void Solicitante::setTipo(tipoSolicitante tipo) {
    this->tipo = tipo;
}