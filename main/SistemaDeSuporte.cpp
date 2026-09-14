#include "interface/SistemaDeSuporte.h"
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <windows.h>

using namespace std;

namespace {
std::string dataHoraAtual() {
    std::time_t agora = std::time(nullptr);
    std::tm* horario = std::localtime(&agora);
    std::ostringstream texto;
    if (horario != nullptr) texto << std::put_time(horario, "%d/%m/%Y %H:%M:%S");
    return texto.str();
}

bool lerTexto(const char* mensagem, std::string& valor) {
    while (true) {
        std::cout << mensagem;
        if (!std::getline(std::cin, valor)) return false;
        if (valor.find_first_not_of(" \t\r") != std::string::npos) return true;
        std::cout << "Erro: Este campo nao pode ficar vazio.\n";
    }
}

bool lerInteiro(int& valor) {
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
    SetConsoleCP(CP_UTF8);
    int opcao = -1;

    do {
        exibirMenu();
        if (!lerInteiro(opcao)) {
            if (cin.eof() || cin.bad()) return;
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1: {
                cout << "\n--- Abrir Chamado ---" << endl;
                string nome, matricula, descricao;
                int tipo, categoria, prioridade;
                if (!lerTexto("Nome do solicitante: ", nome)) return;
                if (!lerTexto("Matricula do solicitante: ", matricula)) return;
                if (!lerEscolha("Tipo: 1. Docente  2. Discente  3. Servidor\nEscolha: ", 1, 3, tipo)) return;
                if (!lerTexto("Descricao do problema: ", descricao)) return;
                if (!lerEscolha("Categoria: 1. Hardware  2. Software  3. Rede  4. Sistema  5. Acesso  6. Outros\nEscolha: ", 1, 6, categoria)) return;
                if (!lerEscolha("Prioridade: 1. Baixa  2. Media  3. Alta  4. Critica\nEscolha: ", 1, 4, prioridade)) return;
                Solicitante solicitante(nome, matricula, static_cast<tipoSolicitante>(tipo - 1));
                Chamado novoChamado(solicitante, descricao, static_cast<Categoria>(categoria - 1),
                                   static_cast<Prioridade>(prioridade - 1));
                
                if (arvore.inserir(novoChamado)) {
                    arvore.localizar(novoChamado.getId())->getHistorico().inserir(dataHoraAtual(), "Chamado aberto no sistema.");
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
                if (!lerInteiro(idBusca)) {
                    if (cin.eof() || cin.bad()) return;
                    break;
                }
                
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
                if (!lerInteiro(idRemover)) {
                    if (cin.eof() || cin.bad()) return;
                    break;
                }

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
                int idEncaminhar;
                cout << "Digite o ID do chamado aberto para a fila: ";
                if (!lerInteiro(idEncaminhar)) {
                    if (cin.eof() || cin.bad()) return;
                    break;
                }

                Chamado* c = arvore.localizar(idEncaminhar);
                if (c != nullptr) {
                    fila.enfileirar(c);
                    c->getHistorico().inserir(dataHoraAtual(), "Encaminhado para a fila de atendimento.");
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
                    c->setStatus(Status::EM_ANDAMENTO);
                    cout << "Tecnico iniciou o atendimento do chamado #" << c->getId() << endl;
                    c->getHistorico().inserir(dataHoraAtual(), "Tecnico iniciou o atendimento.");
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
                c->getHistorico().inserir(dataHoraAtual(), registro);
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
