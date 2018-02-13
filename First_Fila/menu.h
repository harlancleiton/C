#include <iostream>
#include <cstdlib>

using namespace std; 

void menu (char &action){
	cout << "1 - ENVIAR ARQUIVO PARA A IMPRESSORA (MAX: 5 ARQUIVOS)\n2 - IMPRIMIR ARQUIVO\n3 - EXIBIR FILA DE IMPRESSAO\n4 - LIMPAR A FILA DE IMPRESSAO\n0 - SAIR\nOpcao: ";
	cin >> action;
}