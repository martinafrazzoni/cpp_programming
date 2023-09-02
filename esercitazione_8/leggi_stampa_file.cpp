/*Scrivere un programma che: 
1.	Crei un file testo.txt
2.	Chieda all’utente di inserire il contenuto del file, carattere per carattere mediante letture formattate (gestire opportunamente la comunicazione della fine dell’immissione dei caratteri da parte dell’utente, assumendo che l’utente non comunichi a propri il numero di caratteri che immetterà). 
3.	Chiuda il file
4.	Lo riapra in lettura 
5.	Ne stampi il contenuto
*/

#include <iostream>
#include <fstream>
using namespace std; 
int main(){
    // creo un file di nome caratteri.txt
    ofstream file_caratteri; 
    file_caratteri.open("caratteri.txt"); 
    char a; 
    if (!file_caratteri)
        cerr << "La lettura è fallita!"; 
    else{
        // chiedo all'utente di inserire un carattere
        cout << "Inserisci un carattere (o EOF per smettere): "; 
        while(cin>>noskipws>>a){
            file_caratteri << a; 
        }
        // ci ho scritto dentro e adesso lo chiuso
        file_caratteri.close(); 

        // lo apro in lettura., e gli dò un nome diverso. 
        ifstream file_caratteri_let; 
        file_caratteri_let.open("caratteri.txt"); 
        if (!file_caratteri_let)
            cerr <<"la lettura è fallita!"; 
        else{
            cout << "ecco il contenuto del file: \n"; 
            while(true){
                file_caratteri_let>>noskipws>>a; 
            if (file_caratteri_let.eof())
                break;
            else
                cout << a; 
            }
        }
        file_caratteri_let.close(); 
    }
    return 0; 
}