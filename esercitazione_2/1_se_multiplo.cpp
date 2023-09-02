/*Scrivere un programma che legge in ingresso due numeri interi positivi, poi stampa 1 se il primo è multiplo dell'altro, 0 altrimenti*/
#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;

    cout << "Inserisci un numero intero: ";
    cin >> a;

    cout << "Inserisci un numero intero: ";
    cin >> b;
    cout << (a + 1) % b << endl;

    return 0;
}