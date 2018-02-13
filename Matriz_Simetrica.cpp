#include <stdlib.h>
#include <iostream>

using namespace std;

int matriz_funcao (int aux, int aux2)
{
	int aux3=0;
	if (aux==aux2) {
		aux3++;
	}
	return aux3;
}

int main()
{
	float matriz[4][4], aux;
	for (int i=1;i<=3;i++){
		for (int j=1;j<=3;j++){
			cout << "Digite o valor da linha " <<i<< " coluna " <<j<< ".\n";
			cin >> matriz[i][j];
		}
	}
	for (int i=1;i<=3;i++){
		for (int j=1;j<=3;j++){
			aux=aux+matriz_funcao(matriz[i][j], matriz[j][i]);
		}
	}
	if (aux==9){
		cout << "A matriz e simetrica.\n";
	}
	#ifdef WIN32
	system ("PAUSE");
	#endif
	return 0;
}
