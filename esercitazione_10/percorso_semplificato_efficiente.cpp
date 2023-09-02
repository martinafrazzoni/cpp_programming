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

enum colore_t {bianco, nero}; 
colore_t colore; 

// creo il tipo di dato percorso 
struct percorso{
    int dim_percorso; 
    colore_t * caselle;  
    // puntatore di tipo colore che si chiama caselle e 
}; 
percorso p; 

void inizializza_percorso(percorso &p){
	// chiedo in input la dimensione del percorso
    cout << "Inserisci la dimensione del percorso: \n"; 
    cin>>p.dim_percorso; 
    //che crea un vettore dinamico di tipo colore di dim_percorso elementi. 
    p.caselle = new colore_t [p.dim_percorso]; 
    // inizializzo a bianco tutti gli elementi
    for (int i = 0; i < p.dim_percorso; i++){
        p.caselle[i] = bianco; 
    }
}

void inizializza_copia(const percorso &p,  percorso &p1){ 
    // se faccio l'assegnamento p1 = p stoi facendo solo una copia superficiale, sto copiando solo i valori dei membri della struct, ma non la memoria a cui puntano p e p1. Devo quindi fare una copia elemento per elemento. 
	/*This means that after the assignment, both p.caselle and p1.caselle will be pointing to the same memory location, so any changes made to the cells of one percorso object will also affect the cells of the other percorso object.*/
	p1.dim_percorso = p.dim_percorso; 
	p1.caselle = new colore_t [p1.dim_percorso]; 
	for (int i = 0; i < p1.dim_percorso; i++){
		p1.caselle[i] = p.caselle[i]; 
	}
}

void cambia_colore(percorso &p){
    // chiedo in input l'indice della casella di cui dobbiamo cambiare colore; 
    int index; 
    do{
        cout << "Inserisci l'indice della casella di cui vuoi cambiare il colore: \n";
        cin>>index; 
    }
    while (index < 0 || index > p.dim_percorso); 

    if(p.caselle[index] == nero)
        p.caselle[index] = bianco; 
    else 
        p.caselle[index] = nero; 
}

void stampa_percorso(const percorso &p){
    // stampo: se la casela è nera stampo il carattere 'n', se è bianca 'b'
    for (int i = 0; i < p.dim_percorso; i++){
        if (p.caselle[i] == bianco)
            cout << 'b' << " "; 
        else
            cout << 'n' << " "; 
    }
}

void dealloca_percorso(percorso &p){
	delete[] p.caselle;
}

int main(){

	const char Menu[] = "\nComandi disponibili:\n"
		"\tc (C) - per cambiare il colore di una casella di p (p1)\n"
		"\td     - per continuare con due nuovi percorsi\n"
		"\tq     - per terminare\n";

	char comando;
	do {
	    percorso p, p1;
        

	    cout<<"Inizializzo due percorsi p e p1.\n" ;
	    inizializza_percorso(p); 
        inizializza_copia(p, p1); 
	    cout<< "p: " ;
	    stampa_percorso(p); 
	    cout<< "\np1: " ;
	    stampa_percorso(p1); 
	    cout<<endl ;

	    cout<<Menu<<"\n\nComando? " ;
	    cin>>comando ;

	    while (comando != 'd' && comando != 'q') {
		switch (comando) {
		case 'c': {
		    cambia_colore(p);
		    break;
		}
		case 'C': {
		    cambia_colore(p1); 
		    break;
		}
		default:
			cout<< "Comando "<<comando<<" non valido\n" ;
		}
		cout<< "p: " ;
		stampa_percorso(p); 
		cout<< "\np1: " ;
	    stampa_percorso(p1); 
		cout<<endl ;

		cout<<Menu<<"\n\nComando? " ;
		cin>>comando ;
	    }
		dealloca_percorso(p); 
		dealloca_percorso(p1); 
		
	} while (comando != 'q');
	cout<< "*\n" ;
     
    return 0; 
}


