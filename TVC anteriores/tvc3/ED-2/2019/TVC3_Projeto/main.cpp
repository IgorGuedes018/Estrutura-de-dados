// ############################################################################
// TVC 3 -- ESTRUTURA DE DADOS e LABORATORIO DE PROGRAMACAO II
// DATA: 25/11/2019
// PREENCHER ESTE CABECALHO COM SUAS INFORMACOES
// ALUNO:
// MATRICULA:
// ############################################################################
#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

///protótipos das funções para os testes de cada questão (Q1, Q2 e Q3)
void testeQ1(ArvBinBusca);
void testeQ2(ArvBinBusca*, int*, int);
void testeQ3(ArvBinBusca, int, int, int);

int main()
{
    cout << "TVC3 -- ESTRUTURA DE DADOS e LAB. DE PROG. II" << endl;
    cout << "FAVOR PREENCHER OS SEUS DADOS" << endl;
    cout << "Exemplo de ABB: " << endl;

    // ARVORES DE TESTE
    ArvBinBusca abb1,abb2,abb3;

    cout << "Arvore 1:" << endl;
    abb1.addValores1(); //adiciona valores na ABB
    abb1.imprime();

    cout << "Arvore 2:" << endl;
    abb2.addValores2();
    abb2.imprime();

    //SUGESTAO: TESTE COM OUTRAS ARVORES BINARIAS TAMBEM!

    // TESTE DA QUESTAO 1 -----------------------------------------------------
    cout << endl << "-------TESTE DA QUESTAO 1----------" << endl;
    testeQ1(abb1);
    testeQ1(abb2);
    cout << endl;
    // ------------------------------------------------------------------------
    // TESTE DA QUESTAO 2 -----------------------------------------------------
    cout << endl << "-------TESTE DA QUESTAO 2----------" << endl;
    int valores[] = {45, -19, 75, 80}; ///valores que serão adicionados na abb2
    testeQ2(&abb2, valores, 4);
    abb2.insNaoRec(45);///testa repetição de elementos
    cout <<"Arvore abb2 apos insercao de 4 valores"<<endl;
    abb2.imprime();///após a insersão dos 4 valores acima, abb2 conterá os mesmos valores de abb1

    testeQ2(&abb3, valores, 4); ///os mesmos valores serão adicionados na arvore vazia abb3
    cout <<"Arvore abb3 apos insercao de 4 valores"<<endl;
    abb3.imprime();
    cout << endl;
    // ------------------------------------------------------------------------


    // TESTE DA QUESTAO 3 -----------------------------------------------------
    cout << endl << "-------TESTES DA QUESTAO 3----------" << endl;
    testeQ3(abb1, -35, 60, 3); ///intervalo [-35, 60], nivelk = 3
    testeQ3(abb1, -10, 90, 2);  ///intervalo [-10, 90], nivelk = 2
    testeQ3(abb1, -100, 800, 5); ///intervalo [-100, 800], nivelk = 5
    testeQ3(abb1, -1, 0, 5); ///intervalo [-1, 0], nivelk = 5
    testeQ3(abb1, 200, 300, 5);///intervalo [200, 300], nivelk = 5

    return 0;
}
void testeQ1(ArvBinBusca abb)
{
    int nImp, n2f;

    abb.nosImpares02Filhos(&nImp, &n2f);
    cout<<"A arvore contem "<<nImp<<" nos impares e "<<n2f<<" nos com 0 ou 2 filhos"<<endl;
}

void testeQ2(ArvBinBusca *arvbb, int valores[], int n)
{
   for(int i=0; i<n; i++)
      arvbb->insNaoRec(valores[i]);
}

void testeQ3(ArvBinBusca arv, int a, int b, int nivel)
{
   int *vOrd;
   vOrd = arv.vetIntervalo(a, b, nivel);

   cout<<endl<<"Vetor ordenado do nivel: "<<nivel<<endl;
   if(vOrd != NULL)
   {

        for(int i=0; vOrd[i] != -1; i++)
            cout<<vOrd[i]<<" ";
        delete [] vOrd;
   }

   cout << endl;
}
