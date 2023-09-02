/*
  Una pila è una struttura dati che prevede due operazioni:

  1) push: inserimento di un elemento di un dato valore (da passare alla 
  funzione)in cima alla pila. La pila ha una dimensione massima predefinita; 
  se la si supera l'operazione di push fallisce;

  2) pop: estrazione di un elemento dalla cima della pila; se la pila
  è vuota l'operazione fallisce altrimenti viene ritornato il valore
  dell'elemento estratto (una volta estratto l'elemento, è necessario
  modificarne il valore all'interno della pila?)
  
  Scrivere un programma che implementi una pila di elementi di tipo
  int. In particolare il programma deve offrire all'utente la
  possibilità di scegliere tra le seguenti operazioni:

  1) inserimento nella pila da stdin: si aggiunge un elemento in cima
     alla pila e si stampa il nuovo contenuto dell'intera pila

  2) estrazione e stampa dalla pila su stdout: si chiede all'utente
     quanti elementi si vuole estrarre dalla pila mediante una
     successione di pop, quindi si effettua una successione di
     estrazioni e stampe del valore su stdout, in numero pari al
     minimo tra il numero di elementi nella pila ed il numero di
     elementi che l'utente ha chiesto di estrarre/stampare

     Come al solito potete definire la pila come variabile locale al
     main, o come variabile globale. La prima soluzione è un pò più
     complessa, ma più pulita, mentre la seconda è più semplice ma
     è peggiore in termini di visibilita' delle variabili ed effetti
     collaterali.
  
  Finite le precedenti due operazioni, realizzare l'operazione:

  3) Riserva memoria: si passa il numero di elementi che si intende
     riservare a partire dalla cima (come se si fossero fatte delle
     push, ma senza cambiare valore agli elementi)


  Aggiungere la possibilità per l'utente di riservare memoria con la
  precedente operazione. In particolare, in conseguenza della
  richiesta di riservare memoria, stampare il valore degli elementi
  riservati

  A questo punto testare il progranmma nel suo insieme facendo un
  pò di inserimenti, seguiti da altrettante estrazioni. Scegliere
  infine di riservare memoria, e controllare il contenuto degli
  elementi riservati. Sono valori fissi o dipendono dalla precedente
  sequenza di inserimenti ed estrazioni?

  Possibile estensione:
  
  4) Operazione di rilascio memoria: si passa il numero di elementi
     che si intende rilasciare a partire dalla cima della pila.
*/
#include <iostream>
using namespace std;
// struct che si chiama pila
struct pila {
   int *collezione;  // puntatore che punta ad un array allocato dinamicamente di interi. 
   int capacita_max; 
   int tot_elem; 
}; 


void crea_pila(pila &p){
   // prendo in input le dimensioni
   do{
      cout << "Inserisci le dimensioni della pila: \n"; 
      cin>>p.capacita_max;
   }
   while (p.capacita_max <= 0); 
   p.collezione = new int [p.capacita_max]; 
   p.tot_elem = 0; 
}

bool controlla_se_piena(pila &p){
   if (p.tot_elem == p.capacita_max){
      cout << "La pila ha raggiunto la capacità massima!\n"; 
      return true; 
   }

   return false; 
}
bool controlla_se_vuota(pila &p){
   if (p.tot_elem == 0){
      cout << "La pila è vuota\n";  
      return true;
   }
   return false; 
}

bool pop(pila &p, int &elem){
   if (controlla_se_vuota(p) == true){
      cout << "Non posso fare la pop \n"; 
      return false; 
   }
   p.tot_elem--; // La funzione pop modifica l'inizio della pila. decrementando, il numero degli elementi, stiamo modificando il punto in cui si trova l'inizio della pila. 
   //se io ho tre elementi dentro la mia pila, l'elemento che va tolto è l'elemento di posto 2. 
   elem = p.collezione[p.tot_elem];
   return true; 
}

bool push(pila &p, int elem){
   if (controlla_se_piena(p)== true){
      cout << "Non posso effettuare la push\n"; 
      return false; 
   }
   p.collezione[p.tot_elem] = elem;   //metto nel vettore collezione, in posizione tot_elem il valore che devo inserire
   p.tot_elem++;  
   cout << endl;
   return true; 
}

void riserva_memoria(pila&p, int &da_riservare, int *&riserva){
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

int main(){
   pila p; 
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
   cout << "\t 7. per terminare\n"; 
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
      return 0; 
      break; 
   }
   default:
      break;
   } 
   }
   return 0; 
}