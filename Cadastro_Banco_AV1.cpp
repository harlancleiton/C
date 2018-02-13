#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{   int action1, numero_conta;
    float saldo_e=200,limite_e=1000,saldo_c=0,saque_e=0,deposito_e=0,saldo=0,deposito_c=0,saque_c;
    string nome,nome2;
    char action2,action3,action4;
    cout << "MENU\n\n\n";
    cout << "Escolha a opcao desejada:\n";
    cout << "1 - Realizar cadastro\n";
    cout << "2 - Sair do programa\n";
    cin >> action1;
    system ("CLS");
    if (action1==2){ //SAIR DO PROGRAMA
                    cout << "O programa esta sendo encerrado...\n";
                    system ("PAUSE");
                    return 0;
                    }
    if (action1==1){     //CADASTRO
                         cout << "CADASTRO\n";
                         cout << "\n";
                         cout << "Digite o primeiro nome do cliente.\n";
                         cin >> nome;
                         cout << "Digite o sobrenome do cliente.\n";
                         cin >> nome2;
                         cout << "Digite o numero da conta.\n";
                         cin >> numero_conta;
                         cout << "Escolha qual tipo de conta deseja criar:\n";
                         cout << "[C]omum\n";
                         cout << "[E]special\n";
                         cin >> action2;
                         system ("CLS");
                         //CONTA ESPECIAL
                         if (action2=='E' || action2=='e'){
                                        cout << "CONTA ESPECIAL\n\n";
                                        cout << "Seu saldo inicial e: " <<saldo_e<< ".\n";
                                        cout << "Seu limite de conta e: " <<limite_e<< ".\n";
                                        cout << "O que deseja fazer agora:\n";
                                        cout << "[S]aque\n";
                                        cout << "[D]eposito\n";
                                        cout << "[E]ncerrar\n";
                                        cin >> action3;
                                        if (action3=='S' || action3=='s') { //SAQUE CONTA ESPECIAL
                                                        cout << "Digite o valor a ser retirado.\n";
                                                        cin >> saque_e;
                                                        saldo_e=saldo_e-saque_e;
                                                        if (saldo_e<0) { //SALDO NEGATIVO, NAO PODE SER EFETUADO
                                                                       cout << "Operacao nao pode ser efetuada. A quantidade ultrapassa o saldo da conta.\n";
                                                                       cout << "Seu limite especial e de " <<limite_e<< ". Deseja utilizar o limite especial?(S/N)\n";
                                                                       cout << "Deseja retirar a quantia maxima permitida do saldo?(M).\n";
                                                                       cin >> action4;
                                                                       if (action4=='S' || action4=='s'){
                                                                                        limite_e=limite_e+saldo_e; // +saldo_e, POIS saldo_e ESTA NEGATIVO, SE FOSSE -saldo_e O LIMITE FICARIA AINDA MAIOR
                                                                                        saldo_e=0; //O CLIENTE NAO VAI FICAR COM SALDO NEGATIVO, AINDA MAIS JA USADO O LIMITE ESPECIAL
                                                                                        cout << "Operacao efetuada com sucesso!\n";
                                                                                        cout << "Nome do cliente: " <<nome<< " " <<nome2<< ".\n";
                                                                                        cout << "Numero da conta: " <<numero_conta<< ".\n";
                                                                                        cout << "Conta: especial.\n";
                                                                                        cout << "Novo saldo atual: R$" <<saldo_e<< ".\n";
                                                                                        cout << "Limite da conta: R$"<<limite_e<< ".\n";
                                                                                        system ("PAUSE");
                                                                                        return 0; //TIVE QUE ENCERRAR O PROGRAMA, SENAO IA ENTRAR NO PROXIMO IF(saldo_e>=0)
                                                                                        }

                                                                       if (action4=='N' || action4=='n'){
                                                                                        cout << "Operacao interrompida pelo usuario!\n";
                                                                                        system ("PAUSE");
                                                                                        return 0;
                                                                                        }
                                                                       if (action4=='M' || action4=='m'){
                                                                                            saldo_e=saque_e;
                                                                                            saldo_e=saldo_e-saque_e;
                                                                                            cout << "Operacao efetuada com sucesso!\n";
                                                                                            cout << "Nome do cliente: " <<nome<< " " <<nome2<< ".\n";
                                                                                            cout << "Numero da conta: " <<numero_conta<< ".\n";
                                                                                            cout << "Conta: especial.\n";
                                                                                            cout << "Novo saldo atual: R$" <<saldo_e<< ".\n";
                                                                                            cout << "Limite da conta: R$"<<limite_e<< ".\n";
                                                                                            system ("PAUSE");
                                                                                            return 0; //TIVE QUE ENCERRAR O PROGRAMA, SENAO IA ENTRAR NO PROXIMO IF(saldo_e>=0)
                                                                                            }
                                                                                        
                                                                       }
                                                        if (saldo_e>=0) { //SALDO POSITIVO, AÇAO EFETUADA
                                                                      cout << "Operacao efetuada com sucesso!\n";
                                                                      cout << "Nome do cliente: " <<nome<< " " <<nome2<< ".\n";
                                                                      cout << "Numero da conta: " <<numero_conta<< ".\n";
                                                                      cout << "Conta: especial.\n";
                                                                      cout << "Novo saldo atual: R$" <<saldo_e<< ".\n";
                                                                      cout << "Limite da conta: R$"<<limite_e<< ".\n";
                                                                      }
                                                        }
                                        if (action3=='D' || action3=='d'){ //DEPOSITO CONTA ESPECIAL
                                                         cout << "Digite o valor a ser depositado:\n";
                                                         cin >> deposito_e;
                                                         saldo_e=saldo_e+deposito_e;
                                                         cout << "Operacao efetuada com sucesso!\n";
                                                         cout << "Nome do cliente: " <<nome<< " " <<nome2<< ".\n";
                                                         cout << "Numero da conta: " <<numero_conta<< ".\n";
                                                         cout << "Conta: especial.\n";
                                                         cout << "Novo saldo atual: R$" <<saldo_e<< ".\n"; 
                                                         cout << "Limite da conta: R$"<<limite_e<< ".\n";
                                                         }
                                        if (action3=='E' || action3=='e') {//ENCERRAR PROGRAMA
                                                         cout << "Programa encerrado pelo usuario.\n";
                                                         cout << "Cliente: " <<nome<< " " <<nome2<< ".\n";
                                                         cout << "Conta: Especial";
                                                         cout << "Saldo da conta: R$" <<saldo_e<< ".\n";
                                                         cout << "Numero da conta: " <<numero_conta<< ".\n";
                                                         cout << "Limite da conta: R$"<<limite_e<< ".\n";
                                                         system ("PAUSE");
                                                         return 0;
                                                         }
                                        }
                                        //CONTA COMUM
                         if (action2=='C' || action2=='c'){
                                        cout << "CONTA COMUM\n\n";
                                        cout << "Seu saldo inicial e " <<saldo_c<< ".\n";
                                        cout << "Para finalizar o cadastro, existe um deposito minimo a ser efetuado de R$200,00.\n";
                                        cout << "Digite o valor do deposito, lembrando que nao pode ser inferior a R$ 200,00.\n";
                                        cin >> deposito_c;
                                        if (deposito_c<200){ //DEPOSITO OBRIGATORIO, MINIMO DE R$200
                                                            cout << "Deposito inferior a quantia solicitada! O programa sera encerrado.\n";
                                                            system ("PAUSE");
                                                            return 0;
                                                            }
                                        if (deposito_c>=200){ //DEPOSITO > 200, OK
                                                             cout << "Deposito efetuado com sucesso!\n";
                                                             saldo_c=saldo_c+deposito_c;
                                                             cout << "Novo saldo atual: " <<saldo_c<< ".\n";
                                                             cout << "O que deseja fazer agora:\n";
                                                             cout << "[S]aque\n";
                                                             cout << "[D]eposito\n";
                                                             cout << "[E]ncerrar\n";
                                                             cin >> action3;
                                                             if (action3=='S' || action3=='s') { //SAQUE CONTA COMUM
                                                                cout << "Digite o valor a ser retirado.\n";
                                                                cin >> saque_c;
                                                                saldo_c=saldo_c-saque_c;
                                                                                        if (saldo_c<0) { //SALDO NEGATIVO, NAO PODE SER EFETUADO
                                                                                        cout << "Operacao nao pode ser efetuada. A quantidade ultrapassa o saldo da conta.\n";
                                                                                        cout << "O programa sera encerrado.\n";
                                                                                        system ("pause");
                                                                                        return 0;
                                                                                               }
                                                                                        if (saldo_c>=0) { //SALDO POSITIVO, AÇAO EFETUADA
                                                                                        cout << "Operacao efetuada com sucesso!\n";
                                                                                        cout << "Nome do cliente: " <<nome<< " " <<nome2<< ".\n";
                                                                                        cout << "Numero da conta: " <<numero_conta<< ".\n";
                                                                                        cout << "Conta: Comum.\n";
                                                                                        cout << "Novo saldo atual :R$" <<saldo_c<< ".\n";
                                                                                             }
                                                                                        }
                                                             if (action3=='D' || action3=='d'){ //DEPOSITO CONTA ESPECIAL
                                                                cout << "Digite o valor a ser depositado\n";
                                                                cin >> deposito_c;
                                                                saldo_c=saldo_c+deposito_c;
                                                                cout << "Operacao efetuada com sucesso!\n";
                                                                cout << "Nome do cliente: " <<nome<< " " <<nome2<< ".\n";
                                                                cout << "Numero da conta: " <<numero_conta<< ".\n";
                                                                cout << "Conta: Comum.\n";
                                                                cout << "Novo saldo atual: R$" <<saldo_c<< ".\n"; 
                                                                     }
                                                             if (action3=='E' || action3=='e') {//ENCERRAR PROGRAMA
                                                                cout << "Cliente: " <<nome<< " " <<nome2<< ".\n";
                                                                cout << "Conta: Comum\n";
                                                                cout << "Saldo da conta: R$" <<saldo_c<< ".\n";
                                                                cout << "Numero da conta: " <<numero_conta<< ".\n";
                                                                system ("PAUSE");
                                                                return 0;
                                                                               }
                                                             }           
                                }
                       }              
    system("PAUSE");
    return 0;
}
