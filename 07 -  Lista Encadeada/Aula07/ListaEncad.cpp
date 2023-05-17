#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    cout << "Criando objeto ListaEncad" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaEncad::~ListaEncad()
{
    cout<< endl << endl << "Destruindo objeto ListaEncad" << endl;
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaEncad::busca(int val)
{
    No *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaEncad::get(int k)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaEncad::set(int k, int val)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}


void ListaEncad::insereInicio(int val)
{
    No* p = new No(); // aloca novo ponteiro
    p->setInfo(val); // p recebe o valor
    p->setProx(primeiro); // coloca o PRIMEIRO como o proximo de P

    primeiro = p; // faz o Primeiro ser P

    n++; // aumenta numero de nos
    if(n == 1)
        ultimo = p; // se o VAL for o unico item da lista o ultimo=p
}

void ListaEncad::insereFinal(int val)
{
    No* p = new No();  //   aloca
    p->setInfo(val);   //   seta val em P
    p->setProx(NULL); //    seta o proximo de VAL como null

    if(ultimo != NULL)
    {
        ultimo->setProx(p);
    ultimo = p;
    }


    n++; // adiciona mais 1 no
    if(n == 1) primeiro = p;
}

void ListaEncad::removeInicio()
{
    No* p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;

        n--;
        if(n == 0) ultimo = NULL;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::removeFinal()
{
    No* p;
    if(ultimo != NULL)
    {
        if(primeiro == ultimo)
        {
            primeiro = NULL;
            p = NULL;
        }
        else
        {
            p = primeiro;
            while(p->getProx() != ultimo)
                p = p->getProx();
            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::imprime()
{
    No *p ;
    p=primeiro;
    if(p ==NULL )\
    {
        cout<< "lista vazia";
        exit(2);
    }
    else
    {
        cout << "lista: ";
        for(p = primeiro; p != NULL; p=p->getProx())
            cout<< p->getInfo() << ", ";
        cout << endl;
    }


}

int ListaEncad::numNos()
{
    return n;
}

int ListaEncad::buscaMaior(int val)
{
    No *p;
    int i=0;
    for(p=primeiro; p != NULL; p=p->getProx())
    {

        if(p->getInfo() > val )
            return i;
        i++;
    }
    return -1;
}

void ListaEncad::limpar()
{
    No *p = ultimo;
    while(p != NULL)
    {
        removeFinal();
        p= ultimo;
    }
}

float ListaEncad::calculaMedia()
{
    float media=0;
    No *p;


    for(p=primeiro; p!= NULL; p=p->getProx())
        media = media + p->getInfo();

    media = media/n;
    return media;



}

void ListaEncad::concatena(ListaEncad *l2)
{



}

ListaEncad* ListaEncad::partir(int x)
{
    int i= n/2;
    int contador=0;
    No *p =primeiro;

    while(contador < i)
    {
        p=p->getProx();
    }

}

void ListaEncad::insereOrdenado(int val)
{
    No* p = new No();
    p->setInfo(val);

    if(n==0 || val < primeiro->getInfo())
        insereInicio(val);
    else
    {
       p= primeiro;

       //val > p->getProx();



    }
}

bool ListaEncad::inserePosicaoVal(int k, int val)
{

    No *novo = new No();
    novo->setInfo(val);
    No *p;
    No *auxProx;
    p=primeiro;

    if( k > n)    // caso o Indice K seja invalido na lista
        return false;

    int contador=0;
    for(contador =0; contador <=k ; contador++) // ate chegar em K/
        p=p->getProx();

    contador = p->getInfo();
     // valor X
    if(contador > n)  // caso o Indice X seja invalido na lista
        return false;

    p=primeiro;
    while(contador > 0)
    {
        p=p->getProx();
        contador--;
    }

    // ocorreu tudo certo

    auxProx = p->getProx();

    p->setProx(novo);
    novo->setProx(auxProx);
    n++;
    return true;
}

int* ListaEncad::menorProximo()
{
    int *vet = new int [n];
    No *p;
    No *auxProx;

    auxProx = primeiro;
    int contador=0;

    for(p=primeiro; p != NULL; p=p->getProx())
    {
        auxProx = auxProx->getProx();
        if(p->getInfo() < auxProx->getInfo())
        {
            vet[contador] = 1;
            contador++;
        }
        else
        {
            vet[contador] = 0;
            contador++;
        }

    }

    cout << "nova lista:";

    for(int i=0; i<n; i++)
        cout << vet[i] << ", ";

    return vet;
}





