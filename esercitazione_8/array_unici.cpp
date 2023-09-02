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

int trova_occorrenze (int a[ ], int dim, int da_trovare){
        // devo trovare quante volte un elemento da_trovare è presente in un vettore.  
    int cont = 0; 
    for (int i = 0; i < dim; i++){
        if (a[i] == da_trovare)
            cont ++; 
    }
    return cont; 
}

int array_unici( int a [ ], int dim, int b [ ] ){ // con questa funzione devo trovare quanti elementi conterrà il mio secondo array. 
    int lun_b = 0; // setto il contatore a zero. 
    for (int i = 0; i < dim; i++){
        if (trova_occorrenze(a, dim, a[i]) == 1){  // ho chiamato la funzione trova_occorrenze e le ho passato i seguenti parametri attuali: a - che sarebbe il mio primo array, dim - che sarebbero le dimensioni dell'array e l'elemento che è contenuto all'interno dell'array a nella posizione di indice i. Sarà infatti quel valore che dovrà essere controllato dalla funzione e vedere quante volte occorre all'interno dell'array. 
            b[lun_b] = a[i];  // se il numero di occorrenze di quel valore è uguale a 1 allora mettiamo a[i] dentro il vettore b di posto lun_b. 
            lun_b++; 
        }
    }
    return lun_b;  
}


int main(){
    const int dim = 11; 
    int a [dim] = {2, 4, 3, 2, 7, 1, 3, 5, 1, 8, 9}; 
    int b [dim];
    int dim_b = array_unici(a, dim, b); 

    cout << "Stampiamo il primo vettore: "; 
    for (int i = 0; i < dim; i++){
        cout <<a[i]<< " "; 
    }
    cout << endl; 

    cout << "Stampiamo il secondo vettore: "; 
    for (int i = 0; i < dim_b; i++){
        cout << b[i] << " "; 
    }
    cout << endl; 



   
   
    return 0; 
}

