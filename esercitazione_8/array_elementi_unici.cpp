/* 
   Scrivere una funzione contavolte che conta quante volte un elemento
   e' presente in un vettore v di n elementi. La funzione riceve come
   parametri x, v, n. Utilizzare contavolte dentro una seconda
   funzione creaunici, per memorizzare, a partire da un vettore v1, in
   un secondo vettore v2 solo gli elementi unici di v1, cioe' presenti
   una sola volta in v1. La funzione restituisce il numero degli
   elementi in v2. 

   Esempio: 
   v1: 2 4 3 2 7 1 3 5 1 8 9 
   v2: 4 7 5 8 9

   Scrivere la funzione creaunici in maniera tale che possa lavorare
   su vettori di dimensione qualsiasi.
   
   Infine scrivere una funzione principale che definisca due vettori
   di int, ed utilizzi la funzione creaunici per memorizzare nel
   secondo vettore solo gli elementi unici di v1. La funzione stampa i
   due vettori.

*/

#include <iostream>
using namespace std; 
int trova_occorrenze (int a [ ], int dim_a, int da_trovare){
    int conta_occorrenze = 0; 
    for (int i = 0; i < dim_a; i++){
        if (a[i] == da_trovare)
            conta_occorrenze++; 
    }
    return conta_occorrenze; 
}

/*dato ogni elemento del mio array, calcola quante volte viene ripetuto il suo valore, se è ripetuto più di 1 volta, allora la funzione lo prende e lo sposta nel mio secondo array b. La funzione mi deve ritornare il numero di elementi presenti nel secondo array.*/

int crea_array_di_singoli(int a [ ], int dim_a, int b [ ]){
    int lunghezza_b = 0; 
    for (int i = 0; i < dim_a; i++){
        if (trova_occorrenze(a, dim_a, a[i]) == 1){ // alla funzione trova_occorrenze, come parametro da cercare gli passo il valore che è contenuto dentro il primo elemento dell'array a, quindi a[i]; Se quell'a[i] occorre solo una volta, allora viene spostato nella posizione di indice lunghezza_b dell'array b. 
            b[lunghezza_b] = a[i]; 
            lunghezza_b ++; 
        }
    }
    return lunghezza_b; 
}

int main(){
    const int dim_a = 10; 
    int a [dim_a] = {2, 5, 9, 3, 7, 1, 5, 9, 3, 4}; 

    // non so ancora la dimensione del vettore b, intanto gli dò la stessa di a. 
    int b [dim_a]; 

    int dim_b = crea_array_di_singoli(a, dim_a, b); 

    // stampa array a
    for (int i = 0; i < dim_a; i++){
        cout << a[i] << " "; 
    }
    cout << endl; 

    //stampa array b
    for (int i = 0; i < dim_b; i++){
        cout << b[i] << " "; 
    }

    return 0; 
}