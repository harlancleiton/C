#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int n[6],aux;
	for (int i=1;i<=5;i++){
		cout << "Digite o numero " <<i<< ".\n";
		cin >> n[i];
	}
	for (int i=1;i<=5;i++){
		for (int j=i+1;j<=5;j++){
			if (n[i]>n[j]){
				aux=n[i];
				n[i]=n[j];
				n[j]=aux;
			}	
		}
	}
	for (int i=1;i<=5;i++){
		cout <<n[i]<< "\n";
	}
	system ("PAUSE");
	return 0;
}
