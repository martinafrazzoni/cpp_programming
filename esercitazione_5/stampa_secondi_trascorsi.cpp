/*Utilizzare quanto appreso nell'esercizio stampa_secondi.cc sull'espressione
time(0).

Utilizzare inoltre le seguenti informazioni: se si mandano all'oggetto cout
il carattere speciale "\r" seguito da caratteri o valori da stampare, ed infine
dal manipolatore flush, allora tali caratteri o valori saranno stampati 
all'inizio delle riga corrente (sovrascrivendo
il precedente contenuto della riga).
Ad esempio, l'istruzione

cout<<"\r"<<"prova"<<flush ; // equivalente a cout<<"\rprova"<<flush ;

stampa prova all'inizio della riga corrente, sovrascrivendo l'eventuale
precedente contenuto (solo) dei primi 5 caratteri di tale riga. Se al posto
del manipolatore flush si utilizza endl, si ottiene lo stesso risultato, solo
che poi, come sappiamo, si va anche a capo (inizio della prossima riga).

Scrivere un programma che stampa il numero di secondi trascorsi dal
suo avvio, in maniera tale che tale numero si aggiorni al passare del
tempo (quindi sempre sulla stessa riga). Il programma deve terminare
automaticamente quando e' trascorso un numero di secondi scelto a tempo
di scrittura del programma stesso.
*/
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std; 
int main (){
    const int max_sec = 10; //visto che il programma deve terminare dopo un certo tempo deciso a tempo di scrittura, scrivo una constante che mi rappresenta la durata del mio programma. 
    int t_start = time(0); // variabile intera che mi indica l'inizio del mio programma. 

    while (time(0)-t_start<=max_sec){ //time (0) - t_start quivale a zero e zero è minore di 10 (max_sec), quindi mi stamperà, ogni secondo, i secondi dall'inizio del programma (zero) fino a 10, dopo smette perchè la condizione non è più vera. 
        cout<<"\r"<<time(0) - t_start<<flush; 
        system("sleep 1"); 
    }
    return 0; 
}