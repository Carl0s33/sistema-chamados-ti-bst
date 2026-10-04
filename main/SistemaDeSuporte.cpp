#include "interface/SistemaDeSuporte.h"
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <windows.h>

using namespace std;

namespace {



bool lerInteiro(int& valor) {
    // ler a linha inteira evita sobrar lixo no buffer para a proxima pergunta
    std::string linha;
    if (!std::getline(std::cin, linha)) return false;
    std::istringstream entrada(linha);
    char extra;
    if (!(entrada >> valor) || (entrada >> extra)) {
        std::cout << "\nErro: Entrada invalida! Digite um numero inteiro.\n";
        return false;
    }
    return true;
}

bool lerEscolha(const char* mensagem, int minimo, int maximo, int& valor) {
    // o usuario pode errar e a funcao insiste ate receber uma opcao valida
    while (true) {
        std::cout << mensagem;
        if (!lerInteiro(valor)) {
            if (std::cin.eof() || std::cin.bad()) return false;
            continue;
        }
        if (valor >= minimo && valor <= maximo) return true;
        std::cout << "Erro: Escolha um numero de " << minimo << " a " << maximo << ".\n";
    }
}
}
SistemaDeSuporte::SistemaDeSuporte() {
    // IDs aleatorios e distintos, com status aberto, para dados iniciais de teste.
    for (int i = 0; i < 5; ++i) {
        Chamado chamado(Status::ABERTO);
        while (arvore.localizar(chamado.getId()) != nullptr) {
            chamado.setId(Chamado().getId());
        }
        arvore.inserir(chamado);
    }
}

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
    SetConsoleCP(CP_UTF8);
    int opcao = -1;
    Chamado* chamadoEmAtendimento = nullptr; 

    do {
        exibirMenu();
        if (!lerInteiro(opcao)) {
            if (cin.eof() || cin.bad()) return;
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1: {
                Chamado novoChamado;
                
                if (arvore.inserir(novoChamado)) {
                    // arvore.localizar(novoChamado.getId())->getHistorico().inserir(dataHoraAtual(), "Chamado aberto no sistema.");
                    // cout << "Chamado #" << novoChamado.getId() << " aberto com sucesso!" << endl;
                    novoChamado.imprimir();
                } else {
                    cout << "Erro: Ja existe um chamado com este ID." << endl;
                }
                break;
            }
            case 2: {
                cout << "\n--- Buscar Chamado ---" << endl;
                int idBusca;
                cout << "Digite o ID do chamado exibido ao abrir: ";
                if (!lerInteiro(idBusca)) {
                    if (cin.eof() || cin.bad()) return;
                    break;
                }
                
                Chamado* c = arvore.localizar(idBusca);
                if (c != nullptr) {
                    c->imprimir();
                    c->imprimirHistorico();
                } else {
                    cout << "Chamado nao encontrado!" << endl;
                }
                break;
            }
            case 3: {
                cout << "\n--- Remover Chamado ---" << endl;
                int idRemover;
                cout << "Digite o ID do chamado a remover: ";
                if (!lerInteiro(idRemover)) {
                    if (cin.eof() || cin.bad()) return;
                    break;
                }

               if (arvore.remover(idRemover)) {
                    cout << "Chamado com o id: " << idRemover << " removido com sucesso." << endl;
                } else {
                    cout << "Chamado com o id: " << idRemover << " não encontrado." << endl;
                }
                break;
            }
            case 4:
                cout << "\n--- Listar Chamados (Ordem Crescente) ---" << endl;
                arvore.listarOrdemCrescente();
                break;
            case 5: {
                cout << "\n--- Consultar Chamados por Intervalo ---" << endl;
                int min, max;
                cout << "Digite o ID minimo: ";
                if (!lerInteiro(min)) {
                    if (cin.eof() || cin.bad()) return;
                    break;
                }
                cout << "Digite o ID maximo: ";
                if (!lerInteiro(max)) {
                    if (cin.eof() || cin.bad()) return;
                    break;
                }
                if (min > max) {
                    cout << "Intervalo invalido: o minimo deve ser menor ou igual ao maximo." << endl;
                } else {
                    arvore.listarPorIntervalo(min, max);
                }
                break;
            }
            case 6: {
                cout << "\n--- Encaminhar Chamado para Atendimento ---" << endl;

                // 1. Mostra as estatísticas da árvore
                exibirEstatisticas();

                // 2. Só faz sentido pedir a quantidade se houver chamados abertos
                int abertos = arvore.contarPorStatus(Status::ABERTO);
                if (abertos == 0) {
                    cout << "\nNao ha chamados abertos para encaminhar." << endl;
                    break;
                }

                // 3. Pede a quantidade (de 1 até o total de abertos)
                int quantidade;
                string mensagem = "\nQuantos chamados deseja encaminhar para a fila (1 a "
                                + to_string(abertos) + ")? ";
                if (!lerEscolha(mensagem.c_str(), 1, abertos, quantidade)) return;

                // 4. Enfileira apenas essa quantidade
                arvore.enfileiraChamados(fila, quantidade);
                cout << "\n" << quantidade << " chamado(s) encaminhado(s) para a fila." << endl;
                break;
            }
            case 7: {
                cout << "\n--- Atender Proximo Chamado ---" << endl;

                Chamado* proximo = fila.desenfileirar();
                if (proximo == nullptr) {
                    cout << "A fila de atendimento esta vazia!" << endl;
                    break;
                }

                if (chamadoEmAtendimento != nullptr) {
                    chamadoEmAtendimento->setStatus(Status::RESOLVIDO);
                    chamadoEmAtendimento->getHistorico().inserir(
                        "Atendimento finalizado ao iniciar o proximo chamado."
                    );
                }

                chamadoEmAtendimento = proximo;
                chamadoEmAtendimento->setStatus(Status::EM_ANDAMENTO);
                chamadoEmAtendimento->getHistorico().inserir(
                    "Tecnico iniciou o atendimento."
                );

                cout << "Tecnico iniciou o atendimento do chamado #"
                    << chamadoEmAtendimento->getId() << endl;
                chamadoEmAtendimento->imprimir();
                break;
            }
            case 8: {
                cout << "\n--- Consultar Historico de Tramitacao ---" << endl;
                int idHist;
                cout << "Digite o ID do chamado: ";
                if (!lerInteiro(idHist)) {
                    if (cin.eof() || cin.bad()) return;
                    break;
                }

                Chamado* c = arvore.localizar(idHist);
                if (c != nullptr) {
                    cout << "=== HISTORICO DO CHAMADO #" << idHist << " ===" << endl;
                    c->getHistorico().listarHistorico();
                } else {
                    cout << "Chamado nao encontrado!" << endl;
                }
                break;
            }
            case 9: {
                cout << "\n--- Alterar Status ---" << endl;
                // o historico registra a mudanca antes de trocar o estado atual
                int id, escolha;
                cout << "Digite o ID do chamado: ";
                if (!lerInteiro(id)) {
                    if (cin.eof() || cin.bad()) return;
                    break;
                }
                Chamado* c = arvore.localizar(id);
                if (c == nullptr) {
                    cout << "Chamado nao encontrado!" << endl;
                    break;
                }
                if (!lerEscolha("Novo status: 1. Aberto  2. Em atendimento  3. Resolvido  4. Cancelado\nEscolha: ", 1, 4, escolha)) return;
                Status novoStatus = static_cast<Status>(escolha - 1);
                if (c->getStatus() == novoStatus) {
                    cout << "O chamado ja possui esse status." << endl;
                    break;
                }
                const char* nomes[] = {"Aberto", "Em atendimento", "Resolvido", "Cancelado"};
                string registro = string("Status alterado de ") + nomes[static_cast<int>(c->getStatus())]
                    + " para " + nomes[escolha - 1] + ".";
                c->getHistorico().inserir( registro);
                c->setStatus(novoStatus);
                cout << "Status do chamado #" << id << " alterado com sucesso!" << endl;
                break;
            }
            case 10:
                exibirEstatisticas();
                break;
            case 0:
                cout << "\nSaindo do sistema... Ate logo!" << endl;
                break;
            default:
                cout << "\nErro: Opcao invalida! Escolha um numero de 0 a 10." << endl;
        }
    } while (opcao != 0);
}

void SistemaDeSuporte::exibirEstatisticas() {
    std::cout << "\n=========== ESTATISTICAS ===========\n\n";
    std::cout << "Total de chamados: " << arvore.determinarNumeroDeChamados() << "\n\n";
    Chamado* menor = arvore.obterMenorIdentificador();
    std::cout << "Menor ID: " << (menor != nullptr ? std::to_string(menor->getId()) : "0") << "\n";
    Chamado* maior = arvore.obterMaiorIdentificador();
    std::cout << "Maior ID: " << (maior != nullptr ? std::to_string(maior->getId()) : "0") << "\n\n";
    std::cout << "Altura da BST: " << arvore.obterAltura() << "\n\n";
    std::cout << "Chamados na fila: " << fila.getQuantidade() << "\n\n";
    std::cout << "Chamados abertos: " << arvore.contarPorStatus(Status::ABERTO) << "\n";
    std::cout << "Em atendimento: " << arvore.contarPorStatus(Status::EM_ANDAMENTO) << "\n";
    std::cout << "Resolvidos: " << arvore.contarPorStatus(Status::RESOLVIDO) << "\n";
    std::cout << "Cancelados: " << arvore.contarPorStatus(Status::CANCELADO) << "\n";
}
