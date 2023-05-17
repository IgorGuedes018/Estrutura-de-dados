#ifndef FILAENCAD_H_INCLUDED
#define FILAENCAD_H_INCLUDED
#include "No.h"
#include "NoArv.h"

class FilaEncad
{
  private:
    No *inicio; // ponteiro para No do comeco
    No *fim; // ponteiro para No do fim
  public:
    FilaEncad();
    ~FilaEncad();
    NoArv* getInicio(); // retorna No do inicio
    void enfileira(NoArv *p); // insere No no fim
    NoArv* desenfileira(); // elimina No do inicio
    bool vazia(); // verifica se esta vazia
    void imprime(); // operação não convencional
};

#endif // FILAENCAD_H_INCLUDED
