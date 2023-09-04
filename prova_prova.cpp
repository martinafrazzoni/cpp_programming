#include <iostream>
#include <fstream>
using namespace std; 

int** crea_matrice(int&righe, int&colonne){
    int**matrice; 
    matrice = new int* [righe]; 
    for(int i = 0; i < righe; i++){
        matrice[i] = new int [colonne]; 
    }
    return matrice; 
}

int main(){
    
    int righe = 6; 
    int colonne = 6; 
    int **matrice = crea_matrice(righe, colonne); 

    // ho allocato una matrice di tot righe e tot colonne. La inizializzo con i valori letti dal file matrice.txt
    ifstream leggi; 
    leggi.open("matrice.txt"); 
    if (!leggi){
        cerr << "Errore! Impossibile leggere da file!"; 
        return 1;
    }
 

    for (int i = 0; i < righe; i++){
        for (int j = 0; j < colonne; j++){
            leggi>>matrice[i][j]; 
            if(!leggi){
                cerr << "Errore nella lettura del file!\n"; 
                return 2; 
            }
        }
    }

    for (int i = 0; i < righe; i++){
        for (int j = 0; j < colonne; j++){
            cout << matrice[i][j]; 
        }
        cout << endl; 
    }

    return 0; 
}