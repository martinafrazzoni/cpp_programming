/* scrivere un programma che definisca ed inizializzi due costanti intere a e b, poi legga in ingresso due numeri interi (controllo ed i) e scriva un messaggio se il controllo è diverso da 0 (il primogramma scrive un messaggio se i non è compreso nell'intervallo), altrimenti segnala che non  stato fatto alcun controllo. */

#include <iostream>
using namespace std;
int main()
{
    const int a = 1;
    const int b = 10;
    int c;
    int controllo;
    cout << "Inserisci due numeri interi: ";
    cin >> c >> controllo;
    if (!(controllo == 0))
    {
        if ((c < a) || (c > b))
            cout << c << " non è compreso in [" << a << " e " << b << "]" << endl;
    }
    else
        cout << "Non è stato effettuato alcun controllo \n";
    return 0;
}