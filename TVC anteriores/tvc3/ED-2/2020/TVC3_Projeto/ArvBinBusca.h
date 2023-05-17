#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    void insere(int val);
    void imprime();
    void removeMenor(int val);

    //Q1
    int* criaVetFolhas(int k, int *n);

    //Q2
    int contaNos1Filho(int val);

private:
    NoArv* raiz; // ponteiro para o No raiz da árvore

    NoArv* libera(NoArv *p);
    NoArv* auxInsere(NoArv *p, int val);
    void imprimeEmOrdem(NoArv* p);
    void AUXcriaVetFolhas(NoArv *p, int *vet,int k, int *n);
    //Q2
    int classificaFilhos(NoArv *pai);

    //Q3
    NoArv* auxRemoveMenor(NoArv *p, int val);
};

#endif // ARVBINBUSCA_H_INCLUDED
