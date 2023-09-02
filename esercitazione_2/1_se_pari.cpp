/*Scrivere un programma che legge in ingresso un numero intero e stampa 1 se il numero è pari 0 altrimenti*/
#include <iostream>
using namespace std;

int main()
{
    int a;

    cout << "Inserisci un numero intero: ";
    cin >> a;

    cout << (a + 1) % 2 << endl;
    return 0;
}