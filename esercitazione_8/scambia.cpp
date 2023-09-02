/*scrivere una funzione tramite la quale sia possibile scambiare il valore di due variabili locali al blocco dall'interno del quale viene invocata. Ad esempio, se viene invocata dentro il main, e supponendo che il main contenga due variabili locali a e b di tipo int, scambi i valori memorizzati in tali due variabili. */
#include <iostream>
using namespace std; 
void scambia (int & a, int & b){
    int app = a;  
    a = b;
    b = app; 
}
int main(){
    int a = 2; 
    int b = 3; 
    cout << a << " e " << b << endl;
    scambia(a, b); 
    cout << a << " e " << b << endl; 
}