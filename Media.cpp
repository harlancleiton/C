#include <cstdlib>
#include <iostream>

using namespace std;

int main ()
{
        float media[3],numero[5]={8.9,7,4,5,6};
        media[0]=(numero[0]+numero[1])/2;
        media[1]=(numero[2]+numero[3]+numero[4])/3;
        media[2]=(media[0]+media[1])/2;
        for (int i=0;i<=3;i++){
        cout << "Media "<<i+1<< ": " <<media[i]<< ".\n";
        }
	return 0;
}
