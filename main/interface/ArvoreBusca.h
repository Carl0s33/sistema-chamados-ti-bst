#ifndef ARVOREBST_H
#define ARVOREBST_H

#include "Chamado.h"
//esqueeda é menor e direta é maior

struct NoBST {
    Chamado chamado;
    NoBST* esquerda;
    NoBST* direita;

    NoBST(const Chamado& c) : chamado(c), esquerda(nullptr), direita(nullptr) {}
};

class ArvoreBST {
private:
    NoBST* raiz;

  
    NoBST* cadastrarRecursivo(NoBST* no, const Chamado& chamado, bool& inserido);
    NoBST* localizarRecursivo(NoBST* no, int identificador) const;
    NoBST* removerRecursivo(NoBST* no, int identificador, bool& removido);
    void emOrdemRecursivo(NoBST* no) const;
    void preOrdemRecursivo(NoBST* no) const;
    void posOrdemRecursivo(NoBST* no) const;
    void listarPorIntervaloRecursivo(NoBST* no, int min, int max) const;
    int calcularAlturaRecursivo(NoBST* no) const;
    int contarNosRecursivo(NoBST* no) const;
    void destruirArvore(NoBST* no);

public:
    ArvoreBST();
    ~ArvoreBST();

    bool cadastrar(Chamado chamado);
    Chamado* localizar(int identificador);
    bool remover(int identificador);
    void listarOrdemCrescente();
    Chamado* obterMenorIdentificador();
    Chamado* obterMaiorIdentificador();
    int obterAltura();
    int determinarNumeroDeChamados();
    void listarPorIntervalo(int min, int max);
    void percursoPreOrdem();
    void percursoPosOrdem();
    void percursoEmLargura();
};

#endif 