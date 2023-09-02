/*
   Scrivere un programma che legga un carattere da stdin, ne
   incrementi il valore di 1 e lo stampi su stdout.

   Esempi:
   Immettere un carattere: r
   Dopo l'incremento: s

   Immettere un carattere: 2
   Dopo l'incremento: 3
*/

#include <iostream>
using namespace std; 
int main(){
    char carattere; 
    cout << "inserisci un charattere: "; 
    cin>>carattere; 
    char incremento = carattere + 1; 
    cout << "il carattere dopo l'incremento è " << incremento << endl;  
    return 0; 
}


/*  int codice = static_cast<int>(carattere); 
    int incremento = codice+1; 
    char char_inc = static_cast<char>(incremento); 
    cout << "il carattere dopo l'incremento è " << char_inc << endl; >*/