/*Scrivere un programma che legge in ingresso un numero intero, lo interpreta come un tempo espresso in secondi e lo sttampa in mnuti e secondi.
Tempo in secondi?
Equivalgono a 1 min, 7 secondi. */

#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "Tempo in secondi?";
    cin >> a;
    int t = 60;
    int sec = (a % t);
    int min = (a / t);
    cout << "equivalgono a " << min << " minuti, "
         << "e " << sec << " secondi" << endl;
    return 0;
}