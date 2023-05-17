#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont (int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont ()
{
    // OMITIDO
}

void ListaCont::insereFinal (int val)
{
    if (n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit (1);
    }
    vet[n] = val;
    n = n + 1;
}

void ListaCont::imprime ()
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << vet[i];
        if (i + 1 < n)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// ----------------------------------------------------------------------------
//Q2

bool ListaCont::insereIntervalo(int a, int b)
{
    int capacidade = max;


    if(a >b)
        insereIntervalo(b,a);
    else
    {
       for(int i=a; i<=b; i++)
       {
            if( n == max) // caso o vetor esteja cheio
                max= max + (b-a);

            // n == ultima posicao
            vet[n] = i;
            n++;
       }
    }

    // caso para retornar
    if(capacidade == max)
        return false;
    else
        return true;

}
//-Q2
// ----------------------------------------------------------------------------
