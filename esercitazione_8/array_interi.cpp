/*
Scrivere un programma che, dato un vettore di 10 numeri interi
(inizializzato a tempo di scrittura del programma),
. lo stampa a schermo
. stampa il valore massimo
. stampa il valore minimo
. lo ordina in senso crescente e lo stampa a schermo
. lo ordina in senso decrescente e lo stampa a schermo
*/
#include <iostream>
using namespace std; 

int calcola_massimo (int a [ ], int dim_a){
    int massimo = 0; 
    for (int i = 0; i < dim_a; i++){
        if (a[i] > massimo){
            massimo = a[i]; 
        }
        
    }
    return massimo; 
}

int calcola_minimo (int a [ ], int dim_a){
    int minimo = calcola_massimo(a, dim_a); 
    for (int i = 0; i < dim_a; i++){
        if (a[i] < minimo)
            minimo = a[i]; 
    }
    return minimo; 
}

void ordina_crescente (int a[ ], int dim_a){
    // ordiniamo l'array in senso crescente
    int min_index; 
    int temp; 
    for (int i = 0; i < (dim_a-1); i++){
        min_index = i; 
        for (int j = (i+1); j < dim_a; j++){
            if (a[j] < a[min_index])
                min_index = j; 
        }
        temp = a[min_index]; 
        a[min_index] = a[i]; 
        a[i] = temp; 
    }
    cout << endl; 
    cout << "Ecco l'array ordinato in ordine crescente: " << endl; 
    for (int i = 0; i < dim_a; i++){
        cout << a[i] << " "; 
    }
    cout << endl; 
}

void ordina_decrescente (int a[ ], int dim_a){
    // ordiniamo l'array in ordine decrescente
    int max_index; 
    int temp_max; 
    for (int c = 0; c < (dim_a-1); c++){
        max_index = c; 
        for (int d = (c+1); d < dim_a; d++){
            if (a[d] > a[max_index])
                max_index = d; 
        }
        temp_max = a[max_index]; 
        a[max_index] = a[c]; 
        a[c] = temp_max; 
    }
    
    cout << endl;  
    cout << "Ecco l'array ordinato in ordine decrescente: " << endl; 
    for (int c = 0; c < dim_a; c++){
        cout << a[c] << " "; 
    }
    cout << endl; 
}

int main(){
    const int dim_a = 10; 
    int a [dim_a] = {12, 5, 4, 17, 15, 9, 3, 23, 1, 2}; 

    cout << "Il massimo tra i valori inseriti è: " << calcola_massimo(a, dim_a) << endl; 
    
    cout << "il minimo tra i valori inseriti è: " << calcola_minimo(a, dim_a) << endl; 

    ordina_crescente(a, dim_a); 
    ordina_decrescente(a, dim_a); 
    
    return 0; 
}