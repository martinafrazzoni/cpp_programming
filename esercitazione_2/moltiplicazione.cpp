#include <iostream>
using namespace std;

int main()
{
    int a, m, ris;
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> m;
    ris = (a * m); // variabile di appoggio è ris.
    cout << "il risultato della moltiplicazione è: " << a << "*" << m << "=" << (a * m) << endl;
    return 0;
}