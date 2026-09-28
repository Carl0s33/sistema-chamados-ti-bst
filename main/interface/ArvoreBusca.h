#ifndef ARVOREBST_H
#define ARVOREBST_H

#include "Chamado.h"
#include "FilaChamados.h"
//esqueeda é menor e direta é maior

struct NoBST {
    Chamado chamado;
    NoBST* esquerda;
    NoBST* direita;

    NoBST(const Chamado& c) : chamado(c), esquerda(nullptr), direita(nullptr) {}
};

class ArvoreBusca {
private:
    NoBST* raiz;

    NoBST* encontrarSucessor(NoBST* raiz, NoBST* alvo);
    NoBST* inserirRecursivo(NoBST* no, const Chamado& chamado, bool& inserido);
    NoBST* localizarRecursivo(NoBST* no, int identificador) const;
    NoBST* removerRecursivo(NoBST* no, int identificador, bool& removido);
    void emOrdem(NoBST* no) const;
    void emOrdemRecursivo(NoBST* no) const;
    void preOrdemRecursivo(NoBST* no) const;
    void posOrdemRecursivo(NoBST* no) const;
    void listarPorIntervaloRecursivo(NoBST* no, int min, int max) const;
    int calcularAlturaRecursivo(NoBST* no) const;
    int contarNosRecursivo(NoBST* no) const;
    int contarPorStatusRecursivo(NoBST* no, Status status) const;
    void destruirArvore(NoBST* no);
    void enfileiraChamadoRecursivo(NoBST* no, FilaChamados& filaDeAtendimento) const;

public:
    ArvoreBusca();
    ~ArvoreBusca();

    bool inserir(Chamado chamado);
    Chamado* localizar(int identificador);
    bool remover(int identificador);
    void listarOrdemCrescente();
    Chamado* obterMenorIdentificador();
    Chamado* obterMaiorIdentificador();
    int obterAltura();
    int determinarNumeroDeChamados();
    int contarPorStatus(Status status) const;
    void listarPorIntervalo(int min, int max);
    void percursoPreOrdem();
    void percursoPosOrdem();
    void percursoEmLargura();
    void enfileiraChamados(FilaChamados& filaDeAtendimento) const;
};

#endif
