#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad ()
{
    primeiro = NULL;
}

ListaEncad::~ListaEncad ()
{
    // OMITIDO
}

void ListaEncad::insereInicio(int val)
{
    No *novo = new No ();
    novo->setInfo (val);
    novo->setProx (primeiro);
    primeiro = novo;
}

void ListaEncad::imprime ()
{
    cout << "[";
    for (No *p = primeiro; p != NULL; p = p->getProx ())
    {
        cout << p->getInfo ();
        if (p->getProx () != NULL)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// ----------------------------------------------------------------------------
//Q4

void ListaEncad::removeBloco(int a, int b)
{
    // se A nao estiver na lista, nao remover nada
    // A sempre estara antes de I
    // A e so para se houver um B

    No *p;
    No *aux;



    if(primeiro->getInfo() == a)
    {
        p = primeiro;
        while (p->getInfo() != b)
        {
            primeiro = primeiro->getProx();
            delete p;
            p = primeiro;
        }
            primeiro = primeiro->getProx();
            delete p;
            p = primeiro;
    }






}

//-Q4
// ----------------------------------------------------------------------------
