/*
 * Chiamiamo gemelli due numeri primi p1 e p2 tlai che p1 == p2 + 2,
 * ossia c'è un solo numero a separare p1 e p2.
 *
 * Scrivere un programma che legge in ingresso due numeri interi non
 * negativi a e b, e stampa sullo schermo tutti i numeri primi gemelli
 * compresi tra a e b.  
 *
 */ 

#include <iostream>
#include <cmath>
using namespace std; 
bool primo (int n){
    // prima funzione che, dato un numero intero n passato come parametro ritorna true se il numero è primo altrimenti false.
    if (n>=1 && n<=3) // guardo se il valore di i è compreso tra 1 e 3. 
        return true; 

    int res = (n%2); // guardo se i è pari, se è pari non è primo.
    if (n%2 == 0){
        return false; 
    }

    else {
        if (n%2==1 && n>3){
            int rad = static_cast<int>(sqrt(n)); 
            for (int i = 3; i<=rad; i+=2){
                int resto = n%i; 
                if (resto == 0){
                    return false;
                }
            }
        }
    }
    return true; 
}

int main(){
    int a, b; 
    cout << "Inserisci due numeri tra i quali calcolare i primi gemelli: \n"; 
    cin>>a>>b;  
    for(int i = a; i <= b - 2; i++) { // la condizione è b-2 perché stiamo cercando coppie di primi gemelli. se avessimo messo solo b come condizione, il ciclo verrebbe eseguito anche per l'ultimo numero del ciclo for che non possiamo confrontare con un altro numero per capire se è primo gemello. il + 2 è perchè i gemelli vanno di due in due. 
        if(primo(i) && primo(i + 2)) {
            cout << "(" << i << ", " << i + 2 << ")" << endl;
        }
    }
    return 0; 
}

