/*Traccia: Realizzare un programma che legge in ingresso un numero
intero non negativo (in base 10) e stampa la configurazione binaria
(su un numero di cifre pari al numero di cifre su cui sono
rappresentati i numeri interi sulla macchina) che lo rappresenta in
base 2.

Un possibile output e' il seguente:
Inserisci un numero 37127634
La rappresentazione di 37127634 su 32 cifre e'
00000010001101101000010111010010*/

#include <iostream>
using namespace std; 
int main(){
    int N; //numero che devo leggere in ingresso da Stdin
    int b = 2; // base. 
    int i = 32; 
    
    int t; 
    int tb = 1; // contenitore
    cout<<"Inserisci un numero intero non negativo da scrivere in base 2 \n"; 
    cin>>N; 
    for (int j = 0; j<i; j++){  // ciclo che mi va da 0 a 32, quindi tutta la lunghezza della mia rappresentazione in memoria. 
    if (j>0){
         for (int x = 0; x < j; x++){
            tb*= b; 
        }
    }
        if (N/tb>0){
            t = (N/tb)%b; 
        }
        else 
            t = 0; 
    cout << t; 
    }
    return 0; 
}
