#include <iostream>
using namespace std; 
int main (){
    int a, b,c; 
    cout << "Inserisci tre numeri interi: "; 
    cin >>a>>b>>c; 
    if ((a<=b && b<=c) || (a>=b && b>=c))
        cout << "la sequenza è ordinata \n"; 
    else
        cout << "la sequenza non è ordinata \n"; 
    return 0; 
}