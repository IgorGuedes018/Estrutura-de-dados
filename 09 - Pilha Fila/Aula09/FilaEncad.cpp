#include <iostream>
#include <cstdlib>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    cout << "Criando FilaEncad" << endl;
    inicio = NULL;
    fim = NULL;
}

FilaEncad::~FilaEncad()
{
    cout << "Destruindo FilaEncad" << endl;
    No* p = inicio;
    while(inicio != NULL)
    {
        inicio = p->getProx();
        delete p;
        p = inicio;
    }
    fim = NULL;
}

bool FilaEncad::vazia()
{
    if(inicio == NULL)
        return true;
    else
        return false;
}

void FilaEncad::enfileira(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(fim == NULL)
        inicio = p;
    else
        fim->setProx(p);
    fim = p;
}

int FilaEncad::getInicio()
{
    if(inicio != NULL)
        return inicio->getInfo();
    else
    {
        cout << "Fila vazia!" << endl;
        exit(1);
    }
}

int FilaEncad::desenfileira()
{
    No* p;
    if(inicio != NULL)
    {
        p = inicio;
        inicio = p->getProx();
        if(inicio == NULL)
            fim = NULL;
        int val = p->getInfo();
        delete p;
        return val;
    }
    else
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
}

void FilaEncad::imprime()
{
    No *p;
    p= inicio;
    cout << "fila: ";
    for(p=inicio; p!=NULL; p=p->getProx())
    {
        cout<< p->getInfo() << ", ";
    }
    cout << endl;


}

FilaEncad* FilaEncad::reorganiza(FilaEncad *f)
{
    FilaEncad* newfila = new FilaEncad();
    No *p;
    No *ant;


    // o primeiro n tem anterior entao nao pode ser
    ant = inicio;
    f->desenfileira(); // salvando o primeiro valor
    p=inicio;


    while(!vazia())
    {
        cout<< p->getInfo() << ", ";
        if(p->getInfo() > 70 && ant->getInfo() > 70) // caso seja um S
        {
            newfila->enfileira(f->desenfileira());// colocando o valor S na fila nova

             //att
             ant=inicio;
             p=p->getProx();
             //cout << "AAAAAAAAAAAAAA";
        }
        else // se nao for um S retira e continua
        {
            f->desenfileira();
            //att
            ant=inicio; // setando o novo ant
            p=p->getProx();
            //cout << "AAAAAAAAAAAAAA";
        }
    }

    // se p for um S e o anterior de p for um S
    // p entrara na lista

    return newfila;
}
