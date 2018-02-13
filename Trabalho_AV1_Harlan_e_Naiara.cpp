#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void menu (char &action){
	cout << "1 - REALIZAR PEDIDO\n2 - ENVIAR PEDIDOS PARA LINHA DE PRODUCAO\n3 - PRODUZIR BICICLETA\n4 - CONSULTAR PRODUCAO\n0 - SAIR\n";
	cin >> action;
	while (action!='1' && action!='2' && action!='3' && action!='4' && action!='0'){
		cout << "Opcao invalida, digite novamente.\n";
		cin >> action;
	}
}

void pedido (char action, int &total, int total_max, string lista[]){
	if (total!=total_max){
		cout << "Informe o tipo de bicicleta:\n1 - Convencional\n2 - Eletrica\nOpcao: ";
		cin >> action;
		while (action!='1' && action!='2'){
			cout << "Opcao invalida, digite novamente.\n";
			cin >> action;
		}
		if (action=='1')
			lista[total]="Convencional";
		else
			lista[total]="Eletrica";
		total++;
		cout << "Adicionado com sucesso.\n";
	}
	else
		cout << "Lista de pedidos cheia.\n";
}

void enviar_pedido (int &total, int &totalc, int &totale, int total_max, string lista[]){
	int aux[2]={0, 0};
	if (total!=0){
		if (totalc!=total_max && totale!=total_max){
			for (int i=0;i<total;i++){
				if (lista[i]=="Convencional")
					aux[0]++;
				else
					aux[1]++;
			}
			if (totalc+aux[0]>total_max ||totale+aux[1]>total_max)
				cout << "A lista nao tem capacidade para armazenar todos os pedidos. Produza mais bicicletas e tente novamente.\n";
			else if (totalc+aux[0]<=total_max ||totale+aux[1]<=total_max){
				totalc=totalc+aux[0];
				totale=totale+aux[1];
				total=0;
				cout << "Pedido concluido com sucesso.\n";
			}
		}
		else
			cout << "Lista(s) cheia(s).\n";
	}
	else
		cout << "Lista vazia.\n";
}

void produzindo (int &total, int &producao, string aux){
	int quant;
	cout << "Digite a quantidade a ser produzida.\n";
	cin >> quant;
	while (quant>total || quant<0){
		cout << "Valor digitado ultrapassa a quantidade de pedidos na lista ou o valor digitado e menor que 0.\nTente novamente: ";
		cin >> quant;
	}
	total=total-quant;
	producao=producao+quant;
	cout << "Foram produzidas " <<quant<< " bicicletas " <<aux<< ".\n";
}

void produzir (char action, int &totalc, int &totale, int &producaoc, int &producaoe){
	string aux;
	if (totalc!=0 || totale!=0){
		cout << "Digite o tipo de bicicleta a ser produzida:\n1 - Convencional\n2 - Eletrica\nOpcao: ";
		cin >> action;
		while (action!='1' && action!='2'){
			cout << "Opcao invalida, digite novamente.\n";
			cin >> action;
		}
		if (action=='1')
			produzindo (totalc, producaoc, aux="convencional");
		else
			produzindo (totale, producaoe, aux="eletrica");
	}
	else
		cout << "Lista vazia.\n";
}

void consultar (string lista[], int total, int totalc, int totale, int producaoc, int producaoe){
	int cont=0;
	cout << "Total de bicicletas na lista de pedidos: " <<total;
	for (int i=0; i<total; i++)
		if (lista[i]=="Convencional")
			cont++;
	cout << "(" <<cont<< " convencional, " <<total-cont<< " eletrica).\n";
	cout << "Bicicletas aguardando sererem produzidas: " <<totalc+totale<< "(" <<totalc<< " convencional, " <<totale<< " eletrica.\n";
	cout << "Total de bicicletas produzidas: " <<producaoc+producaoe<< "(" <<producaoc<< " convencional, " <<producaoe<< " eletrica).\n";
}

int main (){
	int total_max=10, total=0, totalc=0, totale=0, producaoc=0, producaoe=0;
	char action=' ';
	string lista[10];
	while (action!='0'){
        menu(action);
		if (action=='1')
			pedido(action, total, total_max, lista);
		else if (action=='2')
			enviar_pedido (total, totalc, totale, total_max, lista);
		else if (action=='3')
			produzir (action, totalc, totale, producaoc, producaoe);
		else if (action=='4')
			consultar (lista, total, totalc, totale, producaoc, producaoe);
		system ("PAUSE");
		system ("CLS");
	}
	return 0;
}
