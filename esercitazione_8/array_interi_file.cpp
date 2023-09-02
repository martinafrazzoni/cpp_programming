// devo creare un file dati.txt e metterci dentro al massimo 100 interi. 
// quindi:

#include <iostream>
#include <fstream>
using namespace std; 

int main(){
	// vettore di interi, con al massimo 100 elementi. 
	const int max_elem = 100; 
	int a [max_elem]; 

	// apro un nuovo file. 
	ofstream file_interi; 
	file_interi.open("interi.txt"); 

	if (! file_interi){
		cerr << "L'apertura è fallita\n"; 
		return 1; 
	}

	else{
		cout << "Inserisci valori interi fino ad un massimo di 100 elementi (EOF per terminare): \n"; 
		for (int i = 0; i < max_elem; i++){
			if (file_interi.eof()){
				break; 
				return 1; 
			}
			else{
				cin>>a[i]; 
				file_interi << a[i] << " "; 
			}
		}
	file_interi.close(); 

	// riapro il file

	ifstream interi; 
	interi.open("interi.txt"); 

	if (!interi){
		cerr << "l'apertura è fallita!"; 
		return 2;
	} 
	else{
		cout << "Ecco il contenuto: \n"; 
		for (int i = 0; i < max_elem; i++){
			int n; 
			interi >> n; 
				if (n == 0){
					break; 
				} 
			else
				cout << n << " "; 
			}
		}
		interi.close(); 
	}
	return 0; 
}

