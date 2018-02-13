#include <iostream>
#include <cstdlib>

using namespace std;

struct aluno{
    string nome;
    int matricula;
    float media;
};

int main (){
    aluno x;
    cout << "Digite o nome do aluno.\n";
    cin >> x.nome;
    cout << "Nome do aluno: " <<x.nome<< ".\n";
    system ("PAUSE");
    return 0;
}
