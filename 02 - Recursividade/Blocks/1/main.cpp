#include <iostream>

using namespace std;

void imprimeDecrescente(int n)
{
    if(n<0)
    {
        cout << n<< endl;
        if(n !=0)
            imprimeDecrescente(n+1);
    }

    if(n>0)
    {
      cout << n<< endl;
        if(n !=0)
        imprimeDecrescente(n-1);
    }

}


int main()
{
    int n;
    cin >> n;


    imprimeDecrescente(n);


    return 0;
}
