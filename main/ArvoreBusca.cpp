#include "interface/ArvoreBusca.h"
#include <iostream>
#include <queue>
using namespace std;
// Construtor
ArvoreBusca::ArvoreBusca() {
    this->raiz = nullptr;
}

// Destrutor
ArvoreBusca::~ArvoreBusca() {
    
    destruirArvore(this->raiz);
}

void ArvoreBusca::destruirArvore(NoBST* no) {
    if (no == nullptr) {
        return;
    }

    destruirArvore(no->esquerda);
    destruirArvore(no->direita);
    delete no;
}

// vai procurando um lugar pelo id e não deixa entrar id repetido
 NoBST* ArvoreBusca::inserirRecursivo(NoBST* no, const Chamado& chamado, bool& inserido) {
    if (no == nullptr) {
        inserido = true;
        return new NoBST(chamado);
    }

    if (chamado.getId() < no->chamado.getId()) {
        no->esquerda = inserirRecursivo(no->esquerda, chamado, inserido);
    } else if (chamado.getId() > no->chamado.getId()) {
        no->direita = inserirRecursivo(no->direita, chamado, inserido);
    } else {
        inserido = false;
    }
    return no;
 }

bool ArvoreBusca::inserir(Chamado chamado) {
    bool inserido = false;
    this->raiz = inserirRecursivo(this->raiz, chamado, inserido);
    return inserido;
}

NoBST* ArvoreBusca::localizarRecursivo(NoBST* no, int id) const {
    if (no == nullptr || no->chamado.getId() == id) {
        return no;
    } 

    if (id < no->chamado.getId()) {
        return localizarRecursivo(no->esquerda, id);
    } else {
        return localizarRecursivo(no->direita, id);
    }
}

Chamado* ArvoreBusca::localizar(int id) {
    NoBST* no = localizarRecursivo(this->raiz, id);
    if (no != nullptr) {
        return &(no->chamado);
    }
    std::cout << "Chamado com ID " << id << " não encontrado." << std::endl;
    return nullptr;
}

NoBST* ArvoreBusca::removerRecursivo(NoBST* no, int id, bool& removido) {
    if (no == nullptr) {
        removido = false;
        return nullptr;
    }


    // procura o no 
    if(id < no->chamado.getId()) {
        no->esquerda = removerRecursivo(no->esquerda, id, removido);
    } else if (id > no->chamado.getId()) {
        no->direita = removerRecursivo(no->direita, id, removido);
    } else {
        removido = true;


       // Caso 1: Nó com no máximo UM filho (ou nenhum/folha)
        if (no->esquerda == nullptr) {
            NoBST* temp = no->direita; // Salva o filho da direita (pode ser nullptr)
            delete no;                  // Libera a memória do nó atual
            return temp;                // Retorna o filho para reconectar na árvore
        } 
        else if (no->direita == nullptr) {
            NoBST* temp = no->esquerda; // Salva o filho da esquerda
            delete no;                  // Libera a memória do nó atual
            return temp;                // Retorna o filho para reconectar na árvore
        }

        // Caso 2: Nó com DOIS filhos. Transplanta o sucessor sem copiar Chamado.
        NoBST* paiSucessor = no;
        NoBST* sucessor = no->direita;

        while (sucessor->esquerda != nullptr) {
            paiSucessor = sucessor;
            sucessor = sucessor->esquerda;
        }

        if (paiSucessor != no) {
            paiSucessor->esquerda = sucessor->direita;
            sucessor->direita = no->direita;
        }

        sucessor->esquerda = no->esquerda;
        delete no;
        return sucessor;
    }
    return no;
    
}

bool ArvoreBusca::remover(int identificador) {
    bool removido = false;
    this->raiz = removerRecursivo(this->raiz, identificador, removido);
    return removido;
}

NoBST* ArvoreBusca::encontrarSucessor(NoBST* raiz, NoBST* alvo) {
    // Caso 1: Se existe subárvore à direita
    if (alvo->direita != nullptr) {
        NoBST* atual = alvo->direita;
        while (atual->esquerda != nullptr) {
            atual = atual->esquerda;
        }
        return atual;
    }

    // Caso 2: Não existe subárvore à direita
    NoBST* sucessor = nullptr;
    NoBST* atual = raiz;

    while (atual != nullptr) {
        if (alvo->chamado.getId() < atual->chamado.getId()) {
            sucessor = atual; // Candidato a sucessor
            atual = atual->esquerda;
        } else if (alvo->chamado.getId() > atual->chamado.getId()) {
            atual = atual->direita;
        } else {
            break; // Encontrou o nó alvo na navegação
        }
    }

    return sucessor;
}

// passa pela esquerda, pelo nó e pela direita pra mostrar os ids em ordem
void ArvoreBusca::emOrdem(NoBST* no) const {
    if(no != nullptr) {
        emOrdem(no->esquerda);
        no->chamado.imprimir();
        emOrdem(no->direita);
    }

}
void ArvoreBusca::listarOrdemCrescente() {
    if (this->raiz == nullptr) {
        std::cout << "Nenhum chamado cadastrado." << std::endl;
        return;
    }
    emOrdem(this->raiz);
}

Chamado* ArvoreBusca::obterMenorIdentificador() {

    if (this->raiz == nullptr) {
        return nullptr;
    }
    NoBST* atual = this->raiz;
    while(atual->esquerda != nullptr) {

        atual = atual->esquerda;
    }
    return &(atual->chamado);
}

Chamado* ArvoreBusca::obterMaiorIdentificador() {

    if (raiz == nullptr) return nullptr;

    NoBST* atual = raiz;
    while (atual->direita != nullptr) {
        atual = atual->direita;
    }
    return &(atual->chamado);
}

int ArvoreBusca::calcularAlturaRecursivo(NoBST* no) const {
    if (no == nullptr) return -1;

    int alturaEsq = calcularAlturaRecursivo(no->esquerda);
    int alturaDir = calcularAlturaRecursivo(no->direita);
    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);

}

int ArvoreBusca::obterAltura() {
    return calcularAlturaRecursivo(raiz);
}

int ArvoreBusca::contarNosRecursivo(NoBST* no) const {
    if (no == nullptr) return 0;

    return 1 + contarNosRecursivo(no->esquerda) + contarNosRecursivo(no->direita);
}

int ArvoreBusca::determinarNumeroDeChamados() {
    return contarNosRecursivo(raiz);
}

int ArvoreBusca::contarPorStatusRecursivo(NoBST* no, Status status) const {
    if (no == nullptr) return 0;
    return (no->chamado.getStatus() == status ? 1 : 0)
        + contarPorStatusRecursivo(no->esquerda, status)
        + contarPorStatusRecursivo(no->direita, status);
}

int ArvoreBusca::contarPorStatus(Status status) const {
    return contarPorStatusRecursivo(raiz, status);
}

void ArvoreBusca::listarPorIntervaloRecursivo(NoBST* no, int min, int max) const {
    if (no == nullptr) return;

    if (no->chamado.getId() > min) {
        listarPorIntervaloRecursivo(no->esquerda, min, max);
    }
    if (no->chamado.getId() >= min && no->chamado.getId() <= max) {
        no->chamado.imprimir();
    }
    if (no->chamado.getId() < max) {
        listarPorIntervaloRecursivo(no->direita, min, max);
    }
}

void ArvoreBusca::listarPorIntervalo(int min, int max) {
    if (raiz == nullptr) {
        std::cout << "Arvore vazia.\n";
        return;
    }
    listarPorIntervaloRecursivo(raiz, min, max);
}

void ArvoreBusca::percursoPreOrdem() {
    if (raiz == nullptr) {
        std::cout << "Arvore vazia.\n";
        return;
    }
    std::cout << "Pre-Ordem: ";
    preOrdemRecursivo(raiz);
    std::cout << "\n";
}

void ArvoreBusca::percursoPosOrdem() {
    if (raiz == nullptr) {
        std::cout << "Arvore vazia.\n";
        return;
    }
    std::cout << "Pos-Ordem: ";
    posOrdemRecursivo(raiz);
    std::cout << "\n";
}

// usa uma fila pra mostrar um nível da árvore de cada vez
void ArvoreBusca::percursoEmLargura() {
    if (raiz == nullptr) {
        std::cout << "Arvore vazia.\n";
        return;
    }

    std::cout << "Em Largura: ";
    std::queue<NoBST*> fila;
    fila.push(raiz);
    while (!fila.empty()) {
        NoBST* atual = fila.front();
        fila.pop();
        std::cout << atual->chamado.getId() << " ";
        if (atual->esquerda != nullptr) fila.push(atual->esquerda);
        if (atual->direita != nullptr) fila.push(atual->direita);
    }
    std::cout << "\n";
}

void ArvoreBusca::preOrdemRecursivo(NoBST* no) const {
    if (no == nullptr) return;
    std::cout << no->chamado.getId() << " ";
    preOrdemRecursivo(no->esquerda);
    preOrdemRecursivo(no->direita);
}

void ArvoreBusca::posOrdemRecursivo(NoBST* no) const {
    if (no == nullptr) return;
    posOrdemRecursivo(no->esquerda);
    posOrdemRecursivo(no->direita);
    std::cout << no->chamado.getId() << " ";
}
