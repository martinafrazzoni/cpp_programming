/*scrivere un programma che legga una parola da stdin e ne stampi la lunghezza senza utilizzare funzioni di libreria per le stringhe. utilizziamo una strinfa contenente più parole, ed inizializzata a piacere a tempo di scrittura del programma*/
#include <iostream>
using namespace std; 
int main(){
    const int dim_stringa = 50; 
    char stringa [dim_stringa] = "viva vasco"; 
    int cont = 0; 
    for (int i = 0; i < dim_stringa; i++){
        if (stringa[i] == '\0'){
            cont++; 
            break; 
        }
        else if (stringa[i] == ' '){ // ho messo anche il controllo per togliere lo spazio bianco, quinidi il totale dei caratteri è senza lo spazio bianco. 
            cont = cont; 
        }
        else{
            cont++; 
        }
    }
    cout << "La stringa contiene " << cont << " caratteri!\n"; // senza lo spazio bianco ma con il terminatore. 
    return 0; 
}