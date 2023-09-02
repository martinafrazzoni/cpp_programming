/*Scriviamo un programma che legga in ingresso un numenegativo e dica all’utente se il numero è primo (o altrimenti non stampa nulla). */
#include <iostream>
#include <cmath>
using namespace std; 
int main(){
    int n; // numero intero positivo. 
    int res; 
    int j; 
    // leggo il primo numero
   
    do{
        cout <<"inserisci due numeri interi positivi: \n"; 
        cin>>n>>j;  
    }
    while (n < 0 && j < 0);  

    // guardo se n e j sono compresi tra 1 e 3 e se sono pari. 
    if ((n>=1 && n<=3) && (j>=1 && j <=3)){
        cout << "sono entrambi primi!" << endl; 
        return 0; 
    }
    else if ((n>=1 && n<=3) && (j>3)){
        if (j%2 == 0){
            cout << n  << " è primo, ma " << j << " no" << endl; 
            return 0; 
        }
    }
    else if ((n>3) && (j>=1 && j <=3)){
        if (n%2 == 0){
            cout << j << " è primo, ma " << n << " no " << endl;  
            return 0; 
        }
    }

    // guardo se sono maggiori di 3 controllo se sono primi. 

    if (n>3 && j >3){
        if (n%2 == 0 && j%2 == 0){
            cout << "Non sono primi\n"; 
            return 0; 
        }
         else if (n%2 > 0 && j%2 == 0){
            cout << "non sono primi \n"; 
            return 0; 
        }
        else if (n%2 == 0 && j%2>0){
            cout << "non sono primi\n"; 
            return 0; 
        }
    }

    //se sono dispari, calcolo la radice quadrata, e faccio il modulo di n da 3 a radice quadrata di n. 

    int rad_n = static_cast<int>(sqrt(n)); 
    int rad_j = static_cast<int>(sqrt(j));

        // provo a scrivere il ciclo for solo una volta. 
        for (int i=3, k=3; (i<rad_n && k<rad_j); i+=2, k+=2){
            if (((n%i == 0) && (j%k == 0)) || 
               ((n%i == 0) && (j%k > 0)) || 
               ((n%i > 0) && (j%k == 0))){
                cout << "uno dei due o entrambi non sono primi!" << endl; 
                return 1; 
            }
        }
        cout << n << " e " << j << " sono primi!" << endl;

        /*individuo quale dei due è il massimo*/
        int max; 
        int min; 
        if (n>j){
            max = n; 
            min = j; 
        }
        else {
            max = j; 
            min = n; 
        }   
        // dico se sono primi gemelli oppure no. 
        if (max - min == 2)
            cout << n << " e " << j << " sono primi gemelli. " << endl; 
    return 0; 
}