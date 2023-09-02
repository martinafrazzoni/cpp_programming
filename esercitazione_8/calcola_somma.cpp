/*
Scrivere un programma in cui sia definita ed utilizzata una funzione
che, preso un vettore di numeri interi in ingresso, ne calcola la
somma degli elementi. La funzione non legge da stdin e non scrive su stdout.

Il vettore viene modificato dalla funzione?

C'è concreto rischio overflow se si riempie il vettore con numeri
completamente casuali?
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 

int somma (int a [ ], int n){
    int somma = 0; 
    for (int i = 0; i < n; i++){
        somma += a[i]; 
    }
    return somma; 
}

int main(){
    const int n = 3; 
    int a [n];      /* Potevo anche inizializzarlo l'array facendo così int a [n] = {3, 7, 12};*/ 

    // mettiamo dentro l'array dei valori casuali 
    srand(time(0)); 
    for (int i = 0, y = 1; i < n ; i++, y++){
        a[i] = (rand() % 1000);  
        cout << "Elemento (" << y << "/" << n << "): " << a[i] << endl; 
    }
    somma(a, n); 
    cout << "La somma dei valori inseriti all'interno dell'array è: " << somma (a, n) << endl; 
    return 0; 
}