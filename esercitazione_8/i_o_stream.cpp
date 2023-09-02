/*Scrivere un programma che, dopo aver letto da stdin una sequenza di numeri interi qualsiasi, stampi la somma dei valori letti. La lunghezza della sequenza non è nota a priori, né comunicata prima di iniziare ad immettere i numeri. L’utente deve immettere tutti i numeri senza altre comunicazioni nel mezzo. */

#include <iostream>
using namespace std; 
int main(){
    int n; 
    int somma = 0; 
    while (cin>>n){ // appena immetto un carattere che non è una cifra l'operatore cin va in stato di errore. 
        somma+=n; 
    }
    cout << "La somma dei valori inseriti è: " << somma << endl;  
}