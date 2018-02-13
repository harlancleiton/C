#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>

using namespace std;

void pause () {
	#ifdef WIN32
	system ("PAUSE");
	#else
	cout << "Pressione ENTER para continuar..\n";
	getchar ();
	#endif
}

void limpatela (){
	#ifdef WIN32
	system ("CLS");
	#else
	system ("clear");
	#endif
}

void menu (char &action){
	cout << "1 - Incluir elemento na lista.\n2 - Exibir lista.\n3 - Modificar elemento da lista.\n4 - Excluir elemento da lista.\n5 - Pesquisar elemento da lista.\n6 - Limpar lista.\n0 - Sair.\n";
	cin >> action;
	while (action!='1' && action!='2' && action!='3' && action!='4' && action!='5' && action!='6' && action!='0'){
		cout << "Opcao invalida.\n";
		cin >> action;
		}
}

bool checar_duplicidade (char lista[], int total, char elemento){
	for (int i=0;i<total;i++)
			if (lista[i]==elemento)
				return true;
	return false;
}

void ordenar_lista(char lista[], int total, char elemento){
	int aux=0;
	while (elemento>lista[aux] && aux<total-1)
		aux++;
		for (int i=total-1;i>=aux;i--)
			lista[i+1]=lista[i];
		lista[aux]=elemento;
		total++;
}

void incluir_elemento (char lista[], int &total, int tam_max){
	char elemento;
	if (total!=tam_max){
		cout << "Digite o elemento a ser armazenado na posicao " <<total<< ".\n";
		cin >> elemento;
		if (checar_duplicidade(lista, total, elemento)==false){
			total++;
			cout << "O elemento " <<elemento<< " foi adicionado com sucesso.\n";
				ordenar_lista(lista, total, elemento);
		}
		else
			cout << "Esse elemento ja se encontra na lista.\n";
	}
	else{
		cout << "A lista se encontra cheia. Nao e possivel colocar mais nenhum elemento.\n";
	}
	pause();
}

void exibir_lista (char lista[], int total){
	if (total>0){
		cout << "ELEMENTOS DA LISTA\n";
		for (int i=0; i<total; i++)
			cout << "Posicao: " <<i<< "\tElemento: " <<lista[i]<< "\n";
	}
	else{
		cout << "Lista vazia.\n";
	}
	pause();
}

void limpar_lista (int &total){
	if (total!=0){
		total=0;
		cout << "Lista limpa com sucesso.\n";
	}
	else{
		cout << "Lista vazia.\n";
	}
	pause();
}

void operacao (string op, char &action){
	cout << "1 - " <<op<< " por elemento.\n2 - " <<op<< " por posicao.\n";
	cin >> action;
	while (action!='1' && action!='2'){
		cout << "Opcao invalida.\n";
		cin >> action;
	}
}

void pesquisar_elemento (char lista[], int total){
	char action, elemento;
	string op="Pesquisar";
	int aux=0;
	if (total!=0){
		operacao (op, action);
		if (action=='1'){
			cout << "Digite o elemento a ser pesquisado.\n";
			cin >> elemento;
			for (int i=0;i<total;i++){
				if (lista[i]==elemento){
					cout << "O elemento " <<elemento<< " foi encontrado na posicao " <<i<< " da lista.\n";
					aux++;
				}
				else if (i==total-1 && aux==0)
					cout << "Nao foi possivel encontrar o elemento na lista.\n";
			}
		}
		else {
			cout << "Digite a posicao a ser pesquisada.\n";
			cin >> aux;
			while (aux>total-1){
				cout << "Posicao a ser pesquisada ultrapassa o numero de elementos na lista. Tente novamente. (Valor maximo: " <<total-1<< ").\n";
				cin >> aux;
			}
			cout << "A posicao " <<aux<< " foi encontrada com sucesso na lista. Elemento encontrado: " <<lista[aux]<< ".\n";
		}
	}
	else{
		cout << "Lista vazia.\n";
	}
	pause();
}

void modificar_elemento (char lista[], int total){
	char action, elemento, aux2;
	string op="Modificar";
	int aux=1;
	if (total!=0){
		operacao (op, action);
		if (action=='1'){
			cout << "Digite o elemento a ser modificado.\n";
			cin >> elemento;
			for (int i=0;i<total;i++){
				if (lista[i]==elemento){
					cout << "O elemento " <<elemento<< " foi encontrado na posicao " <<i<< " da lista.\nDigite o novo elemento.\n";
					aux=0;
					cin >> aux2;
					if (checar_duplicidade(lista, total, aux2)==false){
						lista[i]=aux2;
						cout << "O elemento foi modificado com sucesso.\n";
					}
					else
						cout << "Esse elemento ja se encontra na lista.\n";
				}
				else if (i==total-1 && aux==1)
					cout << "Nao foi possivel encontrar o elemento na lista.\n";
			}
		}
		else{
			cout << "Digite a posicao a ser modificada.\n";
			cin >> aux;
			while (aux>total-1){
				cout << "Posicao a ser pesquisada ultrapassa o numero de elementos na lista. Tente novamente. (Valor maximo: " <<total-1<< ").\n";
				cin >> aux;
			}
			cout << "Na posicao " <<aux<< " encontra-se o elemento " <<lista[aux]<< ", digite o elemento que deve substitui-lo.\n";
			cin >> aux2;
			if (checar_duplicidade(lista, total, aux2)==false){
				lista[aux]=aux2;
				cout << "O elemento foi modificado com sucesso.\n";
			}
			else
				cout << "Esse elemento ja se encontra na lista.\n";
		}
	}
	else{
		cout << "Lista vazia.\n";
	}
	pause();
}

bool pesquisar_elemento2 (char lista[], int total, char aux, char action, int &n){
	int i;
	if (action=='1')
		for (i=0;i<total;i++)
			if (lista[i]==aux){
				cout << "O elemento " <<aux<< " foi encontrado na posicao " <<i<< " da lista.\n";
				n=i;
				return true;
			}
		if (n!=i)
			return false;
	else{
		while (n>total-1){
			cout << "Posicao a ser pesquisada ultrapassa o numero de elementos na lista. Tente novamente. (Valor maximo: " <<total-1<< ").\n";
			cin >> n;
		}
		cout << "Na posicao " <<n<< " encontra-se o elemento " <<lista[n]<< ".\n";
		return true;
	}
	return true;
}

void excluindo (char lista[], int &total, int n){
	for (int i=n;i<total;i++){
		lista[i]=lista[i+1];
	}
	cout << "Elemento excluido com sucesso.\n";
}

void excluir_elemento(char lista[], int &total){
	char action, aux=' ';
	int n;
	string op="Excluir";
	if (total!=0){
		operacao (op, action);
		if (action=='1'){
			cout << "Digite o elemento a ser excluido.\n";
			cin >> aux;
			if (pesquisar_elemento2 (lista, total, aux, action, n)==true)
				excluindo (lista, total, n);
			else
				cout << "Elemento nao encontrado.\n";
		}
		else{
			cout << "Digite a posicao do elemento a ser excluido.\n";
			cin >> n;
			pesquisar_elemento2 (lista, total, aux, action, n);
			excluindo (lista, total, n);
		}
	}
	else{
	cout << "Lista vazia.\n";
	}
	pause();
}

int main (){
	char lista[5], action=' ';
	int total=0, tam_max=5;
	while (action!='0'){
		limpatela();
		menu(action);
		if (action=='1')
			incluir_elemento(lista, total, tam_max);
		else if (action=='2')
			exibir_lista(lista, total);
		else if (action=='3')
			modificar_elemento (lista, total);
		else if (action=='4')
			excluir_elemento(lista, total);
		else if (action=='5')
			pesquisar_elemento(lista, total);
		else if (action=='6')
			limpar_lista(total);
	}
	pause();
	return 0;
}
