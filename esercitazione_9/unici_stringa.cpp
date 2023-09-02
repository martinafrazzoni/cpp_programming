#include <iostream>
#include <cstring>
using namespace std; 
bool tutti_unici(char string [ ]){
    // troviamo la lunghezza della stringa: 
    int lunghezza_stringa = strlen(string); // la funzione ritorna la lunghezza della stringa escluso il terminatore. 
    // ciclo for che scorre l'array
    for(int i = 0; i < lunghezza_stringa; i++){
        // ciclo for innestato che controlla se il carattere di indice i è presente anche nel resto della stringa
        for (int j = i+1; j < lunghezza_stringa; j++){
            if (string[i] == string[j]) // se l'if è true allora abbiamo trovato un carattere. 
                return false; 
        }
    }
    return true; 
}
int main(){
    // programma che controlla se in una stringa tutti i caratteri sono unici. 
    char string[] = "abcdefbghi"; 
    tutti_unici(string); 
    return 0; 
}