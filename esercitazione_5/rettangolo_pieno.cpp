/*Stampare un rettangolo (pieno e vuoto) di lati m ed n. Scrivere una soluzione sia con un due cicli che con uno solo (rettangolo_pieno_un_ciclo.cpp)*/

#include <iostream>
using namespace std; 
int main(){
    int m; //lato lungo
    int n; //lato corto
    const int k = 10; 
    do {
        cout << "Inserisci i valori del lato lungo e del lato corto, attenzione, devono essere maggiori di zero e minori di " << k << endl;  
        cin>>m>>n; 
    }
    while ((m<0 || m>k) || (n<0 || n >k)); 
    /*stampiamo a schermo il rettangolo*/
    for (int i = 0; i < n; i++) { // questo ciclo stampa il lato lungo del mio rettangolo m = 7
        for (int j = 0; j < m; j++){ // questo ciclo invece stampa il lato corso del mio rettangolo, n = 3
            cout << "# "; 
        }
        cout << endl; 
    }
    

    return 0; 
}