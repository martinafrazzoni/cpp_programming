/*Scrivere un programm
a che legga un numero intero non negativo in ingresso e lo divida progressivamente per 10 finchè non si riduce a 0. il programma stampa il numero iniziale ed il risultato intermedio di ogni divisione.*/

#include <iostream>
using namespace std; 
int main (){
    int n; //numero letto da stdin; 
    do {
        cout << "Inserisci un numero intero non negativo \n"; 
        cin>>n; 
    }
    while (n<0); 
    do {
        cout << n << endl; 
        n/=10; 
    }
    while (n>0); 
    cout << n << endl; 
    return 0; 
}