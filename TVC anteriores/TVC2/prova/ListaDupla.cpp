#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla ()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla ()
{
    // OMITIDO
}

void ListaDupla::insereInicio (int val)
{
    NoDuplo *p = new NoDuplo ();
    p->setInfo (val);
    p->setProx (primeiro);
    p->setAnt (NULL);

    if (n == 0)
    {
        ultimo = p;
    }
    else
    {
        primeiro->setAnt (p);
    }
    primeiro = p;
    n = n + 1;
}

void ListaDupla::imprime ()
{
    cout << "[";
    for (NoDuplo *p = primeiro; p != NULL; p = p->getProx ())
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
//Q3

void ListaDupla::removeMaior()
{
    if(primeiro != NULL)
    {
        NoDuplo *p;
        NoDuplo *maior;
        NoDuplo *ant;

        maior = primeiro;


        for(p=primeiro; p!= NULL; p=p->getProx() )
        {
            if(p->getInfo() > maior->getInfo() )
                maior = p;
        }

        p= maior->getProx(); // PRoximo de maior
        ant = maior->getAnt(); // anterior de maior     ->   -ANT-MAIOR-P-



        // setangem
        ant->setProx(p);
        p->setAnt(ant);
        delete maior;
    }

}

//-Q3
// ----------------------------------------------------------------------------
