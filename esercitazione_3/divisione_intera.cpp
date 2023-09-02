#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;
    cout << "Inserisci due numeri interi: ";
    cin >> a >> b;
    if (!(b == 0))
        cout << a << "/" << b << " = " << (a / b) << endl;
    else
        cout << "Attenzione: Il denominatore non può essere 0!!\n";
    return 0;
}