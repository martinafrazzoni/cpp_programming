#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;
    cout << "Inserisci il valore di a: ";
    cin >> a;
    cout << "inserisci il valore di b: ";
    cin >> b;

    // visto che sto usando delle variabili intere io posso applicare ad esse qualsiasi formula metematica.
    a = a + b; // se ad a io vado a sommare b e lo salvo nella variabile a, all'interno della variabile io ho memorizzata la somma di entrambi.
    b = a - b; // se ad a+b che è a, tolgo b, è equivalente al valore di a, che assegno a b.
    a = a - b; // in a io ho ancora il valore della somma di a+b, e visto che in b è contenuto il valore di a, posso andare ad assegnare ad a il valore di a-b.

    // a = a+b;
    // b = (a+b) -b; = ab-b = a;
    // a = (a+b) -a; = ab -a = b;

    // senza utilizzare una variabile di appoggio io ho ottenuto lo stesso scambio che avevo prima.
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}