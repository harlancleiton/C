#include <iostream>
#include <cstdlib>

using namespace std;

float somar(float i,int j)
{
	return i+j;
}

int main()
{
	float n[7],soma=0;
	for (int i=1;i<=6;i++){
		cout << "Digite um numero real para o vetor " <<i<< ".\n";
		cin >> n[i];
		soma=somar(soma,n[i]);
	}
	cout << "Vetor soma=" <<soma<< ".\n";
	system ("PAUSE");
	return 0;
}
