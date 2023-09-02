/*copiare soltanto i primi 10 caratteri di una stringa, in un'altra stringa, inizialmente vuota. */
#include <iostream>
#include <cstring>
using namespace std; 
int main(){
    const int max_string = 10; 
    char stringa_uno [ ] = "Nel mezzo del cammin di nostra vita\n"; 
    int lunghezza = strlen(stringa_uno); 

    char stringa_due[max_string]; 

    int conta_char = 0; 
    int i; 
    for (i = 0; i < lunghezza; i++){
        stringa_due[i] = stringa_uno[i]; 
        conta_char ++; 
        if (conta_char == max_string){
            break; 
        }
    }
    stringa_due[i] = '\0'; 
    for (int i = 0; stringa_due[i] != '\0'; i++){
        cout << stringa_due[i]; 
    }
    cout << endl; 
}