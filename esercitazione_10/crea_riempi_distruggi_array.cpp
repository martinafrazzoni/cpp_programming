/*
Scrivere un programma che crei dinamicamente un array di int, di
dimensioni inserite dall'utente da tastiera, e che lo riempia con
valori anch'essi inseriti dall'utente. Quindi il programma stampa il
contenuto dell'array.

A questo punto, il programma conserva in memoria SOLO una parte degli
elementi iniziali dell'array. In particolare chiede all'utente di
inserire un numero naturale n non maggiore delle dimensioni dell'array
e conserva in memoria solo i primi n elementi dell'array.  Quindi
stampa il sotto-array conservato in memoria, lo dealloca e termina.

Esempio:

Dimensioni array? 4
Valore elemento 1/4? 3
Valore elemento 2/4? 2
Valore elemento 3/4? 1
Valore elemento 4/4? 2

Valore elemento 1/4: 3
Valore elemento 2/4: 2
Valore elemento 3/4: 1
Valore elemento 4/4: 2
Numero di elementi da preservare? 2

Sotto-array:
Valore elemento 1/2: 3
Valore elemento 2/2: 2

*/

#include <iostream>
using namespace std; 
int main(){
        // chiedere all'utente le dimensioni dell'array; 
    int dim_a; 
    cout << "Inserisci la dimensione dell'array: \n"; 
    cin>>dim_a; 

    int *p_primo = new int[dim_a]; 
    // inizializziamo l'array. 
    for (int i = 0; i < dim_a; i++){
        cout << "Valore elemento  (" << (i + 1) << " / " << dim_a << "): "; 
        cin>>p_primo[i]; 
    }

    cout << "Ecco stampato l'array dinamico: \n"; 
    for (int i = 0; i < dim_a; i++){
        cout << "Valore elemento (" << (i + 1) << " / " << dim_a << "): " << p_primo[i] << endl; 
    }

    // chiedo all'utente quanti elementi vuole tenere
    int da_tenere; 
    do{
        cout << "Inserisci numero di elementi dell'array che vuoi preservare: \n"; 
        cin>>da_tenere; 
    }
    while (da_tenere < 0 || da_tenere > dim_a); 

    // tutti gli elementi che vanno da da_tenere + 1 fino a dim_a vanno deallocati, MA se faccio così la dimensione dell'array non cambia. //Quindi, posso copiare tutti gli elementi che l'utente vuole tenere dentro un altro array, che ha le dimensioni da_tenere. poi dopo lo //stampo e lo dealloco. 
    int *p_secondo = new int[da_tenere]; 

    for (int i = 0; i < da_tenere; i++){
        p_secondo[i] = p_primo[i]; 
    }

    // deallochiamo il primo array
    delete[ ] p_primo; 

    cout << "Sotto array: " << endl;
    for (int i = 0; i < da_tenere; i++){
        cout << "Valore elemento (" << (i+1) << " / " << da_tenere << "): " << p_secondo[i] << endl; 
    }

    // deallochiamo il secondo array
    delete [ ] p_secondo; 
    return 0; 
}