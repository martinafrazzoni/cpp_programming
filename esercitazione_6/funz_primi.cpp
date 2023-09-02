/*Scrivere una funzione che verifichi se un numero naturale passo in ingresso come parametro attuale è primo. Il numero non viene letto da stdin da parte della funzione. La funzione deve restituire falso se il numero non è primo, vero se il numero è primo. Facciamo attenzione al tipo di ritorno della funzione. Utilizzando tale funzione, riscrivere il programma che controlla se due numeri primi sono gemelli. */
#include <iostream>
using namespace std; 
bool primo (int n){ 
    for (int i = 2; i < n; i++){ 
        int res = (n%i); 
        if (res == 0){
            return false; 
        }
    }
    return true; 
}

int main(){
    primo(9); 
    cout << primo(9) << endl; 
}
