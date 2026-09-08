#pragma once
#include <string>

class NoHistorico {
private:
    std::string dataHorario;
    std::string descricao;
    NoHistorico* proximo;

public:
    NoHistorico(std::string dataHorario, std::string descricao);

    std::string getDataHorario() const;
    std::string getDescricao() const;

    NoHistorico* getProximo() const;
    void setProximo(NoHistorico* prox);
};
