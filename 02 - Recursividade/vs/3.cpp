#include <iostream>

using namespace std;

void imprimeDecrescente(int n)
{
    if(n > 0)
    {
        cout << n << " ";
        imprimeDecrescente(n-1); 
    }
    if(n<0)
    {
        cout << n << " ";
        imprimeDecrescente(n+1); 
    }

}

int main()
{
    int n;
    cout << "digite um valor:";
    cin >> n;


    imprimeDecrescente(n);
    
    return 0;
}
