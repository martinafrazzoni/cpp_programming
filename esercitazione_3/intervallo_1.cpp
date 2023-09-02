/* scrivere un programma che definisca ed inizializzi due costanti intere a e b, poi legga in ingresso un numero intero e scriva un messaggio se il numero è compreso nell'intervallo [a, b].*/
#include <iostream>
using namespace std;
int main()
{
    const int a = 1;
    const int b = 10;
    int c;
    cout << "Inserisci un numero intero: ";
    cin >> c;
    if (!((c < a) || (c > b)))
        cout << c << " è compreso in [" << a << " e " << b << "]" << endl;
    return 0;
}