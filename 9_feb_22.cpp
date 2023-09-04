#include <iostream>
#include <fstream>
using namespace std; 

struct prodotto_t {
    int quantità; 
    int codice; 
}; 

struct archivio_t {
    int N; 
    prodotto_t *prodotti;  
    prodotto_t *prodotti_ordinati;
}; 

void crea_archivio(archivio_t &archivio){
    archivio.N = 1; 
    archivio.prodotti = new prodotto_t[archivio.N]; 
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
    int cod = 1; 
    for (int i = 0; i < archivio.N; i++){
        archivio.prodotti[i].codice = cod++; 
        archivio.prodotti[i].quantità = 0; 
    }
    return true; 
}

bool aggiungi_prodotto(archivio_t &archivio){
    int n; 
    cout << "Inserisci il codice del prodotto che vuoi aggiungere: \n";
    cin>>n; 
    if(n <= 0 || n > archivio.N){
        cout << "Codice inserito non valido!\n"; 
        return false; 
    }
    // scorro l'archivio dei prodotti per vedere se trovo un elemento che ha il codice pari a n, se lo trovo incremento la quantità di 1. 
    for (int i = 0; i < archivio.N; i++){
        if(archivio.prodotti[i].codice == n){
            archivio.prodotti[i].quantità++; 
        }
    }
   return true; 
}

void stampa_archivio(archivio_t &archivio){
   // scorro tutti i prodotti per cercare quelli che hanno una quantità maggiore di 0, e li metto dentro un secondo array, e infine ordino questo secondo array. 
    archivio.prodotti_ordinati = new prodotto_t[archivio.N]; 
    int index = 0;  
   for (int i = 0; i < archivio.N; i++){
        if(archivio.prodotti[i].quantità > 0){
            archivio.prodotti_ordinati[index].codice = archivio.prodotti[i].codice;
            archivio.prodotti_ordinati[index].quantità = archivio.prodotti[i].quantità;
            index++; 
        }
   }
   cout << "Ecco l'archivio: \n"; 
   for (int i = 0; i < archivio.N; i++){
        if(archivio.prodotti_ordinati[i].quantità > 0)
        cout << archivio.prodotti_ordinati[i].codice << " " << archivio.prodotti_ordinati[i].quantità << endl; 
   }
   delete[] archivio.prodotti_ordinati; 
}

void salva_archivio(ofstream &file_archivio, archivio_t &archivio){
    for (int i = 0; i < archivio.N; i++){
        if(archivio.prodotti[i].quantità > 0){
            file_archivio << archivio.prodotti[i].codice << " " << archivio.prodotti[i].quantità << endl;    
        }
    }
}

void carica_archivio(ifstream &file_archivio_lett, archivio_t &archivio){
    for (int i = 0; i < archivio.N; i++){
        file_archivio_lett >> archivio.prodotti[i].codice >> archivio.prodotti[i].quantità;  
    }
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
                cout << "Archivio inizializzato correttamente!"; 
            }
            break;
        }
		case 2:
        {
            if (aggiungi_prodotto(archivio) == true){
                cout << "Quantità aggiunta correttamente!\n"; 
            } 
            break;
        }
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
            ifstream file_archivio_lett; 
            file_archivio_lett.open("archivio.txt"); 
            if(!file_archivio_lett){
                cerr << "Errore! Impossibile aprire il file in lettura!"; 
                return 1; 
            }
            carica_archivio(file_archivio_lett, archivio); 
            file_archivio_lett.close(); 
            break;
        }
		case 6:
        { 
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