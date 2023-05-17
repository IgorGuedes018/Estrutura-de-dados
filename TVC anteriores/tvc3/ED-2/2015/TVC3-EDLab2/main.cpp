// ############################################################################
// TVC 3 de ESTRUTURA DE DADOS e LABORATORIO DE PROGRAMACAO 2
// DATA: 07/03/2016 - PROF.: BERNARDO MARTINS ROCHA
// PREENCHER ESTE CABECALHO COM SUAS INFORMACOES
// ALUNO:
// MATRICULA:
// ############################################################################

#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
    cout << "TVC3 de ESTRUTURA DE DADOS e LAB. PROG. II" << endl;
    cout << "ABB EXEMPLO: " << endl;

    ArvBinBusca abb;
    abb.insere(40);
    abb.insere(15);
    abb.insere(10);
    abb.insere(20);
    abb.insere(35);
    abb.insere(75);
    abb.insere(19);
    abb.insere(50);
    abb.insere(80);
    abb.insere(45);
    abb.insere(60);
    abb.imprime();

    // TESTE DA QUESTAO 1 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 1" << endl;
    int total = abb.contaIntervalo(20,50);
    cout << "No intervalo [20,50] existem " << total << " nos" << endl;
    // ------------------------------------------------------------------------

    // TESTE DA QUESTAO 2 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 2" << endl;
    No * p = abb.buscaPai(60);
    if(p != NULL)
    {
        cout << "Valor do no pai = " << p->getInfo() << endl;
    }
    // ------------------------------------------------------------------------

    // TESTE DA QUESTAO 3 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 3" << endl;
    int * v = abb.criaVetNivel(2);
    int n = abb.numNos();
    if(v != NULL)
    {
        for(int i=0; i<n; i++)
            cout << v[i] << " ";
        cout << endl;
        delete [] v;
    }
    else
    {
        cout << "Implemente a operacao criaVetNivel() corretamente." << endl;
    }
    // ------------------------------------------------------------------------


    return 0;
}
