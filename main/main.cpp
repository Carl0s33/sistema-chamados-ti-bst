#include <iostream>

#include "interface/Chamado.h"
#include "interface/ListaHistorico.h"
#include "interface/ArvoreBusca.h"

int main() {

  Chamado chamado1(1);
  chamado1.imprimir();

  ArvoreBusca arvore;
  arvore.inserir(chamado1);




    return 0;
}