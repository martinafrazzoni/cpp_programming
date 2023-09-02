/* concatenazione (append) di due stringhe. aggiungere una stringa in fondo ad un'altra stringa, lasciando uno spazio tra le due stringhe. */
#include <iostream>
#include <cstring>
using namespace std; 
int main(){
    char stringa_uno [ ] = "Sono stanca e ho caldo "; 
    int lunghezza_stringa_uno = strlen(stringa_uno); 
    char stringa_due [ ] = "ma devo finire gli esercizi!"; 
 
    const int dim_stringa_tre = strlen(stringa_uno)  + strlen(stringa_due); 
    char stringa_tre[dim_stringa_tre];

    int j;
    for (int i = 0; stringa_uno[i] != '\0'; i++){
        stringa_tre[i] = stringa_uno[i]; 
        for ( j = lunghezza_stringa_uno; j < dim_stringa_tre; j++ ){
            stringa_tre[j] = stringa_due[j- lunghezza_stringa_uno]; 
        }
    }
    stringa_tre[j] = '\0'; 

    cout << stringa_tre << endl; 



}