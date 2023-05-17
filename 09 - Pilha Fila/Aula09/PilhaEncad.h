#ifndef PILHAENCAD_H_INCLUDED
#define PILHAENCAD_H_INCLUDED
#include "No.h"

using namespace std;

class PilhaEncad
{
private:
    No *topo;                /// ponteiro p/ o No do topo
    int tam =0;

public:
    PilhaEncad();
    ~PilhaEncad();
    int getTopo();           /// retorna valor do No do topo
    void empilha(int val);   /// insere No no topo
    int desempilha();        /// elimina No do topo
    bool vazia();            /// verifica se está vazia

    void imprime();
    int tamanho();
    void removeDaPilha(PilhaEncad *p, int x);
};

#endif // PILHAENCAD_H_INCLUDED
