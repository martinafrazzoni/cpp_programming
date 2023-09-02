/*
 * Scrivere un programma che legga un numero intero n. Il numero n
 * viene di nuovo richiesto finché non è compreso tra 0 ed
 * una costante definita a tempo di scrittura del programma.
 *
 * Successivamente si chiede l'immissione di n interi positivi e
 * se ne calcola e stampa la somma ed il valore massimo (il valore
 * piu' grande tra quelli inseriti). Realizzare il calcolo prima
 * utilizzando e poi senza utilizzare l'istruzione for.  Trascurare
 * problemi di overflow.
 *
*/
#include <iostream>
using namespace std; 
int main (){
    int n, numero, i; 
    int s = 0; // variabile somma. 
    int max = 0; // variabile che mi contiene il valore massimo tra i valori inseriti. 
    const int a = 10;   // voglio sommare tot numeri compresi tra 0 e 10.

    /*immissione e controllo del numero di contributi che si vogliono sommare. Questo numero deve essere compreso tra 0 e 10.*/
    do{
        cout << "Di quanti numeri vuoi fare la somma? ";  // per vedere se continuare a ripetere il ciclo io devo avere già letto n. 
        cin>>n; 
        if (n < 0 || n > a)
        cout << "il valore immesso non è compreso nell'intervallo \n"; 
    }
    while (n<=0 || n>=a); // continuo ad eseguire il ciclo mentre l'input è sbagliato. 
    //leggere i numeri in ingresso
    for ( i = 1; i<n; i++){
        cout << "Inserisci prossimo numero: "; 
        cin>>numero; 
        s = s + numero; 
        if (numero>max) // calcolo il massimo tra i valori inseriti. 
            max=numero; 
    }
    cout << "La somma tra i valori inseriti è: " << s << endl;
    cout << "Il valore massimo tra quelli inseriti è " << max<< endl;  
return 0; 
}