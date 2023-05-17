#include <iostream>
#include "ArvBin.h"

using namespace std;

int main()
{
    ArvBin f1, f2, f3, i1, i2, i3, i4, r, vazia;

    f1.cria(16, &vazia, &vazia);
    f2.cria(19, NULL, NULL);
    f3.cria(38, &vazia, &vazia);

    i1.cria(14, &f1, NULL);
    i2.cria(18, NULL, &f2);

    i3.cria(12, &i1, &i2);
    i4.cria(25, NULL, &f3);

    r.cria(10, &i3, &i4);

    r.imprime();

    r.imprimeNivel(2);

    r.percursoLargura();

    cout << "Altura: " << r.altura() << endl;
    cout << "Nos   : " << r.contaNos() << endl;
    cout << "Nos2  : " << r.contaNos2() << endl;
    cout << "Soma  : " << r.somaNos() << endl;
    cout << "Media : " << r.somaNos()/r.contaNos() << endl;
    cout << "Media : " << r.mediaNos() << endl;
    r.estatisticasNos();

    f1.anulaRaiz();
    f2.anulaRaiz();
    f3.anulaRaiz();
    i1.anulaRaiz();
    i2.anulaRaiz();
    i3.anulaRaiz();
    i4.anulaRaiz();

    ///

    /*
    ArvBin arv;
    arv.montaArvore();
    arv.imprime();

    arv.insere(14);
    arv.insere(22);
    arv.imprime();
    */

    return 0;
}
