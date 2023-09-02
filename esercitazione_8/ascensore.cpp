/*
  Scrivere un programma per la gestione di un "ascensore impazzito"
  per un parco giochi.

  L'ascensore si trova inizialmente in una posizione "0", a 20 metri
  dal suolo. Se ci si sposta verso l'alto la posizione aumenta di
  valore, mentre se ci si sposta verso il basso la posizione
  diminuisce di valore. Quindi, per esempio, la posizione 1 è a 21
  metri d'altezza, mentre la posizione -2 è a 18 metri
  d'altezza. Nell'attrazione l'ascensore sale o cade velocemente verso
  una nuova posizione, quindi frena bruscamente. L'ascensore è appeso
  a funi spostate da un motore comandato mediante impulsi elettrici:
  un impulso di voltaggio positivo o negativo fa ruotare il motore di
  un angolo di base in una direzione o nell'altra. A ciascuna
  rotazione di base, corrisponde uno spostamento di base
  dell'ascensore di 0.1 m verso l'alto o verso il basso.

  Supporre per dare un impulso al motore e quindi far spostare
  l'ascensore occorra invocare una funzione singolo_impulso, alla
  quale si passa la posizione attuale e la direzione (su o giu) verso
  cui effettuare uno spostamento di base. Nel nostro programma
  supponiamo che la funzione si limiti a ritornare il valore della
  posizione passata come parametro, più o meno 0.1 a seconda della
  direzione passata anch'essa come parametro. NON UTILIZZARE UN INTERO
  PER LA DIREZIONE. E neanche un booleano.

  Il  main gestisce  l'ascensore leggendo  da stdin  un numero  intero
  rappresentante il  numero di spostamenti  di base da  effettuare, ed
  invocando  per un  numero di  volte  oppportuno e  per la  direzione
  opportuna la funzione singolo_impulso.   Numeri in ingresso negativi
  implicano  spostamenti verso  il  basso, mentre  numeri in  ingresso
  positivi  implicano spostamenti  verso  l'alto.  La nuova  posizione
  dell'ascensore  deve   essere  ritornata   da  tale   funzione.  NON
  UTILIZZARE NUMERI INTERI PER LA  POSIZIONE. MISURARE LA POSIZIONE IN
  METRI.

  Nel nostro sistema di riferimento, le posizioni possibili vanno da
  -20.0 a +20.0 (ossia da 0 a 40 metri di altezza nel mondo reale). Se
  si richiedono un numero di spostamenti eccessivi il programma li limita
  comunque per restare nell'intervallo di posizioni [-20.0, +20.0] ed
  evitare che l'ascensore si schianti al suolo o sul motore stesso.

  Scrivere il programma ed assicurarsi che funzioni.

  ----------------------------------------------------

  Per rendere l'attrazione più emozionante, si decide di staccare
  automaticamente le funi quando l'ascensore si ferma, recuperando
  l'ascensore stesso con un gancio che scorre su un binario
  parallelo. Questo può succedere in qualsiasi posizione finale,
  tranne quella a distanza 1 dalla posizione 0, perché per motivi
  tecnici in tale posizione non si può effettuare l'aggancio.

  Modificare il main per gestire il distacco dell'ascensore. In
  pratica per le posizioni sicure stampare "staccare le funi", mentre
  per quella pericolosa stampare "non staccare le funi!!!".

  Testare con cura il programma.
*/

#include <iostream>
using namespace std; 
enum direzione_ascensore {su, giu}; 
direzione_ascensore direzione; 
double singolo_impulso (double posizione_attuale, direzione_ascensore direzione){
   
    double singolo_impulso = 0.1; 
    double posiz_finale; 
    if (direzione == su){
        posiz_finale =  posizione_attuale + singolo_impulso; 
    }
    if (direzione == giu){
        posiz_finale =  posizione_attuale - singolo_impulso;
    }
    return posiz_finale; 
}
int main(){
        double posizione_ascensore = -20.0; // sarebbe la posizione 0. 
        double posizione_ascensore_min = posizione_ascensore; 
        double posizione_ascensore_max = +20.0; 
        double posizione_attuale  = posizione_ascensore; 
    do{
        int spostamenti_base; 
        cout << "Inserisi il numero di spostamenti di base da far effettuare all'ascensore: "; 
        cin>>spostamenti_base;
        if (spostamenti_base < 0){  
            for (int i = 0; i > spostamenti_base; i--){ 
                posizione_attuale = singolo_impulso(posizione_attuale, giu); 
            }
            cout << "la posizione dell'ascensore è di " << posizione_attuale << " mt " << endl; 
            if (posizione_attuale < posizione_ascensore_min || posizione_attuale > posizione_ascensore_max){
                cout << "Attenzione: posizione non valida!" << endl; 
                posizione_attuale = posizione_ascensore_min;
            }
        }    
        else{
            for (int i = 0; i < spostamenti_base; i++){
                posizione_attuale = singolo_impulso(posizione_attuale, su); 
            }
            cout << "la posizione dell'ascensore è  di " << posizione_attuale << " mt" << endl; 
            if (posizione_attuale < posizione_ascensore_min || posizione_attuale > posizione_ascensore_max){ 
                cout << "Attenzione: posizione non valida!" << endl; 
                posizione_attuale = posizione_ascensore_max; 
            }
            if (posizione_attuale != -19)
                cout << ", puoi staccare le funi" << endl; 
            else
                cout << "non staccare le funi!" << endl; 
        }
    } while (true);
    return 0; 
}