/* 
   Scrivere un programma che apra in lettura un file (il cui nome e'
   stabilito a tempo di scrittura del programma) e stampi la lunghezza
   del file in byte.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream file_1; 
    file_1.open("file_1.txt"); 
    if (!file_1){
        cerr << "Errore, impossibile aprire il file in scrittura\n"; 
        return 1; 
    }
    char c; 
    cout << "Inserisci dei caratteri: \n"; 
    while (cin.get(c) && c != EOF){
        file_1 << c; 
    }
    file_1 << '\0'; 
    file_1.close(); 

    ifstream file_1_lett; 
    file_1_lett.open("file_1.txt"); 
    if (!file_1){
        cerr << "Errore, impossibile aprire il file in lettura\n"; 
        return 1; 
    } 

    file_1_lett.seekg(1, ios::end); // sposto il contatore nell'ultima casella del file. 
    int ultimo_val = file_1_lett.tellg(); // mi faccio dire il valore di quell'ultima casella. 
    cout << "La lunghezza del file in byte è: " << ultimo_val << endl; 
    file_1_lett.close(); 
    return 0; 
}
