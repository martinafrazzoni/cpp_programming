/*
Scrivere un programma che compie le seguenti azioni:
a) definisce ed inizializza due costanti N ed M;
b) definisce tre vettori di interi di dimensioni N, M ed N+M;
c) inizializza ciascuno dei due array con una sequenza di valori ordinata in 
   senso crescente di valori (la sequenza è definita a tempo di scrittura del
   programma);
c) copia il contenuto di entrambi i vettori nel terzo vettore;
   la copia deve essere effettuata visitando non più di una volta ciascun 
   elemento dei primi due vettori;
d) stampa i tre vettori.
*/
#include <iostream>
using namespace std; 
int main(){
    const int dim_a = 5; 
    const int dim_b = 3; 

    int a[dim_a] = {1, 2, 3, 4, 5}; 
    int b [dim_b] = {6, 7, 8}; 
    int c [dim_a + dim_b]; 

    // devo copiare a e b dentro il vettore c, quindi otterrò qualcosa del genere
    // scorro il mio array c
    for (int i = 0; i < (dim_a+dim_b); i++){
        c[i] = a[i];  
        for (int j = dim_a; j < (dim_a + dim_b); j++){  // il secondo ciclo parte da dim_a ovvero 5. poi nella posizione c[j] ci sta b<[j-dim_a], con j che cresce. Per ottenere l'indice corretto dei valori dell'array b dobbiamo sottrarre dim_a a j. 
            c[j] = b[j - dim_a]; /*Sure! The expression b[j - dim_a] is used to correctly index the elements of array b when copying them into array c.

        Since the first dim_a elements of array c are filled with the elements of array a, we need to start filling the remaining elements of array c with the elements of array b starting from index dim_a. The variable j in the second loop iterates from dim_a to (dim_a + dim_b), so we need to subtract dim_a from j to correctly index the elements of array b.

        For example, when j = dim_a, we want to copy the first element of array b (i.e., b[0]) into the dim_a-th element of array c. So we use the expression b[j - dim_a], which becomes b[dim_a - dim_a] = b[0].*/
        }
    }

    cout << "Ecco stampato il primo array a: " << endl; 
    for (int i = 0; i < dim_a; i++){
        cout << a[i] << " "; 
    }
    cout << endl; 

    cout << "Ecco stampato il secondo array b: " << endl; 
    for (int i = 0; i < dim_b; i++){
        cout << b[i] << " ";  
    }
    cout << endl; 

    cout << "Ecco stampato il terzo vettore: " << endl; 
    for (int i = 0; i <(dim_a + dim_b); i++){
        cout << c[i] << " "; 
    }

   
    return 0; 
}