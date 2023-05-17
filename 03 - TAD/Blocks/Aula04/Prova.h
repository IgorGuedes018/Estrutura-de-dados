#ifndef PROVA_H
#define PROVA_H

#include <iostream>

using namespace std;

class Prova
{
    public:
        Prova(int nq);
        void leNotas();
        void calculaNotaFinal();
        double obtemNotaFinal();

    private:
        int n;
        double notaFinal;
        double *notasQuestoes;
};

#endif // PROVA_H
