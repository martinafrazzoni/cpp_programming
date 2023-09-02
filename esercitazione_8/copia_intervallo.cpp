/*Dato un vettore di al più max_m = 5 elementi interi non nulli, si copino in un altro vettore solo gli elementi compresi tra 10 e 500. Al termine si stampi solo il numero di valori copiati nel secondo vettore. */

#include <iostream>
using namespace std; 
int main(){
    const int max_m = 5; 
    int a [max_m]; 
    int b [max_m]; 

    // inserisco gli elementi dentro l'array. 
    for (int i = 0, y = 1; i < max_m; i++, y++){
        cout << "Inserisci un valore, inserire 0 per terminare (Elemento " << y << "/" << max_m << "): "; 
        cin>>a[i]; 
        if (a[i] == 0)
            break;
    }

    int conta_b = 0; 
    // guardo se dentro l'array ci sono elementi con valori compresi tra 10 e 500
    for (int i = 0, y = 1; (i < max_m && a[i] !=0); i++, y++){
        if ((a[i] > 10 && a[i] < 500)){
            b[conta_b] = a[i]; // invece che dire vettore b di posizione conta_b (0) avrei potuto anche mettere i. 
            cout << "Elemento (" << y << "/" << max_m << "): " << b[conta_b] << endl;
            conta_b++; 
        }
    }
    cout << "gli elementi che sono stati copiati sono: " << conta_b << endl; 

    return 0; 
}