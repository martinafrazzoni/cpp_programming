/*Leggere da un file di testo dati.txt una 
sequenza di numeri interi terminata da 0. 
Memorizzare in un vettore tutti i numeri compresi 
tra –30 e +30 escluso lo 0. Ordinare il vettore in 
modo crescente e stampare tutti i numeri positivi.
*/

#include <iostream>
#include <fstream>
using namespace std; 

int main(){
	const int dim_max = 100;
	int a [dim_max]; 

	int b [dim_max]; 
	int lungh_b = 0; 

	int num_max = 30; 
	int num_min = -30; 	

	// devo scrivere un file di testo
	ofstream file_interi; 
	file_interi.open("ordina_interi.txt"); 	
	if (!file_interi){
		cerr << "L'apertura in scrittura è fallita!\n"; 
		return 1; 
	}
	
	else{
		cout << "Inserisci numeri interi (0 per terminare): \n"; 
        for (int i = 0; i < dim_max; i++){
                cin>>a[i];                 
                if (a[i] == 0)
                    break; 
                else
                    file_interi << a[i] << " ";
        }
        file_interi.close();
    }

		

    // apro il file in lettura
    ifstream interi; 
    interi.open("ordina_interi.txt"); 

    if (!interi){
        cerr << "L'apertura in lettura è fallita! \n";
        return 1; 
    }
    else{
        int n; 
        while (interi>>n){
            if ((n >= num_min && n <= num_max) && n !=0){
                b[lungh_b] = n; 
                lungh_b ++;  
            }
        }
        cout << "Stampiamo l'array b (valori compresi tra -30 e +30): \n"; 
        for (int i = 0; i < lungh_b; i++){
            cout << b[i] << " "; 
        }
        cout << endl; 
        interi.close(); 
    } // chiusura else

	// ordiniamo il vettore b in modo crescente. 

    int temp;
	for (int i = 0; i < lungh_b-1; i++){
        int min_index = i; 
        for (int j = (i+1); j < lungh_b; j++){
            if (b[j] < b[min_index])
                min_index = j; 
        }

        temp = b[min_index]; 
        b[min_index] = b[i]; 
        b[i] = temp; 
    }
		
	// stampiamo solo i numero positivi
    cout << "Stampiamo soltanto i numeri positivi: \n"; 
	for (int i = 0; i < lungh_b; i++){
        if (b[i] > 0)
			cout << b[i] << " "; 
    }

    return 0; 
}