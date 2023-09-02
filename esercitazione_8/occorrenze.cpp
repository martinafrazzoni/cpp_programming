/*Scrivere una funzione che, dato un vettore in ingresso, e senza utilizzare variabili di appoggio in cui memorizzare temporaneamente valori degli elementi del vettore, stampi il
numero di occorrenze di ciascun elemento del vettore.
Supporre che la funzione abbia la possibilità di modificare il vettore a piacimento.
    DA RIVEDERE CI SONO DEGLI ERRORI
*/

#include <iostream>
using namespace std; 

void trova_occorrenze(int a[], int dim_a){
    int da_trovare; 
    int cont; 
    int max_occorrenze; // tiene traccia del numero di occorrenze dell'elemento che occorre di più nell'array. 
    int valore_max; // numero più frequente di per sè. 

    for (int i = 0; i < dim_a; i++){ // come la variabile j, anche i scorrerà l'array dall'indice 0 all'indice dim-1. Quindi i scorre ogni elemento dell'array. Quindi usiamo il ciclo interno per contare le occorrenze dell'elemento di indice i. 
        cont = 0; // ogni volta, per ogni elemento il contatore va azzerato (altrimenti mi somma le occorrenze di tutti e non va bene). 

        // il ciclo esterno tiene traccia dell'elemento più frequente che trova. 

        da_trovare = a[i]; 
        for (int j = 0; j < dim_a; j++){  // abbiamo una parte dell'algoritmo, adesso possiamo contare le occorrenze di un elemento dell'array. ma noi vogliamo vedere quante volte occorre ogini valore all'interno dell'array. per questo avremo un ciclo interno (questo), e un ciclo esterno. 
            //cout << "[trova_occorrenze]: a[j] =  "<< a[j] << endl; 
            //cout << "[trova_occorrenze]: da_trovare: " << da_trovare << endl; 
            if (a[j] == da_trovare){ // quante occorrenze dell'elemento a[i] sono state trovate. 
                cont ++; 
            }
        }
        cout << "l'elemento [" << da_trovare << "] " <<  "di indice " <<  i  << " è ripetuto  " << cont << " volte"<< endl; 

        if (cont > max_occorrenze) // se è vero abbiamo trovato un valore nell'array che occorre più frequentemente del precedente. 
        {
            max_occorrenze = cont; 
            valore_max = a[i]; 
        }
        cout <<"Valore_max: " << valore_max <<  " Max_occorrenze: " << max_occorrenze << endl;
    
    }

}

int main(){

    const int dim_a = 8; 
    int a [dim_a] = {4, 8, 2, 5, 8, 1, 3, 6}; 

    trova_occorrenze(a, dim_a); 
    return 0; 
}



/*int da_trovare; 
    int cont = 0; 
    for (int i = 0; i < (dim_a-1); i++){
        da_trovare = a[i]; 
        for (int j = (i+1); j < dim_a; j++){  
            cout << "a[j] =  "<< a[j] << endl; 
            cout << "da_trovare: " << da_trovare << endl; 
            if (a[j] == da_trovare){
                cont ++; 
            }
        }
        cout << "l'elemento " << da_trovare << " è ripetuto  " << cont << " volte"<< endl; 
    }*/