/*Scriviamo un programma che legga in ingresso un numero intero non negativo e dica all’utente se il numero è primo (o altrimenti non stampa nulla). */
#include <iostream>
using namespace std; 
int main(){
    int n; // numero intero positivo. 
    int b = 2; 
    int res; 
    do{
        cout <<"inserisci un numero intero positivo: \n"; 
        cin>>n; 
    }
    while (n<0); 
    for (int i = 2; i<n; i++){
        res = (n%i); 
        if (res == 0){
            cout << "non è primo!"; 
            return 1; 
        }
    }
    cout << "primo!"; 
    return 0; 
}

 