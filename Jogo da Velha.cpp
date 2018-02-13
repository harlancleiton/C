#include <iostream>
#include <string>
#include <cstdlib>
#define TAM 3

int zerarTabuleiro(int &tabuleiro[][TAM]){
	for (int i=0;i<TAM;i++)
		for (int j=0;j<TAM;j++)
			tabuleiro[i][j]=NULL;
	return tabuleiro;
}

void menu(char &action){
	cout << "1 - Jogar\n0 - Sair\n";
	cin >> action;
	while(action!='1' && action!='0'){
		cout << "Opcao invalida. Tente novamente: ";
		cin >> action;
	}
}

void jogarNovamente(char &action, int &tabuleiro[][TAM]){
	cout << "Jogar novamente?(S/N)\n";
	cin >> action;
	while(action!='S' && action!='s' && action!='N' && action!='n'){
		cout << "Opcao invalida. Tente novamente: ";
		cin >> action;
	}
	if(action=='S' || action=='s')
		limparTabuleiro(tabuleiro);
}

void exibir(int tabuleiro[][TAM]){
	for (int i=0;i<TAM;i++)
		for (int j=0;j<TAM;j++){
			if(tabuleiro[i][j]==NULL)
				cout << "\t";
			else if(tabuleiro[i][j]==1)
				cout << " X ";
			else
				cout << " O ";
			if(j!=TAM-1)
				cout << "|";
			if(i==1 || i==2)
				cout << "------------------";
		}
}


int main (){
	char action=' ';
	string jogadores[2];
	int tabuleiro[TAM][TAM];
	tabuleiro=zerarTabuleiro(tabuleiro);
	while(action!='N' || action!='n'){
		menu(action);
		iniciarJogo(tabuleiro, jogadores)
		jogarNovamente(action, tabuleiro);
	}
}