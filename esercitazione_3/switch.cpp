#include <iostream>
using namespace std;
int main()
{
    int a = 2, n;
    cout << "Inserisci il valore di n, compreso tra 0 e 4 \n";
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "Ramo A" << endl;
        break;
    case 2:
        cout << "Ramo B" << endl;
        a = (a * a); // a *=a
        break;
    case 3:
        cout << "Ramo C" << endl;
        a = (a * a * a);
        break;
    default:
        a = 1;
    }
    cout << a << endl;
    return 0;
}
