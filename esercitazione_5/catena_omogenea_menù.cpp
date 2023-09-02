/* Scrivere un programma per la gestione di una catena di anelli tutti di ferro. Gli anelli della catena sono numerati a partire da 1. All'inizio la catena è vuota.
Il programma deve fornire il seguente menù di operazioni: 
1. Inserire un anello in posizione j (un anello alla volta). Le posizioni ammissibili vanno dalla posizione 1 a quella immediatamente successiva all'ultima. Il programma da un messaggio di notifica nel caso in cui non sia possibile effettuare l'inserimento. Se l'inserimento ha successo il numero totale di anelli aumenta ovviamente di una unità. Non esiste un limite al numero di anelli che si possono inserire. 
2. Eliminare l'anello in posizione j (un anello alla volta). Il programma da un messaggio di notifica nel caso in cui non sia possibile effettuare l'estrazione, altrimenti il numero di anelli diminuisce di una unità. (non rimangono buchi nella catena.)
3.Stampare la catena nel seguente formato: 
FFFF
dove la F indica un anello di ferro. In questo esempio la catena ha 4 anelli. 
4. terminare. 
Dopo aver eseguito una delle operazioni possibili, il menù è riproposto. realizzare prima solo il menù sostituendo ciascuna funzionalità con una semplice stampa del numero dell'operazione scelta. 
*/

#include <iostream>
using namespace std; 
int main (){
    int n; 
    int max_operazioni = 4; 
    int posizione; 
    int j; 
    int somma_catena = 0; 
    while (true){
        do{
            cout << "Gestione di una catena \n"; 
            cout << "Inserisci il numero dell'operazione che vuoi eseguire: \n";
            " 1. Inserire anello in posizione j \n"; 
            " 2. Eliminare anello in posizione j \n"; 
            " 3. Stampare la catena \n"; 
            " 4. terminare \n"; 
            cin>>n; 
        }
        while (n<0 || n>max_operazioni); 
        switch (n) {
        case 1:
            cout << "Scegli la posizione dove inserire l'anello: \n"; 
            cin>>posizione; 
            if (posizione <=0 || posizione>somma_catena+ 1) {
                cout << "Non è possibile effettuare l'inserimento" << endl; 
                break;
            }
            somma_catena += 1; 
            break;
        case 2: 
            cout << "Inserisci la posizione dell'anello che vuoi eliminare: \n"; 
            cin>>posizione; 
            if (posizione <= 0 || posizione>somma_catena+1){
                cout << "non è possibil effettuare l'estrazione \n";  
            } 
            somma_catena -= 1; 
            break;
        case 3: 
            cout << "Hai scelto di stampare la catena: \n"; 
            for (int i = 0; i < somma_catena; i++){
                cout << "F"; 
            }
            cout << endl; 
            break;
        case 4: 
            cout << "Terminare. \n"; 
            return 0; 
        default:
            cout << "Scelta errata! \n"; 
        }
    }
    return 0; 
}