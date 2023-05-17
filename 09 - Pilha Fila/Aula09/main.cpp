#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"

using namespace std;





int main()
{
    /// TESTE COM PILHA
    PilhaEncad p;
    cout << "-------------------"<< endl;

    for(int i = 0; i < 5; i++) p.empilha(i);
    cout << "Pilha apos inserir 5 valores" << endl;
    p.imprime();


    for(int i = 20; i < 25; i++) p.empilha(i);
    cout << "Pilha apos inserir mais 5 valores" << endl;
    p.imprime();
    cout << "tamanho:"<< p.tamanho() << endl;

    // teste questao


    //p.removeDaPilha(&p2, x);


    cout << "-------------------"<< endl;
    /// TESTE COM FILA



    FilaEncad f;
    /*for(int i=0; i<5; i++) f.enfileira(i);
    cout << "Fila apos inserir 5 valores" << endl;
    f.imprime();

    for(int i = 20; i < 25; i++) f.enfileira(i);
    cout << "Fila apos inserir mais 5 valores" << endl;
    f.imprime(); */
    f.enfileira(15);
    f.enfileira(85);
    f.enfileira(71);
    f.enfileira(75);
    f.enfileira(62);
    f.enfileira(70);
    f.enfileira(30);
    f.enfileira(92);
    f.enfileira(100);
    f.enfileira(54);
    f.imprime();
    cout << "teste::"<< endl;



    f.reorganiza(&f);

    return 0;
}
