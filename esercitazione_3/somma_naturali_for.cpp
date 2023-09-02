#include <iostream>
using namespace std; 
int main () {
    int N, S = 0; 
    cout <<"Inserisci un numero naturale N: "; 
    cin>>N; 
    for (int i = 1; i<=N; i++){
        S +=i;
    } 
    cout << S << endl;
    return 0; 
}