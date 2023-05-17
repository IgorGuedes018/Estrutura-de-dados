#include <iostream>
#include "MatrizLin.h"

using namespace std;

void imprime(MatrizLin *m)
{
    for(int i = 0; i < m->getLinhas(); i++)
    {
        for(int j = 0; j < m->getColunas(); j++)
            cout << m->get(i, j) << " ";
        cout << endl;
    }
}

int main()
{
    MatrizLin m(3, 3);
    m.le();
    //m.imprime();
    imprime(&m);

    MatrizLin m2(3, 4);
    m2.le();
    //m.imprime();
    imprime(&m2);

    return 0;
}
