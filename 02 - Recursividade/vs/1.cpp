#include <iostream>

using namespace std;

int fatorial(int n)
{
    if(n == 1)
        return 1;
    else
        return (n * fatorial(n-1) );
}

int main()
{
    int n;
    cout << "digite um numero: "<< endl;
    cin >> n;


    cout << fatorial(n);
    

    return 0;
}
