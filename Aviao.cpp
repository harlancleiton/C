#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int ce[10],cd[10],je[10],jd[10],valortotal=0,aux[3];
	string vetor;
	char action;
	for (int i=1;i<=10;i++){
		ce[i]=0;
		cd[i]=0;
		je[i]=0;
		jd[i]=0;
	}
	while (action!='4'){
	cout << "\t\tESTADO DAS POLTRONAS\n";
	cout << "    JE   CE   CD   JD\n\n";
	for (int i=1;i<=10;i++){
	cout <<i<< " | " <<je[i]<<"  | "<<ce[i]<<"  | "<<cd[i]<<"  | "<<jd[i]<<"\n";
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
	if (action=='1'){
		cout << "Primeira classe escolhida! Favor escolher onde sentar.(JE/CE/CD/JD)\n";
		aux[1]=1;
		aux[2]=2;
		aux[3]=700;
		cin >> vetor;
	}
	else if (action=='2'){
		cout << "Classe executiva escolhida! Favor escolher onde sentar.(JE/CE/CD/JD)\n";
		aux[1]=3;
		aux[2]=5;
		aux[3]=500;
		cin >> vetor;
	}
	else if (action=='3'){
		cout << "Classe economica escolhida! Favor escolher onde sentar.(JE/CE/CD/JD)\n";
		aux[1]=6;
		aux[2]=10;
		aux[3]=300;
		cin >> vetor;
	}
		if(action!='4'){
		while (vetor!="JE" && vetor!="je" && vetor!="CE" && vetor!="ce" && vetor!="CD" && vetor!="cd" && vetor!="JD" && vetor!="jd"){
			cout << "Opcao invalida\nEscolha onde sentar. ";
			cin >> vetor;
		}
		for (int i=aux[1];i<=aux[2];i++){
			if (vetor=="JE" || vetor=="je"){
				if (je[i]==0){
					cout << "Passagem comprada com sucesso, sua poltrona e a numero " <<i<< ", JE\n";
					je[i]=1;
					i=aux[2];
					valortotal=valortotal+aux[3];
					system ("PAUSE");
				}
				else if (je[aux[2]]==1){
					cout << "Infelizmente nao temos mais assentos vagos para essa classe ou coluna.\nTente novamente para outra classe ou coluna.\n";
					system ("PAUSE");
					i=aux[2];
				}
			}
			if (vetor=="CE" || vetor=="ce"){
				if (ce[i]==0){
					cout << "Passagem comprada com sucesso, sua poltrona e a numero " <<i<< ", CE\n";
					ce[i]=1;
					i=aux[2];
					valortotal=valortotal+aux[3];
					system ("PAUSE");
				}
				else if (ce[aux[2]]==1){
					cout << "Infelizmente nao temos mais assentos vagos para essa classe ou coluna.\nTente novamente para contra classe ou coluna.\n";
					system ("PAUSE");
					i=aux[2];
				}
			}
			if (vetor=="CD" || vetor=="cd"){
				if (cd[i]==0){
					cout << "Passagem comprada com sucesso, sua poltrona e a numero " <<i<< ", CD\n";
					cd[i]=1;
					i=aux[2];
					valortotal=valortotal+aux[3];
					system ("PAUSE");
				}
				else if (cd[aux[2]]==1){
					cout << "Infelizmente nao temos mais assentos vagos para essa classe ou coluna.\nTente novamente para contra classe ou coluna.\n";
					system ("PAUSE");
					i=aux[2];
				}
			}
			if (vetor=="JD" || vetor=="jd"){
				if (jd[i]==0){
					cout << "Passagem comprada com sucesso, sua poltrona e a numero " <<i<< ", JD\n";
					jd[i]=1;
					i=aux[2];
					valortotal=valortotal+aux[3];
					system ("PAUSE");
				}
				else if (jd[aux[2]]==1){
					cout << "Infelizmente nao temos mais assentos vagos para essa classe ou coluna.\nTente novamente para contra classe ou coluna.\n";
					system ("PAUSE");
					i=aux[2];
				}
			}
		}
	}
	system ("CLS");
	}
	aux[1]=0;
	for (int i=1;i<=10;i++){
		if(je[i]==1){
			aux[1]++;
		}
		if(ce[i]==1){
			aux[1]++;
		}
		if(cd[i]==1){
			aux[1]++;
		}
		if(jd[i]==1){
			aux[1]++;
		}
	}
	cout << "Venda do dia: R$ " <<valortotal<<".\nPassagens vendidas: " <<aux[1]<< ".\n\n";
	cout << "\t\tESTADO DAS POLTRONAS\n";
	cout << "    JE   CE   CD   JD\n\n";
	for (int i=1;i<=10;i++){
	cout <<i<< " | " <<je[i]<<"  | "<<ce[i]<<"  | "<<cd[i]<<"  | "<<jd[i]<<"\n";
	}
	system ("PAUSE");
	return 0;
}
