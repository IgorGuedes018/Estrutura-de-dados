#ifndef MATRIZLIN_H_INCLUDED
#define MATRIZLIN_H_INCLUDED

class MatrizLin
{
public:
    MatrizLin(int nl, int nc);
    ~MatrizLin();

    float get(int linha, int coluna);
    void set(int linha, int coluna, float valor);

    void le();
    void imprime();

    int getLinhas();
    int getColunas();
private:
    int linhas; // numero de linhas
    int colunas; // numero de colunas
    float *vet; // vetor
    int detInd(int linha, int coluna);
};

#endif // MATRIZLIN_H_INCLUDED
