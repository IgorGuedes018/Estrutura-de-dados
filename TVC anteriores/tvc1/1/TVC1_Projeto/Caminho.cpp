#include <iostream>
#include <cmath>
#include "Caminho.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q3
Caminho::Caminho(int nn)
{
    int n = nn;
    vet = new int[n];
    for(int i = 0; i < n; i++)
        vet[i] = i;

}

Caminho::~Caminho()
{
    delete [] vet;
}

int Caminho::calculaDistanciaPercorrida(int **distancias)
{   // pelo caminho. Dimensao = numero de cidades

    int valor = 0;
    for(int i=1; i<n; i++)
    {
        valor =valor + distancias[i][i-1];

    }

    return valor;
}

void Caminho::buscaGulosa(int **distancias)
{




}
//-Q3
// ----------------------------------------------------------------------------

void Caminho::ordem(int **distancias, int i, int *ordem)
{
    int cid = 0;
    for(int j = 0; j < n; j++)
        if(i != j)
            ordem[cid++] = j;
    for(cid = 0; cid < n-2; cid++)
    {
        int j = cid+1;
        int pivo = ordem[j];
        while(j > 0 && distancias[i][pivo] < distancias[i][ordem[j-1]])
        {
            ordem[j] = ordem[j-1];
            j--;
        }
        ordem[j] = pivo;
    }
}

void Caminho::imprimirCaminho()
{
    for (int i = 0; i < n; i++)
    {
        cout << vet[i];
        if(i == n-1)
            cout << endl;
        else
            cout << " --> ";
    }
}
