#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include "enviar_arq .h"
#include "exibir.h"
#include "imprimir.h"
#include "iniciar.h"
#include "menu.h"

using namespace std;

int main (){
	int total, inicio, fim, total_max=5;
	string fila[5];
	char action=' ';
	iniciar (total, inicio, fim);
	while (action!='0'){
		menu (action);
		if (action=='1')
			enviar_arq (fila, total, inicio, fim, total_max);
		else if (action=='2')
			imprimir (total, inicio, fila, total_max);
		else if (action=='3')
			exibir (fila, inicio, fim, total, total_max);
		else if (action=='4'){
			if (total!=0){
				cout << "Fila limpa com sucesso.\n";
				iniciar (total, inicio, fim);
			}
			else
				cout << "Fila vazia.\n";
		}
		#ifdef WIN32
		system ("PAUSE");
		system ("CLS");
		#else
		cout << "Pressione ENTER para continuar..\n";
		getchar ();
		#endif
	}
	return 0;
}
