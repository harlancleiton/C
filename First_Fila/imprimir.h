#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void imprimir (int &total, int &inicio, string fila[], int total_max){
	if (total!=0){
		total--;
		if (inicio==total_max-1){
			inicio=0;
			cout << "O seguinte arquivo foi imprimido com sucesso: " <<fila[total_max-1]<< ".\n";
		}
		else{
			inicio++;
			cout << "O seguinte arquivo foi imprimido com sucesso: " <<fila[inicio-1]<< ".\n";
		}
	}
	else
		cout << "Lista vazia.\n";
}