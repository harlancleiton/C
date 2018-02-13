#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct caixa{
	int cep, total;
};

struct lista{
	caixa caixas;
	lista *prox;
};

lista *checarTotal(lista *pontL, lista *pontP, int aux){
	pontP=pontL;
	while (pontP->prox!=NULL && pontP->caixas.cep!=aux)
		pontP=pontP->prox;
	if (pontP->caixas.total>=100){
		pontP->caixas.total=0;
		cout << "Valor de correspondencias atingiu/ultrapassou o limite. As correspondencias foram enviadas automaticamente. Novo total: " <<pontP->caixas.total<< ".\n";
	}
	return pontP;
}

lista *desativarCep (lista *pontL){
	int aux;
	lista *pontP, *pont;
	pontP=pontL;
	if (pontL!=NULL){
		cout << "Digite o CEP a ser desativado.\n";
		cin >> aux;
		if (pontL->caixas.cep==aux){
			if (pontL->caixas.total>0){
			cout << "Ainda existe correspondencias no CEP informado, elas serao enviadas automaticamente.\n";
			pontL->caixas.total=0;
			}
			if (pontL->prox==NULL)
				pontL=NULL;
			else{
				pontP=pontL;
				pontL=pontL->prox;
				delete pontP;
			}
			cout << "O CEP foi desativado com sucesso.\n";
		}
		else{
			pontP=pontL;
			while (pontP->prox!=NULL && pontP->prox->caixas.cep!=aux)
				pontP=pontP->prox;
			if (pontP->prox!=NULL){
				if (pontP->caixas.total>0){
					cout << "Ainda existe correspondencias no CEP informado, elas serao enviadas automaticamente.\n";
					pontP->prox->caixas.total=0;
				}
				pont=pontP->prox;
				pontP->prox=pont->prox;
				delete pont;
				cout << "O CEP foi desativado com sucesso.\n";
			}
			else
				cout << "CEP nao cadastrado.\n";
		}
	}
	else
		cout << "Lista vazia.\n";
	return pontL;
}

lista *incluirCep (lista *pontL, int cep2){
	lista *pontN, *pontP;
	pontN=new lista;
	pontN->caixas.cep=cep2;
	pontN->caixas.total=0;
	pontN->prox=NULL;
	if (pontL==NULL)
		pontL=pontN;
	else{
		pontP=pontL;
		while (pontP->prox!=NULL)
			pontP=pontP->prox;
		pontP->prox=pontN;
	}
	cout << "O CEP " <<pontN->caixas.cep<< " foi cadastrado com sucesso.\n";
	return pontL;
}

lista *enviando (lista *pontP, string op){
	int aux;
	cout << "Digite a quantidade de correspondencias a serem enviadas " <<op<< " CEP " <<pontP->caixas.cep<< ".\n";
		cin >> aux;
		if (op=="do"){
			while (aux>pontP->caixas.total){
				cout << "Valor digitado ultrapassa o valor maximo possivel de "<<pontP->caixas.total<<". \nDigite novamente: ";
				cin >> aux;
			}
			pontP->caixas.total=pontP->caixas.total-aux;
		}
		else
			pontP->caixas.total=pontP->caixas.total+aux;
		cout << "Correspondencias enviadas com sucesso.\nTotal de correspondencias na caixa " <<pontP->caixas.cep<< ": " <<pontP->caixas.total<< ".\n";
	return pontP;
}

lista *enviarCep (lista *pontL){
	int aux;
	string op="para o";
	char action;
	lista *pontP;
	if (pontL==NULL){
		cout << "Nenhum CEP cadastrado, deseja cadastrar um CEP agora? (S/N)\n";
		cin >> action;
		if (action=='S' || action=='s'){
			cout << "Digite o CEP a ser cadastrado.\n";
			cin >> aux;
			pontL=incluirCep (pontL, aux);
			pontP=pontL;
			while (pontP->prox!=NULL && pontP->caixas.cep!=aux)
				pontP=pontP->prox;
			pontP=enviando(pontP, op);
			pontP=checarTotal(pontL, pontP, aux);
		}
		else
			cout << "Operacao cancelada pelo usuario.\n";
	}
	else {
		cout << "Informe o CEP: ";
		cin >> aux;
		pontP=pontL;
		while (pontP->prox!=NULL && pontP->caixas.cep!=aux)
			pontP=pontP->prox;
		if (pontP->caixas.cep==aux){
			cout << "CEP encontrado com sucesso.\n";
			pontP=enviando(pontP, op);
			pontP=checarTotal(pontL, pontP, aux);
		}
		else{
			cout << "O CEP informado nao esta na lista. Deseja cadastrar o CEP agora? (S/N)\n";
			cin >> action;
			if (action=='S' || action=='s'){
				pontP=incluirCep (pontL, aux);
				pontP=pontL;
				while (pontP->prox!=NULL && pontP->caixas.cep!=aux)
					pontP=pontP->prox;
				pontP=enviando (pontP, op);
				pontP=checarTotal(pontL, pontP, aux);
			}
		}
	}
	return pontL;
}

lista *enviarDestinatarios (lista *pontL){
	lista *pontP;
	string op="do";
	int aux;
	if (pontL!=NULL){
		cout << "Informe o CEP: ";
		cin >> aux;
		pontP=pontL;
		while (pontP->prox!=NULL && pontP->caixas.cep!=aux)
			pontP=pontP->prox;
		if (pontP->caixas.cep==aux){
			cout << "CEP encontrado com sucesso.\n";
			pontP=enviando (pontP, op);
		}
		else
			cout << "O CEP informado nao esta cadastrado.\n";
	}
	else
		cout << "Lista vazia.\n";
	return pontL;
}

void exibir (lista *pontL){
	if (pontL!=NULL){
		cout << "\tCEP\tTOTAL DE ITENS\n";
		while (pontL!=NULL){
			cout << "\t" <<pontL->caixas.cep<< "\t" <<pontL->caixas.total<< "\n";
			pontL=pontL->prox;
		}
	}
	else
		cout << "Lista vazia.\n";
}

void menu (char &action){
	cout << "1 - ENVIAR CORRESPONDENCIA PARA UM CEP\n2 - ENVIAR CORRESPONDENCIA PARA DESTINATARIOS\n3 - DESATIVAR CEP\n4 - EXIBIR CAIXAS\n0 - SAIR\n";
	cin >> action;
	while (action!='1' && action!='2' && action!='3' && action!='4' && action!='0'){
		cout << "Opcao invalida.\n";
		cin >> action;
	}
}

int main (){
	char action=' ';
	lista *pontL;
	pontL=NULL;
	while (action!='0'){
		menu (action);
		if (action=='1')
			pontL=enviarCep (pontL);
		else if (action=='2')
			pontL=enviarDestinatarios (pontL);
		else if (action=='3')
			pontL=desativarCep(pontL);
		else if (action=='4')
			exibir(pontL);
		system ("PAUSE");
		system ("CLS");
	}
}