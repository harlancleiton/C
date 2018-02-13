#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int aviao[11][5],aux[4],valortotal=0;
	char action;
	for (int i=1;i<=10;i++){
		for (int j=1;j<=4;j++){
			aviao[i][j]=0;
		}
	}
	while (action!='4'){
	cout << "\tESTADO DAS POLTRONAS\n";
	cout << "    1 | 2 | 3 | 4\n--------\n";
	for (int i=1;i<=10;i++){
		cout <<i<< " | ";
		for (int j=1;j<=4;j++){
			cout <<aviao[i][j]<< "   ";
			if (j==4){
				cout << "\n";
			}
		}
	}
	cout << "\n1 - Ocupado\n0 - Vazio\n";
	cout << "\n\t\tTABELA DE PRECOS\n";
	cout << "  FILEIRA   |   CLASSE  | VALOR(R$)\n";
	cout << "1 -  1 a 2  | 1a classe |  700,00\n";
	cout << "2 -  3 a 5  | executiva |  500,00\n";
	cout << "3 -  6 a 10 | economica |  300,00\n";
	cout << "4 - Sair\n";
	cout << "Escolha a classe desejada.\nOpcao: ";
	cin >> action;
	while (action!='1' && action!='2' && action!='3' && action!='4'){
	cout << "Opcao invalida.\n";
	cin >> action;
	}
	if (action!='4'){
	if (action=='1'){
		cout << "Primeira classe escolhida! Favor escolher onde sentar.(1/2/3/4)\n";
		aux[1]=1;
		aux[2]=2;
		aux[3]=700;
		cin >> aux[4];
	}
	else if (action=='2'){
		cout << "Classe executiva escolhida! Favor escolher onde sentar.(1/2/3/4)\n";
		aux[1]=3;
		aux[2]=5;
		aux[3]=500;
		cin >> aux[4];
	}
	else {
		cout << "Classe economica escolhida! Favor escolher onde sentar.(1/2/3/4)\n";
		aux[1]=6;
		aux[2]=10;
		aux[3]=300;
		cin >> aux[4];
	}
	while (aux[4]!=1 && aux[4]!=2 && aux[4]!=3 && aux[4]!=4){
		cout << "Opcao invalida\nEscolha onde sentar. ";
		cin >> aux[4];
	}
	for (int i=aux[1];i<=aux[2];i++){
		if (aviao[i][aux[4]]==0){
			cout << "Passagem comprada com sucesso, sua poltrona e a fileira " <<i<< ", coluna " <<aux[4]<< "\n";
			aviao[i][aux[4]]=1;
			i=aux[2];
			valortotal=valortotal+aux[3];
			system ("PAUSE");
		}
		else if (aviao[aux[2]][aux[4]]==1){
					cout << "Infelizmente nao temos mais assentos vagos para essa classe ou coluna.\nTente novamente para outra classe ou coluna.\n";
					system ("PAUSE");
					i=aux[2];
				}
	}
	}
	}
	aux[1]=0;
	for (int i=1;i<=10;i++){
		for (int j=1;j<=4;j++){
			if (aviao[i][j]==1){
				aux[1]++;
			}
		}
	}
	system ("CLS");
	cout << "Venda do dia: R$ " <<valortotal<<".\nPassagens vendidas: " <<aux[1]<< ".\n\n";
	cout << "\tESTADO DAS POLTRONAS\n";
	cout << "    1 | 2 | 3 | 4\n--------\n";
	for (int i=1;i<=10;i++){
		cout <<i<< " | ";
		for (int j=1;j<=4;j++){
			cout <<aviao[i][j]<< "   ";
			if (j==4){
				cout << "\n";
			}
		}
	}
	system ("PAUSE");
	return 0;
}
