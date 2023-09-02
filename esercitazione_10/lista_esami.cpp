/*Realizziamo un programma che permetta di gestire la lista degli studenti 
iscritti ad un esame.
Per il momento supponiamo che, per ciascuno studente, inseriamo solo il cognome.
Le funzionalita' del programma sono le seguenti:
. iscrizione di un nuovo studente
. stampa del numero di iscritti e dei nominativi 

-> per lavorare con le stringhe, puo' essere conveniente sfruttare le funzioni di 
   libreria
-> trascuriamo i problemi legati all'inserimento di piu' studenti con lo stesso
   cognome

La soluzione si trova nel file: sol_lista_esami_base.c.

Estensioni al programma:

. far sì che, ogni volta che si effettua una nuova iscrizione, lo studente
  sia inserito nell'elenco in ordine alfabetico 
  Si puo' utilizzare la funzione di libreria strcmp, che e' gia' predisposta 
  per determinare anche l'ordine alfabetico di stringhe composte da piu' 
  parole (separate da spazi).
  strcmp(nome1, nome2) < 0 => nome1 precede alfabeticamente nome2 
  strcmp(nome1, nome2) = 0 => nome2 e nome1 contengono la stessa stringa 
  strcmp(nome1, nome2) > 0 => nome2 precede alfabeticamente nome1 
  La soluzione di questa seconda versione si trova nel file: 
  sol_lista_esami_ordinata.c.

. ogni volta che si iscrive un nuovo partecipante, richiedere sia il nome che il
  cognome. Le due stringhe contenenti il nome ed il cognome immessi da tastiera 
  vanno quindi concatenate e copiate nel nominativo.
  Assicurarsi (ed eventualmente effettuare delle conversioni) che la prima 
  lettera di ciascuna parola del nominativo sia maiuscola e che tutte le altre
  siano minuscole.
  Ad esempio, se l'utente immette: "tOMBA aLberTo", il nominativo, prima di 
  essere inserito, va convertito nella forma "Tomba Alberto".
  La soluzione di questa terza versione si trova nel file: 
  sol_lista_esami_completa.c.

. implementare anche la disiscrizione di uno studente */

#include <iostream>
#include <cstring>
using namespace std;

const int max_nominativo  = 100; 

struct studente {
	char nominativo[max_nominativo]; 
};

void trasforma_lettere(char nome[ ], const int max_nominativo){
	// calcolo la lunghezza della stringa  
	int lunghezza = strlen(nome); 
	nome[0] = toupper(nome[0]); 
	for (int i = 1; i < lunghezza; i++){
		nome[i] = tolower(nome[i]); 
	}
}

/*funzione per l'iscrizione di ogni studente*/
int iscrizione_studente (studente iscrizioni[ ], const int max_iscrizioni, int &posizione){
	if (posizione > max_iscrizioni){
		cout << "Lista piena impossibile effettuare l'iscrizione!"; 
		return posizione; 
	}
	/* chiedo in input il cognome dello studente*/
	char nome [max_nominativo]; 
	char cognome[max_nominativo]; 

	cout << "Inserisci il nome: \n"; 
	cin>>nome; 
	trasforma_lettere(nome, max_nominativo);

	cout << "Inserisci cognome: \n";
	cin>>cognome; 
	trasforma_lettere(cognome, max_nominativo);

	// adesso che ho convertito sia il nome che il cognome nel formato che voglio le devo concatenare; 
	strcat(nome, " "); 
	strcat(nome, cognome); 
	
	// adesso le ho concatenate e posso copiare nome dentro iscrizioni[posizione].nominativo. 
	strcpy(iscrizioni[posizione].nominativo, nome); 
	posizione ++; 

	return posizione; 	
}

void stampa_iscritti(studente iscrizioni[ ], const int max_iscrizioni, int &posizione){
	// facciamo si che l'inserimento avvenga in ordine alfabetico, compariamo la stringa successiva con quella precedente, se la seconda precede alfabeticamente la priima facciamo lo swap. 
	char temp[100];  
	for (int i = 0; i < (posizione - 1); i++){
		for (int j = (i+1); j < posizione; j++){
			if (strcmp(iscrizioni[i].nominativo, iscrizioni[j].nominativo) > 0){
				strcpy(temp, iscrizioni[i].nominativo); 
				strcpy(iscrizioni[i].nominativo, iscrizioni[j].nominativo); 
				strcpy(iscrizioni[j].nominativo, temp); 
			}
		}
	}
	// devo usare strcpy perchè NON POSSO FARE L'ASSEGNAMENTO TRA DUE ARRAY, quindi per copiarli uso strcpy. 
	cout << "Ecco la lista degli studenti iscritti: " << endl; 
	for (int i = 0; i < posizione; i++){
		cout << iscrizioni[i].nominativo << endl; 
	}
	cout << "Il numero totale di stidenti iscritti è: " << posizione << endl; 

}

int disiscrivi_studente(studente iscrizioni [ ], const int max_iscrizioni, int &posizione){
	// controllo che si possa effettuare l'estrazione. 
	if (posizione == 0){
		cout << "Impossibile effettuare la disiscrizione, la lista è vuota!";
		return posizione; 
	}
	int pos_stud; 
	do{
		cout << "Inserisci l'indice dello studente che vuoi disiscrivere: \n"; 
		cin>>pos_stud; 
	}while (pos_stud < 0 || pos_stud > posizione); 
	for (int i = pos_stud; i < posizione; i++){
		strcpy(iscrizioni[i].nominativo, iscrizioni[i+1].nominativo); 
	}
	posizione --; 
	cout << "Il numero totale di studenti iscritti è: " << posizione << endl; 
	return posizione; 
}


int main(){
	int posizione = 0; 
	const int max_iscrizioni = 15; 
	studente iscrizioni[max_iscrizioni]; 

	int scelta; 
	while (true){
	cout << "Gestione iscrizioni\n"; 
	cout << "Menu\n"; 
	cout << "1. Inserimento di un nuovo studente \n"; 
	cout << "2. Stampa elenco iscritti\n"; 
	cout << "3. Disiscrivi studente \n"; 
	cout << "4. Uscita\n"; 
	cin>>scelta;
	switch(scelta){
	 case 1: {
		iscrizione_studente(iscrizioni, max_iscrizioni, posizione); 
		break; 
	}
	case 2: {
		stampa_iscritti(iscrizioni, max_iscrizioni, posizione); 
		break; 
	}
	case 3: {
		disiscrivi_studente(iscrizioni, max_iscrizioni, posizione); 
		break;
	}
	case 4: {
		return 0; 
	}
	default:
		continue; 
 	} // fine switch
     } // fine while
	return 0; 
}
