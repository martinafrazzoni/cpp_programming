/*copuare soltanto le vocali di una stringa in un'altra stringa. */
#include <iostream>
using namespace std; 


int main(){

    const int max_char = 15; 
    char prima_stringa [] = "Domani piove"; 
    char seconda_stringa [max_char];
    int lunghezza = 0; 

    int i; 
    for (i = 0; prima_stringa[i] != '\0'; i++){
        if (
            prima_stringa[i] == 'a' || 
            prima_stringa[i] == 'e' || 
            prima_stringa[i] == 'i' || 
            prima_stringa[i] == 'o' || 
            prima_stringa[i] == 'u'
            ){
            seconda_stringa[lunghezza] = prima_stringa[i]; 
            lunghezza++; 
        }
    } 
    seconda_stringa[lunghezza] = '\0'; 
    cout << seconda_stringa << endl; 

}