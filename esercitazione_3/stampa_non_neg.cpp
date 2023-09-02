/*Scrivere un programma che legge un numero intero da stdin e stampa "il numero inserito è non negativo" se il numero inserito è positivo o nullo. Altrimenti stampa "il numero inserito è negativo". */
#include <iostream>
using namespace std; 
int main ()
{
    int a; 
    cout << "Inserisci un numero intero: \n"; 
    cin >>a; 
    if (a>=0)
        cout << "Il numero inserito è non negativo.\n"; 
    else 
        cout << "IL numero inserito è negativo. \n"; 
    return 0; 
}