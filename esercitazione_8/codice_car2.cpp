/*
  Traccia: Realizzare un programma che legge in ingresso un intero e,
  se il valore inserito appartiene all'insieme dei codici ASCII dei
  caratteri stampabili, stampa il carattere corrispondente.  Se il
  valore inserito e' fuori dall'intervallo dei codici dei caratteri
  stampabili, cambia automaticamente tale valore affinche' stia nel
  suddetto intervallo, quindi stampa il carattere corrispondente.  Ad
  esempio, se l'utente inserisce un valore inferiore al valore minimo
  concesso, si sostituisce tale valore con il valore minimo concesso;
  se l'utente inserisce un valore superiore al massimo concesso, si
  sostituisce tale valore con il valore massimo concesso. Realizzare
  il programma utilizzando l'operatore condizionale.  Scrivere il
  programma supponendo di non conoscere il codice ASCII dei caratteri,
  ma di sapere solo che i codici dei caratteri stampabili appartengono
  all'intervallo che va dal codice del carattere ' ' (spazio) al
  codice del carattere '~'. Ovviamente si assume di non conoscere neanche il
  codice dei due estremi, ossia dei caratteri ' ' e '~'.
*/
#include <iostream>
using namespace std; 
int main(){
  int cod; 
  char carattere; 
while (true)
  {
    cout << "Inserisci il codice di un carattere ASCII: "; 
    cin>>cod; 
    char car = static_cast<char>(cod); 
    carattere = car >= ' ' ? car : ' '; 
    carattere = car <= '~' ? car : '~'; 
    cout << carattere << endl; 
  }
return 0; 
}