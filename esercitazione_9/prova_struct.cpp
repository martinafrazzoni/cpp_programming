#include <iostream>
using namespace std; 

struct dati {
    char cognome[10]; 
    int tempo; 
}; 

// array di partecipanti. non so la dimensione esatta, ma metto il numero massimo. 
// per l'iscrizione alla gara di sci, io jo il mio array di partecipanti a cui dovrò aggiungerne uno alla volta. 

bool inserimento(dati partecipante [ ], int &posizione){
    // chiedo in input il nominativo
    cout << "Inserisci il cognome: ";
    cin>>partecipante[posizione].cognome; 
    posizione++; 

    return true; 
}

int main(){

    //              INSERIMENTO PARTECIPANTI 

    const int max = 3; // al massimo ci possono essere dieci partecipanti in gara. 
    dati partecipante [max]; 
    int posizione = 0; 

    inserimento(partecipante, posizione); 

    cout << "Ecco gli iscritti alla gara: " << endl; 
    int i; 
    for ( i = 0; i < posizione; i++){
        cout << partecipante[i].cognome << endl; 
    }
    cout << endl; 

    cout << "Il numero di iscritti alla gara è pari a:  " << i << endl; 

    //                      FINE INSERIMENTO PARTECIPANTI

    //                      INSERIMENTO TEMPO 
    int minuti; 
    int secondi; 
    int tempo_partecipante; 

    cout << "Inserisci il tempo per ciascun partecipante: "; 
    for (int i = 0; i < posizione; i++){
        cin>>minuti>>secondi; 
        tempo_partecipante = (minuti * 60) + secondi; 
        partecipante[i].tempo = tempo_partecipante; 
    }

    cout << "Ecco i tempi inseriti: " << endl; 
    for (int i = 0; i < posizione; i++){
        cout << "Tempo di: " << partecipante[i].cognome << " = " << partecipante[i].tempo/60 << "minuti " << " e " << partecipante[i].tempo%60 << "secondi" << endl; 
    }
    return 0; 
}