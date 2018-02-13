#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void adicionar (int total, int &fim, int total_max){
	if (total!=total_max && fim==total_max-1){
		fim=-1;
	}
}

void enviar_arq (string fila[], int &total, int inicio, int &fim, int total_max){
	if (total!=total_max){
		adicionar (total, fim, total_max);
		cout << "Digite o nome do arquivo " <<total+1<< ".\nArquivo: ";
		cin >> fila[fim+1];
		total++;
		fim++;
	}
	else
		cout << "Fila cheia.\n";
}