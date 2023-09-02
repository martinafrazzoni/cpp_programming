/*Data una serie di rilevazioni al più di 100 temperature espresse in gradi Kevin da memorizzare in un vettore, si calcoli la media delle temperature effettivamente fornite e si ristampino solo le temperature al di sopra della media. */

#include <iostream>
using namespace std; 

void inserisci_temp (double vett [ ], int m){
    double k; 
    double min_k = 0; 
    double max_k = 273.16; 
    for (int i = 0, y = 1; i < m; i++, y++){
        do {
            cout << "Inserisci la temperatura in gradi kelvin: (elemento " << y << "/" << m << "): "; 
            cin>>k;
        }
        while (k< min_k || k > max_k); 
        vett[i] = k; 
    }
}

void calcola_media_temp (double vett [ ], double vet_media[ ], int m){
    double somma = 0; 
    for (int i = 0, y = 1; i < m; i++, y++){
        somma += vett[i]; 
    }
    cout << endl; 
    cout << "La somma delle temperature è: " << somma << endl; 
    double media = (somma / m); 
    cout << "la media delle temperature è: " << media << endl; 
    cout << endl; 
    cout << "Le temperature sopra la media sono: " << endl; 
    for (int i = 0, y = 1; i < m; i++, y++){
        if (vett[i] > media){
            vet_media[i] = vett[i];
            cout << "Elemento (" << y << "/" << m << "): " << vet_media[i] << " K" << endl; 
        }
             
    }
}


int main(){
    const int max_m = 100; 
    double vett[max_m]; 
    
    // chiedo in input il quante temperature vengono effettivamente rilevate. 
    int m; 
    do{
        cout << "Quante temperature vengono effettivamente rilevate? "; 
        cin>>m; 
    }
    while(m<0 || m>100); 
    
    // chiedo in imput le temperature e le metto dentro l'array. 
    inserisci_temp(vett, m); 
    
    // nuovo array che contiene le temperature sopra la media.
    double vet_media [max_m]; 
    calcola_media_temp(vett, vet_media, m); 

    return 0; 
}