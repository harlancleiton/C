#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{   int n,q[15],codigo[15];
    string nome[15];
    cout << "Quantos produtos estao armazenados?\n";
    cin >> n;
    cout << "Preencha os dados:\nNome: ";
    for (int i=0;i<=n;i++){
        cin >> nome[i];
        cout << "Codigo: ";
        cin >> codigo[i];
        cout << "Quantidade: ";
        cin >> q[i];
        }
    for (int i=0;i<=n;i++){
        cout << "Nome: " <<nome[i]<< ".\n";
        cout << "Codigo: " <<codigo[i]<< ".\n";
        cout << "Quantidade: " <<q[i]<< ".\n";
        }
    system("PAUSE");
    return 0;
}
