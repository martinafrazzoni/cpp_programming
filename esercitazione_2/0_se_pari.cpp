/*scrivere un programma che legge in ingresso un numero intero e stampa 0 se il numero è pari, 1 altrimenti. */
#include <iostream>
using namespace std;

int main()
{
    int a;

    cout << "Inserisci un numero intero: ";
    cin >> a;

    cout << (a % 2) << endl;

    return 0;
}