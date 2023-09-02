/*
  Scrivere un programma che:

  1) definisca un array di reali di dimensioni definite a tempo di
  scrittura del programma, e chieda all'utente di inserirne i valori
  (oppure lo inizializza a tempo di scrittura del programma stesso);

  2) riversi il contenuto dell'array sia in un file binario "dati.dat"
     mediante output non formattato, che in un file di testo
     "dati.txt" mediante output formattato;

  3) chiuda entrambi i file;

  4) li riapra in lettura;

  5) ristampi il contenuto di entrambi i file (in termini di numeri reali).

  Provare a visualizzare e confrontare il contenuto dei due file con
  un editor di testo o con comandi quali 
  cat <nome_file>

  */

#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std; 

void inizializza_array(double *&a, int dim_a){
   // chiedo all'utente di inserire i valori. 
   for (int i = 0; i < dim_a; i++){
      cout << "Inserisci i valori dell'array: \n"; 
      cin>>a[i]; 
   }
}

void scrivi_binario(ofstream &file_binario, double*&a, int dim_a){
   // devo scrivere su un file binario tramite una scrittura non formattata
   file_binario.write(reinterpret_cast<const char *>(a), sizeof(double)*dim_a); 
}

void scrivi_testo (ofstream &file_testo, double *&a, int dim_a){
   // devo scrivere fsu file mediante scrittura formattata
   for (int i = 0; i < dim_a; i++){
      file_testo << a[i] << " "; 
   }
}

void leggi_stampa_binario(ifstream &file_binario_lett, double *&a, int dim_a){
   // leggiamo il contenuto del file
   cout << "Ecco il contenuto del file binario: \n"; 
   file_binario_lett.read(reinterpret_cast<char *>(a), sizeof(double)*dim_a); 
   for (int i = 0; i < dim_a; i++){
      cout <<setprecision(9)<<a[i] << " " ; 
   }
   cout << endl; 
}

void leggi_stampa_testo(ifstream &file_testo_lett, double*&a, int dim_a){
   // stampiamo il contenuto del file
   cout << "Ecco il contenuto del file di testo: \n"; 
   for (int i = 0; i < dim_a; i++){
      file_testo_lett >> a[i]; 
      cout << a[i] << " "; 
   }
}

int main(){
/* definisco un array di reali con dimensioni definite a tempo di scrittura del programma: 
   -> quindi è un array di double allocato dinamicamente
   -> chiedo all'utente la lunghezza dell'array. 
   -> chiedo all'utente di inserire i valori dei singoli elementi. 
*/
   int dim_a; 
   cout << "Inserisci le dimensioni dell'array di double: \n"; 
   cin>>dim_a;
   double *a = new double [dim_a]; // sto creando un array di double di dimensioni dim_a. 
   
   inizializza_array(a, dim_a); 

   // scrittura non formattata
   ofstream file_binario; 
   file_binario.open("dati.dat"); 
   if (!file_binario)
      cerr << "Errore nell'apertura del file in scrittura\n";
   scrivi_binario(file_binario, a, dim_a); 
   file_binario.close(); 

   // scrittura formattata su file di testo
   ofstream file_testo; 
   file_testo.open("dati.txt"); 
   if (!file_testo)
      cerr << "Errore nell'apertura del file in scrittura\n"; 
   scrivi_testo(file_testo, a, dim_a); 
   file_testo.close(); 

   // riapro in lettura entrambi i file
   ifstream file_binario_lett; 
   file_binario_lett.open("dati.dat"); 
   if (!file_binario_lett)
      cerr << "Errore nell'apertura del file in lettura\n"; 
   leggi_stampa_binario(file_binario_lett, a, dim_a); 
   file_binario_lett.close(); 

   ifstream file_testo_lett; 
   file_testo_lett.open("dati.txt"); 
   if (!file_testo_lett)
      cerr << "Errore nell'apertura del file in lettura\n"; 
   leggi_stampa_testo(file_testo_lett, a, dim_a); 
   file_testo_lett.close(); 
   return 0; 
}