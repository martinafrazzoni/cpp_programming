
#include <iostream>
using namespace std; 

int main(){
	/*definisco il numero di righe e di colonne della mia matrice*/
	int righe = 3; 
	int col = 3;
	int matrice [righe][col] = 
	{ {1, 2, 3}, 
	  {4, 5, 6}, 
	  {7, 8, 9}
	}; 
	/*devo sommare tutti gli elementi degli indici che formano la diagonale secondaria*/
	int indice_colonna; 
	int somma = 0; 
	for (int i = 0; i < righe; i++){
		indice_colonna = (col-1-i);
		somma+= matrice[i][indice_colonna]; 
	}
	//cout << "La somma degli elementi della diagonale secondaria è: " << somma << endl; 
	/*adesso devo sommare tutti gli elementi degli indici che formano la diagonale principale*/
	int somma_p = 0; 
	for(int i = 0; i < righe; i++){
		somma_p += matrice[i][i]; 
	}
	//cout << "la somma degli elementi della diagonale principale è: " << somma_p << endl; 
	cout << "La differenza tra le somma degli elementi della diagonale principale e gli elementi della diagonale secondaria è: " << (somma_p - somma) << endl; 

	/*avrei potuto anche scrivere un solo ciclo for: 
	for (int i = =; i  righe; i++){
		somma += matrice[i][indice_colonna]; 
		somma_p += matrice[i][i]; 
	}
*/
return 0; 
}
