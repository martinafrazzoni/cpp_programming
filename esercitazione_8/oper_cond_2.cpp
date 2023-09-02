/*
 Senza utilizzare nÃ¨ l'istruzione if nÃ¨ l'istruzione switch nÃ¨ le
 istruzioni cicliche, scrivere un programma che legge un numero
 intero da stdin e lo memorizza in una variabile n. Se il numero letto
 Ã¨ minore di 0 oppure maggiore di 10, nel programma si assegna
 rispettivamente il valore 0 oppure 10 ad n. Infine si stampa il
 valore di n.
*/
#include <iostream>
using namespace std; 
int main(){
    int n; 
    const int k = 10; 
    cout << "Inserisci un numero intero: "; 
    cin>>n; 
    n = (n<0) ? 0 : n; 
    n = (n>10) ? 10 : n;  
    cout << n << endl;  
    return 0; 
}