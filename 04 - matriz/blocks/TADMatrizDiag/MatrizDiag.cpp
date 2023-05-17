#include <iostream>
#include "MatrizDiag.h"

using namespace std;

MatrizDiag::MatrizDiag(int tam)
{
    dim = tam;
    vet = new float[dim];
}

MatrizDiag::~MatrizDiag()
{
    delete [] vet;
}

float MatrizDiag::get(int linha, int coluna)
{
    int k = detInd(linha, coluna);
    if(k == -2)
        return 0;
    if(k != -1)
        return vet[k];
    cout << "indice invalido" << endl;
    exit(1);
}

void MatrizDiag::set(int linha, int coluna, float valor)
{
    int k = detInd(linha, coluna);
    if(k == -2 && valor != 0)
        cout << "valor invalido" << endl;
    else if(k == -1)
        cout << "indice invalido" << endl;
    else
        vet[k] = valor;
}

int MatrizDiag::detInd(int linha, int coluna)
{
    if(linha >= 0 && linha < dim && coluna >= 0 && coluna < dim)
    {
        if(linha == coluna)
            return linha;
        else
            return -2;
    }
    else
        return -1;
}
