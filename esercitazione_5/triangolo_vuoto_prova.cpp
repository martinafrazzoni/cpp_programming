/*stampa triangolo pieno di lato n - mi ha aiutato il prof*/
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
            cout << " "; // stampo gli spazi vuoti prima dei cancelletti, il numero degli spazi vuoti è uguale a lato - i, dove i è il numero della riga corrente. 
        }
        for (int k = 0; k<=i; k++){
            if ((k == 0 || k == i) || (i == 0 || i == lato-1)){
                cout << " #";
            }
            else 
            cout << "..";  
        }
        cout << endl; 
    }
    return 0; 
}
