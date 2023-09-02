/*
  Scrivere un programma che legga due numeri INTERI, e stampi il
  risutato della divisione REALE tra i due numeri.  Non utilizzare la
  conversione esplicita per realizzare il programma.

  Esempio:

  Inserisci due valori interi: 5 2
  5 / 2 = 2.5

*/
#include <iostream>
using namespace std; 
int main(){
    int a, b; 
    cout << "Inserisci dui numeri interi: "; 
    cin>>a>>b; 
    double c = a; 
    double ris = (c / b); 
    cout << ris << endl; 
    return 0; 
}