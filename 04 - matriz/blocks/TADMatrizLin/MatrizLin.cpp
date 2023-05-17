#include <iostream>
#include "MatrizLin.h"

using namespace std;

MatrizLin::MatrizLin(int nl, int nc)
{
    linhas = nl;
    colunas = nc;
    vet = new float[linhas*colunas];
}

MatrizLin::~MatrizLin()
{
    delete [] vet;
}

float MatrizLin::get(int linha, int coluna)
{
    int k = detInd(linha, coluna);
    if(k != -1)
        return vet[k];
    cout << "indice invalido" << endl;
    exit(1);
}

void MatrizLin::set(int linha, int coluna, float valor)
{
    int k = detInd(linha, coluna);
    if(k != -1)
        vet[k] = valor;
    else
        cout << "indice invalido" << endl;
}

int MatrizLin::detInd(int linha, int coluna)
{
    if(linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas)
        return linha*colunas + coluna;
    else
        return -1;
}

void MatrizLin::le()
{
    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
        {
            cout << "Valor " << i << ", " << j << ": ";
            cin >> vet[i*colunas + j];
        }
}

void MatrizLin::imprime()
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
            cout << vet[i*colunas + j] << " ";
        cout << endl;
    }
}

int MatrizLin::getLinhas()
{
    return linhas;
}

int MatrizLin::getColunas()
{
    return colunas;
}
