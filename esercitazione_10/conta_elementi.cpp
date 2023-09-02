#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 
const int righe = 3; 
const int col = 4; 

void riempi_matrice_rand(int matrice[righe][col], int max, int min){
    // loop esterno che scorre le righe
    for (int i = 0; i < righe; i++){
        for (int j = 0; j < col; j++){
            matrice[i][j] = min + (rand() % (max - min + 1)); /*To generate random numbers within a specific range, you can use the following formula: min + (rand() % (max - min + 1)). This generates a random integer between min and max, inclusive.*/
        }
    }
}

int main(){
    // seme per la funzione rand
    srand(time(0)); 

    
    int matrice[righe][col]; 
    int min = -20; 
    int max = 50; // riempiamo la matrice con valori che vanno da min a max

    riempi_matrice_rand(matrice, max, min);  

    // stampo la matrice
    cout << "Ecco la matrice inserita: \n"; 
    for (int i = 0; i < righe; i++){
        for (int j = 0; j < col; j++){
            cout << matrice[i][j] << " "; 
        }
        cout << endl; 
    }

    /*definisco tre variabili: una che conta il totale di numero positivi presenti nalla matrice, un'altra per i numeri negativi e l'ultima che tiene il conto degli elementi nulli*/
    int tot_positivi = 0; 
    int tot_negativi = 0; 
    int tot_nulli = 0; 

    /*ciclo per scorrere la matrice*/
    for (int i = 0; i < righe; i++){
        for(int j = 0; j < col; j++){
            if (matrice[i][j]  > 0){
                tot_positivi++;
            }
            else if (matrice[i][j] < 0){
                tot_negativi++;
            }
            else
                tot_nulli++; 
        }
    }
    cout << "Elementi positivi: " << tot_positivi << endl; 
    cout << "Elementi negativi: " << tot_negativi << endl; 
    cout << "Elementi nulli: " << tot_nulli << endl; 
    return 0; 
}

