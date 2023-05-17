#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    else if(p->getInfo() == val)
        return true;
    else if(val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else
        return auxBusca(p->getDir(), val);
}

void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p == NULL)
        return NULL;
    else if(val < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxRemove(p->getDir(), val));
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = remove1Filho(p);
        else
        {
            NoArv *aux = menorSubArvDireita(p);
            int tmp = aux->getInfo();
            p->setInfo(tmp);
            aux->setInfo(val);
            p->setDir(auxRemove(p->getDir(), val));
        }
    }
    return p;
}

NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv* ArvBinBusca::remove1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir();
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

void ArvBinBusca::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return p;
}

float ArvBinBusca::mediaCaminho(int ch)
{
    int soma = 0, cont = 0;
    NoArv *p = raiz;
    while(p != NULL)
    {
        cont++;
        soma += p->getInfo();
        if(ch == p->getInfo())
            break;
        else if(ch > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
    return (float)soma/cont;
}

//---------------------------------------------------------------

int ArvBinBusca::maior()
{
    return auxMaior(raiz);
}
int ArvBinBusca::auxMaior(NoArv *p)
{

    if(p->getDir() == NULL)
    {
        return p->getInfo();

    }
    else
        auxMaior(p->getDir());
}


int ArvBinBusca::menor()
{
    return auxMenor(raiz);
}
int ArvBinBusca::auxMenor(NoArv *p)
{

    if(p->getEsq() == NULL)
    {
        return p->getInfo();

    }
    else
        auxMenor(p->getEsq());
}


void ArvBinBusca::removeMaior()
{
    auxRemoveMaior(raiz);
}
NoArv* ArvBinBusca::auxRemoveMaior(NoArv *p)
{
    if(p->getDir() == NULL)
    {
        if(p->getEsq() == NULL)
        {
            p= removeFolha(p);
            return NULL;
        }
        else
        {
             p = remove1Filho(p);
             return p;
        }
    }
    else
    {
        p->setDir(auxRemoveMaior(p->getDir()));
        return p;
    }
}


void ArvBinBusca::removeMenor()
{
    auxRemoveMenor(raiz);
}
NoArv* ArvBinBusca::auxRemoveMenor(NoArv *p)
{
    if(p->getEsq() == NULL)
    {
        if(p->getDir() == NULL)
        {
            p= removeFolha(p);
            return NULL;
        }
        else
        {
             p = remove1Filho(p);
             return p;
        }
    }
    else
    {
        p->setEsq(auxRemoveMenor(p->getEsq()));
        return p;
    }
}

int ArvBinBusca::contaParesCaminho(int x)
{
    return auxContaParesCaminho(raiz, x);
}

int ArvBinBusca::auxContaParesCaminho(NoArv *p, int x)
{
    if(p == NULL)
        return NULL;
    if(x > p->getInfo()) // direita
    {
        if(p->getInfo() %2 == 0)
            return 1 + auxContaParesCaminho(p->getDir() , x);
        else
            return auxContaParesCaminho(p->getDir() , x);
    }
    else if( x < p->getInfo() ) // esqerda
    {
        if(p->getInfo() %2 == 0)
            return 1 + auxContaParesCaminho(p->getEsq() , x);
        else
            return  auxContaParesCaminho(p->getEsq() , x);
    }
}


aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
{
    NoArv *p = raiz;
    NoArv *pai = NULL;
    bool removerEsq = true; // Decidir de que lado atualizar o pai
    while (p != NULL)
    {
        int info = p->getInfo();
        NoArv *esq = p->getEsq();
        NoArv *dir = p->getDir();

        if (val < info) // Chave esta a esquerda
        {
            pai = p;
            p = esq;
            removerEsq = true;
        }
        else if (val > info) // Chave esta a direita
        {
            pai = p;
            p = dir;
            removerEsq = false;
        }
        else // Foi encontrado
        {
            if (esq == NULL && dir == NULL) // Eh folha
            {
                delete p;
                if (pai == NULL) // Eh raiz e folha
                    raiz = NULL;
                else // Eh apenas folha
                {
                    if (removerEsq)
                        pai->setEsq(NULL);
                    else
                        pai->setDir(NULL);
                }
            }
            else
                cout << "NAO REMOVIDO: No " << val << " nao e folha!" << endl;
            return;
        }
    }
    cout << "NAO REMOVIDO: No " << val << " nao encontrado!" << endl;
}


















