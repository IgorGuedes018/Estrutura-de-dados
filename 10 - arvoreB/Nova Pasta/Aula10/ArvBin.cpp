#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Árvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}


void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}
NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}


void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}
NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}


bool ArvBin::vazia()
{
    return (raiz == NULL);
}


bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}
bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}


ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}


void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}
void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}


//-------------------------------------------------------------------------------------

int ArvBin::contaNos()
{
    return auxcontaNos(raiz);
}
int ArvBin::auxcontaNos(NoArv *p)
{
    if( p == 0)
        return 0;
    else
        return 1 + auxcontaNos(p->getEsq()) + auxcontaNos(p->getDir());
}


int ArvBin::contaNosFolhas()
{
    return auxcontaNosFolhas(raiz);
}
int ArvBin::auxcontaNosFolhas(NoArv *p)
{
    if(p== 0)
        return 0;
    else
    {
        if(p->getDir() == 0 && p->getEsq() == 0)
        {
            return 1 + auxcontaNosFolhas(p->getEsq()) + auxcontaNosFolhas(p->getDir());
        }
        else
            return auxcontaNosFolhas(p->getEsq()) + auxcontaNosFolhas(p->getDir());
    }
}

int ArvBin::altura()
{
    return auxAltura(raiz);
}
int ArvBin::auxAltura(NoArv *p)
{
    if(p == NULL)
        return -1;
    int he = auxAltura(p->getEsq());
    int hd = auxAltura(p->getDir());
    if(he > hd)
        return 1 + he;
    return 1 + hd;
}


int ArvBin::contaImpar()
{
    return auxContaImpar(raiz);
}
int ArvBin::auxContaImpar(NoArv *p)
{
    if(p== 0)
        return 0;
    else
    {
        if(p->getInfo() %2 != 0)
        {
            return 1 + auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
        }
        else
            return auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
    }
}


int ArvBin::contaFolhaImpar()
{
    return auxContaFolhaImpar(raiz);
}
int ArvBin::auxContaFolhaImpar(NoArv *p)
{
    if(p== 0)
        return 0;
    else
    {
        if(p->getDir() == 0 && p->getEsq() == 0 && (p->getInfo() %2 != 0))
        {
            return 1 + auxContaFolhaImpar(p->getEsq()) + auxContaFolhaImpar(p->getDir());
        }
        else
            return auxContaFolhaImpar(p->getEsq()) + auxContaFolhaImpar(p->getDir());
    }

}

void ArvBin::imprimeNivel(int k)
{
    auxImprimeNivel(raiz,k , 0);
}
void ArvBin::auxImprimeNivel(NoArv *p, int k, int nivel)
{
    if(p == 0)
        exit(1);
    else
    {
        if(k == nivel)
        {
            cout << "valores:"<< p->getInfo() << " ,";
        }
        auxImprimeNivel(p->getEsq(), k, nivel +1);
        auxImprimeNivel(p->getDir(), k, nivel +1);
    }


}


float ArvBin::mediaNivel(int k)
{
    int contador =0;
    int soma = 0;
    auxMediaNivel(raiz, k, &soma, &contador, 0);
    return (float)soma/contador;
}
float ArvBin::auxMediaNivel(NoArv *p, int k, int *soma, int *contador, int nivel)
{
    if(p == 0)
        return 0;
    if(k == nivel)
    {
        *soma = *soma + p->getInfo(); // somando
        *contador = *contador +1;    // contador de valores somados
    }

    return auxMediaNivel(p->getEsq(), k, soma, contador, nivel+1);
    return auxMediaNivel(p->getDir(), k, soma, contador, nivel+1);
}


int ArvBin::minimo()
{
    int valor =raiz->getInfo();
    return auxMinimo(raiz, &valor);
}
int ArvBin::auxMinimo(NoArv *p, int *valor)
{
    if(p ==0)
        return 0;

    if(*valor > p->getInfo())
        *valor = p->getInfo();

    auxMinimo(p->getEsq(), valor);
    auxMinimo(p->getDir(), valor);

    return *valor;
}


int ArvBin::maximo()
{
    int valor =raiz->getInfo();
    return auxMaximo(raiz, &valor);
}
int ArvBin::auxMaximo(NoArv *p, int *valor)
{
    if(p ==0)
        return 0;

    if(*valor < p->getInfo())
        *valor = p->getInfo();

    auxMaximo(p->getEsq(), valor);
    auxMaximo(p->getDir(), valor);

    return *valor;
}


void ArvBin::inverte()
{
    auxInverteValor(raiz);
}
void ArvBin::auxInverteValor(NoArv *p)
{
    NoArv *aux;

    if(p !=0 )
    {

        auxInverteValor(p->getEsq() );
        auxInverteValor(p->getDir() );

        if(p->getEsq() != 0 && p->getDir() != 0) // caso tenha 2 filhos
        {
            aux = p->getEsq();
            p->setEsq(p->getDir());
            p->setDir(aux);
        }
    }
}


int ArvBin::noMaisEsquerda()
{
    return AUXnoMaisEsquerda(raiz);
}
int ArvBin::AUXnoMaisEsquerda(NoArv *p)
{
    NoArv *aux;
    while( p != NULL)
    {
        aux = p;
        AUXnoMaisEsquerda(p->getEsq());
    }
    return aux->getInfo();
}


int ArvBin::noMaisDireita()
{
    return AUXnoMaisDireita(raiz);
}
int ArvBin::AUXnoMaisDireita(NoArv *p)
{
    NoArv *aux;
    while( p != NULL)
    {
        aux = p;
        AUXnoMaisDireita(p->getDir());

    }
    return aux->getInfo();
}

void ArvBin::contaElegante()
{
    int filhos =0;
    int Mult5=0;
    AUXcontaElegante(raiz, &filhos, &Mult5);
    cout << endl << "pares:" << filhos;
    cout << endl << "folhasP:" << Mult5;
}
void ArvBin::AUXcontaElegante(NoArv *p, int *filhos, int *Mult5)
{
    if(p != 0)
    {
        if(p->getInfo() %5 == 0)
            *Mult5 += 1;
        if(p->getDir() != NULL && p->getEsq() != NULL)
            *filhos != 1;


        AUXcontaElegante(p->getEsq(), filhos, Mult5);
        AUXcontaElegante(p->getDir(), filhos, Mult5);
    }
}


void ArvBin::contagens(int val)
{
    int multVal =0;
    int folha =0;

    AUXcontagens(raiz, val, &multVal, &folha);


}
void ArvBin::AUXcontagens(NoArv *p, int val, int *multVal, int *folha)
{
    AUXcontagens(p->getEsq(), val, multVal,folha);
    if( p != 0)
    {
        if(p->getEsq() == NULL && p->getDir() ==NULL ) // folha
            *folha += 1;
        else if(p->getEsq() == NULL || p->getDir() == NULL)
            *folha += 1;
        if(p->getInfo() %val == 0)
            *multVal +=1;

    }
    AUXcontagens(p->getDir(), val, multVal, folha);

}


