/*realizzare un programma che legge in ingresso un numero negativo in base 10 e stampa la rappresentazione in base 2 di tale numero. 

Un possibile output è il seguente: 
Inserisci un numero: 46
La rappresentazione del numero 46 in base 2 è 101110

(N/bi)%b   // la formula che devo usare è questa qua. 

Nota: se non ci viene in mente una buona idea per stampare le cifree nell'ordine giusto va bene anche la stampa in ordine inverso.*/
#include <iostream>
using namespace std; 
int main(){
    int n; 
    string b;// stringa di caratteri, è il mio contenitore che contiene le cifre. 
    b = ' '; 
    int base = 2; 
    cout<<"Inserisci un numero decimale: ";
    cin>>n; 
    while (n>0){
        if (n%base == 0)
            b = '0' + b;  
        else 
            b = '1' + b; 
        n = n/base; 
    } 
    cout << b; 
    return 0; 
}
