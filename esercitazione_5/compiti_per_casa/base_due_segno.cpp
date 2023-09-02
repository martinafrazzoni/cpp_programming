/*#include <iostream>
using namespace std; 
int main(){
    int n; 
    int base = 2; 
    string b; 
    b = " "; 
    cout << "inserisci un numero intero: ";
    cin>>n; 
    while (!n==0){
        if (n%base == 0)
            b = '0' + b; 
        else 
            b = '1' + b; 
        n = n/2; 
        
    } 
    cout << "-" << b; 
    return 0; 
}*/

#include <iostream>
using namespace std; 
int main(){
int n;  
int N; // numero di bit sui quali voglio memorizzare il mio numero. 
int somma; // ((2^N)+n)
int cont = 1; 
cout<<"inserisci un numero:"; 
cin>>n; 
cout<<"Inserisci il numero di bit su cui vuoi rappresentare quel numero: \n"; 
cin>>N; 
// calcolo 2^N
    for (int i = 0; i < N; i++){
        cont*=2; 
    } 
    somma = (cont + n); 
    //cout << "n in complemento a 2 vale: " << somma; 
    string b; 
    b = ' '; 
    while (!(somma==0)){
        if (somma%2 == 0){
            b = '0'+b; 
        }
        else 
            b = '1'+b; 
        somma = (somma/2); 
    }
    cout << " in binario vale " << b << endl; 

    return 0; 
}