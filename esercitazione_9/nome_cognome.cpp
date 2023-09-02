/*Scrivere una funzione che riceve in ingresso una stringa e suppone
che, in tale stringa siano contenuti il cognome ed il nome di
qualcuno.  La funzione elabora la stringa affinche' la prima lettera
del cognome e la prima lettra del nome siano maiuscole e tutte le
restanti lettere siano minuscole.  Ad esempio, se la funzione riceve
in ingresso la stringa "tOmBa alBERto", la converte nella stringa
"Tomba Alberto".  Data la somiglianza con l'esercizio precedente, non
vi fornisco la soluzione.*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std; 

int main(){
    const int max_stringa = 20; 
    char stringa[max_stringa] = "tOmBa alBERto"; 
    int lunghezza = strlen(stringa); 

    int maiuscola = 0; 
    stringa[maiuscola] = toupper(stringa[maiuscola]); 

    int indice_spazio; 
    for (int i = 0; i < lunghezza; i++){
        if (stringa[i] == ' '){
            indice_spazio = i; 
        }
        for (int j = 1; j < indice_spazio; j++){
            stringa[j] = tolower(stringa[j]); 
        }
        for (int k = (indice_spazio +1); k < lunghezza; k++){
            stringa[k] = toupper(stringa[k]); 
            for (int y = (indice_spazio +2); y < lunghezza; y++){
                stringa[y] = tolower(stringa[y]); 
            }
        }
    }
    cout << stringa << endl; 
    return 0; 
}