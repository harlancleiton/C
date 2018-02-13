#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{   char action1,action2;
    float valortotal=0,valor=0,dinheiro=0,troco;
    int q;
    while(action2=='N' || action2!='n'){ //WHILE DO PROGRAMA
    cout << "Bem vindo ao Fast Food Estacio!\nPor favor, escolha o item desejado.\n\n";
    while (action1!='4'){ //WHILE DA COMPRA
    cout << "-------------------------------------------------------------------\n";
    cout << " OPCAO |    PROMOCAO    |           DESCRICAO            | PRECO(R$)\n";
    cout << "-------------------------------------------------------------------\n";
    cout << "   1   | Big Super      | 2 hamburgueres, queijo, batata | 5,00\n";
    cout << "       |                | frita e refrigerante           |\n";
    cout << "-------------------------------------------------------------------\n";
    cout << "   2   | Quase Super    | 1 hamburguer, batata frita e   | 3,00\n";
    cout << "       |                | refrigerante                   |\n";
    cout << "-------------------------------------------------------------------\n";
    cout << "   3   | Promocao Misto | 1 misto quente e refrigerante  | 1,50\n";
    cout << "-------------------------------------------------------------------\n";
    cout << "   4   | Sair e exibir  |                                |\n";
    cout << "       | total          |                                |\n";
    cout << "-------------------------------------------------------------------\n\n";
    cin >> action1;
		  while (action1!='1' && action1!='2' && action1!='3' && action1!='4') { //CASO NAO SEJA SELECIONADO NENHUM ITEM DO MENU
			cout << "Opcao invalida!\nEscolha uma opcao valida.\n";
			cin >> action1;
			}
    	  if (action1=='4' && valortotal==0){ //CASO SAIA SEM COMPRAR NADA
    	  	cout << "Nenhum item foi comprado!\nPrograma sendo encerrado..\n";
    	  	system ("PAUSE");
    	  	return 0;
    	  	}
    	  if (action1!='4'){//QUANTIDADE
		  cout << "Digite a quantidade de itens.\n";
    	  cin >> q;
    	  	}
    	  	//PARTE DOS CALCULOS
          if (action1=='1'){
                           valor=5.00;
                           valortotal=valortotal+valor*q;
            }
          else if (action1=='2'){
                valor=3.00;
                valortotal=valortotal+valor*q;
            }
          else if (action1=='3'){
                valor=1.50;
                valortotal=valortotal+valor*q;
			}
	system ("CLS"); //LIMPAR TELA
    }
			//VALOR
          	cout << "Valor a ser pago: R$" <<valortotal<< ".\nDigite a quantia dada em dinheiro.\n";
          	cin >> dinheiro;
          	troco=dinheiro-valortotal;
          	while (troco<0){ //SE PAGAR MENOS DO QUE O TOTAL
                cout << "Quantia dada e menor do que o valor a ser pago!\n";
                cout << "O valor a ser pago e: R$ " <<valortotal<< ".\nDigite a quantia dada em dinheiro.\n";
                cin >> dinheiro;
                troco=dinheiro-valortotal;
                		   }
          system ("CLS");
		  //EXTRATO
          cout << "Valor a ser pago: R$ " <<valortotal<< ".\n";
          cout << "Dinheiro: R$ " <<dinheiro<< ".\n";
          cout << "Troco: R$ " <<troco<< ".\n";
          cout << "O Fast Food Estacio agrarece pela preferencia!\nVolte sempre!\n\n";
          cout << "Reninciar aplicativo?(S/N)\n";
          cin >> action2;
          while (action2!='S' && action2!='s' && action2!='N' && action2!='n'){ //SE NAO SELECIONAR NENHUMA OPCAO VALIDA
          	cout << "Opcao invalida.\nDeseja reninciar o aplicativo?(S/N)\n";
          	cin >> action2;
          }
          if (action2=='S' || action2=='s'){ //ZERAR VALORES PARA RENINCIAR O PROGRAMA
		  system ("CLS");
		  action1='0';
		  valor=0;
		  q=0;
		  valortotal=0;
          }
      }
    return 0;
}
