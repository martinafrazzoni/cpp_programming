/*
  Scrivere un programma che definisca una matrice bidimensionale di interi di
  dimensioni stabilite a tempo di scrittura del programma e la
  inizializzi con valori letti da stdin. Successivamente stampi la
  matrice.  Infine calcoli e stampi il valore della somma degli
  elementi di ciascuna riga.

  La somma degli elementi di ciascuna riga va effettuata mediante una
  funzione che prende in ingresso un array di interi e ritorna il
  valore della somma degli elementi. La funzione non legge nulla da
  stdin e non scrive nulla su stdout.
*/
#include <iostream>
using namespace std; 

const int righe = 3; 
const int col = 3; 

void calcola_somma_righe(int matrice[ ], int righe){
	int somma =  0; 
	for (int i = 0; i < righe; i++){
		somma+=matrice[i]; 
	}
	cout << endl; 
	cout << "Somma: " <<  somma << endl; 
}
int main(){
	
	int matrice [righe][col]; 
	for(int i = 0; i < righe; i++){
		for (int j = 0; j < col; j++){
			cout << "Inizializza matrice: \n"; 
			cin >> matrice[i][j]; 
		}
	}
	cout << "Ecco la matrice: \n"; 
	for (int i = 0; i < righe; i++){
		for (int j = 0; j < col; j++){
			cout << matrice[i][j] << " ";  
			}
		cout << endl; 
	}

	/*float somma = 0; 
	for (int i = 0; i < righe; i++){ // ciclo che va da 0 al numero di righe.
		somma = 0; 
		for (int j = 0; j < col; j++){ // valore nella riga di indice i per ogni colonna. QUindi nel mio caso 1, 2, 3 
			somma += matrice[i][j]; 
		}
		cout << "Riga " << i << " = " << somma << endl; 
	}*/

	for (int i = 0; i < col; i++){
		calcola_somma_righe(matrice[i], righe);
	}
	 
	
	return 0; 
}
