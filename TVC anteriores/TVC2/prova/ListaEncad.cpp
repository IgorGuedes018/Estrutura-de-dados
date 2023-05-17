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
    // Implemente aqui a sua solução para a questão 4.

}

//-Q4
// ----------------------------------------------------------------------------
