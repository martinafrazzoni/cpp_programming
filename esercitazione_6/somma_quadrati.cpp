/*
 * Scrivere un programma che legge in ingresso un numero intero e
 * verifica se può essere ottenuto come somma di quadrati
 * interi. Implementare la verifica definendo ed utilizzando in prima
 * battuta una funzione che prenda in ingresso (attraverso parametri
 * formali) due numeri interi n ed i e, se esiste un numero intero non
 * negativo j tale che n == i*i + j*j, ritorna tale numero, altrimenti
 * ritorna -1.  NOTA: la funzione non legge i numeri da stdin e non li
 * stampa su stdout.
 *
 * Commento: Utilizzando la precedente funzione, la ricerca può essere
 * effettuata per tentativi successivi, ossia provando per i = 1, 2,
 * ...  In questo caso, si può notare che non è necessario che in
 * ciascuno di tali tentativi la funzione in questione prenda in
 * considerazione valori j < i, ma basta che consideri solo j >= i.
 *
 * Suggerimento: sfruttando il precedente commento, si può
 * implementare l'algoritmo in modo più efficiente definendo ed
 * utilizzando, al posto della precedente funzione, una funzione
 * simile, che, se esiste un numero intero non negativo j >= abs(i)
 * tale che n == i*i + j*j, ritorna tale numero, altrimenti ritorna
 * -1.  Se ci si riesce, definire ed utilizzare quest'ultima funzione
 * al posto di quella generale.
 */


// IL MIO PROGRAMMA è DIVERSO DA QUELLO DLE PROF, IO SONO PARTITA DA UN SOLO NUMERO E HO TROVATO I DUE NUMERI CHE ELEVATI AL QUADRATO MI DANNO N. 

#include <iostream>
#include <cmath>
using namespace std; 

int somma_di_quadrati(int n){
    int b = 2; 
    int k_al_quadrato = 1; // variabile dove mi si accumuna k^2 (il mio k*k)
    int k = static_cast<int>(sqrt(n)); 
    // eleviamo a potenza il risultato intero di radice quadrata di n. 
    for (int j = 0; j < b; j++){
        k_al_quadrato*=k; 
    }
    // sottraggo al numero n il quadrato del primo numero che è k, quindi n - k_al_quadrato che mi dà j. 
    int ris = (n-k_al_quadrato);
    int j = static_cast<int>(sqrt(ris)); 
    int somma = ((k*k) + (j*j)); 
    if (somma == n)
        cout << n << " si può scrivere come la somma dei seguenti quadrati: " << k << "^2 " << j << "^2 " << endl; 
    else 
        cout << n << " non si può scrivere come somma di quadrati" << endl; 
    return k, j; 
}


int main(){
    int n; 
    cout << "Inserisci un numero n per verificare se si può scrivere come somma di quadrati: "; 
    cin>>n; 
    somma_di_quadrati(n); 
    return 0; 
}
