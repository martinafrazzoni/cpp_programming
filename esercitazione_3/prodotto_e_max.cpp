/*
 * Scrivere un programma che legga un numero intero n. Il numero n
 * viene di nuovo richiesto finché non è compreso tra 0 ed
 * una costante definita a tempo di scrittura del programma.
 *
 * Successivamente si chiede l'immissione di n interi positivi e
 * se ne calcola e stampa il prodotto ed il valore massimo (il valore
 * piu' grande tra quelli inseriti). Realizzare il calcolo prima
 * utilizzando e poi senza utilizzare l'istruzione for. Messaggio di errore se il prodotto va in overflow. 
 *
*/
#include <iostream>
using namespace std; 
int main (){
    const int k = 10; 
    int max_int = 2147483647; 
    int n; 
    do {
        cout << "Quanti numeri vuoi moltiplicare tra 0 e " << k << " ? "; 
        cin>>n; 
        if (n<=0 || n>k)
            cout << "Il valore immesso non è compreso nell'intervallo"<<endl; 
    }
    while (n<=0 || n>k); // continuamo a fare il ciclo do while mentre l'input è sbagliato, cioè mentre n è minore di zero oppure più grande di 20. 
    int p = 1; // prodotto dei valori; 
    int numero;
    int max = 0; 
    for (int i=1; i<=n; i++){
        cout << "Inserisci un numero intero positivo "; 
        cin>>numero; 
        p*=numero;  // p=p*numero, ed è la moltiplicazione iterativa dei numeri. 
        if (numero>max)
            max = numero; 
// devo stare attenta ad inizializzare max a 0, perchè se voglio  guardare il massimo tra numeri positivi max=0 va bene, perchè           tutti i numeri che prendo dovrebbero essere più grandi di zero. ma se voglio guardare al valore massimo di numeri che potrebbero essere negativi, devo iniziializzare max al più grande valore negativo possibile (min_int). 
    }
    cout << "Il prodotto dei valori inseriti è " << " = " << p << endl; 
    if (numero>(max_int/=p)) // p*=numero>max_int, ma così non lo posso scrivere perchè non posso fare il controllo, i valori più alti di max_int sono casuali, per poter fare il controllo devo essere ancora negli interi possibili. e quindi divido *=p che diventa numero>(max_int/=p). 
        cout << "Attenzione: il risultato non è attendibile perchè c'è stato overflow. \n"; 
    
    cout << "Il massimo tra i valori inseriti è "<< max << endl; 
    return 0; 
}

// se avessi voluto usare il while 
/*int i = 1; 
while(i<=n){
    cout<<"Inserisci un numero intero positivo: "; 
    cin>>numero; 
    if (numero>max)
        max=numero; 
    i++
}*/