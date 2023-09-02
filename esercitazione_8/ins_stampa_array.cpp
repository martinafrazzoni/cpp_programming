/*

Scrivere un programma che chieda all'utente di inserire un numero di
valori interi prefissato (a tempo di scrittura del programma),
li inserisca in un array e stampi l'array risultante.

Un possibile output è il seguente:

Inserisci un intero positivo (elemento 1 / 3): 2
Inserisci un intero positivo (elemento 2 / 3): 5
Inserisci un intero positivo (elemento 3 / 3): 1
Ecco l'array immesso:
Elemento 1: 2
Elemento 2: 5
Elemento 3: 1

*/
#include <iostream>
using namespace std; 
int main(){
    const int n = 3; // numero elemento array. 
    int primo_array [n]; // definiamo array che ha b elementi ( n == 3). dobbiamo inserire solo costanti e non variabili. 

    // se devo riempire un array lo faccio utilizzando un for. 
    for (int i = 0, y = 1; i < n; i++, y++)
    {
        cout << "Inserisci elemento positivo" << "(elemento " << y << " / " << n << "): "; 
        cin>> primo_array[i]; 
    }
    cout << "Ecco l'array inserito: " << endl; 
    for (int i = 0, y = 1; i < n; i++, y++){
        cout <<"Elemento " << y << ": " <<  primo_array[i] << endl; 
    }
    return 0; 
    
}