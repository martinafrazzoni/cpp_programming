/*
  Scrivere un programma che:

  1) definisca un array di reali di dimensioni definite a tempo di
  scrittura del programma, e chieda all'utente di inserirne i valori
  (oppure lo inizializza a tempo di scrittura del programma stesso);

  2) riversi il contenuto dell'array sia in un file di testo
     "dati.txt" mediante output formattato;

  3) chiuda il file;

  4) lo riapra in lettura;

  5) ristampi il contenuto del file.

  Provare a visualizzare il contenuto del file con un editor di testo o
  con comandi quali 
  cat <nome_file>

  */

 #include <iostream>
 #include <fstream>
 using namespace std; 

int main(){
    // definisco l'array e le sue dimensioni. 
    const int dim_a = 3; 
    double a [dim_a]; 
    
    // creo un nuovo file per metterci dentro  valori dell'array
    ofstream file_reali; 
    file_reali.open("dati.txt"); 

    // controllo che il file si posso aprire 
    if (!file_reali){
        cerr << "L'apertura è fallita!" << endl;
        return 1; 
    }
    else{
        // scorro l'array e chiedo all'utente di inserire i valoei, e ogni valore lo vado a mettere dentro il file.
        cout << "Inserisci i valori reali per inizializzare l'array :\n";
        for (int i = 0; i < dim_a; i++){
            cin>>a[i]; 
            file_reali << a[i] << " "; 
        }
        file_reali.close(); 
    }

    // riapro il file con un altro nome
    ifstream reali; 
    reali.open("dati.txt"); 
    // controllo che il file si apra
    if (!reali){
        cerr << "l'apertura del file è fallita!\n"; 
        return 2; 
    }
    else{
        cout << "Ecco il contenuto del file: \n"; 
        for (int i = 0; i < dim_a; i++){
            double n; 
            reali>> n; 
            cout << n << " "; 
        }
    }
    reali.close(); 
    return 0; 
}


// altra versione dell'ultimo ciclo for
double n; // ho definito un'altra variabile e lì dentro ci metto n. 
        while (reali>>n){
            cout << n; 
        }
        cout << endl; 