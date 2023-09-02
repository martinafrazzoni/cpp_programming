/*Scrivere un programma che chieda all'utente di inserire tre valori interi a, b, c e stampa 1 se a<b oppure se a<c 0 altrimenti. */
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Inserisci tre numeri interi a, b, c: ";
    cin >> a;
    cin >> b;
    cin >> c;
    cout << "Il valore è: " << ((a < b) || (a < c)) << endl;
    return 0;
}
