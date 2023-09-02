/*
 * Scrivere un programma che legge in ingresso un numero intero non
 * negativo a, e stampa sullo schermo tutti i numeri primi compresi
 * tra 0 ed a.  Realizzare il programma definendo ed utilizzando
 * almeno le due funzioni seguenti.
 *
 * Una funzione che, dato un numero intero passato come parametro,
 * ritona true se il numero e' primo, false altrimenti.
 *
 * Una funzione che, dato un numero intero n passato come parametro,
 * ritorna il il piÃ¹ piccolo numero primo maggiore o uguale di n.  La
 * seconda funzione DEVE utilizzare la prima.
 *
 * Se ci si riesce, realizzare il programma invocando solo la seconda
 * funzione dal main, e prima di definirla.
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

int primo_più_piccolo(int n){
    int k; 
    if (primo(n))
        return n; 
    else {
        for (k = n ; k++;){
            primo(k); 
            if (primo(k))
                return k; 
        }
    }
    return k; 
}


int main(){
    int n; 
    do {
        cout << "Inserisci un numero intero non negativo: "; 
        cin>>n; 
    }
    while (n<0);    
    for(int j = 0; j <=n; j++){// faccio un ciclo che mi calcola quali dei numeri da 0 a n sono primi. 
        primo(j); 
        if (primo(j)){
            cout << j << " è primo!" << endl; 
        }
    }
    cout << "il numero primo più piccolo > o uguale a  "<< n << " è " << primo_più_piccolo(n) << endl; 
    return 0; 
}
