/*
   Scrivere un programma che legga un carattere da stdin e lo stampi
   su stdout.

   Esempi:
   Immettere un carattere: r
   Hai immesso il carattere r

   Immettere un carattere: 2
   Hai immesso il carattere 2

 */
#include <iostream>
using namespace std; 
int main(){
    char carattere; 
    cout << "immetti un carattere: "; 
    cin>>carattere; 
    cout << "hai immesso il carattere " << carattere << endl; 
    return 0; 
}