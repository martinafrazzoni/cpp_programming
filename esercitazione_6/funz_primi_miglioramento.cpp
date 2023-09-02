/*Scrivere una funzione che verifichi se un numero naturale passo in ingresso come parametro attuale è primo. Il numero non viene letto da stdin da parte della funzione. La funzione deve restituire falso se il numero non è primo, vero se il numero è primo. Facciamo attenzione al tipo di ritorno della funzione. Utilizzando tale funzione, riscrivere il programma che controlla se due numeri primi sono gemelli. */
#include <iostream>
#include <cmath>
using namespace std; 
bool primo(int n){
    // controllo se n + compreso tra 1 e 3
    if (n>=1 && n<=3){
        return true; 
    }
    
    // controllo se n è pari
    int res = (n%2); 
    if (res == 0){
        return false; 
    }
    else { // codice da eseguire se è dispari
        if (res == 1 && n>3){
            int rad = static_cast<int>(sqrt(n)); 
            for (int i = 3; i<=rad; i+=2){
                if (n%i == 0)
                    return false; 
            }
        }
    }
    return true; 
}

int main(){
    int n, x; 
    cout << "Inserisci 2 numeri per verificare se sono primi gemelli: "; 
    cin>>n>>x; 
    if (primo(n) && primo(x)){
       if (n == x - 2 || n == n - 2)
            cout << n << " e " << x << " sono primi gemelli!" << endl; 
    return 0; 
    }   
}