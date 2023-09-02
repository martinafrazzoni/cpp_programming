/* controllo se una stringa è più lunga di un'altra*/
#include <iostream>
using namespace std; 
int lunghezza_stringhe(char stringa_uno[ ], char stringa_due[]){
    int cont_stringa_uno = 0; 
    int cont_stringa_due = 0; 

    for (int i = 0; stringa_uno[i] != '\0'; i++){
        cont_stringa_uno++; 
    } 

    for (int i = 0; stringa_due[i] != '\0'; i++){
        cont_stringa_due++; 
    }
    
    if ((cont_stringa_uno > cont_stringa_due) || (cont_stringa_uno < cont_stringa_due))
        return 1; 
    else
        return 0; 
}

int main(){
    // definisco una lunghezza massima per le due stringhe. 
    const int max_string = 100; 
    char stringa_uno [max_string];  
    char stringa_due [max_string];

    cout << "Inserisci la prima stringa: "; 
    cin>>stringa_uno; 

    cout << "Inserisci la seconda stringa: "; 
    cin>>stringa_due;   
    int risultato = lunghezza_stringhe(stringa_uno, stringa_due); 
    cout << "Risultato: " << risultato << endl; 
    return 0; 
}