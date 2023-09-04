#include <iostream>
#include <fstream>
using namespace std;

enum operazioni_t {addizione = '+', sottrazione = '-'}; 

/* devo implementare una coda, ogni elemento della coda ha due campi: 
- tipo operazione, che è un enum (addizione o sottrazione), e 
- il valore che è una variabile intera

ogni elemento della codaa è una struct: ha un campo tipo operazione e un campo valore. 
*/

struct elemento_t {
    operazioni_t tipo_operazione; // variabile di tipo operazioni_t.
    int valore;  
}; 

struct coda_t{
    elemento_t* coda_operazioni;
    int dim_coda; 
    int fine = 0; 
}; 

void crea_coda(coda_t &coda){
    coda.dim_coda = 0; 
    coda.coda_operazioni = new elemento_t [coda.dim_coda]; 
}

bool inizializza_coda(coda_t &coda, int &N){
    if(N < 0){
        cout << "La coda non può avere dimensioni negative!"; 
        return false; 
    }
    if(N != coda.dim_coda ){
        delete[] coda.coda_operazioni; 
        coda.coda_operazioni = new elemento_t[N]; 
        coda.dim_coda = N; 
    }
    return true; 
}

bool accoda_operazioni(coda_t &coda, char&c, int&val){
    
    if(coda.fine == coda.dim_coda){ // la coda è piena. 
        return false; 
    }
    coda.coda_operazioni[coda.fine].tipo_operazione = static_cast<operazioni_t>(c); 
    coda.coda_operazioni[coda.fine].valore = val; 
    coda.fine++; 
    return true; 
}

void stampa_operazioni(coda_t &coda){
    for(int i = 0; i < coda.dim_coda; i++){
        cout << "(" << static_cast<char>(coda.coda_operazioni[i].tipo_operazione) << " " << coda.coda_operazioni[i].valore << ") " << " "; 
    }
    cout << endl; 
}

bool salva_operazioni(ofstream &file_operazioni, coda_t &coda){
    if(!file_operazioni){
        cerr << "Errore! Non riesco ad prire il file in scrittura \n"; 
        return 1; 
    }
    file_operazioni << coda.dim_coda << endl; 
    for(int i = 0; i < coda.dim_coda; i++){
        file_operazioni << static_cast<char>(coda.coda_operazioni[i].tipo_operazione) << " " << coda.coda_operazioni[i].valore << " "; 
    }
    file_operazioni << endl; 
    return true; 
}

bool carica_operazioni(ifstream &leggi_operazioni, coda_t &coda){
    char c; 
    if(!leggi_operazioni){
        cerr << "Errore! Non riesco ad aprire il file in lettura!\n"; 
        return false; 
    }
    // prima di leggere i dati da file devo deallocare l'array con i dati vecchi, e riallocarlo con le dimensioni dell'array contenute nel fiile, così da poter leggere i valori correttamente. 

    delete[] coda.coda_operazioni; 
    leggi_operazioni >> coda.dim_coda; 
    coda.coda_operazioni = new elemento_t [coda.dim_coda]; 

    // ---------- RICORDATI DI DEALLOCARE SEMPRE PRIMA DI LEGGERE DEI NUOVI DATI ------- 

    for (int i = 0; i < coda.dim_coda; i++){
        leggi_operazioni >> c; 
        coda.coda_operazioni[i].tipo_operazione = static_cast<operazioni_t>(c); 
        leggi_operazioni >> coda.coda_operazioni[i].valore;  
        // prova di stampa - tracing. 
        cout << endl; 
        cout << "[carica_operazioni: sto stampando gli elementi che ho letto: ] (" << static_cast<char>(coda.coda_operazioni[i].tipo_operazione) << " " << coda.coda_operazioni[i].valore << ") " << " " << endl; 
    }

    return true; 
}

/*bool elimina_operazione(coda_t &coda){

    if(coda.dim_coda == 0){
        cout << "La cods è vuota!"; 
        return false; 
    }
    int testa = 0; 
    cout << "Testa: " << testa << endl;
    testa++; 
    coda.dim_coda--;  
    cout << static_cast<char>(coda.coda_operazioni[testa].tipo_operazione) << " "; 
    cout << coda.coda_operazioni[testa].valore << endl; 
    return true; 
}*/

int main()
{
    coda_t coda; 
	const char menu[] =
		"1. Inizializza coda\n"
		"2. Accoda operazione\n"
		"3. Stampa operazioni\n"
		"4. Salva operazioni\n"
		"5. Carica operazioni\n"
		"6. Elimina operazione\n"
		"7. Unisci operazioni\n"
		"8. Esci\n";

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
            crea_coda(coda); 
            int N; 
            cout << "Inserisci le dimensioni della coda: ";
            cin>>N; 
            inizializza_coda(coda, N); 
            break;
        }
		case 2:
        {
            char c; 
            int val; 
            do{
                cout << "Inserisci il tipo dell'operaizone '+' o '-': "; 
                cin>>c; 
                //coda_operazioni.tipo_operazione = static_cast<operazioni_t>(c); 
            }
            while(c != '+' && c != '-'); 

            cout << "Inserisci valore: "; 
            cin>>val;  

            if(accoda_operazioni(coda, c, val)){
                cout << "Accodamento effettuato con successo!\n"; 
            } 
            else
                cout << "La coda è piena!\n"; 
            break;
        }
		case 3:
        {
            stampa_operazioni(coda);
            break;
        }
		case 4:
        {
            ofstream file_operazioni; 
            file_operazioni.open("operazioni.txt"); 
            if(!file_operazioni){
                cerr << "Errore! Impossibile aprire il file in scrittura."; 
                return 1; 
            }
            if(salva_operazioni(file_operazioni, coda))
                cout << "Salvataggio su file eseguito con successo!\n"; 
            file_operazioni.close(); 
            break;
        }
		case 5:
        {
            ifstream leggi_operazioni; 
            leggi_operazioni.open("operazioni.txt"); 
            if(!leggi_operazioni){
                cerr << "Errore! Impossibile aprire il file in lettura.\n";
                return 1; 
            }
            if(carica_operazioni(leggi_operazioni, coda))
                cout << "Caricamento da file avvenuto con successo!\n"; 
            leggi_operazioni.close(); 
            break;
        }
		case 6:
        {
            //elimina_operazione(coda); 
            break;
        }
		case 7:
			break;
		case 8:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}