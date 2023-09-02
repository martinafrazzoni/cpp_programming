/*Stampare un rettangolo pieno con un ciclo*/
#include <iostream>
using namespace std; 
int main (){
    int m; //lato lungo
    int n; //lato corto
    const int k = 10; // costante max lunghezza dei lati. 
    do {
        cout << "Inserisci i valori del lato lungo e del lato corto, fancendo attenzione che devono essere maggiori di zero e minori di " << k << endl; 
        cin>>m>>n; 
    }
    while ((n<0 || n > k) || (m<0 || m>k)); 
    /*stampiamo il rettangolo con un solo ciclo*/
    for (int i = 0; i < (m*n); i++){
        cout << " #"; 
        /*per capire quando andare a capo utilizzo l'aritmetica modulare (i+1)%m = 0 allora vai a capo. */
        if ((i+1)%m == 0)
        cout << endl; 
    }
    return 0; 
}