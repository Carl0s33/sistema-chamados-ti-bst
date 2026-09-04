#pragma once 

#include <string>
#include "../enums/tipoSolicitante.h"

using namespace std;

class Solicitante {
private:
    string nome;
    string matricula;
    tipoSolicitante tipo;

    static string gerarNomeAleatorio();
    static string gerarMatriculaAleatoria();
    static tipoSolicitante gerarTipoAleatorio();

public:
    Solicitante();

    Solicitante(string nome, string matricula, tipoSolicitante tipo);

    void imprimir() const;

    // Getters
    string getNome() const;
    string getMatricula() const;
    tipoSolicitante getTipo() const;

    // Setters
    void setNome(const string& nome);
    void setMatricula(const string& matricula);
    void setTipo(tipoSolicitante tipo);
};