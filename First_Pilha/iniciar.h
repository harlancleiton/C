#include "includes.h"

void iniciar (int &total){
	if (total>0 && total<=5){
		total=0;
		cout << "Lista limpa com sucesso.\n";
	}
	else if (total==0)
		cout << "Lista vazia.\n";
	else
		total=0;
}