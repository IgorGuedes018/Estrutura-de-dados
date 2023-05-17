#include <iostream>
#include <cmath>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca ()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca ()
{
    // OMITIDO
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq (libera (p->getEsq ()));
        p->setDir (libera (p->getDir ()));
        delete p;
        p = NULL;
    }
    return p;
}

void ArvBinBusca::insere (int val)
{
    raiz = auxInsere (raiz, val);
}

NoArv* ArvBinBusca::auxInsere (NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv ();
        p->setInfo (val);
        p->setEsq (NULL);
        p->setDir (NULL);
    }
    else if (val < p->getInfo ())
        p->setEsq (auxInsere (p->getEsq (), val));
    else
        p->setDir (auxInsere (p->getDir (), val));
    return p;
}

void ArvBinBusca::imprime()
{
    cout << "ABB em ordem: ";
    imprimeEmOrdem (raiz);
    cout << endl;
}

void ArvBinBusca::imprimeEmOrdem (NoArv *p)
{
    if (p != NULL)
    {
        imprimeEmOrdem (p->getEsq ());
        cout << p->getInfo () << " ";
        imprimeEmOrdem (p->getDir ());
    }
}

void ArvBinBusca::removeMenor (int val)
{
    raiz = auxRemoveMenor (raiz, val);
}

// ----------------------------------------------------------------------------
//Q1
int* ArvBinBusca::criaVetFolhas(int k, int *n)
{
    if(raiz == NULL)
        return NULL;

    int tam = powf(2, k);
    *n=0;

    int *vet = new int[tam];
    AUXcriaVetFolhas(raiz, vet, k, n);

    // alocando as sobras com -1
    for(int i= *n; i<tam; i++)
        vet[i] = -1;

    *n = tam;
    return vet;
}
void ArvBinBusca::AUXcriaVetFolhas(NoArv *p, int *vet,int k, int *n)
{

    if(p == NULL)
        return;
    if(k >= 0)
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            vet[(*n)++] = p->getInfo();





        AUXcriaVetFolhas(p->getEsq(), vet, k-1, n);
        AUXcriaVetFolhas(p->getDir(), vet, k-1, n);
    }
}

//-Q1
// ----------------------------------------------------------------------------

// ------------------------------------------------------------------------
//Q2
int ArvBinBusca::classificaFilhos(NoArv *pai)
{
    if(pai == NULL)
        return -2;

    if(pai->getDir() == NULL && pai->getEsq() == NULL)
        return 0;
    if(pai->getDir() != NULL && pai->getEsq() != NULL)
        return 2;
    if(pai->getDir() != NULL && pai->getEsq() == NULL)
        return 1;
    if(pai->getDir() == NULL && pai->getEsq() != NULL)
        return -1;

}



int ArvBinBusca::contaNos1Filho(int val)
{
    if(raiz == 0)
        return 0;

    int num =0;
    NoArv *p = raiz;
    while(p != NULL){

        if(classificaFilhos(p) == -1 || classificaFilhos(p) == 1)
            num++;
        if(p->getInfo() < val)
            p=p->getDir();
        else if(p->getInfo() > val)
            p=p->getEsq();
        else
            break;

    }
    return num;
}
//-Q2
// ------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//Q3
NoArv* ArvBinBusca::auxRemoveMenor (NoArv *p, int val)
{
    if(p == NULL)
        return NULL;


    if (p->getInfo() < val)
    {

        NoArv *dir = p->getDir(); // Salva direita, pode ser maior que val

        p->setDir(NULL); // Separa a direita e libera p, que é menor
        libera(p);


        dir = auxRemoveMenor(dir, val);      // Faz verificações para a direita
        return dir;
    }
    else
        p->setEsq(auxRemoveMenor(p->getEsq(), val));
    return p;
}
//-Q3
// ----------------------------------------------------------------------------
/*


dir 11
apaga direita de P
apaga 9

11 = null

*/
