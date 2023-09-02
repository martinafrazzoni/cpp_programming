#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; 

double calcola_media (double a[ ], int n){
    if (n == 1)
        return a[n-1]; // se l'array è composto solo da un elemento ritorni n-1, ovvero solo il valore contenuto nell'elemento di indice 0 che è l'unico elemento dell'array e quindi la media sarà pari al suo valore. ù
    else 
    return calcola_media(a, n-1)* (n-1) + a[n-1] / n; 
}

int main(){
    const int n = 100; 
    double a [n]; 
    srand(1); 

    for (int i = 0; i < n; i++){
        a[i] = rand(); 
    }
    
    cout << calcola_media(a, n) << endl;  
    return 0; 
}
