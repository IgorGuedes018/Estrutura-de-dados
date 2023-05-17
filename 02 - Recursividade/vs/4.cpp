#include <iostream>

using namespace std;

float soma(int n, float vet[])
{
    if(n == 0)
        return 0;
    if(n > 0)
        return (vet[n-1] + soma(n-1, vet) );
}

int main()
{
    int n;
    cout<< "digite o numero de elementos:";
    cin>> n;

    float *vet = new float[n];

    for(int i=0; i<n; i++)
    {
        cin>> vet[i];
    }

    cout <<endl << "a soma e:" << soma(n, vet);

    return 0;
}
