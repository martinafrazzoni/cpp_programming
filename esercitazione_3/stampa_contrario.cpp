/*scrivere un programma che legga un numero intero non negativo in ingresso e lo stampi al contrario. Ex. immettere un numero intero non negativo: 164 -> 461*/
#include <iostream>
using namespace std; 
int main (){
    int n; 
    do {
        cout << "immettere un numero intero non negativo \n"; 
        cin>>n; 
    }
    while (n<0); 
    do {
        cout << (n%10); 
        n/=10; 
    }
    while (n>0);
    // cout << (n%10) << ((n%1000)/100) << endl; 
    return 0; 
}