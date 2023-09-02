/*scrivere un programma che definisca ed inizializzi due costanti intere a e b, poi legga in ingresso un numero intero e scriva un messaggio se il numero NON E' comporeso nell'intervallo [a,b]*/
#include <iostream>
using namespace std; 
int main ()
{
    const int a = 1; 
    const int b = 100; 
    int x ;
    cout << "Inserisci un numero intero: "; 
    cin >> x; 
    if ((x<=a) || (x>=b))
    {
        cout << x << " Non è incluso " << endl; 
        cout << "in [" << a << "," << b << "]" << endl;
    }
    return 0; 
}