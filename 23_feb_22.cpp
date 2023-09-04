#include <iostream>
#include <cstring>
#include <fstream>
using namespace std; 

enum giorni_t {lunedi, martedi, mercoledi, giovedi, venerdi, sabato, domenica}; 
giorni_t giorno; 

const int lung_nome = 11; 
const int giorni_sett = 7;
char trova_lavoratore[lung_nome]; 
char agg_turni[giorni_sett+1]; 


struct lavoratore_t{
    char nome_lavoratore[lung_nome]; 
    bool turni[giorni_sett+1]; 
}; 

bool inizializza_elenco(lavoratore_t *&elenco_lavoratori, int&num_lavoratori){
    int conta = 0; //contatore che mi tiene traccia man mano di tutti i lavoratori che inserisco. 
    for (int i = 0; i < num_lavoratori; i++){
        cout << "Inserisci nome lavoratore: "; 
        cin>>elenco_lavoratori[i].nome_lavoratore; 
        conta ++;
        // dobbiamo controllare che il nome di ogni lavoratore non sia doppio. per ogni lavoratore controllo i successivi che non siano uguali, ho un for con due indici.  
        for(int j = 0; j < conta-1; j++){
            for (int y = j+1; y < conta; y++){
                if(strcmp(elenco_lavoratori[j].nome_lavoratore, elenco_lavoratori[y].nome_lavoratore) == 0){
                    cout << "Non si possono inizializzare due lavoratori con lo stesso nome!\n";
                    return false;  
                }
            }
        }
    }
    
    // metto l'array di bool a false, che vuol dire che sono tutti in riposo. 
    for (int i = 0; i < giorni_sett; i++){
        elenco_lavoratori[i].turni[i] = false; 
    }
    return true; 
}

void stampa_turni(lavoratore_t *&elenco_lavoratori, int&num_lavoratori){
    cout << "LMMGVSD \n"; 
    for (int i = 0; i < num_lavoratori; i++){
        for(int j = 0; j < giorni_sett; j++){
            if(elenco_lavoratori[i].turni[j] == false){
                cout << "_"; 
            }
            else{
                cout << "*";
            }
        }
        cout << "\t" << elenco_lavoratori[i].nome_lavoratore; 
        cout << endl; 
    }
    cout << endl; 
}

int trova_indice(lavoratore_t *&elenco_lavoratori, int &num_lavoratori, char trova_lavoratore[ ]){
    // scorro tutto l'array dei nomi dei lavoratori se ne trovo uno che combacia con la stringa trova_lavoratore, allora ritorna la sua posizione.  
    for(int i = 0; i < num_lavoratori; i++){
        if(strcmp(elenco_lavoratori[i].nome_lavoratore, trova_lavoratore) == 0){
            return i; 
        } 
    }
    cout << "Il lavoratore non è presente!\n"; 
    return -1; 
}

void aggiorna_turni(lavoratore_t *&elenco_lavoratori, int &num_lavoratori, char agg_turni[], int &index){
    // trovo il lavoratore di indice 'index', poi nell'array dei suoi turni lo metto a true se è di turno, oppure false se è a riposo. 
    for(int i = 0; i < giorni_sett; i++){
        if(agg_turni[i] == '*'){
            elenco_lavoratori[index].turni[i] = true;         
        }
        else{
            elenco_lavoratori[index].turni[i] = false; 
        }
    }
}

void salva_turni(ofstream &file_turni, lavoratore_t *&elenco_lavoratori, int & num_lavoratori){
    file_turni << "LMMGVSD \n"; 
    for (int i = 0; i < num_lavoratori; i++){
        for(int j = 0; j < giorni_sett; j++){
            if(elenco_lavoratori[i].turni[j] == false){
                file_turni << "_"; 
            }
            else{
                file_turni << "*";
            }
        }
        file_turni << "\t" << elenco_lavoratori[i].nome_lavoratore; 
        file_turni << endl; 
    }
    file_turni << endl; 
} 

/*void carica_turni(ifstream &leggi_turni, lavoratore_t *&elenco_lavoratori, int &num_lavoratori){
    char iniziali[giorni_sett]; 
    leggi_turni>>iniziali; 
    for(int j = 0; j < num_lavoratori; j++){
        for(int i = 0; i < giorni_sett; i++){
            char c; 
            if(leggi_turni.get(c)){
                if(c == '*'){
                    elenco_lavoratori[j].turni[i] = true; 
                }
                else{
                    elenco_lavoratori[j].turni[i] = false; 
                }
            }
        }
        leggi_turni>>elenco_lavoratori[j].nome_lavoratore; 
    }
}*/
    


int main()
{

    int index; 
    // chiedo in input il numero dei lavoratori.
    int num_lavoratori;

    cout << "Inserire numero lavoratori: \n"; 
    cin>>num_lavoratori; 

    // alloco un array di struct di tipo lavoratore di dimensione num_lavoratori. 
    lavoratore_t *elenco_lavoratori = new lavoratore_t [num_lavoratori]; 

	const char menu[] =
		"1. Inizializza elenco\n"
		"2. Stampa turni\n"
		"3. Trova indice\n"
		"4. Aggiorna turni\n"
		"5. Salva turni\n"
		"6. Carica turni\n"
		"7. Minimizza turni\n"
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
            
            if(!inizializza_elenco(elenco_lavoratori, num_lavoratori)){
                return 0; 
            }
			break;
        }    
		case 2:
        {
            stampa_turni(elenco_lavoratori, num_lavoratori); 
            break;
        }
		case 3:
        {
            cout << "Controlla se lavoratore è presente: \n"; 
            cin>>trova_lavoratore; 
            index = trova_indice(elenco_lavoratori, num_lavoratori, trova_lavoratore); 
            break;
        }
		case 4:
        {
            // prendo in input i turni dei lavoratori aggiornati e li passo alla funzione aggiorna turni.
            bool input_valido;
            do {
                input_valido = true;
                cout << "Inserisci i turni aggiornati del lavoratore: \n";
                for (int i = 0; i < giorni_sett; i++) {
                    cin >> agg_turni[i];
                    if (agg_turni[i] != '*' && agg_turni[i] != '_') {
                        input_valido = false;
                    }
                }
                agg_turni[i] = '\0'; 
            } while (!input_valido);
            aggiorna_turni(elenco_lavoratori, num_lavoratori, agg_turni, index);
            break;
        }	
		case 5:
        {
            // devo scrivere su un file di testo. ù
            ofstream file_turni; 
            file_turni.open("turni.txt"); 
            if(!file_turni){
                cerr << "Errore! Impossibile effettuare la scrittura su file! \n"; 
                return 1; 
            }
            salva_turni(file_turni, elenco_lavoratori, num_lavoratori);
            cout << "Turni salvati con successo!\n"; 
            file_turni.close();  
            break;
        }
		case 6:
        {
            /*ifstream leggi_turni; 
            leggi_turni.open("turni.txt"); 
            if(!leggi_turni){
                cerr << "Errore! Impossibile aprire il file in lettura!"; 
                return 1; 
            }
            carica_turni(leggi_turni, elenco_lavoratori, num_lavoratori); 
            leggi_turni.close(); 
            break;*/
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