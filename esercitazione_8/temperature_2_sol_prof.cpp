#include <iostream>
using namespace std; 
int main(){
    const int max_m = 100; 
    double vett_temper [max_m]; 
    double media = 0; 

    cout << "Inseriamo i valori (immettere valore -1 per terminare): " << endl; 
    for (int i = 0, i < max_m; i++){
        cin>>vett_temper[i]; 
        if (vett_temper[i] < 0){
            vett_temper[i] = -1; 
            break; 
        }
    }

    /*se abbiamo inserito max_m elementi non ci sarà alcun terminatore, perchè il ciclo termina naturalmente*/

    int num_val_letti; 
    for (int num_val_letti = 0; (num_val_letti < max_m && vett_temper[num_val_letti] >=0); num_val_letti++){
        media += vett_temper[num_val_letti]; 
    } 
    media /= num_val_letti; 
    cout << "media: " << media << endl; 
    
    cout << "I valori superiorei alla media sono: " << endl; 
    for (int i = 0; i < max_m && vett_temper[i] > 0; i++){
        if (vett_temper[i] > media){
            cout << vett_temper[i] << endl; 
        }
    } 
    return 0; 
}