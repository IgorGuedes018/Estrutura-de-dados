#include <iostream>
#include <cstdlib>
#include "MatrizDistancias.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q4
MatrizDistancias::MatrizDistancias(int ordem)
{
    n=ordem;
    if( n< 3)
    {
        cout<< "ordem da matriz invalida";
        exit(2);
    }
    int tam= ( (n*2) + (n*2));
    vet = new int[tam];
}

MatrizDistancias::~MatrizDistancias()
{
   delete [] vet;
}

int MatrizDistancias::detInd(int i, int j)
{
    if(i>=0 && j>=0 && i<n && j<n )
    {
        if(i==j)            // diagonal principal
        {
            return i;
        }
        else if(i+j == n)    //diagonal secundaria
        {
            return i+n;
        }
        else if(i ==0)      // primeira linha
        {
            return j+(n*2);
        }
        else if(i == 4)     // ultima linha
        {
            return (n*3)+ j;
        }
        else
            return -2; // valor ==0
    }
    else
        return -1; // indice invalido
}

int MatrizDistancias::get(int i, int j)
{
    int k= detInd(i,j);
    if(k== -1)
    {
        cout << "indice invalido";
        exit(2);
    }
    else if(k ==-2)
    {
        cout<<"indice n pertence a matriz ampulheta/ ==0";
        exit(3);
    }
    else
        return vet[k];

}

void MatrizDistancias::set(int i, int j, int val)
{
    int k= detInd(i,j);
    if(k== -1)
    {
        cout << "indice invalido";

    }
    else if(k ==-2)
    {
        cout<<" Tentando atribuir valor nao zero em posicao impropria";

    }
    else
        vet[k] = val;


}
//-Q4
// ----------------------------------------------------------------------------

void MatrizDistancias::imprime()
{
    cout << "Matriz " << n << " x " << n << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << get(i, j) << "\t";
        cout << endl;
    }
    cout << endl;
}
