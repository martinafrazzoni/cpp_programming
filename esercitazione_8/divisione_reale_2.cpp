/*
  Scrivere un programma che legga due numeri INTERI, e stampi il
  risultato della divisione REALE tra i due numeri.  Assumere che non
  si possa avere una espressione di tipo intero come rvalue in un
  assegnamento in cui a sinistra (lvalue) si ha una variabile di tipo
  reale.

  Esempio:

  Inserisci due valori interi: 5 2
  5 / 2 = 2.5

*/
#include <iostream>
using namespace std; 
int main(){
    int a, b; 
    cout << "Inserisci due numeri interi: "; 
    cin>>a>>b; 
    double a1 = static_cast<double>(a); 
    double b1 = static_cast<double>(b); 
    cout << a1 / b << endl; // la divisione la posso fare anche con b1. 
    return 0;
}