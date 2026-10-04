#include "interface/NoHistorico.h"

NoHistorico::NoHistorico(std::string dataHorario, std::string descricao) : dataHorario(dataHorario), descricao(descricao), proximo(nullptr) {}

std::string NoHistorico::getDataHorario() const {
    return dataHorario;
}

std::string NoHistorico::getDescricao() const {
    return descricao;
}

NoHistorico* NoHistorico::getProximo() const {

    return proximo;
}

void NoHistorico::setProximo(NoHistorico* prox) {
    proximo = prox;
}
