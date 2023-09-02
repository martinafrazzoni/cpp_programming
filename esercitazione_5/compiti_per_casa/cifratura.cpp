/*Supponiamo di sfruttare la configurazione di bit che rappresenta un numero intero non negativo c per nascondere un ulteriore numero intero non negativo n. La tecnica con cui il numero n viene inserito nel numero c è la seguente: si prende la configurazione di bit che rappresenta un numero n, la si fa precedere e seguire da un bit a 1  e si inserisce la configurazione risultante a partire dalla cifra di ordine n, della configurazione di bit che rappresenta il numero non negativo c (tutti i bit di c, al di fuori della configurazione che vi abbiamo immerso dentro, sono a zero). 

Vediamo un esempio: supponiamo di voler inserire il numero 4 all'intero di un numero intero rappresentato su 32 bit. La rappresentazione binaria del numero 4 è la seguente: 100. la configurazione che dobbiamo immergere è quindi 11001  (abbiamo inserito prima e dopo un bit a 1.). L'ordine della cifra a partire dalla quale la immergiamo è 4. la configurazione risultate su 32 bit è quindi: 
00000000 00000000 00000001 10010000.
Per evitare problemi di overflow, supponiamo sempre che n <=16. 

Traccia: Scrivere un programma che legga in ingresso un numero intero
non negativo n minore o uguale a 16, e lo immerga nella configurazione
di un altro numero intero non negativo, in base all'algoritmo definito
prima.

Il programma stampa quindi 
. il numero da nascondere in base 2
. il numero risultante in base 10 
. il numero risultante in base 2.

Un possibile output e' il seguente:

Inserisci il numero (compreso tra 0 e 16) da nascondere: 3
La configurazione del numero da inserire in base 2 e'
00000000000000000000000000000011
Il numero risultante e' 120
La configurazione risultante in base 2 e'
00000000000000000000000001111000
 */


#include <iostream>
#include <string>
using namespace std; 
int main(){
    int n; // numero intero da nascondere non deve essere maggiore di 16. 
    int b = 32; // numero di bit sui cui voglio rappresentare il mio numero
    int tb = 1; // contenitore dove accumulo b^i 
    int base = 2; 
    do{
        cout<<"inserisci un numero compreso da 0 e 16: \n"; 
        cin>>n;
    }
    while (n<0 || n>16); 
    
    for (int j = 0; j < b; j++){
        if (j>0){
            for (int x = 0; x < j; x++){
                tb*=base; 
            }
        }
    cout << ((n/tb)%base); 
    tb = 1; 
    }
    return 0; 
}



