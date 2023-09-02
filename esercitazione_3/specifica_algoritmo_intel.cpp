/* se i due numeri sono molto distanti tra di loro, controlliamo qual'è il maggiore e sommiamo il maggiore tante volte quante ne indica il minore. */
#include <iostream>
using namespace std; 
int main (){
    int a, b, p = 0; 
    int max, min; 
    do {
        cout << "Inserisci due valori da moltiplicare: \n"; 
        cin>>a>>b;
        if (a>=b){
            max = a;
            min = b; 
        }
        else{
            min = a; 
            max = b; 
        }  
        cout << "il massimo è " << max << " il minimo è " << min << endl; 
    }
    while (a<=0 && b<=0); 
    for (int i=1; i<=min; i++ ){
        p+=max;
    }
    cout << "il prodotto tra i valori inseriti è "<< p << endl; 
    return 0; 
}