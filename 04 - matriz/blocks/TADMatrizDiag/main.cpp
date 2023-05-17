#include <iostream>
#include "MatrizDiag.h"

using namespace std;

int main()
{
    MatrizDiag m(5);
    float val;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
        {
            cout << "Valor " << i << ", " << j << ": ";
            cin >> val;
            m.set(i, j, val);
        }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cout << m.get(i, j) << " ";
        cout << endl;
    }

    return 0;
}
