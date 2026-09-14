#include "interface/SistemaDeSuporte.h"

int main() {

    SetConsoleOutputCP(CP_UTF8);

     ArvoreBusca arvore;
    Chamado chamado1(1);
    arvore.inserir(chamado1);
 
    for(int i = 0; i < 7 ;i++) {
      Chamado chamado{};
      bool inserido = arvore.inserir(chamado);
      std::cout << "contador " << i << ": ID " << chamado.getId()
                << (inserido ? " inserido" : " duplicado") << std::endl;
    }

    // arvore.listarOrdemCrescente();
    
     Chamado* chamadoEncontrado = arvore.obterMaiorIdentificador();
    chamadoEncontrado->imprimir();


    SistemaDeSuporte sistema;
    sistema.executar();

    return 0;
}