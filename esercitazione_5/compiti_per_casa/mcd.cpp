#include <iostream>
using namespace std; 
int main(){
    int a, b, resto; 
    do{
        cout << "Inserisci i valori di A e B: "; 
        cin>>a>>b; 
    }
    while (a<=0 || b<=0); 
    while (b>0){
        resto = (a%b); 
        a = b; 
        b = resto; 
    }
    cout << "MCD " << "= " << a<< endl; 
    return 0; 
}