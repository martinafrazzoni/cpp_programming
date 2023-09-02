/* 
    La simulazione e' una delle tecniche che si utilizzano per testare
    un qualcosa che non si puo' (o che, in un dato momento, non si
    vuole) costruire fisicamente. Per fare delle simulazioni e'
    necessario generare degli eventi in modo casuale.

    Scrivere una funzione "generatore di eventi", che generi due
    possibili eventi, un evento di tipo 0 oppure un evento di tipo 1.
    La probabilita' di generare un evento di tipo 0 e' la stessa di
    generare un evento di tipo 1.  Per implementare il generatore di
    eventi si puo' scrivere semplicemente una funzione che ritorni il
    valore 0 per rappresentare un evento di tipo 0 ed il valore 1 per
    rappresentare un evento di tipo 1.

    Per realizzare il generatore di eventi, utilizzare la funzione di libreria
    rand(), che genera un numero casuale compreso tra 0 e RAND_MAX.
    Tale funzione permette di generare una sequenza di numeri pseudocasuali. 
    Tali numeri si definiscono pseudocasuali perche', fissato il primo valore 
    della sequenza (chiamato seme), e' fissata tutta la sequenza di valori che 
    saranno generati nelle successive invocazioni della funzione rand().
    Pertanto, per ottenere sequenze diverse, bisogna cambiare il valore del
    seme. Per cambiare il valore del seme, si utilizza la funzione srand(n), 
    ove n e' il nuovo valore che si da al seme.
    Per utilizzare le funzioni rand() ed srand(n), bisogna includere il file 
    di intestazione "stdlib.h".

    Oltre alla funzione per la generazione degli eventi, scrivere un programma
    per testarne il funzionamento. In particolare il programma invoca la
    funzione di generazione eventi un numero N di volte, e poi stampa a schermo
    quante volte si e' verificato un evento di tipo 0 e quante volte si e' 
    verificato un evento di tipo 1 (sia in termini assoluti che in 
    percentuale).
    Un possibile output sullo schermo e' il seguente:

    Testo il generatore di eventi su 100000 eventi
    
    Eventi di tipo 0 -> quantita':  50047 percentuale:      50.047
    Eventi di tipo 1 -> quantita':  49953 percentuale:      49.953
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std; 

int genera_lancio (){
   int lancio =  rand() % 2; 
   return lancio; 
}

int main(){
    int testa_0 = 0; 
    int croce_1 = 0; 
    const int num_lanci = 100; 

    srand(time(0));  

    for (int i = 0; i < num_lanci; i++){
        if (genera_lancio() == 0)
            testa_0++; 
        else    
            croce_1++; 
    }

    //calcolo la percentuale. 

    double testa_0_reale = static_cast<double>(testa_0); 
    double croce_1_reale = static_cast<double>(croce_1); 

    double percentuale_testa = (testa_0_reale / num_lanci)*100;  
    double percentuale_croce = (croce_1_reale / num_lanci)*100; 

    cout <<"Esce testa: " << "Quantità: "<< testa_0 << " Percentuale: " << percentuale_testa << "%" << endl; 
    cout <<"Esce croce: " << "Quantità: "<< croce_1 << " Percentuale: " << percentuale_croce << "%" << endl; 
    return 0; 
}