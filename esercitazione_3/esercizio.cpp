#include <iostream>
using namespace std; 
int main (){
    int x,z; 
    const int  max_int = 2147483647; 
    const int  min_int = (- max_int-1); 
    cout << "Inserisci due numeri da moltiplicare \n"; 
    cin >>x>>z; 
    int y = (x*z); 
    if (y < (min_int/x) || y >(max_int/x))
        cout << "Overflow" << endl; 
    return 0; 
}