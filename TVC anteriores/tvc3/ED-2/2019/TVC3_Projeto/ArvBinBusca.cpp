#include "ArvBinBusca.h"
#include <cmath>

// ----------------------------------------------------------------------------
//Q1

void ArvBinBusca::nosImpares02Filhos(int *nImp, int *n02F)
{
    *nImp =0;
    *n02F =0;
    AUXnosImpares02Filhos(raiz, nImp, n02F);
}
void ArvBinBusca::AUXnosImpares02Filhos(NoArv *p, int *nImp, int *n02F)
{
    if(p != NULL)
    {
        if(p->getInfo() %2 != 0)
            *nImp += 1;    // impares
        if(p->getEsq() == NULL  && p->getDir() == NULL)
            *n02F += 1;     // 0 filhos
        else if(p->getEsq() != NULL  && p->getDir() != NULL)
            *n02F += 1;     // 2 filhos

        AUXnosImpares02Filhos(p->getEsq(), nImp, n02F);
        AUXnosImpares02Filhos(p->getDir(), nImp, n02F);
    }
}
//-Q1

// ----------------------------------------------------------------------------
//Q2

void ArvBinBusca::insNaoRec(int val)
{
    NoArv *p =raiz;
    NoArv *pai;

    while(p!= NULL)
    {

        if(val > p->getInfo() )
        {
            pai =p;
            p= p->getDir();

        }
        else if( val < p->getInfo())
        {
            pai =p;
            p=p->getEsq();
        }
        else
        {
            cout << "No ja existente na arvore." << endl;
            return;
        }
        //chegou onde deve colocar o no
    }

    NoArv *novo = new NoArv;
    novo->setDir(NULL);
    novo->setEsq(NULL);
    novo->setInfo(val);

    if(raiz == NULL)
    {
        raiz = novo;
    }
    else
    {
        if(val > pai->getInfo()) // caso val va para a direita
        {
            pai->setDir(novo);
        }
        else                       // esquerda
            pai->setEsq(novo);
    }
}
//-Q2

// ----------------------------------------------------------------------------
//Q3

int* ArvBinBusca::vetIntervalo(int a, int b, int k)
{
    int tam = pow(2, k) +1;
    int *vet = new int[tam];
    int pos =0;
    AUXvetIntervalo(raiz, vet, &pos,a, b, k, 0);

    for(int i=pos; i <tam; i++)
        vet[i] = -1;
    return vet;
}

int* ArvBinBusca::AUXvetIntervalo(NoArv *p,int vet[] ,int *pos,int a, int b, int k, int atual)
{

   if(p!= 0)
   {
       if(p->getInfo() > a)
            AUXvetIntervalo(p->getEsq(), vet, pos, a, b,k, atual+1);
        if(atual == k && p->getInfo() >= a && p->getInfo() <= b)
            vet[(*pos)++] = p->getInfo();
        if(p->getInfo() <b)
            AUXvetIntervalo(p->getDir(),vet, pos, a, b,k, atual+1);
   }
}
//-Q3

// ----------------------------------------------------------------------------
// Restante da classe ArvBinBusca
// ----------------------------------------------------------------------------

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
    /// destrutor vazio (só para avaliação)
}

void ArvBinBusca::cria(int c, ArvBinBusca *sae, ArvBinBusca *sad)
{///Só para a avaliação.
    NoArv *p = new NoArv();
    p->setInfo(c);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBinBusca::addValores1()
{//adiciona valores em uma ABB
    ArvBinBusca *arvRaizNula = new ArvBinBusca(), a1, a2;

    a1.cria(-35, arvRaizNula, arvRaizNula);
    this->cria(-19, arvRaizNula, arvRaizNula);
    this->cria(-20, &a1, this);

    a1.cria(-5, arvRaizNula, arvRaizNula);
    a1.cria(10, &a1, arvRaizNula);
    this->cria(-15, this, &a1);

    a1.cria(45, arvRaizNula, arvRaizNula);
    a2.cria(60, arvRaizNula, arvRaizNula);
    a1.cria(50, &a1, &a2);

    a2.cria(80, arvRaizNula, arvRaizNula);
    a1.cria(75, &a1, &a2);

    this->cria(40, this, &a1);
}

void ArvBinBusca::addValores2()
{//adiciona valores em uma ABB
    ArvBinBusca *arvRaizNula = new ArvBinBusca(), a1, a2;

    this->cria(-35, arvRaizNula, arvRaizNula);
    this->cria(-20, this, arvRaizNula);

    a1.cria(-5, arvRaizNula, arvRaizNula);
    a1.cria(10, &a1, arvRaizNula);
    this->cria(-15, this, &a1);

    a1.cria(60, arvRaizNula, arvRaizNula);
    a1.cria(50, arvRaizNula, &a1);
    this->cria(40, this, &a1);
}

void ArvBinBusca::imprime()
{
    auxImprime(raiz);
    cout << endl;
}

void ArvBinBusca::auxImprime(NoArv *p)
{
    if(p != NULL)
    {
        auxImprime(p->getEsq());
        cout << p->getInfo() << " ";
        auxImprime(p->getDir());
    }
}

void ArvBinBusca::imprime2()
{
    auxImprime2(raiz, 0);
    cout << endl;
}
void ArvBinBusca::auxImprime2(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 0; i < nivel; i++)
            cout << "~~";
        cout << p->getInfo() << endl;
        auxImprime2(p->getEsq(), nivel+1);
        auxImprime2(p->getDir(), nivel+1);
    }
}
