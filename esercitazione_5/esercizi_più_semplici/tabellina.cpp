/*stampare su video i primi n multipli di un numero i, entrambi letti da tastiera.*/
#include <iostream>
using namespace std; 
int main (){
    int P; 
    int i; // numero di cui calcolare i multipli
    int n; // numero dei multipli da calcolare
    cout << "Inserire i ed n: \n"; 
    cin>>i>>n; 
    for (int j = -3; j<=n; j++){
        P = i * n; 
        cout << i << " * " << n << " = " << P << endl;
        n--; 
    }
    return 0; 
}