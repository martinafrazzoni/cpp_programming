/*- chiedo il numero di valori che si vogliono inserire
  - si alloca un array dinamico della dimensione richiesta
  - si inseriscono i valori nell'array
*/

#include <iostream>
using namespace std; 

int *crea_dinamico(int &quanti_elem){
	// chiedo all'utente quanti elementi vuole inserire
	cout << "Inserisci numero elementi dell'array: \n"; 
	cin>>quanti_elem; 
	int *puntatore = new int [quanti_elem]; // alloco array della dimensione richiesta
	// inizializzo array
	for (int i = 0; i < quanti_elem; i++){
		cout << "Inserisci valori array: \n"; 
		cin>>puntatore[i]; 
	}
	return puntatore; 
}
int main(){
	int *p_secondo; 
	int quanti_elem; 
	p_secondo = crea_dinamico(quanti_elem); 
	for (int i = 0; i < quanti_elem; i++){
		cout << p_secondo[i] << " "; 
	}
	return 0; 
}
