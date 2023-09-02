#include <iostream>
using namespace std;
int durata_ricevimento(int tempo_domande, int intervallo, int durata_tel){
    int durata = tempo_domande; // la durata prevista per il colloquio.  
    int durata_precedente; // variabile in cui vad a mettere la durata se aumenta.
    do{
        int numero_interruzioni; // numero di interruzioni durante il ricevimento. 
        durata_precedente = durata; 
        numero_interruzioni = durata / intervallo; 
        cout << "[durata_ricevimento]: il numero di interruzioni è pari a " << numero_interruzioni << endl; 
        // calcoliamo il numero di interruzioni che ci saranno durante la durata presunta.<
        if ((durata%intervallo) != 0)
            numero_interruzioni++; 
        cout << "[durata_ricevimento]: il numero di interruzioni dopo l'if è pari a " << numero_interruzioni << endl; 
        durata = tempo_domande + (numero_interruzioni * durata_tel); 
        cout << "[durata_ricevimento]" <<  durata << endl;  
    } 
    while (durata != durata_precedente); // finchè la durata è diversa dalla durata precedente il ciclo continua. Quando la condizione diventa falsa si ferma. 
    return durata; 
}



int main(){
    int tempo_domande; 
    int intervallo; 
    int durata_tel; 
    cout << "In quanti minuti speri di riuscire? "; 
    cin>>tempo_domande; 
    cout << "Ogni quanti minuti il professore riceve una chiamata? "; 
    cin>>intervallo; 
    cout << "Quanto dura ogni telefonata? "; 
    cin>>durata_tel; 
    if (durata_tel>=intervallo)
        cout << "Il prof sarà sempre al telefono e non finirai mai!"; 
    cout << "te la caverai in " << durata_ricevimento (tempo_domande, intervallo, durata_tel) << "minuti" << endl; 
    return 0; 
}