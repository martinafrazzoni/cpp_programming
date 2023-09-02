/* Esercizio
Scrivere un programma che calcoli le radici reali di equazioni di secondo 
grado.
In particolare il programma legge da tastiera quante equazioni
si vuole risolvere, e, per ognuna, legge i tre coefficienti e stampa il 
risultato.

inoltre, per ciascuna equazione, il programma segnala esplicitamente
se l'equazione è degenere, se ha una sola radice, se ha due radici
(eventualmente coincidenti) e se non ne ha.
*/
#include <iostream>
#include <cmath>
using namespace std; 
int main(){
    double a, b, c; 
    cout << "Inserisci i tre valori dell'equazione, a, b, c:  "; 
    cin>>a>>b>>c; 

    double delta = (b*b) - ((4*a)*c); 
    double rad_delta = sqrt(delta); 

    if (delta > 0){
        cout << "l'equazione ammette due soluzioni reali: "; 
        double dividendo = (rad_delta + (-(b))); 
        double divisore = (2*a); 
        double primo_ris = dividendo / divisore; 
        cout << "la prima soluzione è: " << primo_ris << endl; 

         // seconda soluzione 
        double dividendo_2 = (-b - rad_delta); 
        double divisore_2 = (2*a); 
        double secondo_ris = dividendo_2 / divisore_2; 
        cout << "la seconda soluzione è: " << secondo_ris << endl; 
    }
    else if (delta < 0)
        cout << "l'equazione non ammette nessuna soluzione reale"; 
    else{
        cout << "l'equazione ammette un'unica soluzione reale (o due coincidenti)! " << endl; 
        double dividendo = (rad_delta + (-(b))); 
        double divisore = (2*a); 
        double primo_ris = dividendo / divisore; 
        cout << "la soluzione dell'equazione è: " << primo_ris << endl; 
    }
        
    return 0;  
}