/*Scrivere un programma che legge in ingresso un numero intero diverso da 0, e stampa 0 se è negativo, 1 se è positivo. */
#include <iostream>
using namespace std;

int main()
{
    int a;

    cout << "Inserisci un numero intero diverso da zero: ";
    cin >> a;

    cout << (a / abs(a) + 1) / 2 << endl;

    return 0;
}