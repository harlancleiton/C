o#include <stdlib.h>
#include <iostream>

using namespace std;

int somar(int x,int y){
	x+y;
	return x+y;
}

int main()
{
	int a,b,c;
	cout << "Digite o valor de A.\nA: ";
	cin >> a;
	cout << "Digite o valor de B.\nB: ";
	cin >> b;
	c=somar(a,b);
	cout <<a<<"+"<<b<<"="<<c<< ".\n";
	system ("PAUSE");
	return 0;
}
