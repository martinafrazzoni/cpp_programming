/*
  Scrivere un programma che definisca un vettore di interi di
  lunghezza prefissata (a tempo di scrittura del programma) e lo
  inizializzi con valori casuali compresi tra due valori interi
  introdotti dall'utente. Il programma riversa quindi in un secondo
  vettore i soli elementi di valore pari contenuti nel primo, infine
  stampa il contenuto dei due vettori.  Il riversamento DEVE essere
  effettuato da una funzione dedicata.  La funzione deve o non deve
  ritornare il numero di elementi copiati?
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 


int trova_pari (int a [ ], int n){ 
    int resto; 
    int cont = 0; 
       for (int i = 0; i < n; i++){
        resto = (a[i]%2); 
            if (resto == 0){
                cont ++;  
            }
        }
    return cont; 
}

void riversa (int a [ ], int v [ ], int n){
    for (int i = 0, y = 1; i < n; i++, y++){
        if (a[i] % 2 == 0){
            v[i] = a[i]; 
            cout << "Elemento (" << y << "/" << n << "): " << v[i] << endl; 
        }
    }
}


int main(){
    // definiisco l'array e la sua lunghezza
    const int n = 5; 
    int a [n]; 
    int v[n]; 

    // chiedo in input il range dei valori tra i quali generare i valori casuali. 
    int b, c; 
    cout << "Inserisci il range di valori: ";
    cin>> b >> c;  

    srand(time(0)); 
    cout << "Ecco l'array inserito: " << endl; 
    for (int i = 0, y = 1; i < n; i++, y++){
        a[i] = rand()%(c-b+1)+ b; 
        cout << "Elemento (" << y << "/" << n << "): " << a[i] << endl; 

    }

    if (trova_pari(a, n) == 0){
        cout << "All'interno dell'array non sono presenti numeri pari!"; 
        return 0; 
    }
    else{
        cout << "il numero di numeri pari è: " << trova_pari(a,n) << endl;
    }

    riversa (a, v, n); 
    return 0; 
}