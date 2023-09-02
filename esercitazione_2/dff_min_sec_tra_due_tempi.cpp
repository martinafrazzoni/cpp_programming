#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int a;
    int b;
    int c;
    int d;
    int A;
    int C;
    int S;
    int s;
    int diff;

    int diff_min;
    int diff_sec;

    cout << "Minuti primo tempo?" << endl;
    cin >> a;
    cout << "Secondi primo tempo?" << endl;
    cin >> b;
    cout << "Minuti secondo tempo?" << endl;
    cin >> c;
    cout << "secondi secondo tempo?" << endl;
    cin >> d;

    A = (a * 60);
    C = (c * 60);
    S = (A + b);
    s = (C + d);
    diff = abs(S - s);

    // per calcolare la differenza tra i due tempi in minuti e secondi, divido (divisone intera) i miei secondi per 60, e per sapere i secondi faccio diff (in secondi) modulo 60.
    diff_min = abs(diff / 60);
    diff_sec = abs(diff % 60);

    cout << "la differenza in minuti e secondi è: " << diff_min << " minuti e " << diff_sec << " secondi." << endl;

    return 0;
}