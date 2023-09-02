/*scrivere un programma che, senza effettuare letture formattate: 
1. crei un file di testo di nome testo.txt
2. chieda all'utente di inserire il contenuto del file, carattere per carattere (gestire opportunamente la comunicazione della fine dell'immissione dei carattere da parte dell'utente e ricordarsi che si posso effettuare solo letture non formattate); 
3. chiud il file; 
4. lo riapra in lettura; 
5. ne stampi il contenuto ed il numero di righe. */
#include <iostream>
#include <fstream>
using namespace std; 
int main(){
    ofstream file_testo; 
    file_testo.open("testo.txt"); 
    if (! file_testo)
        cerr << "Impossibile apirire il file in scrittura!"; 
    char c; 
    cout << "Inserisci il contenuto del file carattere per carattere, EOF per terminare: \n"; 
    while (cin.get(c) && c != EOF) {
        file_testo << c;
    }
    file_testo.close(); 

    ifstream file_testo_lett; 
    file_testo_lett.open("testo.txt"); 
    if (!file_testo_lett)
        cerr << "Impossibile aprire il file in lettura!"; 
    char caratt; 
    int conta_righe = 0; 
    cout << endl; 
    cout << "Ecco il contenuto del file: \n"; 
    while (file_testo_lett.get(caratt) && caratt != EOF){
        cout << caratt; 
        if (caratt == '\n')
            conta_righe++; 
    }
    cout << "Il file ha " << conta_righe << " righe!" << endl; 
    return 0; 
}