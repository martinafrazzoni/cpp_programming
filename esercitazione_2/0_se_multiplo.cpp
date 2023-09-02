/*Scrivere un programma che legge in ingresso due numeri interi positivi, poi stampa 0 se il primo è multilplo dell'altro, 1 altrimenti*/
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
    cout << (a % b) << endl;

    return 0;