#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int i,j,n=0;
    cout << "Sao numeros primos(de 1 a 100):\n";
    for (i=1;i<=100;i++){
        for (j=1;j<=i;j++)
            if (i%j==0)
               n++;
        if (n==2)
           	cout <<i<< "\n";
        	n=0;
    }    
    system("PAUSE");
    return 0;
}
