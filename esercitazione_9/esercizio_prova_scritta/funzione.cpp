/*Partendo dal frammento di codice fornito, scrivere un gioco in cui 2 giocatori hanno una pedina
ciascuno. Lanciando un dado che restituisce valori discreti uniformemente distribuiti tra 1 e 6, i
giocatori muovono a turno la propria pedina su M caselle consecutive. Il numero M di caselle è
prefissato. Vince il giocatore che raggiunge o supera per primo l'ultima casella. In particolare,
realizzare le seguenti funzionalità:
1. Inizio nuova partita: la pedina di ciascun giocatore è posizionata nella prima casella, il giocatore
di turno è il giocatore 1. Un'eventuale partita in corso viene persa.
2. Stampa stato partita: se c'è una partita in corso, stampa, per ciascun giocatore, la casella in cui il
giocatore si trova; quindi stampa il prossimo giocatore di turno, o l'indicazione di partita finita
se la partita è già finita. Se, ad esempio le pedine si trovano nelle caselle 8 e 10 ed il giocatore di
turno è il secondo, si stampa: Giocatore 1: 8, Giocatore 2: 10 
Turno: Giocatore 2. 
3. Prossimo turno: se la partita è già finita non fa nulla; altrimenti il giocatore di turno lancia il
dado ed avanza di un numero di caselle corrispondente al valore restituito dal dado. Se il
giocatore raggiunge o supera l'ultima casella vince, e la partita finisce. Altrimenti il turno passa
al prossimo giocatore.
4. Salva stato partita: salva in un file di testo (dal nome definito a tempo di scrittura del
programma) lo stato della partita.
5. Carica stato partita: carica da un file di testo (dal nome definito a tempo di scrittura del
programma) lo stato della partita. La partita riprende da dove era stata salvata, ed un'eventuale
partita in corso è persa*/


#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std ;

// struct per la partita
struct partita_info{
	int pos_giocatore_1;  
    int pos_giocatore_2; 
    int turno; 
}; 

// Funzioni per l'inizializzazione ed il lancio del dado:

void inizializza_dado() {
	srand((unsigned int)time(0)); // la funzione time ritorna un valore di tipo time_t. ma la funzione srand prende come parametro un unsigned int. 
}

// Ritorna un numero casuale tra 1 e 6
unsigned int lancia_dado() {
	// implementiamo il lancio del dado, che genera dei numeri da 1 e 6. 
    // generiamo numeri random dalla lbreria cstdlib

    unsigned int roll = 0; // memorizza il numero di lanci. 
    roll = (rand() % 6) + 1; 
    return roll; 
}

void inizio_partita(partita_info &partita){
	partita = {
		.pos_giocatore_1 = 0,
		.pos_giocatore_2 = 0, 
		.turno = 1,
	}; 
	cout << "Giocatore 1: " << partita.pos_giocatore_1 << endl; 
	cout << "Giocatore 2: " << partita.pos_giocatore_2 << endl; 
	cout << "Turno: " << partita.turno << endl; 
}	

int prossimo_turno(partita_info &partita){
	// invochiamo la funzione del lancio del dado: 
        int dado = lancia_dado(); 
        if (partita.turno == 1){
            // la posizione del giocatore_! all'interno dell'array casella è uguale a pos_giocatore_1 + dado: 
            partita.pos_giocatore_1 += dado; 
            cout << "Il giocatore_1 lancia il dado e viene fuori: " << dado << endl; 
            cout << "La posizione del giocatore 1 è pari a: " << partita.pos_giocatore_1 << endl; 
            partita.turno = 2; 
			return partita.pos_giocatore_1; 
        }
        else{
            // adesso è il turno del giocatore_2
            dado = lancia_dado(); 
            partita.pos_giocatore_2 += dado; 
            cout << "Il giocatore_2 lancia il dado e viene fuori: " << dado << endl; 
            cout << "La posizione del giocatore 2 è pari a: " << partita.pos_giocatore_2 << endl; 
            partita.turno = 1; 
			return partita.pos_giocatore_2; 
        }
}


void stampa_stato_partita(partita_info &partita, const int dim_M){
	cout << "Giocatore 1: " << partita.pos_giocatore_1 << endl; 
	cout << "Giocatore 2: " << partita.pos_giocatore_2 << endl; 
	if (partita.turno == 1)
		cout << "Prossimo turno: Giocatore 1!" << endl; 
	else{
		cout << "Prossimo turno: giocatore 2!" << endl; 
	} 

	if (partita.pos_giocatore_1 > dim_M || partita.pos_giocatore_2 > dim_M)
	cout << "Partita finita!"; 
}

void salva_stato_partita(partita_info &partita, ofstream &stato_partita, const int dim_M){
	stato_partita << "Giocatore 1: " << partita.pos_giocatore_1 << endl; 
	stato_partita << "Giocatore 2: " << partita.pos_giocatore_2 << endl; 
	if (partita.turno == 1)
		stato_partita << "Prossimo turno: Giocatore 1!" << endl; 
	else{
		stato_partita << "Prossimo turno: giocatore 2!" << endl; 
	} 

	if (partita.pos_giocatore_1 > dim_M || partita.pos_giocatore_2 > dim_M)
	stato_partita << "Partita finita!" << endl; 
}

void carica_stato_partita(ifstream &leggi_stato_partita, partita_info &partita){
	leggi_stato_partita>>partita.pos_giocatore_1; 
	leggi_stato_partita>>partita.pos_giocatore_2;
	leggi_stato_partita>>partita.turno; 

	cout << partita.pos_giocatore_1 << endl; 
	cout << partita.pos_giocatore_2 << endl; 
	cout << partita.turno << endl; 
} 

int main()
{
    const int dim_M = 8; 
    int M [dim_M]; 
    
	partita_info partita; 

	while(true) {
		cout<<"1 Nuova partita"<<endl ;
		cout<<"2 Prossimo turno"<<endl ;
		cout<<"3 Stampa stato partita"<<endl ;
		cout<<"4 Salva stato partita"<<endl ;
		cout<<"5 Carica stato partita"<<endl ;
		cout<<"6 Stampa caselle"<<endl ;
		cout<<"7 Uscita"<<endl ;

		cout<<"Scelta? " ;

		int scelta ;
		cin>>scelta ;

		switch(scelta) {
		case 1:
        {
			inizio_partita(partita); 
            break ;
        }
		case 2:
		{
			prossimo_turno(partita); 
			if (partita.pos_giocatore_1 >= dim_M){
				cout << "Il giocatore 1 è il vincitore!" << endl; 
				return 0; 
			}
    		else if (partita.pos_giocatore_2 >= dim_M){
				cout << "Il giocatore 2 è il vincitore!" << endl;
				return 0; 
			}		
			break ;
		}
		case 3:
		{
			stampa_stato_partita(partita, dim_M); 
			break ;
		}
		
		case 4:
		{
			// creo un file di testo dove memorizzare lo stato della partita
			ofstream stato_partita; 
			stato_partita.open("stato_partita.txt"); 
			if (!stato_partita){
				cerr << "Errore! Impossibile aprire il file in scrittura!";
				return 1; 
			}
			salva_stato_partita(partita, stato_partita, dim_M); 
			stato_partita.close(); 
			break ;
		}
		case 5:
		{
			// devo leggere le info di una partita da file
			ifstream leggi_stato_partita; 
			leggi_stato_partita.open("stato_partita.txt"); 
			if (!leggi_stato_partita){
				cerr << "Errore! Impossibile aprire il file in lettura!";
				return 1; 
			}
			carica_stato_partita(leggi_stato_partita, partita);
			leggi_stato_partita.close(); 
			break ;
		}
		case 6:
			break ;
		case 7:
			return 0 ;
		default:
			cout<<"Scelta errata"<<endl ;
		}
	}
}
