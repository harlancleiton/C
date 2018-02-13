#include "includes.h"
#include "iniciar.h"
#include "menu.h"
#include "empilhar.h"
#include "desempilhar.h"
#include "exibir.h"

int main (){
	int total, total_max=5;
	string pilha[5];
	char action=' ';
	iniciar(total);
	while (action!='0'){
		menu (action);
		if (action=='1')
			empilhar (pilha, total, total_max);
		else if (action=='2')
			desempilhar (pilha, total, total_max);
		else if (action=='3')
			exibir (pilha, total, total_max);
		else if (action=='4'){
			iniciar (total);
		}
		system ("PAUSE");
		system ("CLS");
	}
}