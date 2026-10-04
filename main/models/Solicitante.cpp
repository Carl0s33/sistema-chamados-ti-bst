#include "Solicitante.h"
#include <random>


Solicitante::Solicitante()
    : nome(gerarNomeAleatorio()), 
      matricula(gerarMatriculaAleatoria()), 
      tipo(gerarTipoAleatorio()) {}

Solicitante::Solicitante(std::string nome, std::string matricula, tipoSolicitante tipo)
    : nome(nome), matricula(matricula), tipo(tipo) {}




std::string Solicitante::gerarNomeAleatorio() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static const std::string nomes[] = {
        "João Pedro", "Ana Julia", "Carlos Eduardo", "Maria Clara", "Lucas Gabriel"
    };
    std::uniform_int_distribution<int> dist(0, 4);
    return nomes[dist(gen)];
}

std::string Solicitante::gerarMatriculaAleatoria() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
  
    std::uniform_int_distribution<> dist(20260000, 20269999);
    return std::to_string(dist(gen));
}

tipoSolicitante Solicitante::gerarTipoAleatorio() {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0, 2); 
    return static_cast<tipoSolicitante>(dist(gen));
}



std::string Solicitante::getNome() const {
    return nome;
}

std::string Solicitante::getMatricula() const {
    return matricula;
}

tipoSolicitante Solicitante::getTipo() const {
    return tipo;
}



void Solicitante::setNome(const std::string& nome) {
    this->nome = nome;
}

void Solicitante::setMatricula(const std::string& matricula) {
    this->matricula = matricula;
}

void Solicitante::setTipo(tipoSolicitante tipo) {
    this->tipo = tipo;
}