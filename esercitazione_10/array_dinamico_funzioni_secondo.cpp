/*- chiedo il numero di valori che si vogliono inserire
  - si alloca un array dinamico della dimensione richiesta
  - si inseriscono i valori nell'array
*/

#include <iostream>
using namespace std; 

void crea_dinamico(int &quanti_elem, int *& indirizzo ){
	// chiedo all'utente quanti elementi vuole inserire
	cout << "Inserisci numero elementi dell'array: \n"; 
	cin>>quanti_elem; 
	int *puntatore = new int [quanti_elem]; // alloco array della dimensione richiesta
	// inizializzo array
	for (int i = 0; i < quanti_elem; i++){
		cout << "Inserisci valori array: \n"; 
		cin>>puntatore[i]; 
	}
	indirizzo =  puntatore; 
}

int main(){
	//int *p_secondo; 
	int quanti_elem; 
	int *indirizzo; 
	crea_dinamico(quanti_elem, indirizzo); 
	for (int i = 0; i < quanti_elem; i++){
		cout << indirizzo[i] << " "; 
	}
	return 0; 
}
