/*

Percorso Semplificato

Un Percorso è formato da N caselle, ciascuna delle quali può assumere
il colore bianco od il colore nero. Le operazioni che possono essere
effettuate su un percorso sono le seguenti:

·	inizializza(p, N, c);
Inizializza un percorso p di lunghezza N. Inizialmente, tutte le
caselle sono di colore c.

· 	inizializza_copia(p1, p); 

Inizializza il valore del percorso p1 col valore del percorso p.

·	cambiaColore(p, i)
Operazione che cambia il colore della i-esima casella del percorso p.

·	stampa(p)
Operatore di uscita per il tipo Percorso. L'uscita ha la forma seguente:
		bbnnnb

Il carattere 'b' rappresenta una casella bianca, il carattere
'n' rappresenta una casella nera.

Utilizzando il linguaggio C++, realizzare il tipo di dato Percorso,
definito dalle precedenti specifiche.

Quale soluzione intermedia, un possibile main per questo esercizio si
trova nel file percorso_semplificato_solo_main.cc.

*/

#include <iostream>
#include <cstring>
using namespace std; 
enum colore {bianco, nero}; 

struct percorso{
    int dim_percorso; 
    colore ptr_colore; 
};

// creo una funzione che crea il vettore dinamico e mi restituisce l'indirizzo
void crea_dinamico(int &dim_percorso, char *&puntatore){
    // chiedo in input il valore delle caselle 
    cout << "Inserisci il numero delle caselle del percorso: \n"; 
    cin>>dim_percorso; 
    
    // alloco array dinamico di dimensione dim_percorso
    puntatore = new char [dim_percorso+1]; // +1 per il terminatore.
}

void inizializza_percorso(char *&puntatore, int &dim_percorso){

    int colore_caselle; 
    cout << "Di che colore vuoi inizializzare le caselle ( 0 bianco o 1 nero): \n"; 
    cin>>colore_caselle; 

    // inizializziamo il percorso con il colore delle caselle che abbiamo scelto
    int i; 
    for (i = 0; i < dim_percorso; i++){
        if (colore_caselle == 0){
            puntatore[i] = 'b'; 
        }
        else 
            puntatore[i] = 'n'; 
    }
    puntatore[i] = '\0'; 
}

void stampa_percorso(char *puntatore, int &dim_percorso){
    for (int i = 0; i < dim_percorso; i++){
        cout << puntatore[i] << " "; 
    }
    cout << endl;
}

void cambia_colore(char *puntatore, int &dim_percorso){
    int cambia_colore; 
    do{
        cout << "Inserisci l'indice della casella di cui vuoi cambiare il colore: \n"; 
        cin>>cambia_colore; 
    }
    while (cambia_colore < 0 || cambia_colore >= dim_percorso); 

    if (puntatore[cambia_colore] == 'b'){
        puntatore[cambia_colore] = 'n'; 
    }
    else{
        puntatore[cambia_colore] = 'b';
    } 
}

int main(){
    char *indirizzo; 
    int dim_percorso; 

    crea_dinamico(dim_percorso, indirizzo); 

    // inizializziamo il percorso
    inizializza_percorso(indirizzo, dim_percorso); 

    // stampiamo il percorso
    stampa_percorso(indirizzo, dim_percorso); 
     
    // se voglio cambiare colore alla iesima casella del percorso
    cambia_colore(indirizzo, dim_percorso); 

    stampa_percorso(indirizzo, dim_percorso); 

    return 0; 
}