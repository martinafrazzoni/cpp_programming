/*definiamo un oggetto di tipo stringa, lo inizializziamo e lo stampiamo. Ci riversiamo dentro il contenuto dello stdin e lo ristampiamo*/

#include <iostream>
using namespace std; 
int main(){
    char prima_stringa [ ] = "Martina"; 
    cout << prima_stringa << endl; 
    cout <<"Inserisci una parola: \n"; 
    cin>>prima_stringa; 
    cout << prima_stringa << endl; 
}