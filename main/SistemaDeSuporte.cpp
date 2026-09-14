#include "interface/SistemaDeSuporte.h"
#include <iostream>
#include <windows.h>

using namespace std;

SistemaDeSuporte::SistemaDeSuporte() {}

void SistemaDeSuporte::exibirMenu() const {
    cout << "\n========================================" << endl;
    cout << "        SISTEMA DE SUPORTE DE TI        " << endl;
    cout << "========================================" << endl;
    cout << "1. Abrir chamado" << endl;
    cout << "2. Buscar chamado" << endl;
    cout << "3. Remover chamado" << endl;
    cout << "4. Listar chamados" << endl;
    cout << "5. Consultar chamados por intervalo" << endl;
    cout << "6. Encaminhar chamado para atendimento" << endl;
    cout << "7. Atender proximo chamado" << endl;
    cout << "8. Consultar historico" << endl;
    cout << "9. Alterar status" << endl;
    cout << "10. Estatisticas" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha: ";
}

void SistemaDeSuporte::executar() {
    SetConsoleOutputCP(CP_UTF8);
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1: {
                cout << "\n--- Abrir Chamado ---" << endl;
                Chamado novoChamado;
                novoChamado.getHistorico().inserir("14/09/2026 07:30", "Chamado aberto no sistema.");
                
                if (arvore.inserir(novoChamado)) {
                    cout << "Chamado #" << novoChamado.getId() << " aberto com sucesso!" << endl;
                    novoChamado.imprimir();
                } else {
                    cout << "Erro: Ja existe um chamado com este ID." << endl;
                }
                break;
            }
            case 2: {
                cout << "\n--- Buscar Chamado ---" << endl;
                int idBusca;
                cout << "Digite o ID do chamado: ";
                cin >> idBusca;
                
                Chamado* c = arvore.localizar(idBusca);
                if (c != nullptr) {
                    c->imprimir();
                } else {
                    cout << "Chamado nao encontrado!" << endl;
                }
                break;
            }
            case 3: {
                cout << "\n--- Remover Chamado ---" << endl;
                int idRemover;
                cout << "Digite o ID do chamado a remover: ";
                cin >> idRemover;

                if (arvore.remover(idRemover)) {
                    cout << "Chamado #" << idRemover << " removido com sucesso!" << endl;
                } else {
                    cout << "Chamado nao encontrado na arvore." << endl;
                }
                break;
            }
            case 4:
                cout << "\n--- Listar Chamados (Ordem Crescente) ---" << endl;
                arvore.listarOrdemCrescente();
                break;
            case 5:
                cout << "\n--- Consultar Chamados por Intervalo ---" << endl;
                cout << "[Pendente de implementacao na Arvore]" << endl;
                break;
            case 6: {
                cout << "\n--- Encaminhar Chamado para Atendimento ---" << endl;
                int idEncaminhar;
                cout << "Digite o ID do chamado aberto para a fila: ";
                cin >> idEncaminhar;

                Chamado* c = arvore.localizar(idEncaminhar);
                if (c != nullptr) {
                    fila.enfileirar(c);
                    c->getHistorico().inserir("14/09/2026 08:00", "Encaminhado para a fila de atendimento.");
                    cout << "Chamado #" << idEncaminhar << " adicionado a fila com sucesso!" << endl;
                } else {
                    cout << "Chamado nao encontrado!" << endl;
                }
                break;
            }
            case 7: {
                cout << "\n--- Atender Proximo Chamado ---" << endl;
                Chamado* c = fila.desenfileirar();
                if (c != nullptr) {
                    cout << "Atendendo chamado da frente:" << endl;
                    c->getHistorico().inserir("14/09/2026 08:15", "Tecnico iniciou o atendimento.");
                    c->imprimir();
                } else {
                    cout << "A fila de atendimento esta vazia!" << endl;
                }
                break;
            }
            case 8: {
                cout << "\n--- Consultar Historico de Tramitacao ---" << endl;
                int idHist;
                cout << "Digite o ID do chamado: ";
                cin >> idHist;

                Chamado* c = arvore.localizar(idHist);
                if (c != nullptr) {
                    cout << "=== HISTORICO DO CHAMADO #" << idHist << " ===" << endl;
                    c->getHistorico().listarHistorico();
                } else {
                    cout << "Chamado nao encontrado!" << endl;
                }
                break;
            }
            case 9:
                cout << "\n--- Alterar Status ---" << endl;
                cout << "[Em desenvolvimento]" << endl;
                break;
            case 10:
                cout << "\n--- Estatisticas do Sistema ---" << endl;
                cout << "[Em desenvolvimento]" << endl;
                break;
            case 0:
                cout << "\nSaindo do sistema... Ate logo!" << endl;
                break;
            default:
                cout << "\nOpcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 0);
}