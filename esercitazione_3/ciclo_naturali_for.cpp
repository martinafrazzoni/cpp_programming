#include <iostream>
using namespace std; 
int main (){ 
    int N; 
    cout << "Inserisci un numero naturale: "; 
    cin>>N; 
    for (int i=1; /*inizializzazione della variabile i*/ i<=N; i++ /*modifica della variabile i e quindi della condizione di ripetizione, quando la condizione diventa falsa smetto di ripetere il ciclo*/)
        cout << i << endl; 
    return 0; 
}