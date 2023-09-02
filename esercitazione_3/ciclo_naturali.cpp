#include <iostream>
using namespace std; 
int main () {
    int N, i = 1; 
    cout << "Inserisci un numero naturale: \n"; 
    cin>>N; 
    while (i<=N){
        cout << i<< endl;
        i++; /*modifica della variabile I e quindi della condizione di ripetizione*/
    }
    return 0; 
}