#include <cstdlib>
#include <iostream>

using namespace std;

int main(void)
{
	string cid[6];
	int pop[6],total=0;
	float media;
	for (int i=1;i<=5;i++){
		cout << "Digite o nome da cidade " <<i<< ".\n";
		cin >> cid[i];
		for (int j=1;j<=5;j++){
			if (i!=j){
			while (cid[i]==cid[j]){
				cout << "Cidade ja cadastrada. Digite um nome valido para a cidade " <<i<< ".\n";
				cin >> cid[i];
			}
			}
		}
		cout << "Digite a populacao da cidade " <<i<< ".\n";
		cin >> pop[i];
		while (pop[i]<0){
			cout << "Populacao invalida!\nDigite a populacao correta de " <<cid[i]<< ".\n";
			cin >> pop[i];
		}
		total=total+pop[i];
	}
	system ("CLS");
	for (int i=1;i<=5;i++){
		cout << "Cidade: " <<cid[i]<< "\tPopulacao: " <<pop[i]<< ".\n";
	}
	media=total/5;
	cout << "A media populacional das 5 cidades e " <<media<< ".\n";
	for (int i=1;i<=5;i++){
		if (pop[i]>media){
			cout << "A cidade " <<cid[i]<< " tem populacao maior que a media das 5 cidades.("<<pop[i]<<").\n";
		}
	}
	system ("PAUSE");
	return 0;
}
