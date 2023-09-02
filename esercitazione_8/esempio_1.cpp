#include <iostream>
using namespace std; 
int main(){ 
    char carattere = 'a'; 
    cout << carattere << endl; 
    char carattere_1 = 97; 
    cout << carattere_1 << endl;  
    cout << static_cast<int>(carattere) << endl; 
    cout << static_cast<int>(carattere_1) << endl;  



    char i; 
    cout << "Inserisci un codice: "; 
    cin>>i; 
    cout << "Il carattere immesso è " <<static_cast<int>(i)<< endl;

    return 0; 
}