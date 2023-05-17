#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
private:
    NoArv *raiz; // ponteiro para o nó raiz da árvore

    void libera(NoArv *p);
    void auxImprime(NoArv *p, int nivel);
    void auxImprimeNivel(NoArv *p, int atual, int k);
    bool auxBusca(NoArv *p, int val);
    NoArv* auxMontaArvore();
    NoArv* auxInsere(NoArv *p, int val);
    int auxContaNos(NoArv *p);
    void auxContaNos2(NoArv *p, int *cont);
    int auxSomaNos(NoArv *p);
    void auxMediaNos(NoArv *p, int *cont, int *soma);
    void auxEstatisticasNos(NoArv *p, int *cont2f,
         int *cont1fe, int *cont1fd, int *folhas);
    int auxAltura(NoArv *p);

public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void anulaRaiz();
    void cria(int val, ArvBin *sae, ArvBin *sad); // cria novo nó como raiz das sub-árvores à esquerda (sae) e à direita (sad)
    bool vazia(); // verifica se a árvore está vazia
    void imprime();
    void imprimeNivel(int k);
    bool busca(int val);
    void montaArvore();
    void insere(int val);
    int contaNos();
    int contaNos2();
    int somaNos();
    float mediaNos();
    void estatisticasNos();
    int altura();
    void percursoLargura();
};

#endif // ARVBIN_H_INCLUDED
