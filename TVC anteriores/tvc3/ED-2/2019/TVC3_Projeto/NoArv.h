#ifndef NOARV_H
#define NOARV_H

class NoArv
{
public:
    NoArv()                   {};
    ~NoArv()                  {};
    void setInfo(int val)     { info = val;  };
    void setEsq(NoArv *p)     { esq = p;     };
    void setDir(NoArv *p)     { dir = p;     };
    int getInfo()             { return info; };
    NoArv* getEsq()           { return esq;  };
    NoArv* getDir()           { return dir;  };

private:
    int info;     // informação do No (int)
    NoArv *esq;   // ponteiro para o filho a esquerda
    NoArv *dir;   // ponteiro para o filho a direita
};

#endif //NOARV_H
