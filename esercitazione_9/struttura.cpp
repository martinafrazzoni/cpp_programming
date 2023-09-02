/*
 Scrivere un programma che chieda all'utente di inserire il nome di un
 partecipante ad una gara di SCI ed il tempo che ha fatto registrare,
 espresso in minuti e secondi. Il programma deve quindi memorizzare i
 dati del partecipante in un oggetto struttura che contenga una
 stringa (per memorizzarvi il nominativo) ed un valore intero, contenente il
 tempo in secondi. Infine il programma stampa a video
 i dati appena memorizzati, esprimendo di nuovo il tempo in minuti e
 secondi. Inoltre, il programma stampa a video la lunghezza della
 stringa contenuta nel campo nominativo. Esempio:

 Inserisci nominativo: Tomba
 Tempo di Tomba (minuti e secondi): 2 23
 Il vincitore e' Tomba, con il tempo di 2 minuti e 23 secondi
 Il nominativo contiene una stringa di 5 caratteri

*/

#include <iostream>
#include <cstring>
using namespace std; 

int main(){
    const int max_stringa = 20; 
	struct gara_di_sci{

		char nome [max_stringa]; 
		int tempo_minuti; 
		int tempo_secondi; 
	}; 

    gara_di_sci partecipante;   

    cout << "Inserisci nominativo: " << endl; 
    cin>>partecipante.nome; 

    cout << "Tempo di " << partecipante.nome << "(minuti e secondi): "; 
    cin>>partecipante.tempo_minuti >> partecipante.tempo_secondi; 

    cout << "Il vincitore è " << partecipante.nome << "con il tempo di " << partecipante.tempo_minuti << " minuti e " << partecipante.tempo_secondi << " secondi " << endl; 

    // lunghezza stringa
    int lunghezza_stringa = strlen(partecipante.nome); 
    cout << "Il nominativo contiene una stringa di " << lunghezza_stringa << " caratteri" << endl; 
    return 0; 
}

