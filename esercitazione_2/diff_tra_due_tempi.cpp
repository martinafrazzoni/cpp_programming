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
    cout << "la differenza in secondi è: " << diff << endl;

    return 0;
}