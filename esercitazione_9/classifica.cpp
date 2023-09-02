/*(Il seguente esercizio è la versione completa di quello parziale contenuto in 
traccia_classifica_solo_elenco.txt)

Dobbiamo gestire la classifica di una gara di SCI. Le fasi sono le seguenti:
1 Iscrizione dei partecipanti
2 Gara: per ogni partecipante si immette il tempo di discesa
I dati di ciascun partecipante sono i seguenti: 
. il nominativo (ad esempio il cognome) del partecipante
. un valore intero rappresentante il miglior tempo fatto registrare dal 
  partecipante (espresso in secondi)
Le funzionalita' del programma sono le seguenti:
. iscrizione di un nuovo partecipante
	. si inserisce solo il nominativo (es: Razzoli) del partecipante
. stampa del numero di iscritti e dei nominativi 
. gara: per ogni iscritto si chiede all'utente di inserire il tempo
  espresso in minuti e secondi. Se si ripete una gara, la classifica viene 
  annullata e riempita d'accapo 
. stampa primo classificato. I tempi sono espressi in minuti e secondi
  (realizzare questa funzionalita' trovando il partecipante che ha realizzato
   il tempo migliore tra quelli presenti nell'elenco).

Il programma dovra' quindi fornire un menu del tipo:

Gestione classifica
Menu
1 Inserimento di un nuovo partecipante
2 Stampa elenco partecipanti
3 Gara
4 Stampa primo classificato
5 Uscita

-> per copiare stringhe si puo' utilizzare la funzione 
	strcpy(destinazione, sorgente) 
-> trascuriamo il problema dell'inserimento di piu' partecipanti con lo stesso
   nominativo

Soluzione in classifica.cc

Estensioni al programma:
1 Far si che, ogni volta che si effettua una nuova iscrizione, il partecipante
  sia inserito nell'elenco in ordine alfabetico.
  Si puo' utilizzare la funzione di libreria strcmp, che, tra l'altro,
  e' gia' predisposta per determinare anche l'ordine alfabetico di stringhe 
  composte da piu' parole (separate da spazi).
  strcmp(nome1, nome2) < 0 => nome1 precede alfabeticamente nome2 
  strcmp(nome1, nome2) = 0 => nome2 e nome1 contengono la stessa stringa 
  strcmp(nome1, nome2) > 0 => nome2 precede alfabeticamente nome1 

Soluzione in classifica_elenco_ordinato.cc

*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std ;

struct dati {
    char nominativo[100]; 
    int tempo; 
}; 

int inserimento(dati partecipante [ ], int &posizione, int max){
    if (posizione == max){
        cout << "Errore: elenco già pieno!" << endl; 
        return posizione; 
    }
    char nome[100]; 
    char cognome[100]; 

    // chiedo in input il nominativo
    cout << "Inserisci il nome: "; 
    cin>>nome; 
    int lunghezza_nome = strlen(nome); 

    nome[0] = toupper(nome[0]); 
    cout << "Inserisci il cognome: ";
    cin>>cognome; 
    int lunghezza_cognome = strlen(cognome); 

    cognome[0] = toupper(cognome[0]); 
     
    // trasformiamo tutte le altre lettere in minuscolo
    for (int i = 1; i < lunghezza_nome; i++){
        nome[i] = tolower(nome[i]); 
    }

    for (int i = 1; i < lunghezza_cognome; i++){
        cognome[i] = tolower(cognome[i]); 
    }
    strcat(nome, " "); 
    strcat(nome, cognome); 
    cout << "Nome dopo strcat " << nome << endl; 
    strcpy(partecipante[posizione].nominativo, nome); 
    posizione++;      
    return posizione; 
}

void stampa_elenco(dati partecipante[ ], int &posizione){
    int i; 
    int conta_partecipanti = 0; 
    for ( i = 0; i < posizione; i++){
        //cout << partecipante[i].cognome << endl; 
        conta_partecipanti++; 
    }
    cout << endl; 
    cout << "Il numero di iscritti alla gara è pari a: " << conta_partecipanti << endl; 

    cout << "Ecco gli iscritti alla gara: " << endl; 
    char temp[100]; 
    for (int i = 0; i < conta_partecipanti; i++){
        for (int j = (i+1); j < conta_partecipanti; j++){
            if(strcmp(partecipante[i].nominativo, partecipante[j].nominativo) > 0){
                strcpy(temp, partecipante[j].nominativo); 
                strcpy(partecipante[j].nominativo, partecipante[i].nominativo); 
                strcpy(partecipante[i].nominativo, temp);
            } 
        }
    }
    for (int i = 0; i < conta_partecipanti; i++){
        cout << partecipante[i].nominativo << endl; 
    }
    cout << endl; 
}    

void gara(dati partecipante [ ], int &posizione){
    int minuti; 
    int secondi; 
    int tempo_partecipante; 

    cout << "Inserisci il tempo di  " << endl; 
    for (int i = 0; i < posizione; i++){
        cout << partecipante[i].nominativo << " : "; 
        cin>>minuti>>secondi; 
        tempo_partecipante = (minuti * 60) + secondi; 
        partecipante[i].tempo = tempo_partecipante; 
    }

    cout << "Ecco i tempi inseriti: " << endl; 
    for (int i = 0; i < posizione; i++){
        cout << "Tempo di " << partecipante[i].nominativo << " : " << (partecipante[i].tempo/60) << " minuti " << " e " << (partecipante[i].tempo%60) << " secondi" << endl; 
    }

}

void primo_classificato(dati partecipante[ ], int &posizione){
    /*int vincitore = 0; // indice del vincitore. 
    int tempo_minimo = partecipante[vincitore].tempo; 
    int i; 
    for (i = 0; i < posizione; i++){
	    if (partecipante[i].tempo < tempo_minimo){
            vincitore = i; 
        }
    } 
    cout << "Il primo classificato è " <<  partecipante[vincitore].cognome <<" con il tempo di " << (tempo_minimo/60) << " minuti e " << (tempo_minimo%60) << " secondi!" << endl; */

    // ordiniamo l'array in senso crescente. 
    int min_index; 
    dati temp; 
    for (int i = 0; i < posizione; i++){
    min_index = i; // supponiamo che il tempo minimo sia nella posizione di indice i. 
        for (int j = (i+1); j < posizione; j++){
            if (partecipante[j].tempo < partecipante[min_index].tempo){
                min_index = j; 
            }
        }
    // invece che fare lo scambio solo del campo tempo della struct, swappo ogni partecipante. 
    temp = partecipante[min_index]; 
    partecipante[min_index] = partecipante[i]; 
    partecipante[i] = temp; 
    }
    int podio  = 3; 
    cout << "Classifica: " << endl; 
    for (int i = 0; i < podio; i++){
       cout << partecipante[i].nominativo << " = " << partecipante[i].tempo /60 << " minuti e " << partecipante[i].tempo%60 << " secondi" << endl; 
    }
    cout << endl; 
}

int main(){
    int scelta;
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
            {
                gara(partecipante, posizione); 
                break ;
            }
            case 4:
            {
                primo_classificato(partecipante, posizione); 
                break;
            }
            case 5:
                 return 0 ;
            default:
                 continue ;
        } // Fine switch
    } // Fine while
    return 0 ;
}
