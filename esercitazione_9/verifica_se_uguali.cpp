/*verifica se due stringhe sono uguali o diverse. */

#include <iostream>
using namespace std; 
int main(){
    char stringa_uno [ ] = "Ciao Mamma"; 
    char stringa_due [ ] = "miao Mamma"; 

    // verifico se le due stringhe sono uguali, confronto i caratteri dello stesso indice dei due vettori. 
    for (int i = 0; (i < stringa_uno[i] != '\0' && stringa_due[i] != '\0'); i++){
        if (stringa_uno[i] != stringa_due[i]){
            cout << "le due stringhe non sono uguali!" << endl; 
            break;
        }
        else{
            cout << "sono uguali!" << endl; 
            break; 
        }
            
    }

    return 0; 
}