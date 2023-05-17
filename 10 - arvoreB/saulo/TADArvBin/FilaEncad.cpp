#include <iostream>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    inicio = fim = NULL;
}

FilaEncad::~FilaEncad()
{
    No *p = inicio;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

NoArv* FilaEncad::getInicio()
{
    if(inicio != NULL)
        return inicio->getInfo();
    cout << "Fila vazia" << endl;
    exit(1);
}


NoArv* FilaEncad::desenfileira()
{
    if(inicio != NULL)
    {
        No *q = inicio;
        inicio = q->getProx();
        NoArv *p = q->getInfo();
        if(inicio == NULL)
            fim = NULL;
        delete q;
        return p;
    }
    cout << "Fila vazia" << endl;
    exit(1);
}

void FilaEncad::enfileira(NoArv *p)
{
    No *novo = new No(); // alocação
    novo->setInfo(p);  // ajuste novo info
    novo->setProx(NULL); // ajuste novo prox
    if(inicio == NULL) // lista vazia
        inicio = novo;
    else
        fim->setProx(novo); //ajuste ultimo prox
    fim = novo;
}

bool FilaEncad::vazia()
{
    return inicio == NULL;
}

void FilaEncad::imprime() // operação não convencional
{
    cout << "Fila:  ";
    for(No *p = inicio; p != NULL; p = p->getProx())
        cout << p->getInfo()->getInfo() << " ";
    cout << endl;
}
