#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
int n[11],x[11],cont=0,a=0;
	for(int i=1;i<=10;i++){
    	cout << "Digite o numero " <<i<< ".\n";
    	cin  >> n[i];
    }
    system ("CLS");
    cout << "Os numeros nao repetidos sao:\n";
    for(int i=1;i<=10;i++){
    	for(int j=1;j<=10;j++)
        	if(n[i]==n[j])
            	cont ++;
    	if(cont==1){
        	x[a]=n[i];
            a++;
    	}
    	cont=0;
    }
    for(int i=0;i<a;i++)
        cout << x[i] << " \n";
system("PAUSE");
return 0;
}

