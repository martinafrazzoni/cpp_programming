/*Scrivere un programma che legge in ingresso una sequenza di numeri interi,
ciascuno dei quali può' essere solo 0 oppure 1. Se l'utente immette un numero
diverso, allora la lettura delle cifre termina.

Durante la lettura il programma calcola e stampa il numero in base 10 corrispondente
alla sequenza di cifre in base 2 inserite fino a quel punto. In particolare, quando
l'utente inserisce qualcosa di diverso da 0 o 1, il programma stampa il valore
finale del numero in base 10 ed esce.

Un possibile esempio di input/output è il seguente:

Prossima cifra in base 2: 0
Numero in base 10: 0

Prossima cifra in base 2: 1
Numero in base 10: 2

Prossima cifra in base 2: 0
Numero in base 10: 2

Prossima cifra in base 2: 2
Numero in base 10: 2

Suggerimento per la soluzione.
Considerate che, se si calcola il valore del numero da stampare, in funzione del
valore delle cifre immesse e del peso credente di tali cifre, e lo si memorizza
in una variabile di tipo int, allora la stampa del contenuto di tale variabile fornirà
proprio il numero in base 10 richiesto ad ogni passo.
*/
#include <iostream>
using namespace std; 
int main(){
    int b; // cifra in binario. 
    int d = 0; // numero decimale. 
    while (true){
        do
        {   cout<<"inserisci cifra binaria: "; 
            cin>>b;  
                if (!(b == 1 || b == 0)){
                    return 1; 
                }
            }
        while (b == 0 & b == 1);
        d = (d*2) + b; 
        cout<<"il valore in base 10 è " << d << endl;  
    }
    return 0; 
}