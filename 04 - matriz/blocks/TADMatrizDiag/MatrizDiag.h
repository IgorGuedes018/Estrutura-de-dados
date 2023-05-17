#ifndef MATRIZDIAG_H_INCLUDED
#define MATRIZDIAG_H_INCLUDED

class MatrizDiag
{
public:
    MatrizDiag(int tam);
    ~MatrizDiag();
    float get(int linha, int coluna);
    void set(int linha, int coluna, float valor);
private:
    int dim; // numero de linhas e colunas
    float *vet; // vetor
    int detInd(int linha, int coluna);
};

#endif // MATRIZDIAG_H_INCLUDED
