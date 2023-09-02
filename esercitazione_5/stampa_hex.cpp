/*scrivere un programma che legge da stadin un intero non negativo in notazione decimale e lo stampa in esadecimale. Se il numero è negativo non stampa nulla. */

#include <iostream>
using namespace std; 
int main(){
    int n; 
    cout<<"inserisci un numero intero non negativo: \n"; 
    cin>>n; 
    if (n>0){
        cout << "il numero in base 16 è " << hex << n << endl; 
    }
    else{
        cout << "il numero inserito è negativo\n"; 
    }
    return 0; 
}