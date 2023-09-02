#include <iostream>
using namespace std;
int main()
{
    int i;
    int j;
    cout << "Inserisci il valore di i: ";
    cin >> i;
    cout << "inserisci il valore di j: ";
    cin >> j;
    int app = i; // ci serve una variabile di appoggio di tipo intero a cui assegnamo il valore di i.
    i = j;       // poi assegnamo a i il valore di j.
    j = app;     // assegnamo a j il valore contenuto nella variabile di appoggio.
    cout << "il valore dopo lo scambio i = " << i << " e j = "
         << j << endl;
    return 0;
}