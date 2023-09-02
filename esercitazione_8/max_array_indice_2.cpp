/*dato un vettore di N interi, con N deciso a tempo di scrittura del programma, inizializzati da stdin p casualmente determini il valore massimo tra quelli memorizzati nel vettore e lo si stampi.Si stampi anche la posizione in cui tale massimo compare. */

#include <iostream>
#include <cmath>
using namespace std; 

int main(){
    const int n = 3; // grandezza array. 
    int a [n]; 
    int massimo = 0; 
    int i, y; 
    

    // dentro il mio array voglio metterci valori casuali, uso la funzione rand()
    srand(23); 
    for (i = 0, y = 1; i<n; i++, y++){
        a[i] = rand(); 
    }

    // trovo il massimo e in che posizione si trovano
    for (i = 0; i < n; i++){
        if (a[i] > a[massimo]){ // con a[massimo] io sto accedendo al contenuto della cella, massimo e basta invece mi conta gli indici. 
            massimo = i;  
        }
    }
    cout << "l'array inserito: " << endl; 
    for (i = 0, y = 1; i < n; i++, y++){
        cout << "Elemento " << y << ": " << a[i] << endl; 
    }
    cout << "Il valore massimo inserito è: " << a[massimo] << " che si trova in posizione " << massimo << " dentro l'array. " << endl; 

   return 0; 
}