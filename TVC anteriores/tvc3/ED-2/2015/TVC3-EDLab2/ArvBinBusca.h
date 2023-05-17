#ifndef TVC3_ARVBINBUSCA_H
#define TVC3_ARVBINBUSCA_H

#include <iostream>
#include <cstdlib>
#include "No.h"

using namespace std;

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    void imprime();
    void insere(int x);
    int consultaRaiz();
    bool vazia();
    bool busca(int x);
    int numNos();

    // Questao 1  ------------------------------------------------------------
    int contaIntervalo(int a, int b);

    // Questao 2 --------------------------------------------------------------
    No* buscaPai(int x);

    // Questao 3 --------------------------------------------------------------
    int * criaVetNivel(int k);

private:

    No * raiz;

    // funcoes auxiliares
    No * auxInsere(No * p, int x);
    bool auxBusca(No * p, int x);
    void auxImprime(No * p, int nivel);
    int auxNumNos(No * p);
    //--------
    int AUXcontaIntervalo(No *p ,int a, int b, int *num);
    No * AUXbuscaPai(No *p, int x);
    void AUXcriaVetNivel(No *p, int *vet, int atual, int k, int *pos);

};


#endif //TVC3_ARVBINBUSCA_H
