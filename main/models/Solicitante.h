#pragma once 

#include <string>
#include "../enums/tipoSolicitante.h"


class Solicitante {
private:
    std::string nome;
    std::string matricula;
    tipoSolicitante tipo;

    static std::string gerarNomeAleatorio();
    static std::string gerarMatriculaAleatoria();
    static tipoSolicitante gerarTipoAleatorio();

public:
    Solicitante();

    Solicitante(std::string nome, std::string matricula, tipoSolicitante tipo);

    void imprimir() const;

   
    std::string getNome() const;
    std::string getMatricula() const;
    tipoSolicitante getTipo() const;


    void setNome(const std::string& nome);
    void setMatricula(const std::string& matricula);
    void setTipo(tipoSolicitante tipo);
};