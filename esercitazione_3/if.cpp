#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "Inserisci un numero intero compreso tra 1 e 5: \n";
    cin >> a;
    if (a >= 1 && a <= 5)
    {
        if (a == 1)
            cout << "Primo" << endl;
        else if (a == 2)
            cout << "Secondo" << endl;
        else if (a == 3)
            cout << "terzo" << endl;
        else if (a == 4)
            cout << "quarto" << endl;
        else if (a == 5)
            cout << "quinto" << endl;
    }
    else
        cout << "Hai inserito un valore che non è presente nell'intervallo \n";
    return 0;
}