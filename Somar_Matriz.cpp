#include <iostream>
#include <cstdlib>

using namespace std;
float somar (float i, float j)
{
	return i+j;
}

int main()
{
	float n[4][3],soma=0;
	for (int i=1;i<=3;i++){
		for (int j=1;j<=2;j++){
			cout << "Digite o valor do vetor posicao "<<i<<", "<<j<<".\n";
			cin >> n[i][j];
			soma=somar(soma,n[i][j]);
		}
	}
	cout << "Vetor soma="<<soma<<".\n";
	system ("PAUSE");
	return 0;
}
