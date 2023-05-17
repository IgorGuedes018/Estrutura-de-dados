#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
    ArvBin arv;
    arv.montaArvore();
    arv.insere(15);
    arv.insere(25);
    arv.insere(10);
    arv.preOrdem();
    //--------------
    /*
    cout << endl<< "numero de nos:" << arv.contaNos();
    cout << endl<< "numero de :" << arv.contaNosFolhas();

    cout << endl<< "altura:" << arv.altura();
    cout << endl<< "impar:" << arv.contaImpar();
    cout << endl<< "Folhas Impares:" << arv.contaFolhaImpar();

    //arv.imprimeNivel(2);                                        //6
    cout << endl<< "Media por nivel:" << arv.mediaNivel(2);      //7
    cout << endl<< "valor minimo:" << arv.minimo() << endl<< "valor maximo:" << arv.maximo();  // 8
    cout << endl;
    //arv.inverte();
    //arv.preOrdem(); //9

    //------ ERRO----------
    // cout << endl<< "esquerda:" << arv.noMaisEsquerda() << endl<< "direita:" << arv.noMaisDireita();
    //------ ERRO----------

    */
    arv.contaElegante();
}
