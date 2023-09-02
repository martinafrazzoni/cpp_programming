/*stampa triangolo pieno di lato n*/
#include <iostream>
using namespace std; 
int main(){
    int lato; //lunghezza lato triangolo
    do {
        cout << "Inserisci il valore del lato del triangolo: \n"; 
        cin>>lato; 
    }
    while (lato<=0); 
    for (int i = 0; i < lato; i++){ // i è il valore della riga corrente e va da 1 a lato. 
        for (int j = 0; j < lato-i; j++){
            cout << "."; // stampo gli spazi vuoti prima degli asterischi, il numero degli spazi vuoti è uguale a lato - i, dove i è il numero della riga corrente. 
        }
        for (int k = 0; k<=i; k++){
            cout << " #"; // per ogni riga il programma usa un altro ciclo for per stammpare i cancelletti. il numero dei cancelletti è uguale a i, dove i è il numero della riga corrente. La variabile k indica il numero del cancelletto corrente e va da 1 a i.
        }
        cout << endl; 
    }
    return 0; 
}
