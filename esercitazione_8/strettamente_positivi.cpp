/*scrivere in un file di testo valori_pos.tct tutti i numeri strettamente positivi di un vettore contenente N valori interi, con N definitoo a tempo di scrittura del programma. Alla fine inserire il valore -1 come terminatore. */

#include <iostream>
#include <fstream>
using namespace std; 
int main(){
    // creare un file di testo valori_pos.txt
    const int dim_a = 5; 
    int a [dim_a]; 


    ofstream valori_pos; 
    valori_pos.open("valori_pos.txt"); 

    if (!valori_pos){
        cerr << "Apertura in scrittura fallita!\n"; 
        return 1; 
    }
    else{
        for (int i = 0; i < dim_a; i++){
            while (a[i] <= 0){
                cout << "Inserire un numero strettamente positivo: \n"; 
                cin>>a[i]; 
            }
            valori_pos << a[i] << " "; 
        }
        valori_pos << -1; 
    }
    return 0; 
}