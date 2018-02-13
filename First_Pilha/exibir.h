#include "includes.h"

void exibir (string pilha[], int total, int total_max){
	if (total!=0){
		cout << "Elementos na pilha:\n";
		for (int i=total-1;i>=0;i--)
			cout <<i+1<< " - " <<pilha[i]<< "\n";
	}
	else
		cout << "Lista vazia.\n";
}