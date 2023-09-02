/*stampa triangolo vuoto di lato n*/
#include <iostream>
using namespace std; 
int main(){
    int lato; //lunghezza lato triangolo
    do {
        cout << "Inserisci il valore del lato del triangolo: \n"; 
        cin>>lato; 
    }
    while (lato<=0); 
    for (int i = 0; i < lato; i++){ // i è il numero della riga corrente e va da 1 a lato. 
        for (int j = 0; j < lato-i; j++){
            cout << " "; // stampo gli spazi vuoti prima degli asterischi, il numero degli spazi vuoti è uguale a lato - i, dove i è il numero della riga corrente. 
        }
        for (int j = 0; j < 2*i + 1; j++){ // secondo ciclo viene usato per stampre i caratteri # che formano il triangolo. la variabile j viene utilizzata per tenere traccia dei caratteri stampati nella riga corrente. Il valore di i rappresenta il numero delle righe del triangolo che sono state stampate finora. 2*i + 1 viene usata per calcolare il numero di caratteri (e quindi di spazi vuoti) che devono essere stampati per ogni riga. 
            if (i == 0 || i  == lato-1){ // questo ciclo controlla se la riga corrente è la prima o l'ultima riga del triangolo e stampa una riga piena di asterischi. 
                cout << "#"; 
            } else if (j == 0 || j == 2*i){ // controlla se il crattere corrente è il primo o l'ultimo della riga e stampa un asterisco in tal caso. 
                cout << "#"; 
            } else {
                cout << "."; 
            }
        }
        cout << endl; 
    }
    return 0; 
}
