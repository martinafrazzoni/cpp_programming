/*scrivere un programma che definisca una matrice dinamica di interi di dimensioni lette da stdin a tempo di esecuzione, e la inizializzi con valori letti da stdin, infine stampi il contenuto della matrice. 
 */

#include <iostream>
using namespace std; 
int main(){
	int righe; 
	const int colonne = 6; 
	do{
		cout << "Inserisci il numero di righe della matrice dinamica: \n"; 
		cin>>righe;  
	}
	while (righe < 0 && righe < 0 );
	int (*ptr) [colonne] = new int [righe][colonne]; 
	/*riempo la matrice da stdin */
	cout << "Riempimento matrice \n"; 
	for (int i = 0; i < righe; i++){
		for (int j = 0; j < colonne; j++){
			cout << "Inserisci i valori: \n"; 
			cin>>ptr[i][j];
		}
	}
	/*stampo la matrice dinamica a schermo */
	cout << "Ecco che stampo la matrice: \n"; 
	for (int i = 0; i < righe; i++){
		for (int j = 0; j < colonne; j++){
			cout << ptr[i][j] << " "; 
		}
	cout << endl; 
	}

	delete[] ptr; 

	return 0;
} 
