#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
    ArvBinBusca arv;

    cout << "Criando uma Arvore Binaria de Busca (ABB)" << endl;
    arv.insere(15); arv.insere(9);  arv.insere(20);
    arv.insere(7);  arv.insere(11); arv.insere(18);
    arv.insere(24); arv.insere(6);  arv.insere(8);
    arv.insere(10); arv.insere(12); arv.insere(17);
    arv.insere(19); arv.imprime(); cout << endl;


    cout<<"TESTES PARA A QUESTAO 1 ------------------------------------------------"<<endl;
    int *vet, n = 0;
    vet = arv.criaVetFolhas(3, &n);
    cout << "Vetor:    ";
    if(vet) for(int i = 0; i < n; i++)
        cout << vet[i] << " ";
    cout << endl;
    cout << "Esperado: 6 8 10 12 17 19 24 (alem dos possiveis valores -1)" << endl << endl;
    delete [] vet;
    cout << endl;
    // -----------------------------------------------------------------------------


    cout<<"TESTES PARA A QUESTAO 2 ------------------------------------------------"<<endl;
    ArvBinBusca arv1, arv2, arv3;

    cout << "Esperado: 0,  Obtido: " <<arv1.contaNos1Filho(80)<<endl;

    for(int i=1; i<=40; i++)
    {
        arv1.insere(i);
        arv2.insere(41 - i);
        if(i<= 41 - i)
        {
            arv3.insere(i);
            arv3.insere(41 - i);
        }
    }

    cout << "Esperado: 0,  Obtido: " <<arv.contaNos1Filho(16)<<endl;
    cout << "Esperado: 39, Obtido: " <<arv1.contaNos1Filho(80)<<endl;
    cout << "Esperado: 39, Obtido: " <<arv2.contaNos1Filho(-80)<<endl;
    cout << "Esperado: 39, Obtido: " <<arv3.contaNos1Filho(21)<<endl;
    cout << endl << endl;
    // -----------------------------------------------------------------------------



    cout<<"TESTES PARA A QUESTAO 3 ------------------------------------------------"<<endl;
    cout << "Removendo nos menores do que 6" << endl;
    arv.removeMenor (6);
    arv.imprime ();
    cout << "    Esperado: 6 7 8 9 10 11 12 15 17 18 19 20 24" << endl << endl;

    cout << "Removendo nos menores do que 7" << endl;
    arv.removeMenor (7);
    arv.imprime ();
    cout << "    Esperado: 7 8 9 10 11 12 15 17 18 19 20 24" << endl << endl;

    cout << "Removendo nos menores do que 11" << endl;
    arv.removeMenor (11);
    arv.imprime ();
    cout << "    Esperado: 11 12 15 17 18 19 20 24" << endl << endl;

    cout << "Removendo nos menores do que 15" << endl;
    arv.removeMenor (15);
    arv.imprime ();
    cout << "    Esperado: 15 17 18 19 20 24" << endl << endl;

    cout << "Removendo nos menores do que 18" << endl;
    arv.removeMenor (18);
    arv.imprime ();
    cout << "    Esperado: 18 19 20 24" << endl << endl;

    cout << "Removendo nos menores do que 23" << endl;
    arv.removeMenor (23);
    arv.imprime ();
    cout << "    Esperado: 24" << endl << endl;

    cout << "Removendo nos menores do que 50" << endl;
    arv.removeMenor (50);
    arv.imprime ();
    cout << "    Esperado: " << endl << endl;
    // -----------------------------------------------------------------------------

    return 0;
}

