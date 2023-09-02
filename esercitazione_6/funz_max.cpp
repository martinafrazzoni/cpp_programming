/*Scrivere un programma che stampi il massimo tra due numeri interi letti da
stdin. Implementare il calcolo (e non la stampa) del massimo mediante una
funzione. Implementare la lettura dei valori e la stampa del valore massimo
all'interno della funzione main. Non usare NESSUNA funzione di libreria per calcolare il massimo.

Esempio:
	Inserire i due numeri interi: 21 -3
	Il massimo tra 21 e -3 è 21 */

#include <iostream>
using namespace std;
int massimo(int a, int b){
    int numero_max; 
    if (a>b){
        numero_max = a; 
    }
    else numero_max = b; 
    return numero_max; 
} 
int main(){
    int a, b; // questi sono i nomi delle variabili che passeremo come variabili attuali. 
    cout << "Inserisci i due valori interi: \n"; 
    cin>>a>>b;
    cout << "il massimo tra i due numeri è " << massimo(a,b) << endl;  
    return 0; 
}