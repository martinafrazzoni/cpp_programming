/*scrivere un programma che: 
- allochi un array dinamico di interi di dimensioni lette da stdin, 
- lo inizializzi (con i valori che vogliamo)
- lo stampi
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 
int main(){
	srand(time(0)); 
	int dim_a; 
	cout << "Inserisci dimensione array dinamico: \n"; 
	cin>>dim_a; 
	/*allochiamo un array dinamico */
	// l'array dinamico  non ha un nome.
	// l'allocazione dell'array mi dà come valore l'indirizzo di dove si trova questo array, e questo indirizzo lo  metto dentro un puntatore. 
	// tutte le volte che io invoco new viene creato un nuovo array, io quindi non posso scrivere new int [N], e poi dopo assegnarlo al puntatore p, perchè creo due array invece che uno solo. 
	int *puntatore = new int [dim_a]; 
	
	/*inizializziamo l'array con valori casuali*/
	for (int i = 0; i < dim_a; i++){
		puntatore[i] = (rand()% 10) +1;  
	}
	
	/*stampiamo l'array dinamico*/
	for (int i = 0; i < dim_a; i++){
		cout << puntatore[i] << " "; 
	}
	return 0;  
}
