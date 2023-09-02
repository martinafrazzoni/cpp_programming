#include <iostream>
using namespace std;

int main()
{
    int a, m, ris, resto;
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> m;
    ris = (a / m); // variabile di appoggio è ris.
    resto = (a % m);
    cout << "il risultato della divisione è: " << a << "/" << m << "=" << ris
         << " con resto " << resto << endl;
    return 0;
}