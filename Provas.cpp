#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void carregar_gabarito (char gabarito[]){
     for (int i=1;i<=5;i++){
         cout << "Digite a resposta da questao " <<i<< ".\n";
         cin >> gabarito[i];
         while (gabarito[i]!='A' && gabarito[i]!='B' && gabarito[i]!='C' && gabarito[i]!='D' && gabarito[i]!='E'){
               cout << "Resposta invalida.\nRespostas validas: 'A','B','C','D','E'.\n";
               cin >> gabarito[i];
               }
     }
     system ("PAUSE");
     system ("CLS");
}
void carregar_valores (float valores[]){
     for (int i=1;i<=5;i++){
         cout << "Digite o valor da questao " <<i<< ".\n";
         cin >> valores[i];
         while (valores[i]<=0){
               cout << "Valor digitado e menor ou igual a 0. Digite novamente.\n";
               cin >> valores[i];
         }
     }
     system ("PAUSE");
     system ("CLS");
}
void checar_valores (float valores[], float total){
	while (total>10 || total==0){
		total=0;
		for (int i=1;i<=5;i++){
			total=total+valores[i];
		}
		if (total>10){
			cout << "Total de pontos ultrapassou o limite(10 pontos).\n";
			carregar_valores(valores);
		}
	}   
}
void carregar_aluno (string aluno[], char gabarito[], char respostas[], float valores[], int aux, float total_aluno[]){
	int cont=0;
	cout << "Digite quantos alunos fizeram a prova(max: 50).\n";
	cin >> aux;
	while (aux<0 || aux>50){
		cout << "Quantidade digitada e menor que 0 ou ultrapassou o limite de 50 alunos. Tente novamente.\n";
		cin >> aux;		
	}
	for (int i=1;i<=aux;i++){
		cont=0;
		total_aluno[i]=0;
		cout << "Digite o nome do aluno " <<i<< ".\n";
		cin >> aluno[i];
		for (int j=1;j<=5;j++){
			cout << "Digite a resposta do aluno " <<aluno[i]<< ", questao " <<j<< ".\n";
			cin >> respostas[j];
			while (respostas[j]!='A' && respostas[j]!='B' && respostas[j]!='C' && respostas[j]!='D' && respostas[j]!='E'){
				cout << "Resposta invalida.\nRespostas validas: 'A','B','C','D','E'.\n";
				cin >> respostas[j];
			}
			if (respostas[j]==gabarito[j]){
				total_aluno[i]=total_aluno[i]+valores[j];
				cont++;
				cout << "O aluno " <<aluno[i]<< " , acertou a questao " <<j<< " e fez um total de " <<total_aluno[i]<< " pontos em " <<cont<< " acertos.\n";
			}
			else {
				cout << "O aluno " <<aluno[i]<< " , nao acertou a questao " <<j<< " e continuou com o total de " <<total_aluno[i]<< " pontos.\n";
			}
		}
	}
	system ("CLS");
	for (int i=1;i<=aux;i++){
		cout << "ALUNO: " <<aluno[i]<< "\tNOTA: " <<total_aluno[i]<< ".\n";
	}
	system ("PAUSE");
	system ("CLS");
}
int main (){
    float valores[6], total=0, total_aluno[50];
    int aux;
    string aluno[50];
    char gabarito[6], respostas[6];
    carregar_gabarito(gabarito);
    carregar_valores(valores);
    checar_valores(valores, total);
    carregar_aluno(aluno, gabarito, respostas, valores, aux, total_aluno);
    system ("PAUSE");
    return 0;
}
