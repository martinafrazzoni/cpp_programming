/*Data una serie di rilevazioni al più di 100 temperature espresse in gradi Kevin da memorizzare in un vettore, si calcoli la media delle temperature effettivamente fornite e si ristampino solo le temperature al di sopra della media.
variante. L'utente non comunica il numero di temperature m da memorizzare.  */

#include <iostream>
using namespace std; 

void inserisci_temp (double vett [ ], double vet_media [ ], const int max_m){
    double k; 
    //double min_k = 0; 
    //double max_k = 273.16; 
    int cont = 0; 
    for (int i = 0, y = 1; i < max_m; i++, y++){
        cout << "Inserisci la temperatura in gradi kelvin, inserire -1 per terminare la lettura: (elemento " << y << "/" << max_m << "): "; 
        cin>>k;
        if (k <= -1){
            vett[i] = k; 
            break;
        }
        else{
            vett[i] = k; 
            cont ++; 
        }
    }
    cout << "Numero elementi validi dell'array:  " << cont << endl; // NON c'è compreso anche il temrinatore.  

    double somma; 
    for (int i = 0; i <=cont; i++){
        somma += vett[i]; 
    }
    cout << "La somma delle temperature è: " << somma << endl; 
    double media = (somma / cont); 
    cout << "la media delle temperature è: " << media <<  endl;  
    cout << "Le temperature sopra la media sono: " <<  endl; 
    for (int i = 0, y = 1; i < cont; i++, y++){
        if (vett[i] > media){
            vet_media[i] = vett[i];
            cout << "Elemento (" << y << "/" << max_m << "): " << vet_media[i] << " K" << endl; 
        }
    }

}


int main(){
    const int max_m = 100; 
    double vett[max_m]; 
    double vet_media [max_m]; 
   
    inserisci_temp(vett, vet_media, max_m); 

    return 0; 
}