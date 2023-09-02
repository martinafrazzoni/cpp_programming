/* scivere un programma che legge in ingresos due nuermi, li interpreta come un tempo espresso in minuti e secondi, e lo stampa in secondi.
Minuti? 3
Secondi? 78
Equivalgono a 258 secondi. */

#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;
    cout << "Minuti?";
    cin >> a;
    cout << "Secondi?";
    cin >> b;

    int sec = (a * 60) + b;

    cout << "equivalgono a " << sec << " secondi" << endl;
    return 0;
}