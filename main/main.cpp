#include "interface/SistemaDeSuporte.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif


int main() {


    //  ArvoreBusca arvore;
    // Chamado chamado1(1);
    // arvore.inserir(chamado1);
 
    // for(int i = 0; i < 7 ;i++) {
    //   Chamado chamado{};
    //   bool inserido = arvore.inserir(chamado);
    //   std::cout << "contador " << i << ": ID " << chamado.getId()
    //             << (inserido ? " inserido" : " duplicado") << std::endl;
    // }

    // // arvore.listarOrdemCrescente();
    
    //  Chamado* chamadoEncontrado = arvore.obterMaiorIdentificador();
    // chamadoEncontrado->imprimir();


    SistemaDeSuporte sistema;
    sistema.executar();

    return 0;
}
