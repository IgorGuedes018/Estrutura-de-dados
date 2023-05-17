#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include "NoArv.h"

class No
{
  public:
    No() { } ;
    ~No() { } ;
    NoArv* getInfo()       { return info; } ;
    No* getProx()          { return prox; } ;
    void setInfo(NoArv *p) { info = p; } ;
    void setProx(No *p)    { prox = p; } ;
  private:
    NoArv *info;
    No *prox;
};

#endif // NO_H_INCLUDED
