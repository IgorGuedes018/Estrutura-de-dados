#include <iostream>

using namespace std;

int contaPares(int n, int vet[])
{
    if(n ==1)
        if(vet[0] % 2 == 0) // caso base
            return 1;

    float x = contaPares(n-1, vet);

    if(( vet[n-1] %2 ) == 0)
        return x+1;
    else
        return x;
}


int main()
{
    int n;
    cout << "digite um valor:";
    cin>> n;

    int *vet = new int[n];
    for(int i=0; i<n; i++)
    {
        cin>> vet[i];
    }


    cout << "numero de pares" << contaPares(n, vet);
    
    return 0;
}
