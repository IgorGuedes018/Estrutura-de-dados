#include <iostream>
#include "Matriz.h"

using namespace std;

int main()
{
    Matriz m(3, 3);

    m.set(3, 3, 10);
    float val;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            cout << "Valor " << i << ", " << j << ": ";
            cin >> val;
            m.set(i, j, val);
        }

    m.imprime();


    return 0;
}
