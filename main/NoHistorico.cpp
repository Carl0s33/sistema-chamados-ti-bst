#include "interface/NoHistorico.h"

NoHistorico::NoHistorico(std::string dataHorario, std::string descricao) : dataHorario(dataHorario), descricao(descricao), proximo(nullptr) {}

std::string NoHistorico::getDataHorario() const {
    return dataHorario;
}

std::string NoHistorico::getDescricao() const {
    return descricao;
}

NoHistorico* NoHistorico::getProximo() const {
    // esse ponteiro e a ligacao que transforma os registros numa lista
    return proximo;
}

void NoHistorico::setProximo(NoHistorico* prox) {
    proximo = prox;
}
