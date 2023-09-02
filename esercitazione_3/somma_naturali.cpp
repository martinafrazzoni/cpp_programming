#include <iostream>
using namespace std; 
int main () {
    int i = 1; // variabile contatore; 
    int N; 
    int S = 0; // variabile che contiene la somma dei valori assunti da i ad ogni iterazione, minori di N. 
    cout << "inserisci un numero intero \n"; 
    cin>>N; 
    while (i<=N){
        S = S+i;
        i++;   // s+=i - quando leggo s per fare s+i io sto leggendo il vecchio valore, lo prendo e ci sommo il nuovo valore di i. Quindi S cambia con il nuovo valore.  
    }
    cout << S << endl; // la stampa la scrivo fuori dal blocco perchè devo scriverla una volta sola, cioè quando raggiunge N, e non tutte le volte che c'è l'iterazione. 
    return 0; 
}