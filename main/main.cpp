#include <iostream>
#include <windows.h>
#include "interface/Chamado.h"
#include "interface/ListaHistorico.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Chamado chamado1(1);
    
    // 1. Imprime os dados básicos do chamado gerado
    chamado1.imprimir();

    // 2. Insere um evento de teste no histórico do chamado
    chamado1.getHistorico().inserir("08/09/2026 07:34", "Chamado aberto no sistema.");
    chamado1.getHistorico().inserir("08/09/2026 07:45", "Equipe tecnica notificada.");

    // 3. Consulta e exibe o histórico na tela
    std::cout << "\n=== HISTORICO DE TRAMITACAO ===" << std::endl;
    chamado1.getHistorico().listarHistorico();

    return 0;
}