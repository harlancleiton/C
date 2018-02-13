#include <iostream>
#include <stdlib.h>

using namespace std;

int fat(int numero)
{
	int fatorial=1;
	for (int i=numero;i>1;i--){
		fatorial=fatorial*i;
	}
	return fatorial;
}

int main()
{
	int numero,fatorial;
	for (numero=1;numero<=8;numero++){
		fatorial=fat(numero);
		cout << "O fatorial de "<<numero<<"="<<fatorial<<".\n";
	}
	system ("PAUSE");
	return 0;
}
