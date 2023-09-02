/*Scrivere un programma che: 
1.	Crei un file testo.txt
2.	Chieda all’utente di inserire il contenuto del file, carattere per carattere mediante letture formattate (gestire opportunamente la comunicazione della fine dell’immissione dei caratteri da parte dell’utente, assumendo che l’utente non comunichi a propri il numero di caratteri che immetterà). 
Attenzione di nuovo agli spazi bianchi. Per controllare se il programma ha funzionato, aprite il file che creato dal programma con qualsiasi editor o visualizzazione di testi. 
*/

#include <iostream>
#include <fstream>
using namespace std; 
int main(){
    // creo un file di testo tsto.txt
    ofstream primo_file ("testo.txt"); 
    char a;
    if (! primo_file)
        cerr << "La lettura è errata!" << endl; 
    else{
        cout << "Inserisci un carattere (EOF per terminare): \n"; 
        while (cin>>noskipws>>a){
            primo_file << a;   
        }
    } 
    primo_file.close(); 
    return 0; 
}