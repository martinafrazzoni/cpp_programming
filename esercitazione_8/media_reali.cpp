/*Scrivere un programma che legga da stdin 20 valori reali, calcoli la media di tali valori e ristampi solo il valori maggiori della media. */
#include <iostream>
using namespace std; 
int main(){
    int num = 0; 
    int somma = 0; 
    int media; 
    const int numero_max = 20; 
    while (num < numero_max){
        int p; 
        cout << "Inserisci un numero reale: "; 
        cin>>p; 
        somma +=p; 
        num++; 
        media = somma/num;  
    }
    cout << "la somma dei valori è: " << somma << endl; 
    cout << "la media dei valori è: " << media << endl; 
    return 0; 
}
