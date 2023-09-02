/*Scrivere  un programa che richieda all'utente di inserire un numero intero non positivo maggiore di una costante positiva a scelta, e costruisca un quadrato pieno di lato pari al numero scelto e riempito con il carattere #. 
Ex. lato 3: 
# # #
# # #
# # #  

*/

#include <iostream>
using namespace std; 
int main (){
    int lato; 
    const int lato_max = 6; 
    do{
        cout << "Inserisci la lunghezza del lato (non maggiore di " << lato_max << " ): " << endl; 
        cin>>lato; 
    }
    while (lato < 1 || lato > lato_max); 

    for (int j = 1; j <= lato; j++){ /*con questo ciclo stampo le colonne che mi servono*/
        for (int i = 1; i <= lato; i++){ /*con questo ciclo io ho stampato una sola riga. Ma io voglio stampare la riga tante volte     quante vale il lato. */ 
        cout << " # ";  
        }
        cout << endl;
    }
    
    return 0; 
}