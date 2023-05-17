#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    // -----------------
    int contaNos();
    int contaNosFolhas();
    int altura();
    int contaImpar();
    int contaFolhaImpar();
    void imprimeNivel(int k);
    float mediaNivel(int k);
    int minimo();
    int maximo();
    void inverte();
    int noMaisEsquerda();
    int noMaisDireita();
    void contaElegante();
    void contagens(int val);

  private:
    NoArv *raiz; // ponteiro para o No raiz da árvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    void auxInverte(NoArv * p);
    NoArv* auxInsere(NoArv *p, int x);
    // ----------------------
    int auxcontaNos(NoArv *p);
    int auxcontaNosFolhas(NoArv *p);
    int auxAltura(NoArv *p);
    int auxContaImpar(NoArv *p);
    int auxContaFolhaImpar(NoArv *p);
    void auxImprimeNivel(NoArv *p, int k, int nivel);
    float auxMediaNivel(NoArv *p, int k, int *soma, int *contador, int nivel);
    int auxMinimo(NoArv *p, int *valor);
    int auxMaximo(NoArv *p, int *valor);
    void auxInverteValor(NoArv *p);
    int AUXnoMaisEsquerda(NoArv *p);
    int AUXnoMaisDireita(NoArv *p);
    void AUXcontaElegante(NoArv *p, int *par, int *impar);
    void AUXcontagens(NoArv *p, int val, int *multVal, int *folha);


};

#endif // ARVBIN_H_INCLUDED
