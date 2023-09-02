/*Scrivere un programma che legga una parola da stdin e ne assegni il contenuto ad un’altra stringa. La stringa di destinazione deve essere memorizzata in un array di dimensioni sufficienti a contenere la stringa sorgente. Il precedente contenuto della stringa di destinazione vene perso (sovrascrittura). Ripetere l’esercizio utilizzando invece una stringa contenente più parole, ed inizializzata a piacere a tempo di scrittura del programma. */

#include <iostream>
using namespace std; 
int main(){
    int i; 
    const int max_stringa = 50; 
    char stringa [max_stringa]; 
    
    char seconda_stringa [max_stringa]; 
    cout << "Inserisci una parola: "; 
    cin>>stringa; 
    for (i = 0; stringa[i] != '\0'; i++){
        seconda_stringa[i] = stringa[i]; 
    }
    seconda_stringa[i] = '\0'; 

    cout << seconda_stringa << endl; 
    return 0; 
}

/* */