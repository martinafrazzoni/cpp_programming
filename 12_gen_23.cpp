#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

struct partita_info {
    char*giocatore_1; 
    char*giocatore_2; 
    int turno;
    int n; 
    
    int conta_turni_1 = n; 
    int conta_turni_2 = n; 
}; 

void inizializza_gioco(partita_info &p){
    // all'inizio i giocatori 1 e 2 contengono 0 combattenti. 
    p.n = 0; 
    p.giocatore_1 = new char [p.n]; 
}

void inizia_partita(partita_info &p, int &N){

    if(N != p.n){
        delete[] p.giocatore_1; 
        delete[] p.giocatore_2; 
        //p.giocatore_1 = new char[N];
        //p.giocatore_2 = new char[N]; 
        p.n = N; 
    }

    if(p.n > 0){
        p.turno = 1; 
    }
    p.giocatore_1 = new char [p.n]; 
    p.giocatore_2 = new char [p.n]; 
    // inizializzo la fila di combattenti del giocatore_1
    for (int i = 0; i < p.n; i++){
        p.giocatore_1[i] = '*'; 
    }
    cout << endl; 
    // inizializzo la fila di combattenti del giocatore_2
    for (int j = 0; j < p.n; j++){
        p.giocatore_2[j] = '*'; 
    }
}

void stampa_stato(partita_info &p){

    // stampiamo lo stato della partita. 
    for (int i = 0; i < p.n; i++){
        cout << p.giocatore_1[i] << " "; 
    }
    if(p.turno == 1){
        cout << "<" << p.conta_turni_1 << ">"; 
    }
    else
        cout << p.conta_turni_1; 
    cout << endl; 

    for (int j = 0; j < p.n; j++){
        cout << p.giocatore_2[j] << " "; 
    }
    if(p.turno == 2){
        cout << "<" << p.conta_turni_2 << ">"; 
    }
    else
        cout << p.conta_turni_2 << endl; 
    cout << endl; 

}

void elimina_combattente(int f, int &i, partita_info &p){ 
    int elev = pow(i, p.n); 
    int c = elev % p.n; 
    cout << "c vale: " << c << endl; 
    switch (f){
        case 0:
        {
            if(p.giocatore_1[c] == '*'){
                p.giocatore_1[c] = '-'; 
            }
            break;
        }
        case 1: 
        {
            if(p.giocatore_2[c] == '*'){
                p.giocatore_2[c] = '-'; 
            }
            break;
        }   
        default:
            break;
    }
}


void esegui_turno (partita_info&p){
    int conta_combat_1 = 0; 
    int conta_combat_2 = 0; 
    if(p.conta_turni_1 == 0 || p.conta_turni_2 == 0){
        for (int i = 0; i < p.n; i++){
            if (p.giocatore_1[i] == '*'){
                conta_combat_1++; 
            }
        }

        for (int i = 0; i < p.n; i++){
            if (p.giocatore_2[i] == '*'){
                conta_combat_2++; 
            }
        }
        if (conta_combat_2 > conta_combat_1) {
            cout << "Ha vinto il giocatore 2!\n";
        } else if (conta_combat_1 > conta_combat_2) {
            cout << "Ha vinto il giocatore 1!\n";
        } else {
            cout << "La partita è finita in pareggio!\n";
        }
    }
    else if(p.turno == 1){
        cout << "Sta giocando il giocatore 1: \n"; 
        int pos; 
        do{
            cout << "Inserisci posizione del giocatore da eliminare\n";
            cin>>pos; 
        }
        while(pos < 0 || pos > p.n); 
        elimina_combattente(1, pos, p); // 1 è la fila. 
        // controllo se il turno dell'ultimo giocatore non è l'ultimo.
        if(p.conta_turni_1 > 0){
            p.conta_turni_1--; 
            p.turno = 2; 
        }
    }
	else if(p.turno == 2 ){
		// altrimentii è il turno del giocatore 2. 
        cout << "Sta giocando il giocatore 2: \n"; 
	    int pos; 
	    do{
		    cout << "Inserisci posizione del giocatore da eliminare\n"; 
		    cin>>pos; 
	    }
	    while(pos < 0 || pos > p.n); 
	    elimina_combattente(0, pos, p); 
	    // controllo se il turno dell'ultimo giocatore non è l'ultimo.
	    if(p.conta_turni_2>0){
		    p.conta_turni_2--; 
		    p.turno = 1;  
	    }
    }
}   


void salva_partita(ofstream &file_turni, partita_info &p){
    for (int i = 0; i < p.n; i++){
        file_turni << p.giocatore_1[i] << " "; 
    }
    if(p.turno == 1){
        file_turni << "<" << p.conta_turni_1 << ">"; 
    }
    else
        file_turni << p.conta_turni_1; 
    file_turni << endl; 

    for (int j = 0; j < p.n; j++){
        file_turni << p.giocatore_2[j] << " "; 
    }
    if(p.turno == 2){
        file_turni << "<" << p.conta_turni_2 << ">"; 
    }
    else
        file_turni << p.conta_turni_2 << endl; 
    file_turni << endl; 
}

void carica_partita(ifstream &file_turni_lett, partita_info &p){

    
}

/*void sposta_combattenti(int &fila, int&s, partita_info&p){
    // NON DEL TUTTO IMPLEMENTATA
    
    // guardo la fila che è stata scelta
    switch (fila){
    case 0:
        {
            int pos_corrente = 0;  
            int index = 0; 
            const int dim_pos_libere = 50;   
            int pos_libere [dim_pos_libere]; // array che contiene gli indici delle posizioni libere. 
            // scorro l'array partendo dalla testa e poi ho un altro ciclo che parte da i+1
            for (pos_corrente = pos_corrente + 1; pos_corrente + s < p.n; pos_corrente ++){
                    if (p.giocatore_1[pos_corrente] == '-'){
                        pos_libere[index] = pos_corrente;  
                        index++; 
                }
            }
            cout << "Il numero totale di posizioni libere nell'array è: " << index << endl; 
            int pos; 
            // ho messo l'indice delle posizioni correnti dentro un array. per ogni posizione libera guardo se c'è un combattente dentro l'array e lo sposto. 
            for (int i = 0; i < index ; i++){
                pos = pos_libere[i]; 
                for (int pos_corrente = pos - 1; pos_corrente >= 0; pos_corrente--){
                    if(p.giocatore_1[pos_corrente] == '*'){
                        p.giocatore_1[pos] = '*'; 
                        p.giocatore_1[pos_corrente] = '-'; 
                        break;
                    }
                }
            }
            break;
        }
    default:
    {    
        cout << "Errore!"; 
        break;
    }
    }
}*/

int main()
{
    partita_info p; 
    int f, i, N; 

    inizializza_gioco(p); 
	
    const char menu[] =
		"1. Inizia gioco\n"
		"2. Stampa stato partita\n"
		"3. Elimina combattente\n"
		"4. Esegui turno\n"
		"5. Salva stato partita\n"
		"6. Carica stato partita\n"
		"7. Sposta combattenti\n"
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
            // chiedo il numero di combattenti
            do{
                cout << "Inserisci il numero di combattenti per entrambi i giocatori: \n"; 
                cin>>N; 
                if(N < 0){
                    cout << "Il numero di combattenti deve essere maggiore di 0!"; 
                }
            }
            while(N< 0); 
            // inizializzo i conta turni. 
            p.conta_turni_1 = N; 
            p.conta_turni_2 = N; 
            inizia_partita(p, N); 
            break;
        }
		case 2:
        {
            stampa_stato(p); 
            break;
        }
		case 3:
        {
            do{
                cout << "Inserisci la fila da cui vuoi eliminare il giocatore: \n"; 
                cin>>f; 
            }
            while(f < 0 || f > 1); 
            
            do
            {
                cout << "Inserisci la posizione in cui eliminare il giocatore: \n"; 
                cin>>i; 
            } while (i < 0 || i > p.n);
            elimina_combattente(f, i, p); 
            break;
        }
		case 4:
        {
            esegui_turno(p); 
            break;
        }
		case 5:
        {
            ofstream file_turni; 
            file_turni.open("file_partita.txt"); 
            if(!file_turni){
                cerr << "Errore! Impossibile aprire il file in scrittura!"; 
                return 1; 
            }
            salva_partita(file_turni, p); 
            file_turni.close(); 
            break;
        }
		case 6:
        {
            ifstream file_turni_lett; 
            file_turni_lett.open("file_partita.txt"); 
            if(!file_turni_lett){
                cerr << "Errore! Impossibile aprire il file in lettura!"; 
                return 1; 
            }
            carica_partita(file_turni_lett, p);
            file_turni_lett.close(); 
            break;
        }
			
		case 7:
        /*{
            int fila, s; 
            do{
                cout << "Inserisci la fila: \n";
                cin>>fila; 
            }
            while(fila > 0 || fila > 1); 

            do{
                cout << "Di quante posizioni vuoi spostare i combattenti: \n"; 
                cin>>s; 
            }
            while(s < 0 && s > p.n); 
            sposta_combattenti(fila, s, p); 
            break;
        }*/

		case 8:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}