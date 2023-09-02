/* Esercizio:
Scrivere una funzione:

int init (int vett[], int vett2[], int n);

che riceve in ingresso due vettori di interi di uguale dimensione e un intero
n pari alla dimensione dei due vettori, inizializza il secondo vettore con i 
soli interi PARI (contenuti nel vettore di partenza) 
e ritorna il numero di elementi significativi contenuti nel nuovo vettore.
Se il numero di interi PARI contenuti nel primo vettore e' minore di
n, la funzione assegna agli elementi nelle posizioni 'vuote' del secondo 
vettore il valore -1.
Ad esempio, se il primo vettore in ingresso ha dimensione 5 e contiene i valori
[3, 2, 7, 8, 10], la funzione assegna agli elementi del secondo vettore i 
valori:
[2, 8, 10, -1, -1].

Si scriva poi un main() che compie le seguenti azioni:
a) definisce ed inizializza una costante n;
b) definisce due vettori di interi di dimensione n;
c) chiede all'utente di inserire i valori da inserire nel primo vettore
c) richiama la funzione init() passandole i due vettori;
d) stampa solo i numeri validi contenuti nel secondo vettore (quello contenente
   i numeri pari).
*/
#include <iostream>
using namespace std; 

void inizializza_vettore_pari (int a [ ], int b [ ], int n){
    
    // ordiniamo l'array in ordine decrescente
    int temp; 
    int min_index; 
    for (int i = 0; i < n; i++){
        min_index = i; 
        for (int j = (i+1); j < n; j++){
            if (a[j] < a[min_index])
                min_index = j; 
        }
        temp = a[min_index]; 
        a[min_index] = a[i]; 
        a[i] = temp; 
    }


    int elementi_pari = 0; 
    for (int i = 0; i < n; i++){
        if (a[i] % 2 == 0){
            b[i] = a[i]; 
            elementi_pari++; 
        }
    }
    
    if (elementi_pari < n){
        for (int i = 0; i < n; i++){
            if (b[i] == 0)
                b[i] = -1; 
        }
    }

}

int main(){
    const int n = 5; 
    int a [n] = {3, 2, 7, 8, 10}; 
    int b [n] = {0};
    
    inizializza_vettore_pari(a, b, n);  

    cout << "Il vettore dei numeri pari è: "; 
    for (int i = 0; i < n; i++){
        if (b[i] != -1){
            cout << b[i] << " "; 
        }
    }
    
    cout << endl; 

    return 0; 
}