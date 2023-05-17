#include <iostream>

using namespace std;



int main()
{
    int n;
    cout << "digite um valor";
    cin>>n;

    int *vet;
    vet = new int[n];
    for(int i=0; i<0; i++)
    {
        cin >> vet[i];
    }
     
    // calcular media
    
    int media =0;

    for(int i=0; i<0; i++)
    {
        media = vet[i] + media;
    }
    media = media/n;
    cout << "media =" << media;

    delete [] vet;

    return 0;
}
