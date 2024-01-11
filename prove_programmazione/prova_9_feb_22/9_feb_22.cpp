#include <iostream>
#include <fstream>
#include <cstring>
using namespace std; 

struct prodotto_t {
    int quantità; 
    int codice; 
}; 

struct archivio_t {
    int N;  
    prodotto_t *prodotti;   // array che mi contiene i prodotti. 
    int testa = 1; 
}; 

void crea_archivio(archivio_t &archivio){
    archivio.N = 1; // totale dei prodotti presenti nell'archivio. All'inizio c'è solo un prodotto.
    archivio.prodotti = new prodotto_t[2];
    archivio.prodotti[1].quantità = 0; 
    archivio.prodotti[1].codice = 1; 
}

bool inizializza_archivio(archivio_t &archivio, int&N){

    // controllo se N è 0 e se è uguale a 0 allora la funzione ritorna falso.  
    if(N <= 0){
        return false; 
    }

    // se la dimensione passata non è uguale a archivio.N, allora togliamo tutti i prodotti e riallochiamo l'array. 
    if(N != archivio.N){
        delete[] archivio.prodotti; 
        archivio.prodotti = new prodotto_t[N+1]; 
        archivio.N = N; 
    }

    // per ogni elemento dell'array prodotti, io devo inizializzare il campo codice.  
    for (int i = archivio.testa; i <= archivio.N; i++){
        archivio.prodotti[i].codice = i;  
        archivio.prodotti[i].quantità = 0; 
    }
    return true; 
}

bool aggiungi_prodotto(archivio_t &archivio){
    int cod; 
    cout << "Inserisci il codice del prodotto che vuoi aggiungere: \n";
    cin>>cod; 
    if(cod <= 0 || cod > archivio.N){
        cout << "Codice inserito non valido!\n"; 
        return false; 
    }
    // scorro l'archivio dei prodotti per vedere se trovo un elemento che ha il codice pari a n, se lo trovo incremento la quantità di 1. 
    for (int i = archivio.testa; i <= archivio.N; i++){ // qui il for comincia da 0. 
        if(cod == archivio.prodotti[i].codice){
            archivio.prodotti[i].quantità++; 
        }
    }
   return true; 
}

void stampa_archivio(archivio_t &archivio){
    cout << "Ecco l'archivio: \n"; 
    for(int i = archivio.testa; i <= archivio.N; i++){
        if(archivio.prodotti[i].quantità > 0)
            cout << archivio.prodotti[i].codice << " " << archivio.prodotti[i].quantità << " " << endl; 
    }
}

void salva_archivio(ofstream &file_archivio, archivio_t &archivio){
    file_archivio << archivio.N << '\n'; // ho scritto su file il numero totale di prodotti. 
    for (int i = archivio.testa; i <= archivio.N; i++){
        file_archivio << archivio.prodotti[i].codice << " " << archivio.prodotti[i].quantità << '\n';    // i mi tiene traccia degli indici, che nel mio caso equivalgono anche ai codici dei prodotti. 
    }
}


bool carica_archivio(ifstream &leggi_archivio, archivio_t &archivio){
    delete[] archivio.prodotti; 
    
    leggi_archivio>>archivio.N;  
    archivio.prodotti = new prodotto_t [archivio.N]; 

    if(leggi_archivio.fail()){
        cerr << "Errore nella lettura da file!\n"; 
        return false; 
    }

    for(int i = archivio.testa; i <= archivio.N; i++){
        leggi_archivio>>archivio.prodotti[i].codice >> archivio.prodotti[i].quantità; 
    }
    return true; 
}

int leggi_elimina_primo_prodotto(archivio_t &archivio){
    int q_testa = archivio.prodotti[archivio.testa].quantità; 
    cout << q_testa << endl; 
    archivio.testa++; 
    return q_testa; 
}


int main()
{
    archivio_t archivio; 
    int N; 

    crea_archivio(archivio); 

    const char menu[] =
		"1. Inizializza archivio\n"
		"2. Aggiungi prodotto\n"
		"3. Stampa archivio\n"
		"4. Salva archivio\n"
		"5. Carica Archivio\n"
		"6. Leggi e elimina primo prodotto\n"
		"7. Esci\n";

	while (true) {
		cout<<menu<<endl;
		int scelta = 0;
		if (!(cin>>scelta)) {
			cout<<"Esco: input in stato d'errore o finito"<<endl;
			return 1;
		}

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1:
        { 
            cout << "Inserisci il numero di prodotti dell'archivio: \n"; 
            cin>>N; 
            if(inizializza_archivio(archivio, N)){
                cout << "Archivio inizializzato correttamente!\n"; 
            }
            break;
        }
		case 2:
        {   if(aggiungi_prodotto(archivio)){
                cout << "prodotto aggiunto correttamente!\n"; 
            }
        }       
        break;
		case 3:
        {
            stampa_archivio(archivio); 
            break;
        }
		case 4:
        {
            // apriamo file in scrittura e scriviamoci dentro l'array di struct. 
            ofstream file_archivio; 
            file_archivio.open("archivio.txt"); 
            if(!file_archivio){
                cerr << "Errore! Impossibile aprire il file in scrittura!"; 
                return 1; 
            }
            salva_archivio(file_archivio, archivio); 
            file_archivio.close(); 
            break;
        }
		case 5:
        {
            ifstream leggi_archivio; 
            leggi_archivio.open("archivio.txt"); 
            if(!leggi_archivio){
                cerr << "Errore! Impossibile aprire il file in lettura!"; 
                return 1; 
            }
            if(carica_archivio(leggi_archivio, archivio) == true){
                cout << "Caricamento avvenuto con successo!\n"; 
            }
            leggi_archivio.close(); 
            break; 
        }
		case 6:
        { 
            if(leggi_elimina_primo_prodotto(archivio)==true){
                cout << "Prodotto eliminato con successo!\n"; 
            } 
            break;
        }
			
		case 7:
        {
            delete[] archivio.prodotti; 
            return 0; 
        }
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}