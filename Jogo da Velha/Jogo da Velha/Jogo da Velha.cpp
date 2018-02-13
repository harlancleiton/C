#include <iostream>
#include <string>
#include <cstdlib>
#define TAM 3

using namespace std;

void limparTela(){
	system("PAUSE");
	system("CLS");
}

void limparTabuleiro(int tabuleiro[][TAM], int contJogadas[]){
	for (int i=0;i<2;i++)
		contJogadas[i]=0;
	for (int i=0;i<TAM;i++)
		for (int j=0;j<TAM;j++)
			tabuleiro[i][j]=NULL;
}

void menu(char &action){
	cout << "1 - Jogar\n0 - Sair\n";
	cin >> action;
	while(action!='1' && action!='0'){
		cout << "Opcao invalida. Tente novamente: ";
		cin >> action;
	}
}

void jogarNovamente(char &action){
	cout << "Jogar novamente?(S/N)\n";
	cin >> action;
	while(action!='S' && action!='s' && action!='N' && action!='n'){
		cout << "Opcao invalida. Tente novamente: ";
		cin >> action;
	}
}

void exibir(int tabuleiro[][TAM]){
	limparTela();
	for (int i=0;i<TAM;i++){
		for (int j=0;j<TAM;j++){
			if(tabuleiro[i][j]==NULL)
				cout << "     ";
			else if(tabuleiro[i][j]==1)
				cout << "  X  ";
			else
				cout << "  O  ";
			if(j!=TAM-1)
				cout << "|";
		}
		cout << "\n";
	}
}

int checarTabuleiro(int tabuleiro[][TAM]){
	for(int i=0;i<TAM;i++){
		if((tabuleiro[i][0]==1 && tabuleiro[i][1]==1 && tabuleiro[i][2]==1) || (tabuleiro[i][0]==2 && tabuleiro[i][1]==2 && tabuleiro[i][2]==2)){
			if(tabuleiro[i][0]==1)
				return 1;
			else if(tabuleiro[i][0]==2)
				return 2;
		}
	}
	for(int i=0;i<TAM;i++){
		if((tabuleiro[0][i]==1 && tabuleiro[1][i]==1 && tabuleiro[2][i]==1) || (tabuleiro[0][i]==2 && tabuleiro[1][i]==2 && tabuleiro[2][i]==2)){
			if(tabuleiro[i][0]==1)
				return 1;
			else if(tabuleiro[i][0]==2)
				return 2;
		}
	}
	if ((tabuleiro[0][0]==1 && tabuleiro[1][1]==1 && tabuleiro[2][2]==1) || (tabuleiro[0][2]==1 && tabuleiro[1][1]==1 && tabuleiro[2][0]==1) || (tabuleiro[0][0]==2 && tabuleiro[1][1]==2 && tabuleiro[2][2]==2) || (tabuleiro[0][2]==2 && tabuleiro[1][1]==2 && tabuleiro[2][0]==2)){
		if(tabuleiro[0][0]==1)
			return 1;
		else if(tabuleiro[0][0]==2)
			return 2;
	}
	return 0;
}

bool checarJogada(int tabuleiro[][TAM], int aux[]){
	if (tabuleiro[aux[0]][aux[1]]==NULL)
		return true;
	else
		return false;
}

void jogada (int tabuleiro[][TAM], string jogadores[], int contJogadas[], char &vez){
	int aux[2];
	cout << "Jogador " <<vez<< ": ";
		if (vez=='1')
			cout << "X\nLinha: ";
		else
			cout << "O\nLinha: ";
	cin >> aux[0];
	aux[0]--;
	cout << "Jogador " <<vez<< ": ";
	if (vez=='1')
			cout << "X\nColuna: ";
		else
			cout << "O\nColuna: ";
	cin >> aux[1];
	aux[1]--;
	while(checarJogada(tabuleiro, aux)==false){
		cout << "Jogada invalida, tente novamente.\nLinha: ";
		cin >> aux[0];
		aux[0]--;
		cout << "Coluna: ";
		cin >> aux[1];
		aux[1]--;
	}
	if(vez=='1'){
		tabuleiro[aux[0]][aux[1]]=1;
		contJogadas[0]++;
		vez='2';
	}
	else{
		tabuleiro[aux[0]][aux[1]]=2;
		contJogadas[1]++;
		vez='1';
	}
}

void iniciarJogo(int tabuleiro[][TAM], string jogadores[], int contJogadas[]){
	char vez='1';
	int aux;
	limparTabuleiro(tabuleiro, contJogadas);
	for (int i=0;i<2;i++){
		cout << "Digite o nome do jogador " <<i+1<< ".\nJogador " <<i+1<< ":";
		cin>> jogadores[i];
	}
	limparTela();
	cout << "Jogador 1: "<<jogadores[0]<< ": X\nJogador 2: " <<jogadores[1]<< ": O\n\nO JOGO IRA COMECAR!!\n";
	while(contJogadas[0]+contJogadas[1]<9){
		exibir(tabuleiro);
		jogada(tabuleiro, jogadores, contJogadas, vez);
		if (checarTabuleiro(tabuleiro)!=0){
			aux=checarTabuleiro(tabuleiro);
			exibir(tabuleiro);
			cout << "Jogador " <<aux<< " venceu!.\n";
			break;
		}
	}
}

int main (){
	char action=' ';
	string jogadores[2];
	int tabuleiro[TAM][TAM], contJogadas[2];
	//limparTabuleiro(tabuleiro, contJogadas);
	while(action!='N' && action!='n' && action!='0'){
		menu(action);
		limparTabuleiro(tabuleiro, contJogadas);
		exibir(tabuleiro);
		iniciarJogo(tabuleiro, jogadores, contJogadas);
		if(action!='0')
			jogarNovamente(action);
		limparTela();
	}
}