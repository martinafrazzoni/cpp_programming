/*stampa una colonna specifica in una matrice*/
#include <iostream>
using namespace std; 
int main(){
    // la nostra matrice avrà 2 righe e deu colonne. 
    int righe = 4; 
    int col = 4; 
    // dichiariamo ed inizializziamo una matrice
    int data[righe][col] = 
    { 
    {1, 2, 3, 4}, 
    {5, 6, 7, 8},
    {9, 10,11, 12},
    {13, 14,15, 16},    
    }; 
    // creiiamo una variabile che conterrà il numero della colonna da stampare. 
    int col_da_stampare; 
    cout << "Inserisci il numero della colonna che vuoi stampare: \n"; 
    cin>>col_da_stampare; 

    // controlliamo che la colonna da stampare sia nel range
    if (col_da_stampare <= 0 || col_da_stampare >= col){
        cout << "Colonna fuori range!"; 
        return 1; 
    }

    // facciamo un for che va da 0 al numero di righe, e stamperemo i valori all'indice col_da_stampare
    for (int i = 0; i <righe; i++ ){
        cout << data[i][col_da_stampare] << " "; 

    }
    cout << endl; 
    cout << endl; 
    // per stampare solo la colonna dobbiamo scorrere tutti gli indici della colonna
    //data[0][col_da_stampare]; // il secondo indice è la colonna che ci interessa. 
    //data[1][col_da_stampare]; // secondo valore della colonna
    //data[2][col_da_stampare];
    //data[3][col_da_stampare]; 

    return 0; 
}