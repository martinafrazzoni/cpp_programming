/*
Scrivere un programma che apra un file di testo (il cui nome è
stabilito a tempo di scrittura del programma), e crei un secondo file
(anch'esso con nome stabilito a tempo di scrittura del programma) contenente
solo i caratteri numerici (cifre da 0 a 9) contenuti nel primo file, e
l'indicazione del numero totale di occorrenze di tali caratteri. 
Un esempio di contenuto del secondo file e' il seguente:

6       3       7       3       1
Il numero di caratteri numerici letti e' 5

*/

#include <iostream>
#include <fstream>
using namespace std; 
int main(){
    ofstream primo_file; 
    primo_file.open("primo_file.txt"); 
    if (!primo_file){
        cerr << "Errore, impossibile aprire il file in scrittura\n";
        return 1; 
    }
    // creo un array di 100 caratteri
    char c; 
    while (cin.get(c) && c!= EOF){
        primo_file << c; 
    }
    primo_file.close(); 

    ofstream secondo_file; 
    secondo_file.open("secondo_file.txt"); 
    if(!secondo_file){
        cerr << "Errore, impossibile aprire il file in scrittura!"; 
        return 1; 
    }  
    ifstream primo_file_lett; 
    primo_file_lett.open("primo_file.txt"); 
    if (!primo_file_lett){
        cerr << "Errore, impossibile aprire il file in lettura\n";
    }

    char carat; 
    int conta_carat; 
    while (primo_file_lett.get(carat) && carat != EOF){
        if (carat >= '0' && carat <= '9'){
            secondo_file << carat << " "; 
            conta_carat++;
        }
    }   
    secondo_file << "Il totale dei caratteri numerici letti è: " << conta_carat << endl; 

    secondo_file.close(); 
    primo_file_lett.close(); 
    return 0; 
}