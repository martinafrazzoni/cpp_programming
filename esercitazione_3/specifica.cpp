/*Leggere da input due valori naturali, calcolarne il prodotto comme sequenza di somme e stampare il risultato su video*/
#include <iostream>
using namespace std; 
int main (){
    int a, b; 
    int p = 0;  
    cout<< "Inserisci due valori naturali da moltiplicare: \n"; 
    cin>>a>>b;
   while (a <= 0 || b <= 0){
    cout << "Non puoi inserire valori minori di zero \n"; 
    cout<< "Inserisci due valori naturali da moltiplicare: \n"; 
    cin>>a>>b;
   } 
    for (int i = 1; i<=b; i++){
        p+=a; 
    }
    cout << "il prodotto tra i valori inseriti è " << p << endl; 
    return 0; 
}
