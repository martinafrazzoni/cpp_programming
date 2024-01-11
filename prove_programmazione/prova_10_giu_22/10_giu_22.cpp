#include <iostream>
#include <fstream>
using namespace std;

// devo allocare una matrice dinamica di interi di dimensioni nulle
int** crea_matrice(int righe, int colonne){
    int** matrice; // indirizzo in memoria della matrice dinamica. 
	matrice = new int*[righe]; 
	for (int i = 0; i < righe; i++){
	matrice[i] = new int[colonne];
	}
	return matrice; 
}

void inizializza_matrice(int**&matrice, int&righe, int&colonne){
    for(int i = 0; i < righe; i++){
        for (int j = 0; j < colonne; j++){
            matrice[i][j] = 0; 
        }
    }
}

void aggiungi_valore(int **&matrice, int&righe, int&colonne, int&val){
    int a = matrice[righe][colonne]; 
    //cout << "a: " << a << endl; 
    int num = (a+val); 
    //cout << "num: " << num << endl;
    if(num > 3){
        matrice[righe][colonne] = a;
       //cout << "contenuto coordinate:  " << matrice[righe][colonne] << endl;
    }
    else{
        matrice[righe][colonne] = num; 
        //cout << "contenuto coordinate:  " << matrice[righe][colonne] << endl;
    }
}

void stampa_matrice(int**&matrice, int&righe, int&colonne){
    char caratteri[] = {'o', '-', '+', '*'}; 
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            int indice = matrice[i][j]; 
            cout << caratteri[indice]; 
            /*Certo! Nell'esempio che ti ho fornito, la funzione `stampa_matrice` utilizza un array di caratteri `caratteri` per memorizzare i caratteri corrispondenti a ogni valore della matrice. 

            Ad esempio, se la matrice contiene il valore `0`, la funzione stampa il carattere `"o"`. Se la matrice contiene il valore `1`, la funzione stampa il carattere `"-"`. E così via.

            La funzione `std::cout` viene utilizzata per stampare ogni elemento della matrice come un carattere. La funzione `matrice[i][j]` restituisce l'elemento della matrice corrente, che viene utilizzato come indice nell'array `caratteri` per ottenere il carattere corrispondente.

            Spero che questo ti sia stato utile! Se hai altre domande o dubbi, non esitare a chiedere.*/
        }
        cout << endl; 
    }
}

void salva_matrice(ofstream &scrivi_matrice, int**&matrice, int&righe, int&colonne){
    scrivi_matrice << righe << " " << colonne << endl; 
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            scrivi_matrice << matrice[i][j] << " "; 
        }
        scrivi_matrice << endl; 
    }
}


bool carica_matrice(ifstream &leggi_matrice, int**&matrice, int&righe, int&colonne){
    // primo passo è deallocare la matrice vecchia. 
    for(int i = 0; i < righe; i++){
        delete[] matrice[i]; 
    }
    delete[] matrice; 

    //leggo le nuove dimensioni della matrice e ne rialloco un'altra di queste dimensioni. 
    leggi_matrice>>righe>>colonne; 
    //cout << "Num righe matrice file: " << righe << endl;
    matrice = crea_matrice(righe, colonne); 
    //cout << "Num colonne matrice file: " << colonne << endl; 
    
    if(!leggi_matrice){
        cout << "Errore nella lettura da file!\n"; 
        return false; 
    }

    for(int i = 0; i < righe; i++){
        for (int j = 0; j < colonne; j++){
            leggi_matrice >> matrice[i][j]; 
        }
        cout << endl; 
    }   
    return true; 
}

void trova_indice_riga(int**&matrice, int&righe, int&colonne){
    int conta_pos = 0, riga_corrente = 0; 
    int i; 
    int* array_indici = new int [righe]; 
    for(i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(matrice[i][j] > 0){
                conta_pos++; 
            }
        }
        array_indici[riga_corrente] = conta_pos; 
        conta_pos = 0; 
        riga_corrente++; 
    }

    int min_index = 0; 
    int max = array_indici[0]; 
    for (int i = 0; i < righe; i++){
        if(array_indici[i] > max){
            max = array_indici[i];
            min_index = i;  
        }
    } 
    cout << min_index << endl; 
    
}

int main()
{
    int** matrice = crea_matrice(0, 0);
    int N;  
	const char menu[] =
		"1. Inizializza matrice\n"
		"2. Aggiungi valore\n"
		"3. Stampa matrice\n"
		"4. Salva matrice\n"
		"5. Carica matrice\n"
		"6. Trova indice riga\n"
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
            cout << "Inserisci le dimensioni di N: \n"; 
            cin>>N; 
            matrice = crea_matrice(N, N); 
            inizializza_matrice(matrice, N, N); 
            break;
        }
		case 2:
        {
            int i, j, n;
            
            cout << "Inserisci il valore naturale n: \n"; 
            cin>>n; 

            cout << "Inserisci le coordinate dove vuoi aggiungere il valore (righe, colonne): \n"; 
            cin>>i>>j;

            if(((i < 0 || i > N-1)|| (j < 0 || j > N-1)) || (n < 0 || n > 3)){
                break;
            } 
            aggiungi_valore(matrice, i, j, n); 
            break;
        }
		case 3:
        {
            stampa_matrice(matrice, N, N); 
            break;   
        }
		case 4:
        {
            ofstream scrivi_matrice; 
            scrivi_matrice.open("matrice.txt");
            if(!scrivi_matrice){
                cerr << "Errore! Impossibile aprire il file in scrittura!"; 
                return 1; 
            } 
            salva_matrice(scrivi_matrice, matrice, N, N); 
            scrivi_matrice.close(); 
            break;
        }
		case 5:
        {
            ifstream leggi_matrice; 
            leggi_matrice.open("matrice.txt"); 
            if(!leggi_matrice){
                cerr << "Errore ! Impossibile aprire il file in lettura!"; 
                return 1; 
            }
            if(carica_matrice(leggi_matrice, matrice, N, N)){
                cout << "Caricamento avvenuto con successo!\n"; 
            } 
            leggi_matrice.close(); 
            break;
        }
		case 6:
            trova_indice_riga(matrice, N, N); 
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}