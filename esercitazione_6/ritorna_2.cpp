/*Scrivere un programma in cui si definisce una funzione di nome ritorna_2, che: 
-	Non prende alcun parametro in ingresso
-	Ritorna il valore 2
Da dentro la funzione main, si invoca la funzione ritorna_2 e si stampa il valore ritornato da tale funzione. 
*/
#include <iostream>
using namespace std; 
int ritorna_2 (){
    return (2*1); 
}

int main(){
    ritorna_2(); 
    cout << ritorna_2() << endl; // questa espressione contiene solo un fattore che è ritorna_2, quindi solo l'invocazione. Quando devo scoprire il valore di ritorno. di questa funzione, la chiamo e la eseguo, lei mi ritorna 2 e quindi stampa 2. 
    return 0;  
}