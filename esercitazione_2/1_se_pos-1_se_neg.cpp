/*Scrivere un programma che legge in ingresso un numero intero diverso da 0, e stampa -1 se è negativo, 1 se è positivo. */
#include <iostream>
using namespace std;

int main()
{
    int a;

    cout << "Inserisci un numero intero diverso da zero: ";
    cin >> a;

    cout << a / abs(a) << endl;

    return 0;
}