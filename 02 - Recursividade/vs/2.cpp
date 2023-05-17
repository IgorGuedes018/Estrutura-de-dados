#include <iostream>

using namespace std;

void imprimeIntervalo(int a, int b, int inc)
{

    if(a == b)
    {
        cout << a;
    }
    if(a < b)
    { 
        cout << a << endl;
        imprimeIntervalo(a+inc, b, inc);
    }
}

int main()
{
    int a, b, inc;

    cout << "digite A:";
    cin>> a;
    
    cout << endl << "digite B:";
    cin>> b;

    cout << endl << "digite INC:";
    cin>> inc;

    imprimeIntervalo(a, b,  inc);

    return 0;
}
