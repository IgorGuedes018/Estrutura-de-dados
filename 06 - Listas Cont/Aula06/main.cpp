#include <iostream>
#include "Ponto.h"
#include "ListaCont.h"

using namespace std;

int main()
{
    ListaCont l(10);

    l.insereFinal(24);
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(-1);
    l.insereFinal(99);
    l.imprime();

    cout << "Numero de nos:" << l.numNos() << endl;
    // l.limpar();
    // l.imprime();

    int vetor[4]= {6, 7, 8, 9};

    l.insereValores(4, vetor);

    return 0;
}
