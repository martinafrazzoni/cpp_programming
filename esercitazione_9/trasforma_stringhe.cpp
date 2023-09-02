/*Scrivere una funzione che prende in ingresso una stringa e la elabora nella
seguente maniera:
. se il primo carattere e' una lettera minuscola, lo converte in una lettera 
  maiuscola
. se uno qualsiasi dei caratteri seguenti e' una lettra maiuscola, lo converte 
  in una lettera minuscola
Ad esempio, se la funzione riceve in ingresso la stringa "ciAo",  
la converte nella stringa "Ciao".
Possono tornare utili funzioni di libreria come tolower e toupper (per dettagli
sulle funzioni di libreria e sui file di intestazione vedere, ad esempio, 
www.cppreference.com).
per utilizzarle si può includere:
#include <cstdlib> */

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std; 
int main(){
    const int max_stringa = 20; 
    char stringa[max_stringa]; 
    cout << "Inserisci una stringa: \n"; 
    cin>>stringa; 

    int lunghezza = strlen(stringa); 
    int maiuscola = 0; 

    stringa[maiuscola] = toupper(stringa[maiuscola]); 
    for (int i = 1; i < lunghezza; i++){
        stringa[i] = tolower(stringa[i]); 
    }

    cout << stringa << endl; 
}
