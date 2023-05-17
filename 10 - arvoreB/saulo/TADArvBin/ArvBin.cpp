#include <iostream>
#include <sstream>
#include "ArvBin.h"
#include "FilaEncad.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

ArvBin::~ArvBin()
{
    libera(raiz);
}

void ArvBin::libera(NoArv *p)
{
    if(p != NULL)
    {
        libera(p->getEsq());
        libera(p->getDir());
        delete p;
    }
}

int ArvBin::getRaiz()
{
    if(raiz != NULL) //ou if(!vazia())
        return raiz->getInfo();
    else
    {
        cout << "Árvora vazia!" << endl;
        exit(1);
    }
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

bool ArvBin::vazia()
{
    return raiz == NULL;
}

void ArvBin::cria(int val, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(val);
    if(sae == NULL)
        p->setEsq(NULL);
    else
        p->setEsq(sae->raiz);

    if(sad == NULL)
        p->setDir(NULL);
    else
        p->setDir(sad->raiz);
    raiz = p;
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
    if(linha != "NULL" && linha != "null" && linha != "N" && linha != "n")
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

void ArvBin::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvBin::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << val << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), val));
        else
            p->setDir(auxInsere(p->getDir(), val));
    }
    return p;
}

void ArvBin::imprime()
{
    auxImprime(raiz, 0);
    cout << endl;
}
void ArvBin::auxImprime(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 0; i < nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        auxImprime(p->getEsq(), nivel+1);
        auxImprime(p->getDir(), nivel+1);
    }
}

void ArvBin::imprimeNivel(int k)
{
    auxImprimeNivel(raiz, 0, k);
    cout << endl;
}
void ArvBin::auxImprimeNivel(NoArv *p, int atual, int k)
{
    if(p != NULL)
    {
        if(atual == k)
            cout << p->getInfo() << endl;
        else
        {
            auxImprimeNivel(p->getEsq(), atual+1, k);
            auxImprimeNivel(p->getDir(), atual+1, k);
        }
    }
}


bool ArvBin::busca(int val)
{
    return auxBusca(raiz, val);
}
bool ArvBin::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    if(p->getInfo() == val)
        return true;
    if(auxBusca(p->getEsq(), val))
        return true;
    return auxBusca(p->getDir(), val);
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

int ArvBin::contaNos()
{
    return auxContaNos(raiz);
}
int ArvBin::auxContaNos(NoArv *p)
{
    if(p == NULL)
        return 0;
    return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
}

int ArvBin::contaNos2()
{
    int cont = 0;
    auxContaNos2(raiz, &cont);
    return cont;
}
void ArvBin::auxContaNos2(NoArv *p, int *cont)
{
    if(p != NULL)
    {
        *cont = *cont + 1;
        auxContaNos2(p->getEsq(), cont);
        auxContaNos2(p->getDir(), cont);
    }
}

int ArvBin::somaNos()
{
    return auxSomaNos(raiz);
}
int ArvBin::auxSomaNos(NoArv *p)
{
    if(p == NULL)
        return 0;
    return p->getInfo() + auxSomaNos(p->getEsq()) + auxSomaNos(p->getDir());
}

float ArvBin::mediaNos()
{
    int cont = 0;
    int soma = 0;
    auxMediaNos(raiz, &cont, &soma);
    return (float)soma/cont;
}
void ArvBin::auxMediaNos(NoArv *p, int *cont, int *soma)
{
    if(p != NULL)
    {
        *cont = *cont + 1;
        *soma = *soma + p->getInfo();
        auxMediaNos(p->getEsq(), cont, soma);
        auxMediaNos(p->getDir(), cont, soma);
    }
}

void ArvBin::estatisticasNos()
{
    int cont2f = 0;
    int cont1fe = 0;
    int cont1fd = 0;
    int folhas = 0;
    auxEstatisticasNos(raiz, &cont2f, &cont1fe, &cont1fd, &folhas);
    cout << "Estatisticas dos Nos:" << endl;
    cout << "2 filhos: " << cont2f << endl;
    cout << "1 filho a esquerda: " << cont1fe << endl;
    cout << "1 filho a direita: " << cont1fd << endl;
    cout << "Folhas: " << folhas << endl;
}
void ArvBin::auxEstatisticasNos(NoArv *p, int *cont2f, int *cont1fe, int *cont1fd, int *folhas)
{
    if(p != NULL)
    {
        if(p->getEsq() != NULL && p->getDir() != NULL)
            *cont2f += 1;
        else if(p->getEsq() != NULL)
            *cont1fe += 1;
        else if(p->getDir() != NULL)
            *cont1fd += 1;
        else
            *folhas += 1;
        auxEstatisticasNos(p->getEsq(), cont2f, cont1fe, cont1fd, folhas);
        auxEstatisticasNos(p->getDir(), cont2f, cont1fe, cont1fd, folhas);
    }
}

void ArvBin::percursoLargura()
{
    FilaEncad f;
    if(raiz != NULL)
    {
        NoArv *p;
        f.enfileira(raiz);
        while(!f.vazia())
        {
            p = f.desenfileira();
            cout << p->getInfo() << endl;
            if(p->getEsq() != NULL)
                f.enfileira(p->getEsq());
            if(p->getDir() != NULL)
                f.enfileira(p->getDir());
        }
    }
}
