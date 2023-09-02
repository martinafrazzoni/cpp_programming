#include <iostream>
using namespace std; 
int proposta_rad_intera(int n){
    int radice; 
    for (int i = 1; i <=n; i++)
        if (i*i > n)
            radice = i -1; 
    return radice; 
}
int main (){
    int n; 
    cout << "Inserisci il numero di cui vuoi calcolare la radice quadrata: "; 
    cin >>n; 
    cout << proposta_rad_intera(n) << endl; 
}

// la funzione non è corretta, manca il return nell'if. 