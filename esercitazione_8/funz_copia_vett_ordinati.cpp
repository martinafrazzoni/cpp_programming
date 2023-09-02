/* Esercizio:
Scrivere una funzione:

void copiaord (int v1[], int n1, int v2[], int n2, int v3[]);

che riceve per parametri tre vettori di interi;
i primi due vettori sono ORDINATI ed hanno dimensioni rispettivamente n1 e n2,
la funzione assume che il terzo vettore abbia dimensioni n1+n2 e vi copia, in
modo ordinato, gli elementi dei due vettori

Si scriva poi un main() che compie le seguenti azioni:
a) definisce ed inizializza due costanti n1 ed n2;
b) definisce tre vettori di interi di dimensioni n1, n2 ed n1+n2;
c) per entrambi i primi due vettori, chiede all'utente di inserire i valori in
   esso contenuti in ordine crescente
c) copia il contenuto di entrambi i vettori nel terzo vettore, utilizzando la 
   funzione copiaord();
d) stampa il terzo vettore.

*/

#include <iostream>
#include <cmath>
using namespace std; 
int main(){
    const int dim_a = 7; 
	const int dim_b = 9; ; 
    const int dim_c = dim_a + dim_b; 

    int a [dim_a] = {1, 4, 7, 8, 9, 11, 13};
	int b [dim_b] = {2, 3, 5, 6, 10, 12, 14, 15, 16}; 
    int c [dim_c]; 
    

    // per determinare la lunghezza del vettore c
    //const int dim_c = (sizeof(a) / sizeof(a[0])) + (sizeof(b) / sizeof (b[0])); 
    //cout << "le dimensioni del vettore c sono: " << dim_c << endl; 
    
  
    // inserisco gli elementi dentro il vettore c; 
    for (int i = 0; i < (dim_c); i++){
        c[i] = a[i]; 
        for (int j = dim_a; j < (dim_c); j++){
            c[j] = b[j-dim_a];  
        }
    }

    // ordiniamo l'array
    int min_index; 
    int temp; 
    for (int i = 0; i < (dim_c-1); i++){
        min_index = i; 
        for (int j = (i+1); j < dim_c; j++){
            if (c[j] < c[min_index])
                min_index = j;  
        }
        temp = c[min_index]; 
        c[min_index] = c[i]; 
        c[i] = temp;
    }

    cout << "Stampiamo il primo array: "; 
    for (int i = 0; i < dim_a; i++){
        cout << a[i] << " "; 
    }
    cout << endl; 

    cout << "Stampiamo il secondo array: "; 
    for (int i = 0; i < dim_b ; i++){
        cout << b[i] << " ";  
    }
    cout << endl; 

    cout << "Stampiamo il terzo array: "; 
    for (int i = 0; i < (dim_c); i++){
        cout << c[i] << " ";  
    }
    cout << endl; 

    return 0; 
}