/*Scrivere un programma che, dato un numero intero, lo fattorizza
 * come prodotto di numeri primi, o comunica esplicitamente che il
 * numero e' primo.
 *
 * Esempi:
 *
 * Inserisci un numero: 23
 * 23 e' un numero primo
 *
 * Inserisci un numero: 24
 * 24 = 2*2*2*3
 * 
 * ESERCIZIO CHE NON HO CAPITO. 
 */

#include <iostream>
using namespace std; 
int main(){
    int ris; 
    int numero; 
    int divisore = 2; 
    cout<< "Inserisci un numero intero positivo: "; 
    cin>>numero;
    if (numero < 0 )
        cout << "Attenzione hai inserito un numero negativo" << endl; 
        return 1; 

    for (int i = 0; i < (numero-1); i++){
        ris = (numero%divisore); 
        divisore++; 
        cout << ris; 
    }
    
    if (ris == 0){
        cout <<"è primo!"; 
    }
    else 
        cout << "non è primo!"; 

    return 0;
}
