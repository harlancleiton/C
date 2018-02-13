#include <iostream>
#include <cstdlib>

using namespace std;

float potencia (float i,float j)
{
	float resultado=1;
	for (int x=j;x>=1;x--){
		resultado=resultado*i;
	}
	return resultado;
}

int main()
{
	float base, expoente,resultado;
	cout << "Digite o numero que esta na base da potencia.\nBase: ";
	cin >> base;
	cout << "Agora digite o expoente da potencia.\nExpoente: ";
	cin >> expoente;
	resultado=potencia(base,expoente);
	cout << "A potencia de "<<expoente<< " na base " <<base<< " e " <<resultado<<".\n";
	system ("PAUSE");
	return 0;
}
