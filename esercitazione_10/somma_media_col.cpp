#include <iostream>
using namespace std; 
int main(){
	int righe = 5; 
	int col = 5; 

	/*creiamo la nostra matrice*/
	/*matrice di 5x5*/
	float matrice [righe][col] = 
	{ {1, 2, 3, 4, 5}, 
	  {1, 2, 3, 4, 5}, 
	  {1, 1, 1, 1, 1}, 
	  {2, 2, 2, 2, 2}, 
	  {3, 3, 3, 3, 3}
	}; 
	/*per trovare la somma degli elementi nella colonna della matrice, dobbiamo sommare tutti gli elementi che sono memorizzati in ogni riga di quella colonna.
	Poi possiamo trovare la media, dividendo la somma per il numero di righe.
	Noi dobbiamo sommare ogni colonna della nostra matrice.*/
	
	float somma = 0;
	float media = 0;  
	/*partiamo con un ciclo più esterno, che va da zero e incrementa di uno fino all'ultimo indice della colonna*/
	for (int i = 0; i < col; i++){ // utilizza il contatore i per scorrere ogni indice della colonna
		/*per ogni colonna, dobbiamo guardare anche l'indice della riga così possiamo fare la somma*/
		somma = 0; // cos' per ogni riga la somma si azzera. 
		for (int j = 0; j < righe; j++){
			somma += matrice[j][i]; 
			/*per la colonna i,stiamo aggiungendo l'elemento di ogni riga alla somma. il ciclo più interno calcola la somma degli elementi nella colonna di indice i */
			/*stampiamo la somma: */
		}
		cout << "colonna " << i << " = " << somma << endl;  
		media = somma / righe; 
		cout << "Colonna media: " << media << endl; 
	}

	return 0; 
}
