/*data una frase, contare il numero dei caratteri maiuscolo, minuscoli, numerici, e dei caratteri non alfanumerici*/

#include <iostream>
#include <cstring>
using namespace std; 
int main(){
    char stringa [] = "Sul tavolo ci sono 2 libri!"; 
    int conta_maiusc = 0; 
    int conta_minusc = 0; 
    int conta_num = 0; 
    int conta_non_alfanum = 0; 

    for (int i = 0; stringa[i] != '\0'; i++){
        if ((stringa[i] >='A' && stringa[i] <= 'Z'))
            conta_maiusc ++; 
        if ((stringa[i] >='a' && stringa[i] <= 'z'))
            conta_minusc ++; 
        if ((stringa[i] >='0' && stringa[i] <= '9'))
            conta_num++; 
        if (!((stringa[i] >='0' && stringa[i] <= '9'))
        && (!(stringa[i] >='a' && stringa[i] <= 'z'))
        && (!(stringa[i] >='A' && stringa[i] <= 'Z')))
            conta_non_alfanum++; 
    }
    cout << "Lettere maiuscole: " << conta_maiusc << endl; 
    cout << "Lettere minuscole: " << conta_minusc << endl; 
    cout << "Caratteri numerici: " << conta_num << endl; 
    cout << "Crattere non alfanumerico: " << conta_non_alfanum << endl; 
    return 0; 
}