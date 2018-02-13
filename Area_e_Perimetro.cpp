#include <iostream>
#include <cstdlib>

using namespace std;

float perimetro(float i,float j)
{
	return 2*i+2*j;
}

float area(float i,float j)
{
	return i*j;
}

int main()
{
	float l1,l2;
	cout << "Digite o comprimeto do retangulo.(cm)\nComprimetro: ";
	cin >> l1;
	cout << "Digite a altura do retangulo.(cm)\nAltura: ";
	cin >> l2;
	cout << "Perimetro: " <<perimetro(l1,l2)<< ".\nArea: " <<area(l1,l2)<<".\n";
	system ("PAUSE");
	return 0;
}
