/*scrivere un programma che legga una parola da stdin e ne stampi la lunghezza senza utilizzare funzioni di libreria per le stringhe*/
#include <iostream>
using namespace std; 
int main(){
    const int dim_stringa = 50; 
    char stringa [dim_stringa]; 
    int cont = 0; 
    cout << "Inserisci una parola: \n"; 
    cin>>stringa; 
    for (int i = 0; i < dim_stringa; i++){
        if (stringa[i] == '\0'){
            break;
        }
        else{
            cont++; 
        }
    }
    cout << "La stringa contiene " << cont << " caratteri!\n";  
    return 0; 
}