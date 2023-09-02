/*Proviamo a scrivere, compilare ed eseguire un programma in cui, si definisce una funzione di nome fun che: 
-	Non prende alcun parametro in ingresso; 
-	Non ritorna alcun valore; 
-	Stampa sullo schermo un messaggio
Invochiamo tale funzione all’interno della funzione main e si esce. */

#include <iostream>
using namespace std; 
void fun (){
    cout << "la mia prima funzione! \n"; 
}
int main(){
    fun(); 
    return 0; 
}
