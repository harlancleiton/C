#include "includes.h"

void desempilhar (string pilha[], int &total, int total_max){
	char action;
	if (total!=0){
		cout << "O seguinte elemento sera excluido: " <<pilha[total-1]<< ". Deseja continuar?(S/N)\n";
		cin >> action;
		while (action!='S' && action!='s' && action!='N' && action!='n'){
			cout << "Opcao invalida.\nTemte novamente: ";
			cin >> action;
		}
		if (action=='S' || action =='s'){
			total--;
			cout << "Elemento excluido com sucesso.\n";
		}
		else
			cout << "Cancelado pelo usuario.\n";
	}
	else
		cout << "Pilha vazia.\n";
}