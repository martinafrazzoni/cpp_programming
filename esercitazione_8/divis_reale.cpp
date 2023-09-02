/*
  Scrivere un programma che legga due numeri reali da stdin, e stampi il 
  risultato della divisione reale tra i due numeri.

  Esempio:

  Inserisci due valori reali: 5.5 2
  5.5 / 2 = 2.75

*/
#include <iostream>
#include <iomanip>
using namespace std; 
int main(){
    double a; // posos usare anche double, la differenza è nella precisione, quante cifre dopo la virgola sono corrette. 
    double b; 
    cout << "Inserisci due valori reali: "; 
    cin>>a>>b; 
    cout << a << " / " << b << " = " << (a/b) << setprecision(8) << endl; // ho ut8lizzato septecision
    return 0; 
}