/* 
 Scrivere un programma che conta le occorrenze di un carattere
 inserito da tastiera all'interno di una stringa, costituita da una
 sola parola, inserita anch'essa da tastiera. La lettura della stringa
 e del carattere devono avvenire nel main, mentre il numero di
 occorrenze deve essere ritornato da una funzione dedicata, a cui
 vengono passate sia la stringa che il carattere da cercare. La
 funzione non legge nulla da stdin e non scrive nulla su stdout.

 Inoltre la ricerca deve essere case-insensitive.  Gestire il problema
 delle maiuscole/minuscole sfruttando funzioni di libreria standard
 che operano sui caratteri. Trovare da soli quali sono tali funzioni e
 cosa bisogna includere per utilizzarle.
 A tal proposito ricordare che, dato un header file da includere per utilizzare
 un alcune funzioni ed oggetti della libreira standard del C, il nome del 
 corrispondente header file da includere in C++ si ottiene tipicamente 
 togliendo il suffisso .h ed aggiungendo il carattere c in testa al nome 
 dell'header file originario (es.: math.h in C diventa cmath in C++).

 Infine non bisogna sfruttare il controllo del terminatore per
 decidere quando fermare la ricerca nella stringa. Trovare da soli qualche
 funzione di libreria da utilizzare per evitare di dover effettuare tale 
 controllo e quale header file bisogna includere.

 -> il tipo size_t lo assumiamo equivalente a unsigned int
 -> la notazione <nome_tipo> * la assumiamo equivalente a <nome_tipo> []

 Esempio di output:

 Inserisci la parola in cui cercare: Pippo
 Stringa: Pippo
 Quale carattere devo cercare?
 P
 P compare 3 volte nella stringa "Pippo"
*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std; 

int trova_occorrenze(char parola [ ], char da_trovare, int lungh_parola){
    int conta = 0; 
    for (int i = 0; i < lungh_parola; i++){
        parola[i] =  tolower(parola[i]); 
        if (parola[i] == da_trovare)
            conta ++; 
    }
    return conta; 
}

int main(){
    const int max_stringa = 100; 
    char parola [max_stringa]; 
    char da_trovare; 

    cout << "Inserisci la parola: \n"; 
    cin>>parola; 
    
    cout << "Stringa: " << parola << endl; 

    cout << "Quale carattere devo cercare:  \n"; 
    cin>>da_trovare; 
    if (isupper(da_trovare))
        da_trovare = tolower(da_trovare); 

    int lungh_parola = strlen(parola); 

    trova_occorrenze(parola, da_trovare, lungh_parola); 

    cout << "Nella parola " << parola << " la lettera " << da_trovare << " è ripetuta " << trova_occorrenze(parola, da_trovare, lungh_parola) << " volte!\n"; 

    return 0; 
}
