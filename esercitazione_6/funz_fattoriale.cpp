/*Scrivere un programma che stampi il fattoriale di un numero intero
non negativo letto dallo stdin. Implementare il calcolo (e non la stampa)
del fattoriale mediante una funzione. Implementare la lettura del
valore e la stampa del fattoriale all'interno della funzione main.
E in più faccio anche il controllo dell'overflow. (opzionale, l'ho aggiunto io per fare esercizio!)*/
#include <iostream>
using namespace std; 
int fattoriale (int n){
    int f = 1; // variabile contenitore che mi tiene traccia delle moltiplicazioni che devo fare. 
    int max_int = 2147483647; 
    int i; 
    for (i = 1; i <= n; i++){
        f*=i; 
    }
    if (i>(max_int/=f)){
        cout << "il risultato non è attendibile perchè c'è stato overflow!" << endl; 
        return 0; 
    }
    return f; 
}
int main(){
    int n; 
    do {
        cout << "Inserisci un numero n: "; 
        cin>>n; 
    }
    while (n<0); 
    cout << "Il fattoriale di " << n << " é: " << fattoriale (n) << endl; 
    return 0; 
}
