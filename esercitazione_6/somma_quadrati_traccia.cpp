/*
 * Scrivere un programma che legge in ingresso un numero intero e
 * verifica se può essere ottenuto come somma di quadrati
 * interi. Implementare la verifica definendo ed utilizzando in prima
 * battuta una funzione che prenda in ingresso (attraverso parametri
 * formali) due numeri interi n ed i e, se esiste un numero intero non
 * negativo j tale che n == i*i + j*j, ritorna tale numero, altrimenti
 * ritorna -1.  NOTA: la funzione non legge i numeri da stdin e non li
 * stampa su stdout.
 *
 * Commento: Utilizzando la precedente funzione, la ricerca può essere
 * effettuata per tentativi successivi, ossia provando per i = 1, 2,
 * ...  In questo caso, si può notare che non è necessario che in
 * ciascuno di tali tentativi la funzione in questione prenda in
 * considerazione valori j < i, ma basta che consideri solo j >= i.
 *
 * Suggerimento: sfruttando il precedente commento, si può
 * implementare l'algoritmo in modo più efficiente definendo ed
 * utilizzando, al posto della precedente funzione, una funzione
 * simile, che, se esiste un numero intero non negativo j >= abs(i)
 * tale che n == i*i + j*j, ritorna tale numero, altrimenti ritorna
 * -1.  Se ci si riesce, definire ed utilizzare quest'ultima funzione
 * al posto di quella generale.
 */

#include <iostream>
#include <cmath>
using namespace std; 
int somma_di_quadrati(int n, int i){
    // n == ((i*i) + (j*j)), per trovare j faccio la formula inversa. quindi. j = n-i^2 tutto sotto radice. 
    int quadrato_i = (i*i); 
    //cout << "il quadrato di i è " << quadrato_i << endl; 
    int ris = (n-quadrato_i); 
    //cout << "il risultato di n - quadrato_i è " << ris << endl; 
    int j = static_cast<int>(sqrt(ris)); 
    //cout << " j è " << j << endl; 
    int quadrato_j = (j*j); 
    int risultato = ((i*i)+(j*j)); 
    //cout << risultato << endl; 
    if (risultato == n)
        return j; 
    else 
        return -1; 
}
int main(){
    int n; int i; 
    do{
        cout << "inserisci il valore per il numero n e per i: "; 
        cin>>n>>i; 
    }
    while (i<= 0 && n <= 0); 
    somma_di_quadrati(n, i);
    cout << somma_di_quadrati(n,i) << endl; 
}
