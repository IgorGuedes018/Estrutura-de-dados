#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

class Matriz
{
public:
    Matriz(int nl, int nc);
    ~Matriz();
    float get(int linha, int coluna);
    void set(int linha, int coluna, float valor);
    void imprime();
private:
    int linhas; // numero de linhas
    int colunas; // numero de colunas
    float **mat; // matriz
    bool verifica(int linha, int coluna);
};

#endif // MATRIZ_H_INCLUDED
