#include <iostream>
using namespace std; 
void crea_vettore(int *&ptr, int a[ ], int dim_a){
    // creiamo un array di interi uguale a quello passato in ingresso. 
    ptr = new int [dim_a]; // puntatore al nuovo array di 4 elementi.
    for (int i = 0; i < dim_a; i++){
        ptr[i] = a[i]; 
    }
}
int main() {
    const int dim_a = 4; 
    int *indirizzo; // puntatore. 
    int a [dim_a] = {1, 2, 3, 4}; 
    crea_vettore(indirizzo, a, dim_a); 
    // stampo il nuovo vettore
    for (int i = 0; i < dim_a; i++){
        cout << indirizzo[i] << " "; 
    }
    return 0;
}