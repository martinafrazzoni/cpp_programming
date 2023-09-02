/*
  Scrivere un programma che definisca una matrice bidimensionale di
  interi, di dimensioni stabilite a tempo di scrittura del programma, ed
  assegni ad ogni elemento un valore letto da stdin. Infine stampi il
  contenuto della matrice.
 */

#include <iostream>
using namespace std; 
int main(){
    // definire una matrice bidimensionale di interi

    const int dim_righe = 4; 
    const int dim_col = 4; 
    int matrice [dim_righe] [dim_col]; 

    // matrice bidimensionale di 4 righe e 4 colonne. 
    // assegno ad ogni elemento un valore da stdin
    // per accedere agli elementi ci accedo come faccio con gli array

    // faccio un ciclo for che parte da 0 e arriva fino a dim_righe, e chiedo all'utente di inserire un valore. 
    cout << "Riempimento matrice: \n"; 
    for(int i = 0; i < dim_righe; i++){
        for(int j = 0; j < dim_col; j++){
            cout << "Inserisci i valori: \n"; 
            cin >> matrice[i][j]; 
        }
    }

    for(int i = 0; i < dim_righe; i++){
        for(int j = 0; j < dim_col; j++){
            cout << matrice[i][j] << " "; 
        }
        cout << endl; 
    }

    
    return 0; 
}
