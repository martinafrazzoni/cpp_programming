#include <iostream>
using namespace std; 
int main (){
    int x, y, n, P; 
    cin>>x>>y; 
    P = 0; n = x; 
    while (n > 0){
        P = P + y; 
        if (P>250000)
            break;
        n--; 
    }
    cout << (x * y) << " = " << P << endl; 
}