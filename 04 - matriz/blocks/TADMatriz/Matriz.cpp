#include <iostream>
#include "Matriz.h"

using namespace std;

Matriz::Matriz(int nl, int nc)
{
    linhas = nl;
    colunas = nc;
    mat = new float*[linhas];
    for(int i = 0; i < linhas; i++)
        mat[i] = new float[colunas];
}

Matriz::~Matriz()
{
    for(int i = 0; i < linhas; i++)
        delete [] mat[i];
    delete [] mat;
}

float Matriz::get(int linha, int coluna)
{
    if(verifica(linha, coluna))
        return mat[linha][coluna];
    cout << "indice invalido" << endl;
    exit(1);
}

void Matriz::set(int linha, int coluna, float valor)
{
    if(verifica(linha, coluna))
        mat[linha][coluna] = valor;
    else
        cout << "indice invalido" << endl;
}

bool Matriz::verifica(int linha, int coluna)
{
    return linha>=0 && linha<linhas && coluna>= 0 && coluna<colunas;
}

void Matriz::imprime()
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
