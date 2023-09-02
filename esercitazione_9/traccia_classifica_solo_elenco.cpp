/*Dobbiamo gestire la classifica di una gara di SCI. Le fasi sono le seguenti:
1 Iscrizione dei partecipanti
2 Gara: per ogni partecipante si immette il tempo di discesa

I dati di ciascun partecipante sono i seguenti:
. il nominativo (ad esempio il cognome) del partecipante
. un valore intero rappresentante il miglior tempo fatto registrare dal
  partecipante (espresso in secondi)

Per ora scriviamo una versione semplificata del programma, con le seguenti
funzionalitaÕ:
. iscrizione di un nuovo partecipante (UNO SOLO ALLA VOLTA!)
	. si inserisce solo il nominativo (es: Razzoli) del partecipante
. stampa del numero di iscritti e dei nominativi

Il programma dovra' quindi fornire un menu del tipo:

Gestione classifica
Menu
1 Inserimento di un nuovo partecipante
2 Stampa elenco partecipanti
3 Uscita

-> per copiare stringhe si puo' utilizzare la funzione
	strcpy(destinazione, sorgente)
-> trascuriamo il problema dell'inserimento di piu' partecipanti con lo stesso
   nominativo

Si puo' partire dal main fornito nel file classifica_solo_main.cc.
Soluzione: classifica_solo_elenco.cc */

#include <iostream>
#include <cstring>
using namespace std ;

struct dati {
    char cognome[10]; 
    int tempo; 
}; 

int inserimento(dati partecipante [ ], int &posizione, int max){
    if (posizione == max){
        cout << "Errore: elenco già pieno!" << endl; 
        return posizione; 
    }
    // chiedo in input il nominativo
    cout << "Inserisci il cognome: ";
    cin>>partecipante[posizione].cognome; 
    posizione++;  
    return posizione; 
}

void stampa_elenco(dati partecipante[ ], int &posizione){
    cout << "Ecco gli iscritti alla gara: " << endl; 
    int i; 
    for ( i = 0; i < posizione; i++){
        cout << partecipante[i].cognome << endl; 
    }
    cout << endl; 
    cout << "Il numero di iscritti alla gara è pari a: " << i << endl; 

} 
void gara(){

}

int main()
{
    int scelta ;
    const int max = 10; // al massimo ci possono essere dieci partecipanti in gara. 
    dati partecipante [max]; 
    int posizione = 0; 

    while (true) {
        cout<<"Gestione classifica\n" ;
        cout<<"Menu\n" ;
        cout<<"1 Inserimento di un nuovo partecipante\n" ;
        cout<<"2 Stampa elenco partecipanti\n" ;
        cout<<"3 Gara\n" ;
        cout<<"4 Stampa primo classificato\n" ;
        cout<<"5 Uscita\n" ;
        cin>>scelta ;
        switch(scelta) {

            case 1:
            {
                inserimento(partecipante, posizione, max);  
                break;
            }
            case 2:
            {
                stampa_elenco(partecipante, posizione); 
                break ;
            }
            case 3:
                 cout<<"Da implementare\n" ;
                 break ;
            case 4:
                 // stampa_primo(..., ...) ;
                 cout<<"Da implementare\n" ;
                 break ;
            case 5:
                 return 0 ;
            default:
                 continue ;
        } // Fine switch
    } // Fine while
    return 0 ;
}
