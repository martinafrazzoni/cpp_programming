/*leggere da un file di testo "dati_inp.txt" una sequenza di numeri interi terminata da 0, e copiare in un vettore solo gli elementi positivi. Copiare tutti i valori del vettore compresi fra 10 e 100 in un file di testo "dati_out.txt"*/
#include <iostream>
#include <fstream>
using namespace std; 

int main(){
    const int max_elem = 100; 
    int a[max_elem]; 

    int positivi [max_elem]; 
    int dim_pos = 0; 

    int min_pos = 10; 
    int max_pos = 100; 

    // array che contiene i positivi nell'intervallo 10 100.     
    int pos_inter[max_elem]; 
    int dim_inter = 0; 
    // creiamo il file
    ofstream dati_scrit; 
    dati_scrit.open("dati_inp.txt"); 
    if (!dati_scrit){
        cerr << "L'apertura in scrittura è fallita!\n"; 
        return 1; 
    }
    else{
        cout << "Inserisci una sequenza di numeri interi (EOF per terminare): \n"; 
        for (int i = 0; i < max_elem; i++){
            while(cin>>a[i]){
                if (dati_scrit.eof()){
                    break; 
                }
                else{
                    dati_scrit<<a[i] << " "; 
                }
            }  
        }
        dati_scrit << " 0 " << " ";
        dati_scrit.close(); 
    }


    // apro in lettura e copio solo gli elementi maggiori di zero. 
    ifstream dati_let; 
    dati_let.open("dati_inp.txt"); 
    if (!dati_let){
        cerr << "L'apertura in lettura è fallita!\n"; 
        return 1; 
    }
    else{
        for (int i = 0; i < max_elem; i++){
            int n; 
            while (dati_let>>n){
                if (dati_let.eof()){
                    break;
                }
                else{
                    if (n > 0){
                        positivi[dim_pos] = n; 
                        dim_pos++; 
                    }
                }
            }
        }
        cout << "Ecco gli elementi maggiori di zero inseriti: \n"; 
        for (int i = 0; i < dim_pos; i++){
            cout << positivi [i] << " "; 
        }
        cout << endl; 

        dati_let.close(); 
    }

    // apro in lettura il file, poi copio in un secondo file solo gli elementi compresi tra 10 e 100; 
    // creo il secondo file

    ofstream dati_inter; 
    dati_inter.open("dati_out.txt"); 
    if (!dati_inter){
        cerr << "l'apertura in scrittura è fallita \n"; 
        return 1; 
    }
    else{
        // apriamo il primo file
        ifstream dati_let_1; 
        dati_let_1.open("dati_inp.txt"); 
        if (!dati_let_1){
            cerr << "Errore apertura del file!\n"; 
        }
        else{
            // leggiamo il valori, se sono compresi tra 10 e 100 li metto nell'array pos_inter e lo copiamo nell'altro file. 
            int num; 
            while (dati_let_1>>num){
                if (num > min_pos && num < max_pos){
                    pos_inter[dim_inter] = num; 
                    dim_inter++; 
                }
            }
        }
        for (int i = 0; i < dim_inter; i++){
            dati_inter << pos_inter[i] << " "; 
        }
        cout << endl; 

        dati_let_1.close(); 
        dati_inter.close(); 
    }

    // apriamo il secondo file, leggiamo il contenuto e stampiamolo su stdout
    ifstream dati_inter_2; 
    dati_inter_2.open("dati_out.txt"); 
    if (!dati_inter_2){
        cerr << "apertura in lettura è fallita!\n";
    }
    else{
        cout << "Ecco il contenuto del secondo file: \n"; 
        int numero; 
        while (dati_inter_2>>numero){
            if (dati_inter_2.eof()){
                break;
            }
            else{
                cout << numero << " "; 
            }
        }
    }
    dati_inter_2.close(); 
    return 0; 
}