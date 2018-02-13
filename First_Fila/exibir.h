#include <iostream>
#include <cstdlib>
#include <string>

void exibir (string fila[], int inicio, int fim, int total, int total_max){
	if (total!=0){
		cout << "Arquivos na fila de impressao:\n";
		if (inicio<=fim)
			for (int i=inicio; i<=fim; i++)
			cout <<fila[i]<< "\n";
		else
			if (fim<total_max-1){
				for (int i=inicio; i<=total_max-1; i++)
					cout <<fila[i]<< "\n";
				for (int i=0;i<=fim;i++)
					cout <<fila[i]<< "\n";
			}
	}
	else
		cout << "Fila vazia.\n";
}