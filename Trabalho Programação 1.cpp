#include <iostream>
#include <string>

using namespace std;

int main() {

    // Limite de contas do sistema
    const int MAX_CONTAS = 5;

    // Variáveis que irá armazenar os dados das contas
    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string CPF[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];

    // Variável de controle da quantidade de contas cadastradas
    int quantidadeContas = 0;

    int opcao;

    // Variável que inicializa o sistema com 0 contas cadastradas
    int i = 0;

    while (i < MAX_CONTAS) {
        contaAtiva[i] = false;
        i++;
    }

    // Inicialização da variável de menu
    opcao = 0;

    while (opcao != 6) {

        cout << endl;
        cout << "**************************************" << endl;
        cout << "**          BANCO INF101             **" << endl;
        cout << "**************************************" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair do sistema" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            // =====================================
            // 1 - CADASTRO DE CONTA
            // =====================================
            case 1: {

                if (quantidadeContas == MAX_CONTAS) {

                    cout << endl;
                    cout << "Limite de 5 contas atingido!" << endl;

                } else {

                    int numero;
                    bool numeroRepetido = false;

                    cout << endl;
                    cout << "===== CADASTRAR A SUA CONTA =====" << endl;

                    // Numero da conta
                    numero = 0;

                    while (numero <= 0) {
                        cout << "Numero da conta: ";
                        cin >> numero;

                        if (numero <= 0) {
                            cout << "O numero deve ser maior que zero." << endl;
                        }

                    } while (numero <= 0);

                    // Comando que verifica se o numero da conta já existe
                    i = 0;

                    while (i < quantidadeContas) {

                        if (numeroConta[i] == numero) {
                            numeroRepetido = true;
                        }

                        i++;
                    }

                    if (numeroRepetido == true) {

                        cout << "Esse numero de conta ja existe." << endl;

                    } else {

                        numeroConta[quantidadeContas] = numero;

                        // Nome do cliente
                        cin.ignore();

                        cout << "Nome do titular: ";
                        getline(cin, nomeCliente[quantidadeContas]);

                        // CPF do cliente
                        cout << "CPF do titular: ";
                        getline(cin, CPF[quantidadeContas]);

                        // Comando que verifica o tipo da conta e se ele é valido ou não
                        tipoConta[quantidadeContas] = 0;

                        while (tipoConta[quantidadeContas] != 1 &&
                               tipoConta[quantidadeContas] != 2) {

                            cout << endl;
                            cout << "1 - Corrente" << endl;
                            cout << "2 - Poupanca" << endl;
                            cout << "Escolha o tipo: ";
                            cin >> tipoConta[quantidadeContas];

                            if (tipoConta[quantidadeContas] != 1 &&
                                tipoConta[quantidadeContas] != 2) {

                                cout << "Tipo de conta invalido!" << endl;
                            }
                        }

                        // Comando que pega o saldo inicial da conta e verifica se ele é negativo ou não
                        saldo[quantidadeContas] = -1;

                        while (saldo[quantidadeContas] < 0) {

                            cout << "Saldo inicial: R$ ";
                            cin >> saldo[quantidadeContas];

                            if (saldo[quantidadeContas] < 0) {
                                cout << "O saldo nao pode ser negativo." << endl;
                            }
                        }

                        // Comando que salva as informações da conta e ativa ela no sistema
                        contaAtiva[quantidadeContas] = true;

                        quantidadeContas++;

                        cout << endl;
                        cout << "Conta cadastrada com sucesso!" << endl;
                    }
                }

                break;
            }

            // =====================================
            // 2 - CONSULTOR DE CONTAS
            // =====================================
            case 2: {

                if (quantidadeContas == 0) {

                    cout << endl;
                    cout << "Nenhuma conta cadastrada." << endl;

                } else {

                    int numero;
                    int posicao = -1;

                    cout << endl;
                    cout << "===== CONSULTAR CONTA =====" << endl;
                    cout << "Numero da conta: ";
                    cin >> numero;

                    // Comando que procura a conta do cliente e verifica se ela existe ou não
                    i = 0;

                    while (i < quantidadeContas) {

                        if (numeroConta[i] == numero) {
                            posicao = i;
                        }

                        i++;
                    }

                    if (posicao == -1) {

                        cout << "Conta não encontrada." << endl;

                    } else {

                        cout << endl;
                        cout << "Numero da conta: "
                             << numeroConta[posicao] << endl;

                        cout << "Nome: "
                             << nomeCliente[posicao] << endl;

                        cout << "CPF: "
                             << CPF[posicao] << endl;

                        if (tipoConta[posicao] == 1) {
                            cout << "Tipo: Corrente" << endl;
                        } else {
                            cout << "Tipo: Poupanca" << endl;
                        }

                        cout << "Saldo: R$ "
                             << saldo[posicao] << endl;

                        if (contaAtiva[posicao] == true) {
                            cout << "Status: Ativa" << endl;
                        } else {
                            cout << "Status: Desativada" << endl;
                        }
                    }
                }

                break;
            }

            // =====================================
            // 3 - VERIFICADOR DE SALDO
            // =====================================
            case 3: {

                // Comando que verifica se existe alguma conta cadastrada no sistema

                if (quantidadeContas == 0) {

                    cout << endl;
                    cout << "Nenhuma conta cadastrada." << endl;
                
                    // Comando que mostra o saldo da conta indicada pelo cliente, caso ela exista e esteja ativa
                } else {

                    int numero;
                    int posicao = -1;

                    cout << endl;
                    cout << "===== VERIFICAR SALDO =====" << endl;
                    cout << "Numero da conta: ";
                    cin >> numero;

                    i = 0;

                    while (i < quantidadeContas) {

                        if (numeroConta[i] == numero) {
                            posicao = i;
                        }

                        i++;
                    }
                    
                    // Comando que mostra caso a conta não exista ou esteja desativada
                    if (posicao == -1) {

                        cout << "Conta não encontrada." << endl;

                    } else if (contaAtiva[posicao] == false) {

                        cout << "A conta esta desativada." << endl;

                    } else {

                        cout << "Conta: "
                             << numeroConta[posicao] << endl;

                        cout << "Saldo atual: R$ "
                             << saldo[posicao] << endl;
                    }
                }

                break;
            }

            // ===========================================================
            // 4 - ALTERAR TIPO DA CONTA PARA CORRENTE OU POUPANÇA
            // ===========================================================
            case 4: {

                if (quantidadeContas == 0) {

                    cout << endl;
                    cout << "Nenhuma conta cadastrada." << endl;

                } else {

                    int numero;
                    int posicao = -1;
                    int novoTipo;

                    cout << endl;
                    cout << "===== ALTERAR TIPO =====" << endl;
                    cout << "Numero da conta: ";
                    cin >> numero;

                    i = 0;

                    while (i < quantidadeContas) {

                        if (numeroConta[i] == numero) {
                            posicao = i;
                        }

                        i++;
                    }

                    if (posicao == -1) {

                        cout << "Conta nao encontrada." << endl;

                    } else if (contaAtiva[posicao] == false) {

                        cout << "A conta esta desativada." << endl;

                    } else {

                        novoTipo = 0;

                        while (novoTipo != 1 && novoTipo != 2) {

                            cout << endl;
                            cout << "1 - Corrente" << endl;
                            cout << "2 - Poupanca" << endl;
                            cout << "Novo tipo: ";
                            cin >> novoTipo;

                            if (novoTipo != 1 && novoTipo != 2) {
                                cout << "Tipo invalido!" << endl;
                            }
                        }

                        tipoConta[posicao] = novoTipo;

                        cout << "Tipo alterado com sucesso!" << endl;
                    }
                }

                break;
            }

            // =====================================
            // 5 - ATIVAR/DESATIVAR CONTA
            // =====================================
            case 5: {

                if (quantidadeContas == 0) {

                    cout << endl;
                    cout << "Nenhuma conta cadastrada." << endl;

                } else {

                    int numero;
                    int posicao = -1;

                    cout << endl;
                    cout << "===== ATIVAR/DESATIVAR CONTA =====" << endl;
                    cout << "Numero da conta: ";
                    cin >> numero;

                    i = 0;

                    while (i < quantidadeContas) {

                        if (numeroConta[i] == numero) {
                            posicao = i;
                        }

                        i++;
                    }

                    if (posicao == -1) {

                        cout << "Conta nao encontrada." << endl;

                    } else {

                        if (contaAtiva[posicao] == true) {

                            contaAtiva[posicao] = false;

                            cout << "Conta desativada com sucesso!" << endl;

                        } else {

                            contaAtiva[posicao] = true;

                            cout << "Conta ativada com sucesso!" << endl;
                        }
                    }
                }

                break;
            }

            // =====================================
            // 6 - SAIR DO SISTEMA
            // =====================================
            case 6:

                cout << endl;
                cout << "Saindo do sistema..." << endl;
                cout << "Obrigado por utilizar o Sistema Bancário INF101!" << endl;

                break;

            // =====================================
            // OPCAO INVALIDA
            // =====================================
            default:

                cout << endl;
                cout << "Opcao invalida!" << endl;
        }
    }

    return 0;
}