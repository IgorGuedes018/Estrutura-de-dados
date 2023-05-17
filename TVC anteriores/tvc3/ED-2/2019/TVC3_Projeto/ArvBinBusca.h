#ifndef ARVBINBUSCA_H
#define ARVBINBUSCA_H
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "NoArv.h"

using namespace std;

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    void addValores1();
    void addValores2();
    void imprime();
    void imprime2();

    // Questao 1  -------------------------------------------------------------
    void nosImpares02Filhos(int *nImp, int *n02F);


    // Questao 2  -------------------------------------------------------------
    void insNaoRec(int val);


    // Questao 3  -------------------------------------------------------------
    int* vetIntervalo(int a, int b, int k);
private:
    NoArv *raiz;

    void auxImprime(NoArv *p);
    void auxImprime2(NoArv *p, int nivel);
    void cria(int c, ArvBinBusca *sae, ArvBinBusca *sad);
    // ------
    void AUXnosImpares02Filhos(NoArv *p, int *nImp, int *n02F);
    int* AUXvetIntervalo(NoArv *p,int vet[] ,int *pos,int a, int b, int k, int atual);

};

#endif //ARVBINBUSCA_H
