/*Scrivere un programma che richieda all'utente un numero intero positivo non maggiore di una costante positiva a scelta, e costruisca un quadrato pieno di lato pari al numero scelto e riempito con il carattere #. Implementare la stampa del quadrato mediante una funzione. 
Esempio: 
Lato:3
# # #
# # # 
# # #

*/
#include <iostream>
using namespace std;

void stampa_quadrato(int n){
    // ciclo for che mi disegna il quadrato. 
    for(int j = 1; j <=n; j++){
        for (int i = 1; i <=n; i++){
        cout << " # "; 
    }
    cout << endl;
    }
}

int main(){
    int n; 
    int k = 10; //costante. il lato del quadrato non può essere maggiore di k. 
    do{
        cout << "Inserisci un numero intero positivo: "; 
        cin>>n; 
    }
    while (n>k); 
    stampa_quadrato(n);      
    return 0; 
}