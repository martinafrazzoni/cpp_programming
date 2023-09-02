/*
  Una pila è una struttura dati che prevede due operazioni:

  1) push: inserimento di un elemento in cima alla pila. La pila ha una
  dimensione massima predefinita; se la si supera l'operazione di
  push fallisce;

  2) pop: estrazione di un elemento dalla cima della pila; se la pila
  è vuota l'operazione fallisce altrimenti viene ritornato il valore
  dell'elemento estratto
  
  Scrivere un programma che implementi una pila di elementi di tipo
  int. In particolare il programma deve offrire all'utente la
  possibilità di scegliere tra le seguenti operazioni:

  1) inserimento nella pila da stdin: si effettuano una serie di push
     successive finché la pila si riempie, o l'utente comunica la fine
     dell'input;

  2) estrazione e stampa dalla pila su stdout: si chiede all'utente
     quanti elementi si vuole estrarre dalla pila mediante una
     successione di pop, quindi si effettua una successione di
     estrazioni e stampe del valore su stdout, in numero pari al
     minimo tra il numero di elementi nella pila ed il numero di
     elementi che l'utente ha chiesto di estrarre/stampare

  3) inserimento nella pila da file: si effettuano una serie di push
     successive leggendo i valori da un file, il cui nome viene
     fornito dall'utente. L'inserimento procede finché la pila si
     riempie o si raggiunge la fine del file

  4) estrazione e stampa dalla pila su file: si chiede all'utente
     quanti elementi si vuole estrarre dalla pila mediante una
     successione di pop, ed il nome del file in cui scrivere i valori
     di tali elementi; quindi si effettua una successione di
     estrazioni e scritture del valore sul file, in numero pari al
     minimo tra il numero di elementi nella pila ed il numero di
     elementi che l'utente ha chiesto di estrarre/scrivere

     Come al solito potete definire la pila come variabile locale al
     main, o come variabile globale. La prima soluzione è un pò più
     complessa, ma più pulita, mentre la seconda è più semplice ma può
     rivelarsi peggiore in termini di visibilita' delle variabili.
*/
#include <iostream>
#include <fstream>
using namespace std;
// struct che si chiama pila
struct pila_t{
   int *collezione;  // puntatore che punta ad un array allocato dinamicamente di interi. 
   int capacita_max; 
   int tot_elem; 
}; 

void crea_pila(pila_t &p){
   // prendo in input le dimensioni
   do{
      cout << "Inserisci le dimensioni della pila: \n"; 
      cin>>p.capacita_max;
   }
   while (p.capacita_max <= 0); 
   p.collezione = new int [p.capacita_max]; 
   p.tot_elem = 0; 
}

bool controlla_se_piena(pila_t &p){
   if (p.tot_elem == p.capacita_max){
      cout << "La pila ha raggiunto la capacità massima!\n"; 
      return true; 
   }

   return false; 
}
bool controlla_se_vuota(pila_t &p){
   if (p.tot_elem == 0){
      cout << "La pila è vuota\n";  
      return true;
   }
   return false; 
}

bool pop(pila_t &p, int &elem){
   if (controlla_se_vuota(p) == true){
      cout << "Non posso fare la pop \n"; 
      return false; 
   }
   p.tot_elem--; // La funzione pop modifica l'inizio della pila. decrementando, il numero degli elementi, stiamo modificando il punto in cui si trova l'inizio della pila. 
   //se io ho tre elementi dentro la mia pila, l'elemento che va tolto è l'elemento di posto 2. 
   elem = p.collezione[p.tot_elem];
   return true; 
}

bool push(pila_t &p, int elem){
   if (controlla_se_piena(p)== true){
      cout << "Non posso effettuare la push\n"; 
      return false; 
   }
   p.collezione[p.tot_elem] = elem;   //metto nel vettore collezione, in posizione tot_elem il valore che devo inserire
   p.tot_elem++;  
   cout << endl;
   return true; 
}

void stampa_pila(pila_t &p){
   cout << "Ecco il contenuto della pila: \n"; 
   for (int i = 0; i < p.tot_elem; i++){
      cout << p.collezione[i] << " "; 
   }
   cout << endl; 
}

void riserva_memoria(pila_t&p, int &da_riservare, int *&riserva){
   riserva = new int [da_riservare]; // alloco array dinamico di dimensioni da riservare. 
   for (int i = 0; i < da_riservare; i++){
      riserva[i] = p.collezione[p.tot_elem];
      p.tot_elem--;  
   }
   cout << "Ecco gli elementi riservati: \n"; 
   for (int i = 0; i < da_riservare; i++){
         cout << riserva[i] << " "; 
      }
}

void libera_memoria(int *&riserva){
   delete[] riserva; 
}

void scrivi_file (ofstream &file_pila, const int *a, int elem_file){
   file_pila.write(reinterpret_cast< const char*>(a), sizeof(int)*elem_file); 
}

void leggi_file(pila_t &p, ifstream &leggi_file_pila, int *a, int elem_file){
   leggi_file_pila.read(reinterpret_cast<char*>(a), sizeof(int)*elem_file); 
   for (int i = 0; i < elem_file; i++){
      int n = a[i]; 
      if(controlla_se_piena(p) == false){
         push(p, n); 
      }
   }
}

int main(){
   pila_t p; 
   int elem; 
   while (true){
   int scelta; 
   cout << "Inserisci il numero dell'operazione che vuoi fare: \n";
   cout << "\t 1. per creare la pila: \n"; 
   cout << "\t 2. per controllare se è piena\n"; 
   cout << "\t 3. per controllare se è vuota\n"; 
   cout << "\t 4. push del nuovo elemento\n"; 
   cout << "\t 5. pop del primo elemento\n"; 
   cout << "\t 6. Allocare spazio in memoria\n"; 
   cout << "\t 7. Fai la push da un file\n"; 
   cout << "\t 8. Estrai e stampa valore su file\n";
   cout << "\t 9. Per terminare\n";  
   cin>>scelta; 
   switch (scelta)
   {
   case 1:
   {
      crea_pila(p);
      break;
   }
   case 2: 
   {
      controlla_se_piena(p);
      cout << "Dimensione pila: " << p.tot_elem << endl; 
      break;
   }
   case 3: 
   {
      controlla_se_vuota(p);
      cout << "Dimensione pila: " << p.tot_elem << endl; 
      break; 
   }
   case 4: 
   {
      cout << "Valore da inserire: \n"; 
      cin>>elem;
      push(p, elem); 
      cout << "Stampo la pila: \n"; 
      for (int i = p.tot_elem-1; i >= 0; i--){
         cout << p.collezione[i] << " "; 
      }  
      cout << endl; 
      cout << "Dimensione pila: " << p.tot_elem << endl;  
      break;
   }
   case 5: 
   {
      cout << "Valore da togliere: \n"; 
      cin>>elem; 
      int pop_val = 0; 
      for (int i = 0; i < elem; i++){
         pop(p, pop_val); 
         cout << "Popped value: " << pop_val << endl; 
      }
      cout << "Stampo la pila: \n"; 
      for (int i = p.tot_elem-1; i >= 0; i--){
         cout << p.collezione[i] << " "; 
      }  
      cout << endl;
      cout << "Dimensione pila: " << p.tot_elem << endl;
      break;
   }
   case 6: 
   {
      int da_riservare; 
      cout << "Quanti elementi vuoi riservare: \n"; 
      cin>>da_riservare; 
      int *indirizzo_riserva; 
      riserva_memoria(p, da_riservare, indirizzo_riserva); 
      libera_memoria(indirizzo_riserva); 
      break; 
   }
   case 7: 
   {  
      // apro un file in scrittura, chiedo all'utente il suo nome
      ofstream file_pila; 
      file_pila.open("file_pila.txt"); 
      if (!file_pila){
         cerr << "Errore! impossibile aprire il file in scrittura\n"; 
         return 1; 
      }
      int elem_file;  
      cout << "Quanti valori vuoi inserire nel file: \n"; 
      cin>>elem_file; 
      int *a = new int [elem_file]; 
      for (int i = 0; i < elem_file; i++){
         cout << "Inserisci valore: \n"; 
         cin>>a[i]; 
      }
      scrivi_file(file_pila, a, elem_file); 
      file_pila.close(); 

      // leggiamo i valori inseriti e facciamo la push
      // apro file in lettura
      ifstream leggi_file_pila; 
      leggi_file_pila.open("file_pila.txt"); 
      if (!leggi_file_pila){
         cerr << "Errore! impossibile aprire il file in lettura!"; 
         return 1; 
      }
      leggi_file(p, leggi_file_pila, a, elem_file); // ho letto il contenuto del file, e ho fatto la push degli elementi. 
      cout << endl; 

      stampa_pila(p); 
      leggi_file_pila.close(); 
      break; 
   }
   case 8: 
   {
      ofstream pop_val_file; 
      pop_val_file.open("popped_val.txt"); 
      if(!pop_val_file){
         cerr << "Errore, impossibile aprire il file in scrittura!\n"; 
         return 1; 
      }
      int quanti_estrarre; 
      do{
         cout <<"Quanti elementi vuoi estrarre dalla pila: "; 
         cin>>quanti_estrarre;
      }
      while (quanti_estrarre <= 0 || quanti_estrarre > p.tot_elem); 
      int pop_val = 0; 
      for (int i = 0; i < quanti_estrarre; i++){
         pop(p, pop_val); 
         pop_val_file << pop_val << " "; 
      }
      pop_val_file.close(); 
      break;
   }
   case 9: 
   {
      return 0; 
      break;
   }
   default:
      break;
   } 
   }
   return 0; 
}
