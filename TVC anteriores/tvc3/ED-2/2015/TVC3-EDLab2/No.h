#ifndef TVC3_NO_H
#define TVC3_NO_H

class No
{
public:
    No()                   {};
    ~No()                  {};
    void setInfo(int val)  { info = val;  };
    void setEsq(No *p)     { esq = p;     };
    void setDir(No *p)     { dir = p;     };
    int getInfo()          { return info; };
    No* getEsq()           { return esq;  };
    No* getDir()           { return dir;  };

private:
    int info; // informação do No (int)
    No *esq;   // ponteiro para o filho a esquerda
    No *dir;   // ponteiro para o filho a direita

};

#endif
