/* 
 Scrivere una funzione che riceve in ingresso due stringhe, copia la
 prima nella seconda, e ritorna la nuova lunghezza della stringa di
 destinazione.
*/
#include <iostream>
#include <cstring>
using namespace std; 
int copia_stringa (const char stringa_uno [ ], char stringa_due[ ]){
    int i; 
    for (i = 0; (stringa_uno[i] != '\0'); i++){
        stringa_due[i] = stringa_uno[i]; 
    }
    stringa_due[i] = '\0'; 
    int lunghezza_stringa_due = strlen(stringa_due); 
    return lunghezza_stringa_due; 
}
int main(){
    // creo le mie stringhe
    const int max_stringa = 50; 
    char stringa_uno[] = "Questa è una stringa!"; 
    char stringa_due[max_stringa]; 

    // devo copiare la prima stringa nella seconda
    copia_stringa(stringa_uno, stringa_due); 
    cout << " * " <<  stringa_uno << " * " << endl; 
    cout << " * " <<  stringa_due << " * " << endl; 
    return 0; 
    
}