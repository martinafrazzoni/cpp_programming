/*scrivere una funzione raddoppia, con tipo di ritorno void, che prende in ingresso (parametro formale) un oggetto di tipo intero e ne raddoppi il valore. Poi scriviamo una funzione main che definisca una variabile di tipo int, ne legga il valore da stdin, poi invochi la funzione raddoppia per raddoppiare il valore della variabile, e infine stampi il valore della variabile. */
#include <iostream>
using namespace std; 
void raddoppia (int & i){
    i = (i*2); 
}
int main(){
    int a; 
    cout << "Inserisci un valore da raddoppiare: "; 
    cin>>a; 
    raddoppia(a); 
    cout << a << endl; 
}