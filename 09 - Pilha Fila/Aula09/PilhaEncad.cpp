#include <iostream>
#include <cstdlib>
#include "PilhaEncad.h"

using namespace std;

// construtor
PilhaEncad::PilhaEncad()
{
    cout << "Criando PilhaEncad" << endl;
    topo = NULL;
}

// destrutor
PilhaEncad::~PilhaEncad()
{
    cout << "Destruindo PilhaEncad" << endl;
    No* p = topo;
    while(topo != NULL)
    {
        topo = p->getProx();
        delete p;
        p = topo;
    }
}

void PilhaEncad::empilha(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(topo);
    topo = p;
    tam++;
}

int PilhaEncad::desempilha()
{
    No* p;
    if(topo != NULL)
    {
        p = topo;
        topo = p->getProx();
        int val = p->getInfo();
        delete p;
        tam--;
        return val;
    }
    else
    {
        cout << "ERRO: Pilha vazia!" << endl;
        exit(1);
    }
}

int PilhaEncad::getTopo()
{
    if(topo != NULL)
        return topo->getInfo();
    else
    {
        cout << "Pilha vazia!" << endl;
        exit(1);
    }
}

bool PilhaEncad::vazia()
{
    if(topo == NULL)
        return(true);
    else
        return(false);
}

void PilhaEncad::imprime()
{
    No *p;
    cout << "pilha: ";
    for(p =topo; p != NULL; p= p->getProx())
        cout << p->getInfo() << ", " ;
    cout << endl;
}

int PilhaEncad::tamanho()
{
    return tam;

}

void PilhaEncad::removeDaPilha(PilhaEncad *p2, int x)
{
    No *p;
    p = topo;
    int cont=0;
    while(p->getInfo() != x)
    {
        this->empilha(p->getInfo());
        desempilha();
        p=topo;
        cont++;
        exit(2);
    }
    desempilha();

    while(cont !=0)
    {
        empilha(p2->getTopo());
        this->desempilha();
    }
}
