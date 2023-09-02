/*Scriviamo un programma che legga in ingresso un numenegativo e dica all’utente se il numero è primo (o altrimenti non stampa nulla). */
#include <iostream>
#include <cmath>
using namespace std; 
int main(){
    int n; // numero intero positivo. 
    int res; 
    // leggo il primo numero
     
    do{
        cout <<"inserisci un numero intero positivo: \n"; 
        cin>>n; 
    }
    while (n<0); 
    // Se N = 1, N = 2, N = 3 allora N è primo. 
    if (n==1 || n == 2 || n == 3){ // if (n>=1 || n <=3)
        cout << "è primo!"; 
        return 0; 
    }
    // controllo se N è pari. 
    if (n%2 == 0){
        cout << "è pari quindi non è primo!";
        return 1; 
    }
    // altrimenti, se è dispari e maggiore di 3 calcolo la radice quadrata, e faccio il modulo di n da 3 a radice quadrata di n. 
    else{
        if (n%2 == 1 && n>3){
        int rad = static_cast<int>(sqrt(n)); 
        for (int i = 3; i <= rad; i+=2){ // possiamo anche mettere i+=2 perchè devo guardare solo numeri dispari
            if (n%i == 0){
                cout << "il numero non è primo" << endl; 
                return 1;
            }
        } 
        cout << "è primo!";
        }
    }
    return 0; 
}

