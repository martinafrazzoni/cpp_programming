/*
 Senza utilizzare nÃ¨ l'istruzione if nÃ¨ l'istruzione switch nÃ¨ le
 istruzioni cicliche, scrivere un programma che legge un numero intero
 da stdin e lo memorizza in una variabile n. Se il numero letto Ã¨
 minore di 0, nel programma si assegna forzatamente il valore 0 ad
 n. Infine si stampa il valore di n.
*/

#include <iostream>
using namespace std;
int main(){
    int n; 
    cout << "Inserisci un numero intero da stdin: ";
    cin>>n; 
    // se n è minore di 0 tutta l'espressione n = 0, altrimenti è uguale a n. 
    n = (n<0) ? 0 : n; 
    cout << n << endl; 
    return 0;  
}

