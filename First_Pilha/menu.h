#include "includes.h"

void menu (char &action){
	cout << "1 - Empilhar elemento\n2 - Desempilhar elemento\n3 - Exibir pilha\n4 - Limpar pilha\n0 - Sair\nOpcao:";
	cin >> action;
	while (action!='1' && action!='2' && action!='3' && action!='4' && action!='0'){
		cout << "Opcao invalida.\nTemte novamente: ";
		cin >> action;
	}
}