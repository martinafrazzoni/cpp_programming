/* 
 Scrivere un programma che conti le occorrenze di un carattere
 inserito da tastiera all'interno di una stringa definita a tempo di
 scrittura del programma.

 Esempio di output:

 Stringa: Analisi dei requisiti
 Quale carattere devo cercare?
 i
 i compare 6 volte nella stringa "Analisi dei requisiti"

*/
//definisco la stringa: 
#include <iostream>
using namespace std; 

int main(){
    char stringa [] = "Analisi dei requisiti"; 
    char da_trovare; 
    int conta = 0; 
    cout << stringa << endl; 

    cout << "Quale carattere devo cercare? \n"; 
    cin>>da_trovare; 

    // scorro l'array fino a quando non trovo il terminatore
    for (int i = 0; stringa[i] != '\0'; i++){
        if (stringa[i] == da_trovare)
            conta++; 
    }
    cout << "in " <<  stringa << " il carattere " << da_trovare << " è presente " << conta << " volte\n"; 
    return 0; 
}

