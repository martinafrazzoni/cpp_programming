#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

struct players_t{
    char* combattenti; // puntato ad un array di caratteri che ha dimensione N. 
    bool turno; // booleano per sapere quale giocatore è di turno. 
    int turni_rimasti; // variabile che mi conta i turni rimasti per ogni giocatore. 
}; 

struct partita_t {
    players_t giocatore[2]; 
    int N; // numero di combattenti per ciasucn giocatore
}; 

void inizializza_gioco(partita_t &partita){
    // all'inizio i combattenti di entrambui i giocatori sono pari a 0. 
    partita.N = 0; 
    partita.giocatore[0].combattenti = new char [partita.N]; 
    partita.giocatore[1].combattenti = new char [partita.N]; 
}

void inizia_partita(partita_t &partita, int &n){
    if(n != partita.N){
        delete [] partita.giocatore[0].combattenti; 
        delete [] partita.giocatore[1].combattenti;
        partita.N = n; 
    }

    // se il numero di combattenti è > 0 allora il g.1 è di turno. 
    if(partita.N > 0){
        partita.giocatore[0].turno = true; 
        partita.giocatore[1].turno = false; 
    }

    // inizializziamo i turni rimasti per ogni giocatore. 
    partita.giocatore[0].turni_rimasti = partita.N; 
    partita.giocatore[1].turni_rimasti = partita.N; 

    // allochiamo due array con le dimensioni partita.N
    partita.giocatore[0].combattenti = new char [partita.N]; 
    partita.giocatore[1].combattenti = new char [partita.N]; 

    // inizializziamo 
    for(int i = 0; i < partita.N; i++){
        partita.giocatore[0].combattenti[i] = '*'; 
        partita.giocatore[1].combattenti[i] = '*'; 
    }
}

void stampa_stato(partita_t &partita){
    // stampiamo i combattenti e il numero di turni rimasti
    //STATPO GIOCATORE 0
    for(int i = 0; i < partita.N; i++){
        cout << partita.giocatore[0].combattenti[i]; 
    }
    if(partita.giocatore[0].turno == true){
        cout << " <" << partita.giocatore[0].turni_rimasti << "> " << endl; 
    }
    else{
        cout << " " << partita.giocatore[0].turni_rimasti << endl; 
    }

    // STATO GIOCATORE 1
    for(int i = 0; i < partita.N; i++ ){
        cout << partita.giocatore[1].combattenti[i]; 
    }
    if(partita.giocatore[1].turno == true){
        cout << " <" << partita.giocatore[1].turni_rimasti << "> " << endl; 
    }
    else{
        cout << " "<< partita.giocatore[1].turni_rimasti << endl; 
    }
}

bool elimina_combattente(partita_t &partita, int f, int &i){
    // calcoliamo il valore di c = (i^N)%N
    int pot = pow(i, partita.N); 
    int c = pot % partita.N; 
    if(c > partita.N){
        cout << "Posizione non valida!\n"; 
        return false; 
    }
    if(partita.giocatore[f].combattenti[c] == '*'){
        partita.giocatore[f].combattenti[c] = '-'; 
    }
    return true; 
}

void esegui_turno(partita_t &partita){
    // controllo se i turni sono finiti per entrambi
    int combat_g_0 = 0, combat_g_1 = 0; 
    //do{
        if(partita.giocatore[0].turni_rimasti == 0 && partita.giocatore[1].turni_rimasti == 0){
            cout << "PARTITA FINITA!\n"; 
            return;
        }
        if(partita.giocatore[0].turno == true){
            int pos; 
            do{
                cout << "Inserisci posizione del giocatore 1 da eliminare: \n"; 
                cin>>pos; 
            } while (pos < 0 || pos > partita.N);
            elimina_combattente(partita, 1, pos); 
            if(partita.giocatore[0].turni_rimasti > 0){
                partita.giocatore[0].turni_rimasti--;
                partita.giocatore[1].turno = true; 
                partita.giocatore[0].turno = false; 
            }
        }
        else if(partita.giocatore[1].turno == true){
            int pos; 
            do
            {
                cout << "Inserisci posizione del giocatore 0 da eliminare: \n"; 
                cin>>pos; 
            } while (pos < 0 || pos > partita.N);
            elimina_combattente(partita, 0, pos); 
            if(partita.giocatore[1].turni_rimasti > 0){
                partita.giocatore[1].turni_rimasti--; 
                partita.giocatore[0].turno = true; 
                partita.giocatore[1].turno = false; 
            }
        }
    //}while(true); 
    
    for (int i = 0; i < partita.N; i++){
        if(partita.giocatore[1].combattenti[i] == '-'){
            combat_g_0 ++; 
        }
    }

    for(int i = 0; i < partita.N; i++){
        if(partita.giocatore[0].combattenti[i] == '-'){
            combat_g_1 ++; 
        }
    }
    if(partita.giocatore[0].turni_rimasti == 0 && partita.giocatore[1].turni_rimasti == 0){
        // controlliamo chi ha vinto
        if(combat_g_0 > combat_g_1){
            cout << "VINCE 0 \n"; 
            return;  
        }
        else if(combat_g_1 > combat_g_0){
            cout << "VINCE 1 \n";
            return; 
        }
        else{
            cout << "PAREGGIO" << endl;
            return;  
        }
    }
}

bool salva_partita(ofstream &file_partita, partita_t &partita){
    if(file_partita.fail()){
        cout << "Errore nella apertura del file!\n"; 
        return false; 
    }
    file_partita << partita.N << endl; 
    //STATO GIOCATORE 0
    for(int i = 0; i < partita.N; i++){
        file_partita << partita.giocatore[0].combattenti[i]; 
    }
    file_partita << '\0' << endl; 
    if(partita.giocatore[0].turno == true){
        file_partita << " <" << partita.giocatore[0].turni_rimasti << "> " << endl; 
    }
    else{
        file_partita << " " << partita.giocatore[0].turni_rimasti << endl; 
    }
    
    // STATO GIOCATORE 1
    for(int i = 0; i < partita.N; i++ ){
        file_partita << partita.giocatore[1].combattenti[i]; 
    }
    file_partita << '\0' << endl; 
    if(partita.giocatore[1].turno == true){
        file_partita << " <" << partita.giocatore[1].turni_rimasti << "> " << endl; 
    }
    else{
        file_partita << " "<< partita.giocatore[1].turni_rimasti << endl; 
    }
    return true; 
}

bool carica_partita(ifstream &leggi_partita, partita_t &partita){
    // dealloco i due array di combattenti esistenti
    delete[] partita.giocatore[0].combattenti; 
    delete[] partita.giocatore[1].combattenti; 

    // setto a zero i turni rimasti per ogni giocatore
    partita.giocatore[0].turni_rimasti = 0;
    partita.giocatore[1].turni_rimasti = 0;

    // leggo il numero di combattenti da file
    leggi_partita >> partita.N; 
    //cout << "Combattenti file: " << partita.N << endl; 

    // alloco i due array di combattenti con le dimensioni lette da file
    partita.giocatore[0].combattenti = new char [partita.N]; 
    partita.giocatore[1].combattenti = new char [partita.N]; 

    if(leggi_partita.fail()){
        cerr << "Errore nell'apertura del file!\n"; 
        return false; 
    }

    //LEGGO DATI DEL G_0
    //leggo i combattenti da file per ciasucn giocatore
    for(int i = 0; i < (partita.N + 1); i++){
        leggi_partita>>partita.giocatore[0].combattenti[i]; 
    }

    //poi adesso devo leggere se il giocatore è di turno
    char turnog0[10]; 
    leggi_partita >> turnog0;
    int lunghg0 = strlen(turnog0); 
    for (int i = 0; i < lunghg0; i++){
        if(turnog0[i]  == '<'){
            partita.giocatore[0].turno = true; 
            partita.giocatore[1].turno = false; 
        }
        else{
            partita.giocatore[1].turno = true; 
            partita.giocatore[0].turno = false;
        }
    }
    for (int i = 0; i < lunghg0; i++){
        if(isdigit(turnog0[i]) != 0){
            int turno_0 = turnog0[i] - '0'; 
            partita.giocatore[0].turni_rimasti = turno_0; 
            break;
        }
    }

    //LEGGO DATI DEL G_1
    //leggo i combattenti da file per ciasucn giocatore
    for(int i = 0; i < (partita.N + 1); i++){
        leggi_partita>>partita.giocatore[1].combattenti[i]; 
    }

    //poi adesso devo leggere se il giocatore è di turno
    char turnog1[10]; 
    leggi_partita >> turnog1;
    int lunghg1 = strlen(turnog1); 
    for (int i = 0; i < lunghg1; i++){
        if(turnog1[i]  == '<'){
            partita.giocatore[1].turno = true; 
            partita.giocatore[0].turno = false; 
        }
        else{
            partita.giocatore[0].turno = true; 
            partita.giocatore[1].turno = false;
        }
    }
    for (int i = 0; i < lunghg1; i++){
        if(isdigit(turnog1[i]) != 0){
            int turno_1 = turnog1[i] - '0'; 
            partita.giocatore[1].turni_rimasti = turno_1; 
            break;
        }
    }
    return true; 
}

void sposta_combattenti(partita_t &partita, int&f, int&s){
    //devo spostare uno alla volta i combattenti della fila f partendo da quello in posizione più alta (presumo il primo) fino a quello in posizione più bassa (l'ultimo). 
    //quindi ho bisogno di un ciclo che mi scorra tutto l'array di combattenti. 
    // devo spostarmi in avanti di due posizioni.
    // se parto dall'inizio sono in posizione 0 e poi mi sposto di due posizioni in avanti, quindi arrivo in posizione 2.
    // se parto da posizione 1, mi sposto di due posizioni in avanti e arrivo in posizione 3. 
    //etc. 
    
    for (int i = partita.N -1; i >= 0; i--)
    {   //sposta i combattenti di s posizioni se le prossime s posizoni sono libere
        if(i>=s && partita.giocatore[0].combattenti[i-1] == '-' && partita.giocatore[0].combattenti[i-2] == '-'){
            partita.giocatore[0].combattenti[i] = partita.giocatore[0].combattenti[i-s];
            partita.giocatore[0].combattenti[i-s] = '*'; 
        }
    }

    // sposto i combattenti nella posizione più alta possibile se le prossime s posizioni non sono libere
    for(int i = partita.N -1; i >= 0; i--){
        if(partita.giocatore[0].combattenti[i] == '-'){
            int j = i -1; 
            while(j>=0 && partita.giocatore[0].combattenti[j] == '-'){
                j--; 
            }
            if(j>=0){
                partita.giocatore[0].combattenti[i] = partita.giocatore[0].combattenti[j]; 
                partita.giocatore[0].combattenti[j] = '-'; 
            }
        }
    }
    
}

//function explaination by copilot. 
/*Sure, here's an example of how the function moves the toy soldiers when the next s positions are not empty:

Let's say we have a row of toy soldiers like this:

* * - * * - - - * *
We want to move the toy soldiers in row 1 (the second row) by 2 positions. So we call the function like this:

sposta_combattenti(partita, 1, 2);

The function starts by checking if the next 2 positions in the row are empty. In this case, they are not, because the third and fourth positions are occupied by toy soldiers. So the function looks for the nearest empty position to the left of the toy soldiers.

The nearest empty position to the left of the toy soldiers is the second position, so the function moves the toy soldiers to that position. The row of toy soldiers now looks like this:

* - * * * - - - * *

The function then moves on to the next pair of toy soldiers in the row (the fifth and sixth positions). Again, the next 2 positions are not empty, so the function looks for the nearest empty position to the left of the toy soldiers. */

int main()
{
    partita_t partita;
    int n, f, i, s;  
    inizializza_gioco(partita); 

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
            cout << "Numero di combattenti per ogni colonna: \n"; 
            cin>>n;
            inizia_partita(partita, n); 
            break;
        }
		case 2:
        {
            stampa_stato(partita); 
            break;
        }
		case 3:
        {
            cout << "Fila e  posizione del combattente da eliminare: \n"; 
            cin>>f>>i; 
            if((f > 2 || f < 0) || (i > partita.N || i < 0)){
                break;
            }
            if(elimina_combattente(partita, f, i)){
                cout << "Combattente eliminato correttamente!\n"; 
            } 
            break;
        }
		case 4:
        {
            esegui_turno(partita); 
            break;
        }
		case 5:
        {
            //creo un file di testo dove salvarci lo stato attuale della partita
            ofstream file_partita;
            file_partita.open("partita.txt"); 
            if(!file_partita){
                cerr << "Errore! Impossibile aprire il file in scrittura!\n"; 
                return 1; 
            }
            if(salva_partita(file_partita, partita)){
                cout << "Partita salvata su file\n"; 
            } 
            file_partita.close(); 
            break;
        }
		case 6:
        {
            ifstream leggi_partita; 
            leggi_partita.open("partita.txt"); 
            if(!leggi_partita){
                cerr << "Errore! Impossibile aprire il file in lettura!\n";
                return 1; 
            }
            if(carica_partita(leggi_partita, partita)){
                cout << "Partita caricata correttamente !\n"; 
            }
            leggi_partita.close(); 
            break;
        }
		case 7:{
            cout << "Fila: "; 
            cin>>f; 
            cout << "Posizioni: "; 
            cin>>s; 
            sposta_combattenti(partita, f, s); 
            break;
        }
		case 8:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}



