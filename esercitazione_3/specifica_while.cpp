/*leggere da std input due valori naturali, calcolarne il prodotto come sequenza di somme e stampare il risultato su video. */

#include <iostream>
using namespace std; 
int main (){
    int a, b, p, max;  
    cout << "Inserisci i due valori da moltiplicare: \n"; 
    cin>>a>>b; 
    while (a<0 && b < 0){
        cout << "i valori non possono essere minori di zero! \n"; 
        cout << "Inserisci i due valori da moltiplicare: \n"; 
        cin>>a>>b; 
    }
    int i = 1; // variabile contatore; 
    while (i<=b){
        p+=a; 
        i++; 
    }   
    int max_int = 2147483647;
    if (a>(max_int-=p))
        cout << " il prodotto è " << p << " Attenzione il risultato non è attendibile perchè c'è stato overflow!" << endl; 
    else 
        cout << "il prodotto tra i valori inseriti è: " << p << endl; 
    return 0; 
}