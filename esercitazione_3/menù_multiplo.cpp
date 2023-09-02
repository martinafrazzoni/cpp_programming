#include <iostream>
using namespace std;
int main()
{
    int a;
    int b = 1;
    int c = 5;
    cout << "1 Opzione A \n";
    cout << "2 Opzione B \n";
    cout << "3 Opzione C \n";
    cout << "4 Opzione C \n";
    cout << "5 Opzione D \n";

    cout << "Scegli un'opzione: ";
    cin >> a;
    if (a >= b && a <= c)
    {
        switch (a)
        {
        case 1:
            cout << "Hai scelto l'opzione A \n";
            break;
        case 2:
            cout << "Hai scelto l'opzione B \n";
            break;
        case 3:
        case 4:
            cout << "Hai scelto l'opzione C \n";
            break;
        case 5:
            cout << "Hai scelto l'opzione D \n";
            break;
        default:
            cout << "Non hai inserito un valore nell'intervallo \n";
            break;
        }
    }
    else
        cout << "Non hai inserito un valore valido \n";
    return 0;
}