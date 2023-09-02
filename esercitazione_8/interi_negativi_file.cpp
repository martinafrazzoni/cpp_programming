/*Leggere da un file di testo dati.txt" una sequenza di numeri interi terminata da 0. Memorizzare in un vettore tutti i numeri negativi". */

#include <iostream>
#include <fstream>
using namespace std; 

int main(){
	int a [] = {1, 4, 7, -15, 13, 54, 64, -12, -43, 0};  
	const int lungh_a = sizeof(a) / sizeof(a[0]); 

	int b [lungh_a]; 
    int lungh_b = 0; 
	
	// creare file testo
	ofstream file_interi; 
	file_interi.open("interi_neg.txt"); 

	// controlllo 
	if (!file_interi){
		cerr << "L'apertura in scrittura è fallita!\n"; 
		return 1; 
	}
	else{
		// creiamo un vettore dove memorizzare i numeri inseriti. 
		for (int i = 0; i < lungh_a; i++){
			file_interi << a[i] << " ";
		}
		
		file_interi.close(); 
	// apriamo il file
	ifstream interi; 
	interi.open("interi_neg.txt"); 
	if (!interi){
		cerr << "L'apertura in lettura è fallita: \n"; 
		return 1; 
	} 
	else{
		for (int i = 0; i < lungh_a; i++){
			int n;  
            while (interi >> n){
                if (n < 0){
                        b[lungh_b]  = n; 
                        lungh_b++; 
                    }
                } 
            } 
		}
        interi.close(); 
	}	

    // stampiamo l'array
    for (int i = 0; i < lungh_b; i++){
        cout << b[i] << " "; 
    }

	return 0; 
}