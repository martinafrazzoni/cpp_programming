/*
Scrivere un programma in cui sia definita ed utilizzata una funzione
che, preso un vettore di numeri interi in ingresso, raddoppia il valore degli
elementi del vettore. La funzione non legge da stdin e non scrive su stdout.

Il vettore viene modificato dalla funzione?

C'è concreto rischio overflow se si riempie il vettore con numeri
completamente casuali?
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 
void raddoppia(int a [ ], int n){
    // scorro il mio vettore
    for (int i = 0; i < n; i++){
        a[i] = (a[i] *2); 
    }
}
int main(){
    const int n = 3; 
    int a [n];   // ho definito il mio array. 

    // generiamo numeri casuali e usiamo rand()
    srand(time(0)); 
    for (int i = 0, y = 1; i < n; i++, y++){
        a[i] = rand() % 1000; // non voglio metterci valori troppo grandi, facendo modulo 1000 riduco il rischio di overflow. 
        cout <<"Elemento (" << y << "/" << n << "): " << a[i] << endl; 
    }
    raddoppia(a, n); 

    // quando ho finito di rddoppiare ristampo il mio array
    cout << "Dopo aver raddoppiato, ecco i valori dell'array: " << endl; 
    for (int i = 0, y = 1; i < n; i++, y++){
        cout <<"Elemento (" << y << "/" << n << "): " << a[i] << endl; 
    }
return 0; 
}