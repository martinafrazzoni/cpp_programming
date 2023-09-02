/*Scrivere un programma che chieda all'utente di inserire tre valori interi a, b, x e stampa 1 se a<b oppure se a<=x<=b, 0 altrimenti. */
#include <iostream>
using namespace std;

int main()   
{
    int a, b, x;
    cout << "Inserisci tre numeri interi a, b, x: ";
    cin >> a>> b>> x;
    cout << "Il valore è: " << ((a <= x) && (x <= b)) << endl;
    return 0;
}
