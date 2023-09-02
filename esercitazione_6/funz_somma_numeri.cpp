/*provare a scrivere una funzione che prende in ingresso (come parametro formale) un numero naturale n, e nessun altro parametro, e ritorni la somma dei numeri da 1 a n: 
- definendo una sola variabile locale nella funzione
- senza utilizzare la chiusura della sommatoria
- quella che conterrà il risultato
Per riuscirci dobbiamo usare una tecnica sconsigliata. */
#include <iostream>
using namespace std; 
int somma (int n){
    int somma = 0; 
    // utilizzo il decremento del parametro formale
    for (; n>0; n--)
        somma +=n; 
    return somma; 
}
int main(){
    int n; 
    cout << "Inserisci un numero n: "; 
    cin>>n; 
    int risultato = somma(n); 
    cout << "La somma di tutti i numeri naturali da 1 a n è " << risultato << endl; 
    return 0; 
}