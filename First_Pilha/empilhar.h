#include "includes.h"

void empilhar (string pilha[], int &total, int total_max){
	if (total!=total_max){
		cout << "Digite o elemento " <<total+1<< ".\n";
		cin >> pilha[total];
		total++;
	}
	else
		cout << "Pilha cheia.\n";
}