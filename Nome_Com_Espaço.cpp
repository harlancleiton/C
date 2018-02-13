#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int main()
{
	char nome[2][50]; //vetor de char var[x]
	for (int i=0;i<=1;i++){
	cout << "Como se chama?\nNome : ";
	gets (nome[i]); //funcao para ler vetores como unica variavel, ex: 'n','o','m','e',' ','c','o','m',' ','e','s','p','a','c','o'
	cout << "Oi, " <<nome[i]<< ".\n";
	}
	#ifdef WIN32
	system ("PAUSE");
	#endif
	return 0;
}
