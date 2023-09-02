/*scrivere un programma che copi il contenuto di un file dentro un altro file*/
#include <iostream>
#include <fstream>
using namespace std; 
int main(){
    // per prima cosa devo creare un file e scriverci dentro. 
    ofstream primo_file; 
    primo_file.open("primo_messaggio.txt"); 
    char a; 

    // facciamo il controllo che sia tutto a posto. 
    if (!primo_file){
        cerr << "La lettura è fallita!\n";
        return 1; 
    }
    else{
        // chiedo all'utente di scrivere qualcosa: 
        cout << "Inserisci un messaggio: \n"; 
        while (cin>>noskipws>>a){
            if (primo_file.eof())
                break;
            else   
                primo_file << a; 
        }
        primo_file.close(); // chiudo il file. 

        // devo creare un altro file in cui scrivere il contenuto di primo_messaggio. 
        ofstream secondo_file; 
        secondo_file.open("secondo_messaggio.txt"); 
        // controllo 
        if (!secondo_file){
            cerr << "L'apertura è fallita!\n";
            return 1; 
        }
        else{
            // devo aprire in lettura il primo file e copiare il contenuto dentor il secondo
            ifstream primo_file_let; 
            primo_file_let.open("primo_messaggio.txt"); 
            while (primo_file_let>>noskipws>>a){
                if(primo_file_let.eof())
                    break;
                else{
                    secondo_file << a; 
                }
            }
            primo_file_let.close(); 
        }
        secondo_file.close(); 
        // apriamo il secondo file in lettura 
        ifstream secondo_file_lett; 
        secondo_file_lett.open("secondo_messaggio.txt"); 

        // controllo
        if (! secondo_file_lett){
            cerr << "lettura errata!";
            return 1; 
        }
        else{
            cout <<"ecco il contenuto che è stato copiato: \n"; 
            while (secondo_file_lett>>noskipws>>a){
                if (secondo_file_lett.eof()){
                    break;
                }
                else
                    cout << a; 
            }
        }
        secondo_file_lett.close(); 
    }
    return 0; 
}