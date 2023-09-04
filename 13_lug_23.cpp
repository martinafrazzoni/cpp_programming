#include <iostream>
#include <fstream>
using namespace std;

//creo la struct con le coppie di posizioni di ogni elemento del codice a barre. 
struct elemento{
    char pos_sx; 
    char pos_dx; 
}; 


elemento** crea_etichetta(int&righe, const int&col){
    elemento** etichetta; // contiene l'indirizzo dell'etichetta. 

    // array di puntatori che mi contiene i puntatori alle righe. 
    etichetta = new elemento* [righe]; 
    for (int i = 0; i < righe; i++){
        etichetta[i] = new elemento [col]; 
    }
    return etichetta; 
}

void dealloca_etichetta(elemento **&etichetta, int&righe){
    for (int i = 0; i < righe; i++){
        delete[] etichetta[i]; 
    }
    delete[] etichetta; 
}

int inizializza_etichetta(elemento bar_code[ ], const int&col, elemento **&etichetta, int&righe){ 
    int r = 0; 
    while(r < righe){ 
        for (int i = 0; i < col; i++){
            do{
            cout << "Inizializza codice a barre: '|' o '.' \n"; 
            cin>>bar_code[i].pos_sx; 
            cin>>bar_code[i].pos_dx; 
            }
            while((bar_code[i].pos_dx != '|' && bar_code[i].pos_dx != '.') || (bar_code[i].pos_sx != '|' && bar_code[i].pos_sx != '.')); 
        }

        // abbiamo inizializzato l'array di struct a contenere . |, ma non sappiamo se la sequenza è corretta. Quindi per ogni elemento devo verificare che ci sia almeno un punto e una barra. Se non è inizializzato correttamente conterrà soltanto barre a sx. 

        bool inizializzato_correttamente = true; 

        for (int i = 0; i < col; i++){
            if((bar_code[i].pos_dx == '|' && bar_code[i].pos_sx == '|') || 
                (bar_code[i].pos_dx == '.' && bar_code[i].pos_sx == '.')){
                cout << "Il codice a barre non è inizializzato correttamente\n"; 
                inizializzato_correttamente = false; 
                break; 
            }
        }

        if (!inizializzato_correttamente){
            for (int i = 0; i < col; i++){
                etichetta[r][i].pos_sx = '|';
                etichetta[r][i].pos_dx = '.';           
            }
            cout << "Riga " << r << " della matrice inizializzata con le barre tutte a sinistra!\n"; 
        }

        if (inizializzato_correttamente){
            for(int i = 0; i < col; i++){
                etichetta[r][i] = bar_code[i]; 
            }
            cout << "Riga " << r << " della matrice inizializzata correttamente\n"; 

        }
        r++; 
    }
    return 0; 
}

void stampa_etichette(elemento **&etichetta, const int&col, int&righe){
    for (int i = 0; i < righe; i++){
        for (int j = 0; j < col; j++){
            cout << j << "   "; 
        }
        cout << '\t'; 
    }
    cout << endl; 

    for (int i = 0; i < righe; i++){
        for (int j = 0; j < col; j++){
            cout << etichetta[i][j].pos_dx << " " << etichetta[i][j].pos_sx << " "; 
        }
        cout << '\t'; 
    }
    cout << endl; 
}

void salva_etichetta(ofstream &file_etichetta, elemento **& etichetta, const int&col, int&righe){
    // scrivo su file il numero di righe e di colonne
    file_etichetta.write(reinterpret_cast<char*>(&righe), sizeof(righe)); 
    file_etichetta.write(reinterpret_cast<const char*>(&col), sizeof(col)); 
    
    // scrivo la matrice su file
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < col; j++){
            file_etichetta.write(reinterpret_cast<char*>(&etichetta[i][j]), sizeof(etichetta[i][j])); 
        }
    }

}

void carica_etichetta(ifstream &file_etichetta_lett, elemento **&etichetta, const int&col, int&righe){
    int temp_col = col; 
    
    file_etichetta_lett.read(reinterpret_cast<char*>(&righe), sizeof(righe)); 
    file_etichetta_lett.read(reinterpret_cast<char*>(&temp_col), sizeof(temp_col));


    // leggo il contenuto del file già direttamente dentro gli elementi della matrice.
    for (int i = 0; i < righe; i++){
        for (int j = 0; j < temp_col; j++){
            file_etichetta_lett.read(reinterpret_cast<char*>(&etichetta[i][j]), sizeof(etichetta[i][j])); 
        }
    } 
    stampa_etichette(etichetta, temp_col, righe); 
}

int main()
{    
    int righe; 
    const int col = 8; 
    // creo l'array che mi contiene le posizioni destra e sinistra. 
    elemento bar_code [col];
    elemento**etichetta; 

	const char menu[] =
		"1. Inizializza eitchetta\n"
		"2. Stampa etichetta\n"
		"3. Salva etichetta\n"
		"4. Carica etichetta\n"
		"5. Inizializza etichetta2\n"
		"6. Stampa etichetta2\n"
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
            dealloca_etichetta(etichetta, righe); 
            cout << "Inserisci il numero di codici a barre: \n"; 
            cin>>righe;

            etichetta = crea_etichetta(righe, col);
            inizializza_etichetta(bar_code, col, etichetta, righe); 
            break;
        }
		case 2:
        {
            stampa_etichette(etichetta, col, righe); 
            break;
        }
		case 3:
        {
            // devo creare il file di testo dove andare a scrivere la matrice. 
            ofstream file_etichetta; 
            file_etichetta.open("etichetta.dat"); 
            if(! file_etichetta){
                cerr << "Errore! impossibile aprire il file in scrittura\n"; 
                return 1; 
            }
            salva_etichetta(file_etichetta, etichetta, col, righe); 
            file_etichetta.close(); 
            break;
        }
		case 4:
        {
            ifstream file_etichetta_lett; 
            file_etichetta_lett.open("etichetta.dat"); 
            if (!file_etichetta_lett){
                cerr << "Errore! impossibile aprire il file in scrittura\n"; 
                return 1; 
            }
            carica_etichetta(file_etichetta_lett, etichetta, col, righe);
            file_etichetta_lett.close();  
            break;
        }
			
		case 5:
			break;
		case 6:
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}