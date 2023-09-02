/*
 * Scrivere un programma che legga in ingresso un numero intero non negativo a
 * ed un esponente intero non negativo i, e stampi il valore di a^i.
 * Il programma controlla anche che l'operazione richiesta non generi overflow.
 * Il programma continua a chiedere di inserire i numeri a o i finché non sono 
 * entrambi non negativi.

 * Realizzare sia il calcolo della potenza che il controllo di
 * overflow mediante una funzione potenza. La funzione non deve
 * stampare niente sullo schermo. La stampa dei messaggi avviene
 * invece nella funzione main, in base ai valori ritornati dalla
 * funzione potenza. Come può fare la funzione potenza a dare
 * indicazione di overflow? Si può intuire uno dei modi confrontando
 * l'intervallo di valori di ritorno possibili da un punto di vista
 * matematico (ricordarsi che i valori ingresso devono essere
 * positivi), con l'intervallo di valori che la funzione può ritornare
 * in base al tipo del valore di ritorno.
 *
 * Esempi:
 *
 * Immettere un numero intero: 3
 * Immettere un esponente non negativo: 2
 * 3 ^ 2 = 9
 * Non c'è stato overflow
 *
 * Immettere un numero intero: 5
 * Immettere un esponente non negativo: 213
 * Risultato non esprimibile su un oggetto di tipo int
 *
 */
#include <iostream>
using namespace std; 
int potenza_overflow(int a, int b){
    int max_int = 2147483647;
    int cont = 1; 
    for (int i = 0; i < b; i++){
        cont *=a; 
    } 
    if (a>(max_int/=cont)){ // guardo se va in overflow. 
        return 1; 
    }
    return cont; 
}
int main(){
    int a, b; 
    do{
        cout << "Inserisci un numero intero non negativo ed il suo esponente sempre non negativo: "; 
        cin>>a>>b; 
    }
    while (a<0 || b < 0); 
    if (potenza_overflow(a, b) == 1){
        cout << "Il risultato non è esprimibile su un oggetto di tipo int!" << endl; 
    }
    else {
        cout << a << " ^ " << b << " = " << potenza_overflow(a,b) << endl;
        cout << "non c'è stato overflow!" << endl; 
    }
return 0;     
}