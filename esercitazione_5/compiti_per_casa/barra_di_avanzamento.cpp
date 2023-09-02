/*Nella soluzione del seguente esercizio, si utilizza l'istruzione for. Se non l'abbiamo ancora vista a lezione, utilizziamo l'istruzione while. Riscrivete poi il programma utilizzando l'istruzione for una volta che l'avete vista a lezione e confronta la vostra soluzione con quella riportata in questo file. 
Spesso per rappresentare 8anche al variare del tempo) quale porzione di un certo lavoro è stata completata si utiizza una barra di lunghezza proporzionale a tale porzione. 
Scrivee un programma che legga da stdin un valore percentuale (in centesimi) e la lunghezza massima con cui rappresentare tale percentuale (attenzione al numero massimo di colonne che si suppone sia disponibili sul terminale). Il programma stampa quaindi sullo schermo la barra nel formato mostrato negli esempi: 

Esempi:
 *
 * Inserire la percentuale (in centesimi), e la lunghezza della barra: 20 40
 *  --------------------------------------
 * |XXXXXXX                               |
 *  --------------------------------------
 *
 * Inserire la percentuale (in centesimi), e la lunghezza della barra: 100 30
 * ----------------------------
 *|XXXXXXXXXXXXXXXXXXXXXXXXXXXX|
 * ----------------------------
 */

#include <iostream>
using namespace std; 
int main(){
    int l_completato; // percentuale del lavoro che è stato completato
    int l_totale; // lunghezza della barra. 
    const int lung_max_col = 60; // sono il numero di colonne disponibili sul temrinale. 
    int num_righe = 3; 
    

do{
    cout << "Inserisci la percentuale in centesimi: ", 
    "e la lunghezza della barra: n"; 
    cin>>l_completato>>l_totale; 
}
while(l_totale>lung_max_col); 
 
int numero_x = ((l_completato * l_totale)/100)-1; 

/*primo ciclo for che mi stampa i trattini orizzontali ------ 
for (int i = 0; i<l_totale-2; i++){
    if (i == 0){
        cout << " "; 
    }
    cout << "-";
}
cout << endl; 
// secondo ciclo for che mi stampa i trattini verticali. 
for (int i = 0; i<l_totale; i++){   
    if (i == 0 || i == l_totale-1){
        cout << "|"; 
    }
    else {
       cout << " ";   
    }
}
cout << endl; 
*/

 

// primo ciclo: variabile i che mi tiene conto delle righe, che in questo caso sono 3. 
for (int i = 0; i < num_righe; i++){
    if (i == 0 || i == 2)
    {
        for (int j = 0; j < l_totale-2; j++){ 
            if (j == 0){
                cout << " "; 
            }
            cout << "-"; 
        }
        cout << endl; 
    }
    if (i == 1){
        cout << "|"; 
        for(int k = 0; k <= numero_x; k++){
            cout << "x"; 
        }
        cout << endl;
    }
}
return 0; 
}
