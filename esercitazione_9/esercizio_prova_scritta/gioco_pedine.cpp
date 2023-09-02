#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std; 

int lancia_dado(){
    // implementiamo il lancio del dado, che genera dei numeri da 1 e 6. 
    // generiamo numeri random dalla lbreria cstdlib

    int roll = 0; // memorizza il numero di lanci. 
    roll = (rand() % 6) + 1; 
    return roll; 
}

int main(){
    const int N = 10; 
    int caselle[N]; 

    srand((unsigned int)time(0)); // la funzione time ritorna un valore di tipo time_t. ma la funzione srand prende come parametro un unsigned int. 

    // ad inizio partita, parte il giocatore_1 che si trova in posizione 0. 
    int pos_giocatore_1 = 0; 
    int pos_giocatore_2 = 0; 
    int turno = 1; 

    while (pos_giocatore_1 < N && pos_giocatore_2 < N){
        // invochiamo la funzione del lancio del dado: 
        int dado = lancia_dado(); 
        if (turno == 1){
            // la posizione del giocatore_! all'interno dell'array casella è uguale a pos_giocatore_1 + dado: 
            pos_giocatore_1 += dado; 
            cout << "Il giocatore_1 lancia il dado e viene fuori: " << dado << endl; 
            cout << "La posizione del giocatore 1 è pari a: " << pos_giocatore_1 << endl; 
            turno = 2; 
        }
        else{
            // adesso è il turno del giocatore_2
            dado = lancia_dado(); 
            pos_giocatore_2 += dado; 
            cout << "Il giocatore_2 lancia il dado e viene fuori: " << dado << endl; 
            cout << "La posizione del giocatore 2 è pari a: " << pos_giocatore_2 << endl; 
            turno = 1; 
        }
    }
    
    // poi facciamo il controllo se la posizione del giocatore_1 o del giocatore_2 è maggiore o uguale al numero massimo di caselle dell'array
    if (pos_giocatore_1 >= N)
        cout << "Il giocatore 1 è il vincitore!" << endl; 
    else if (pos_giocatore_2 >= N)
        cout << "Il giocatore 2 è il vincitore!" << endl; 
    return 0; 
}