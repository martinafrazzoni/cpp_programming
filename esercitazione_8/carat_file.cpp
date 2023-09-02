/*scrivere in un file di testo "carat.txt" tutti i caratteri di una stringa letta da stdin. terminare la sequenza di caratteri del fole con * */
#include <iostream>
#include <fstream>
using namespace std; 
int main(){
    char a; 
    
    // creo un file
    ofstream leggi_stringa; 
    leggi_stringa.open("carat_file.txt"); 
    if (! leggi_stringa){
        cerr << "l'apertura in scrittura è fallita!\n"; 
        return 1; 
    }
    else {
        cout << "Inserisci il messaggio (EOF per terminare): \n"; 
        while (cin>>noskipws>>a){
            if (leggi_stringa.eof()){
                break;
            }
            leggi_stringa << a << " ";
            
        } 
    }
    leggi_stringa.close(); 
    return 0; 
}