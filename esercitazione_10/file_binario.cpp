/*
  Scrivere un programma in cui si dichiari un tipo struct studente,
  costituito da un campo nome, un campo cognome ed un campo numero di
  matricola. Si definiscano e si inizializzino quindi almeno due
  oggetti (variabili) di tipo struct studente e si memorizzino in
  forma binaria in un file. Si chiuda quindi il file, lo si riapra in
  lettura e se ne stampi il contenuto.
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std; 

struct studente {
	char nome[10]; 
	char cognome[10]; 
	int num_matricola; 
}; 


int main(){
  studente martina; 
  studente michele; 

  // inizializziamo le struct
  strcpy(martina.nome, "Martina"); 
  strcpy(martina.cognome, "Frazzoni"); 
  martina.num_matricola = 135262; 

  strcpy(michele.nome, "Michele"); 
  strcpy(michele.cognome, "Frazzoni"); 
  michele.num_matricola = 24462; 

  // apriamo un file in scrittura e ci scriviamo dentro le struct
  ofstream file_testo; 
  file_testo.open("dati_struct.txt"); 
  if (!file_testo)
    cerr << "errore impossibile aprire il file in scrittura\n"; 

  char * const ptr = reinterpret_cast<char*>(&martina);
  char * const ptr_1 = reinterpret_cast<char*>(&michele);

  file_testo.write(ptr, sizeof(martina)); 
  file_testo.write(ptr_1, sizeof(michele));

  file_testo.close();

  ifstream file_testo_lett; 
  file_testo_lett.open("dati_struct.txt"); 
  if (!file_testo_lett)
    cerr << "Errore, impossibile aprire il file in lettura\n";  
  
  studente s1, s2; 
  file_testo_lett.read(reinterpret_cast<char*>(&s1), sizeof(martina)); 
  file_testo_lett.read(reinterpret_cast<char*>(&s2), sizeof(michele));  
  
  cout << "Ecco stampato il contenuto del file: \n"; 
  cout << "Struct martina: " << s1.nome << " " << s1.cognome << " " << s1.num_matricola << endl; 
  cout << "Struct michele: " << s2.nome << " " << s2.cognome << " " << s2.num_matricola << endl; 
  file_testo_lett.close(); 
  return 0; 
}
