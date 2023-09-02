/*
 * Scrivere un programma che verifica se la data immessa nel formato
 * GG MM AAAA e' una data corretta.  
 * Realizzare il programma definendo ed utlilizzando una funzione che
 * prende in ingresso tre numeri interi.
 *
 * Aiuto: un anno a è bisestile se e solo se l'espressione logica
 * !(a%400) || ( !(a%4) && (a%100) )
 * è vera
 *
 * Confrontarsi poi con la soluzione fornita in questo file e con la
 * soluzione, di migliore qualita', data nel file
 * verifica_data_migliore.cc contenuto nei compiti per casa
 * dell'esercitazione 9.
 */

#include <iostream>
using namespace std; 

bool controllo (int giorno, int mese, int anno){
   // controllo per l'anno: deve essere compreso tra 0 e 9999
    int bisestile = !(anno%400) || ( !(anno%4) && (anno%100) ); 
    int anno_minimo = 0; 
    int anno_max = 9999; 
    if (anno<anno_minimo || anno > anno_max){
        cout << "l'anno inserito non è valido!" << endl; 
        return false; 
    }
    // controllo per il giorno. 
    int giorno_minimo = 1; 
    int giorno_max = 31; 
    if (giorno<giorno_minimo || giorno>giorno_max){
        cout << "il giorno inserito non è valido!" << endl;
        return false; 
    }
    switch (mese)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        giorno_max = 31; 
        if (giorno>giorno_max)
            cout << "il mese non può avere più di 31 giorni. " << endl; 
        return false;
    case 2: 
        if (anno = bisestile){
            giorno_max = 29; 
            if (giorno == giorno_max){
                cout << "l'anno è bisestile quindi febbraio ha 29 giorni. " << endl; 
                return true; 
            }
        }
        else {
            giorno_max = 28; 
            if (giorno>giorno_max){
                cout << "febbraio non può avere più di 28 giorni!" << endl; 
                return false; 
            }
        }
    case 4: case 6: case 9: case 11: 
        giorno_max = 30; 
        if (giorno>giorno_max)
            cout << "il mese non può avere più di 30 giorni. " << endl; 
        return false; 
    default: 
        if (mese > 12 || mese <1)
            cout << "il mese deve essere compreso tra 1 e 12!" << endl; ; 
        return false;
    }
    return true; 
}
int main(){
    int giorno; 
    int mese; 
    int anno; 
    cout << "Inserisci tre numeri che rappresentino la data nel seguente formato (GG/MM/AAAA): "; 
    cin>>giorno>>mese>>anno;
    controllo(giorno, mese, anno); 
    return 0; 
}








// funzione con gli if
/*int controllo (int giorno, int mese, int anno){
    // controlli per il giorno. 
    int giorno_minimo = 1; 
    int giorno_max = 31; 
    if (giorno<giorno_minimo || giorno>giorno_max)
        cout << "il giorno inserito non è valido!" << endl; 
    // controlli per il mese
    if (mese<1 || mese >12)
        cout << "il mese inserito non è valido!" << endl; 
    if (mese == 2){
        giorno_max == 28; 
        cout << "il mese di febbraio non può avere più di 28 giorni" << endl; 
    }
    if (mese == 11 || mese == 4 || mese == 6 || mese == 9){
        if (giorno >30)
            cout << "aprile, giugno, settembre e novembre non possono avere più di 30 giorni. " << endl; 
    }
    else{
        giorno_max == 31;  
    }
    // controlli per l'anno
    int anno_minimo = 1000; 
    int anno_max = 2023; 
    if (anno<anno_minimo || anno>anno_max)
        cout << "l'anno inserito non è valido!" << endl; 
    return giorno, mese, anno; 
}
*/