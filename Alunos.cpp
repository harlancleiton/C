#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct aluno{
	string nome;
	int matricula, cont;
	float notas[3], media;
};

void cadastrar (aluno alunos[], int &total, int total_max){
    int i=0, j, n=0;
    aluno aux;
	if (total!=total_max){
		cout << "Digite o nome do aluno " <<total+1<< ".\n";
		cin >> alunos[total].nome;
		alunos[total].matricula=alunos[total].matricula+total;
		cout << "Aluno adicionado com sucesso.\nSua matricula e " <<alunos[total].matricula<< ".\n";
		if (total!=0){
			while (alunos[i].nome<=alunos[total].nome ||i<=total)
				i++;
            j=total;
            aux.nome=alunos[i].nome;
            while (n!=alunos[i].cont){
                aux.notas[n]=alunos[i].notas[n];
                n++;
            }
            aux.cont=alunos[i].cont;
            aux.matricula=alunos[i].matricula;
            aux.media=alunos[i].media;
            alunos[i].nome=alunos[j].nome;
            n=0;
            while (n!=alunos[j].cont){
                alunos[i].notas[n]=alunos[j].notas[n];
                n++;
            }
            alunos[i].cont=alunos[j].cont;
            alunos[i].matricula=alunos[j].matricula;
            alunos[i].media=alunos[j].media;
            alunos[j].nome=aux.nome;
            n=0;
            while (n!=aux.cont){
                alunos[j].notas[n]=aux.notas[n];
                n++;
            }
            alunos[j].cont=aux.cont;
            alunos[j].matricula=alunos[i].matricula;
            alunos[j].media=aux.media;
        }
        total++;
	}
	else
		cout << "Lista cheia.\n";
}

void cadastrar_notas (aluno alunos[], int total){
    int matricula, i=0, j=0;
    if (total!=0){
        cout << "Digite a matricula do aluno que sera cadastrada as notas.\n";
        cin >> matricula;
        while (i<total && alunos[i].matricula!=matricula)
            i++;
        if (alunos[i].matricula==matricula && alunos[i].cont!=3){
            cout << "Matricula aceita, aluno: " <<alunos[i].nome<< ".\nDigite a nota " <<alunos[i].cont+1<< ".\n";
            cin >> alunos[i].notas[alunos[i].cont];
            alunos[i].cont++;
			alunos[i].media=0;
            while (j<alunos[i].cont){
                    alunos[i].media=alunos[i].media+alunos[i].notas[j];
					j++;
			}
                alunos[i].media=alunos[i].media/alunos[i].cont;
            cout << "Nota adicionada com sucesso.\n";
        }
        else
            cout << "Matricula nao encontrada ou o aluno em questao ja possui as notas cadastradas.\n";
    }
    else
        cout << "Lista vazia.\n";
}

void excluir (aluno alunos[], int &total, int total_max){
	string nome;
	int i=0;
	if (total!=0){
		cout << "Digite o nome do aluno a ser excluido.\n";
		cin >> nome;
		while (i<=total && alunos[i].nome!=nome)
			i++;
		if (alunos[i].nome==nome){
			cout << "Aluno excluido com sucesso.\n";
			for (int j=i;j<=total;j++){
				alunos[j].nome=alunos[j+1].nome;
				alunos[j].matricula=alunos[j+1].matricula;
				for (int n=0;n<=alunos[j+1].cont;n++)
                    alunos[j].notas[n]=alunos[j+1].notas[n];
			}
			total--;
		}
	}
	else
		cout << "Lista vazia.\n";
}

void exibir (aluno alunos[], int total){
    int j=0, aux=0;
    if (total!=0){
        cout << "ALUNO\tMEDIA\tNOTAS\n\n";
        for (int i=0;i<total;i++){
            cout <<alunos[i].nome;
            if (alunos[i].cont==0)
                cout << "\n";
            else{
                cout << "\t" <<alunos[i].media;
                j=0;
                while (j<alunos[i].cont){
                    if (j!=0)
                        cout << "\t";
                    cout << "\t" <<alunos[i].notas[j]<< "\n";
                    j++;
                }
            }
        }
    }
    else
        cout << "Lista vazia.\n";
}

void limpar (aluno alunos[], int &total){
    if (total!=0){
        for (int i=0;i<=total;i++){
            alunos[i].cont=0;
        }
        total=0;
        cout << "Lista limpa com sucesso.\n";
    }
    else
    cout << "Lista vazia.\n";
}

void menu (char &action){
	cout << "1 - CADASTRAR ALUNO (MAX.: 5 ALUNOS)\n2 - EXCLUIR ALUNO\n3 - CADASTRAR NOTAS\n4 - EXIBIR RELACAO DE ALUNOS COM MEDIA\n5 - LIMPAR LISTA\n0 - SAIR\nOpcao: ";
	cin >> action;
}

int main () {
	int total=0, total_max=5;
	char action=' ';
	aluno alunos[5];
	for (int i=0;i<=4;i++){
		alunos[i].matricula=123456;
		alunos[i].cont=0;
	}
	while (action!='0'){
		menu (action);
		if (action=='1')
			cadastrar (alunos, total, total_max);
		else if (action=='2')
			excluir (alunos, total, total_max);
        else if (action=='3')
            cadastrar_notas (alunos, total);
        else if (action=='4')
            exibir (alunos, total);
        else if (action=='5')
            limpar (alunos, total);
        system ("PAUSE");
        system ("CLS");
	}
}
