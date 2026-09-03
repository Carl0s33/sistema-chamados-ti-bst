#pragma once 

#include <string>
#include "enums/tipoSolicitante.h"

using namespace std;

class Solicitante {
private:
    string nome;
    string matricula;
    tipoSolicitante tipo;

    // Métodos privados auxiliares para geração aleatória
    static string gerarNomeAleatorio();
    static string gerarMatriculaAleatoria();
    static tipoSolicitante gerarTipoAleatorio();

public:
    // Construtor que gera um Solicitante com dados totalmente aleatórios
    Solicitante();
    
    // Construtor Parametrizado
    Solicitante(string nome, string matricula, tipoSolicitante tipo);

    // Getters
    string getNome() const;
    string getMatricula() const;
    tipoSolicitante getTipo() const;

    // Setters
    void setNome(const string& nome);
    void setMatricula(const string& matricula);
    void setTipo(tipoSolicitante tipo);
};