#include <iostream>
using namespace std; 
int main (){
    int n; 
    int k = 10; 
    do {
        cout << "Quanti numeri vuoi sommare tra 0 e " << k << "? "; 
        cin>>n; 
        if (n<=0 || n > k)
            cout << "Attenzione, il valore inserito non è compreso nell'intervallo \n"; 
    }
    while (n<=0 || n > k); 
    int i = 0; 
    int numero; 
    int somma = 0; 
    int max = 0; 
    int max_int = 2147483647; 
    for (i = 1; i<=n; i++){
        cout << "Inserisci numero intero positivo da sommare: ";
        cin>>numero; 
        somma += numero; 
        if (numero>max){
            max = numero; 
        }
    }
    if (somma > max_int - somma){
        cout << "Attenzione: la somma non è attendibile perchè c'è stato overflow."; 
    }
    else cout << "La somma dei valori inseriti è " << somma << endl; 
    return 0; 
}