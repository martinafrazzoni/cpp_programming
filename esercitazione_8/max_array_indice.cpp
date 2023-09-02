/*dato un vettore di N interi, con N deciso a tempo di scrittura del programma, inizializzati da stdin p casualmente determini il valore massimo tra quelli memorizzati nel vettore e lo si stampi.Si stampi anche la posizione in cui tale massimo compare. */

#include <iostream>
#include <cmath>
using namespace std; 

int main(){
    const int n = 5; // grandezza array. 
    int a [n]; 
    int massimo = 0; 
    int i, y; 
    int pos_massimo; 

    // dentro il mio array voglio metterci valori casuali, uso la funzione rand()
    srand(1); 
    for (i = 0, y = 1; i<n; i++, y++){
        a[i] = rand(); 
        if (a[i] > massimo){
            massimo = a[i]; 
            pos_massimo = i; 
        }
    }
    cout << "ecco l'array inserito: " << endl; 
    for (i = 0, y = 1; i < n; i++, y++){
        cout << "Elemento " << y << ": " << a[i] << endl; 
    }
    cout << "Il valore massimo inserito è: " << massimo << " che si trova in posizione " << pos_massimo << " dentro l'array. " << endl; 

    return 0; 
}