#include <iostream>

using namespace std;

float menor(int n, float vet[])
{
    if (n ==1)
       return vet[0];
    
    float x = menor(n-1, vet);

    if(x < vet[n-1])
        return x;           /// retorna o valor de x
    else
        return vet[n-1]; // retorna o valor de vet

}

int main()
{
    int n;
    cout<< "digite um numero de elementos:";
    cin>> n;

    float *vet = new float [n];
    for(int i=0; i<n; i++)
    {
        cin>> vet[i];
    }
    
    cout << "o menor valor e:"<<  menor( n, vet);
    
    return 0;
}
