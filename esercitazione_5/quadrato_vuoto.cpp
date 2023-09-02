/*scrivere un programma che richieda all'utente di inserire un numero intero positivo non maggiore di una costante poisitiva a scelta e costruisca un quadrato vuoto di lato pari al numero scelto e riempito con il carattere #
Ad esempio: 
Lato: 4
# # # #
#     #
#     #
# # # #

*/
#include <iostream>
using namespace std; 
int main (){
    const int lato_max = 10; 
    int lato; 
    do {
        cout << "Immetti la lunghezza del lato del quadrato (non deve essere maggiore di " << lato_max << ") \n"; 
        cin>> lato; 
    } 
    while (lato < 1 || lato > lato_max);
    
    for (int j = 0; j < lato; j++){ // ciclo che mi stampa le colonne
        for (int i = 0; i < lato; i++){ // mi stampa le righe
        if ((i == 0 || i == lato-1) || (j == 0 || j == lato-1))
                cout << " #"; 
            else
                cout << "  ";  
        }
        cout << endl;
    }
    return 0; 
}




/*
for (int i = 0; i < ((lato*lato)-1); i++){
        cout << " # "; 
        if ((i+1)%lato == 0){
            cout << endl; 
        }
    }   
*/