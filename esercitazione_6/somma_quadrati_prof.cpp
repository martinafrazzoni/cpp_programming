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

#include <iostream>
#include <cstdlib> // mi serve per il valore assoluto.
using namespace std; 

int somma_di_quadrati(int , int ); // prototipo della nostra funzione, che prende due interi come parametri formali e restituisce un intero. 
int main(){
    int numero; 
    int i, j; 
    do {
        cout << "immetti un numero intero non negativo: \n"; 
        cin>>numero; 
    }
    while (numero<=0); 
    // tracing: 
    cout << "[main]: numero == " << numero << endl; // esempio di tracing, dico dentro quale funzione di mi trovo [main], e stampo qual'è il valore di numero. 
    for (int i = 0; 2*i*i <= numero; i++){ /*perchè 2*i*i? perchè se io ho numero che è dato dalla somma di due quadrati, se faccio i*i + i*i sono due quadrati, (i^2) + (i^2), ma se io sto facendo questo vuol dire che io ho già provato tutti i valori che sono prima di i e non c'è bisogno che vado a provare numeri più grandi, perchè il numero finale non può essere più grande della somma di due volte del quadrato dello stesso numero.  */

    // tracing: 
    cout << "\t [main]: invoco somma_di_quadrati (" << numero << "," << i << ") "; // sto invocando somma di quadrati e gli passo numero e i. 
    if (j = somma_di_quadrati(numero, i) != -1){ // si capisce ma non è molto leggibile potevamo inizializzare j con il risultato della funzione, e poi fare il controllo.
        cout << "il numero " << numero << " è la somma dei quadrati di " << i <<"e" << j << endl; 
        return 0; 
        }   
    }// se trovo la somma di quadrati finisco dentor il for. altrimenti esco e stampo che non ho trovato i due numeri.  
    cout << "il numero " << numero << "non è somma di quadrati\n"; 
}

/*
    Legge due numeri interi n ed i in ingresso e se esiste, un numero intero non negativo j >= abs(i) tale che n == i*i + j*j, ritorna il valore di j altrimenti ritorna -1.  
*/
int somma_di_quadrati(int numero, int i){
    int j = 0, somma = 0; 
    j = abs(i); //j prende il valore assoluto di i, se voglio includere anche la possibilità di j == i, allora parto da abs(i), altrimenti j = abs(i) + 1 se voglio che j !=i. 
    cout << "\t \t [somma_di_quadrati]: letto in ingresso: " << numero << " "<<i << endl; 
    while (somma <=numero){
        // tracing: 
        cout << "\t \t \t [somma_di_quadrati]: provo j == "<< j << endl; 
        somma = i*i + j*j; 

        if (somma == numero) // se la somma è uguale a n restituisco j, altrimenti incremento j e vado avanti. . 
            return j; 
        j++; 
    }
    return -1; // se non sono mai uscito vuol dire che ho trovato la somma, e quindi posso restituire -1. 
} 