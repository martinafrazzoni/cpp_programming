/*Scrivere un programma che legge un numero intero da stadard input (cin) e stampa "il numero inserito è positivo" se il numero inserito è positivo. Altrimenti esce e non stampa nulla.  */
#include <iostream>
using namespace std; 
int main ()
{
    int a; 
    cout << "Inserisci un numero intero: "; 
    cin >> a; 
    if (a>=0)
        cout << "Il numero inserito è positivo \n"; 
    return 0; 
}