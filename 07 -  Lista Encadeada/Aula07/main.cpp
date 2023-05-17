#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaEncad.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1) ; /// retorna um numero inteiro aleatório entre a e b
}

int main()
{
    ListaEncad l; /// cria lista vazia
    int NumNos = 12;

    srand(time(NULL));
    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: "<< endl;
    for(int i = 1; i <= NumNos; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleatório entre 0 e 50
        cout<< "inserindo: " << val << endl;
        l.insereInicio(val);
    }
    cout << endl;

    bool existe = l.busca(20);
    cout << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;
// -------------------------------------------------------------------------
    l.imprime();
    cout << "Numero de nos:" <<l.numNos() << endl;
    cout << "Indice com valor maior: "<<l.buscaMaior(40) << endl;
    //l.limpar();  funcionando
    //l.imprime();
    cout<< "Media:" << l.calculaMedia() << endl;
//-------------------------------------
    cout << l.inserePosicaoVal(0, 4) << endl;
    l.imprime();

    l.menorProximo();


    return 0;
};

