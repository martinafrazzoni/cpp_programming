/*dato un vettore di N interi, con N deciso a tempo di scrittura del programma, inizializzati da stdin p casualmente determini il valore massimo tra quelli memorizzati nel vettore e lo si stampi.*/
#include <iostream>
#include <cmath>
using namespace std; 
int main(){
    const int n = 3; 
    int a[n]; // definisco il mio array. 
    int massimo = 0; 

    // per mettere i valori dentro l'array uso un for:
    for (int i = 0, y = 1; i < n; i++, y++){
        cout << "Inserisci elemento positivo (elemento " << y << "/" << n << "): "; 
        cin>>a[i]; 
        if (a[i] > massimo)
            massimo = a[i]; 
    }
    cout << "Il massimo tra i valori inseriti è: " << massimo << endl; 
    return 0; 
}