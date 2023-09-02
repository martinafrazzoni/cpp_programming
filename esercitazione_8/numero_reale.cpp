/*
Scrivere un programma che legga da tastiera un numero reale maggiore di 1 e lo ristampi in formato mantissa*10^esponente. La mantissa deve essere un
numero reale minore di 1.

Possibili output:

Inserisci un numero: 35
0.35*10^2

Inserisci un numero: 2
0.2*10

Inserisci un numero reale: -123
-0.123*10^3

Inserisci un numero: 0.5
0.5

(va bene anche il formato 0.123e3)

*/

#include <iostream>
using namespace std; 
int main(){
    double n; 
    cout << "Inserisci un numero reale maggiore di 1: "; 
    cin>>n;
    const double k = 10; 
    int num_divisioni = 0; 
    if (n>1){
        do{
            n = (n / k); 
            num_divisioni++; 
        }
        while (n>1); 
        cout << n << endl; 
        cout << n << " * " << k << " ^ " << num_divisioni << endl; 
    }
    else {
        if (n<1){
            n = (n * -1); 
            do{
                n = (n/k); 
                num_divisioni ++; 
            }
            while (n>1); 
        }
         cout <<" -" << n << endl; 
        cout << "- " <<  n << " * " << k << " ^ " << num_divisioni << endl; 
    }
    return 0; 
}