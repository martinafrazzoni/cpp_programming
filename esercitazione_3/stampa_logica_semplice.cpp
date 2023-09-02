/*Scrivere un programma che chieda all'utente di inserire due valori interi a e b e stampa 1 se a<b 0 altrimenti. */
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Inserisci i due valori di a e b: ";
    cin >> a;
    cin >> b;
    // cin>>a>>b; prendo in ingresso uno dopo l'altro sia il valore di a sia quello di b.
    cout << "Valore di " << (a < b) << endl;
    return 0;
}
