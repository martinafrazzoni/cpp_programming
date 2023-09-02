/* Scrivere un programma che mostri la visibilitÃ  delle variabili.
 * In particolare, nel programma bisogna definire
 * 1) una funzione, chiamiamola fun, oltre la funzione
 *    main. Tale funzione deve prendere in ingresso (parametro formale) un valore intero
 * 2) una variabile globale di nome x, inizializzata ad un qualche valore
 * 3) una variabile di nome x all'interno di un blocco all'interno della
 *    funzione main
 * 4) una variabile di nome x all'interno di un blocco all'interno di fun
 * La funzione main deve stampare il valore della variabile globale x,
 * incrementarlo, e quindi stamparlo di nuovo. Quindi deve stampare il valore
 * della variabile x definita nel blocco interno, incrementarlo e stamparlo
 * di nuovo. Poi deve invocare due volte la funzione fun passandogli
 * prima la x definita nel blocco interno, quindi la x globale.
 * 
 * La funzione fun deve stampare il valore della variabile globale x,
 * incrementarlo, e quindi stamparlo di nuovo. Quindi deve stampare il valore
 * della variabile x definita nel proprio blocco interno, incrementarlo e
 * stamparlo di nuovo. Assieme al valore della variabile x (globale o definita
 * nel proprio blocco interno), la funzione fun deve stampare ogni
 * volta anche il valore del parametro attuale con cui Ã¨ stata invocata.
 *
 * Esempio:
 * Sono il main e la variabile x vale 300
 * Sono il main e la variabile x vale 301 dopo l'incremento
 * Sono il main dentro il blocco e la variabile x vale 3
 * Sono il main dentro il blocco e la variabile x vale 4 dopo l'incremento
 *
 * Sono il main dentro il blocco e adesso chiamo la funzione
 * Sono la funzione e la mia x vale 301 mentre la x di chi mi chiama vale 4
 * Sono la funzione e la mia x vale 302 dopo l'incremento,
 *         mentre la x di chi mi chiama vale 4
 * Sono la funzione dentro il blocco e la mia x vale 0,
 *         mentre la x di chi mi chiama vale 4
 * Sono la funzione dentro il blocco e la mia x vale 1 dopo l'incremento,
 *         mentre la x di chi mi chiama vale 4
 *
 * Sono il main e adesso chiamo la funzione
 * Sono la funzione e la mia x vale 302 mentre la x di chi mi chiama vale 302
 * Sono la funzione e la mia x vale 303 dopo l'incremento,
 *         mentre la x di chi mi chiama vale 302
 * Sono la funzione dentro il blocco e la mia x vale 0,
 *         mentre la x di chi mi chiama vale 302
 * Sono la funzione dentro il blocco e la mia x vale 1 dopo l'incremento,
 *         mentre la x di chi mi chiama vale 302
 *
 */
#include <iostream>
using namespace std;
int x = 2;  
void fun (int n){
    cout << "[fun]: la mia x vale " << x << " e la x di chi mi chiama vale " << n << endl; 
    x++; 
    cout << "[fun]: la x dopo l'incremento vale " << x << " e la x di chi mi chiama vale " << n << endl; 
        {
        int x = 16; 
        cout << "[blocco di fun]: la x vale " << x << " e la x di chi mi chiama vale " << n << endl; 
        x++; 
        cout << "[blocco di fun]: la mia x dopo l'incremento vale " << x << " e la x di chi mi chiama vale " << n << endl;  
    }
}
int main(){
    cout << "[main]: la variabile x vale " << x << endl; 
    x++; 
    cout << "[main]: la variabile x dopo l'incremento vale " << x << endl; 
    {
        int x = 24; 
        cout << "[blocco del main]: la x vale " << x << endl; 
        x++; 
        cout << "[blocco del main]: la x dopo l'incremento vale " << x << endl; 
        cout << "[blocco del main]: adesso chiamo la funzione fun: " << endl;  
        fun(x);  // la x è quella che vive dentro il blocco che ha valore 25 (dopo l'incremento)
    }
    cout << "[main]: adesso chiamo la funzione " << endl; 
    fun(x); // questa x qua è la x globale 
}