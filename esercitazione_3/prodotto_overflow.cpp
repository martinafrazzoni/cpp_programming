#include <iostream>
using namespace std; 
int main (){
    int a,b; 
    int max_int = 2147483647; 
    int min_int = (-max_int -1); 
    cout << "Inserisci due numeri da moltiplicare: \n"; 
    cin >>a>>b; 
    cout << a << "*" << b << "=" << (a*b) << endl;
    if (a>0 && b>(max_int / a) || a<0 && b<(min_int /a)){
        cout << "Attenzione: il risultato non è attendibile perchè c'è stato overflow \n";
    }
    return 0;  
}