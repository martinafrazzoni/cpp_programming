/*Leggere da un file di testo dati.txt una 
sequenza di caratteri terminata da *. Memorizzare 
in un vettore tutti i caratteri alfabetici.*/

#include <iostream>
#include <fstream>
using namespace std; 
int main(){
    const int max_char = 100; 
    char a[max_char]; 

    char alfabetici [max_char]; 
    int lungh_alfa = 0; 

    ofstream caratteri_in; 
    caratteri_in.open("caratteri_in.txt"); 
    if (! caratteri_in){
        cerr << "L'apertura in scrittura è fallita! \n";
        return 1; 
    }
    else {
        cout << "Inserisci caratteri (* per terminare ): \n"; 
        for (int i = 0; i < max_char; i++){
            cin>>a[i]; 
            if (a[i] == '*')
                break;
            else
                caratteri_in << a[i] << " "; 
        }
        caratteri_in.close(); 
    }

    // apro il file. 
    ifstream caratteri; 
    caratteri.open("caratteri_in.txt"); 
    if (! caratteri){
        cerr << "L'apertura in lettura è fallita! \n"; 
        return 1; 
    }        
    else{
        char c; 
        while (caratteri >> c){
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
                alfabetici[lungh_alfa] = c; 
                lungh_alfa++; 
            }
        }
        for (int i = 0; i < lungh_alfa; i++){
            cout << alfabetici[i] << " "; 
        }
        cout << endl; 
        caratteri.close(); 
    }
         
    return 0; 
}