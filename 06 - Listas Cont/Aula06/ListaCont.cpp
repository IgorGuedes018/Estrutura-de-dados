#include <iostream>
#include <cstdlib>
#include "Ponto.h"
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    cout << "Criando objeto ListaCont" << endl;
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont()
{
    cout << "Destruindo objeto ListaCont" << endl;
    delete [] vet;
}

int ListaCont::get(int k)
{
    if(k >= 0 && k < n) // se k estiver dentro dos valores possiveis da lista
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::set(int k, int val)
{
    if(k >= 0 && k < n)
        vet[k] = val;
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereFinal(int val)
{
    if(n == max) // se o vetor estiver cheio n da
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    vet[n] = val; // se n, coloca em n ja q o ultimo no e n-1
    n = n + 1;
}

void ListaCont::removeFinal()
{
    if(n == 0)
    {
        cout << "ERRO: Lista Vazia!" << endl;
        exit(1);
    }
    n = n - 1;
}

void ListaCont::insereK(int k, int val)
{
    if(n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    if(k >= 0 && k < n) // se k estiver no vetor
    {
        for(int i = n-1; i >= k; i--)
            vet[i+1] = vet[i]; // passa todo o vetor depois de K pra frente
        vet[k] = val;
        n = n + 1;
    }
    else // ERRO
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::removeK(int k)
{
    if(k >= 0 && k < n) // confere
    {
        for(int i = k; i < n-1; i++)
            vet[i] = vet[i+1];
        n = n - 1;
    }
    else // erro
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereInicio(int val)
{
    if(n == 0)  // se n == 0 coloca no primeiro
    {   //lista vazia. Sera o unico no da lista
        vet[n] = val;
        n = n + 1;
    }
    else // se a lista n tiver vazia usa o isede K em 0
        insereK(0, val);
}

void ListaCont::removeInicio()
{
    removeK(0);
}


//-------------------------------------------
// questao 1
void ListaCont::imprime()
{
    if(n==0)
    {
        cout << "Imprimindo lista:"<< endl;
        cout <<"Lista Vazia" << endl;

    }
    else
    {
        cout << "Imprimindo lista:"<< endl;
        for(int i=0; i<n; i++)
        {
           cout <<i << ": "<< vet[i] << endl;
        }
    }
}

int ListaCont::numNos()
{
    return n;
}


int ListaCont::buscaMaior(int val)
{

   for(int i=0; i<n; i++)
   {
      if(vet[i]> val)
        return i+1;
   }
    return -1;



}


void ListaCont::limpar()
{
    for(int i=n-1;i>=0 ;i--)
        removeFinal();

}

//----------------------------------------------
//questao 2
void ListaCont::insereValores(int tam, int vet[])
{

    if(n+tam > max)
    {
        cout << "ERRO: Nao cabe no vetor"<< endl;
        exit(1);
    }
    else
    {
        for(int i=0; i<tam; i++)
            insereFinal(vet[i]);

    }
    imprime();
}
//--------------------------
//questao 3







//----------------
// questao 4




//------------------
