#include <iostream>
using namespace std; 
int radice_quadrata_intera(int n){
    int i; 
    for (i = 1; i < n; i++){
        int res = (i*i); 
        if (res>n){
            return (i-1); 
        }
        else if (res == n){
            return i; 
        }
    }
    return i; 
}
int main(){
    int n; 
    cout << "Inserisci un numero di cui vuoi calcolare la radice quadrata: \n"; 
    cin>>n; 
    cout << radice_quadrata_intera (n) << endl;  
    return 0; 
}