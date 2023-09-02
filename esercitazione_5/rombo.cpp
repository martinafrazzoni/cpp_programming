/*stampare un rombo pieno di lato n*/
#include <iostream>
using namespace std; 
int main (){
    int lato;
    const int lato_max = 10;  
    do {
        cout << "Inserisci il valore dle lato del triangolo: \n"; 
        cin>>lato; 
    }
    while (lato<0 || lato>lato_max); 
    
    for (int i = 0; i <= lato; i++){
        for (int j = 0; j <= lato-i; j++){
            cout << " "; 
        }
        for (int k = 0; k <= i; k++){
            cout <<" #"; 
        }
        cout << endl; 
    }
 //ho usato delle variabili con gli stessi nomi, ma è stato un caso. Se cambio i nomi il programma funziona lo stesso, perchè nel primo ciclo for la visibilità delle variabili, è limitata a quel ciclo lì. Quindi non le avrei potute comunque riutilizzare nel disegnare il triangolo rovesciato (il rombo). 
    for (int i = lato-1; i>=0; i--){ //ho messo lato -1 così mi stampa una sola base e non due, visto che con il primo for la i va da 0 a minore uguale di lato, questo for parte da lato-1. 
            for (int j = lato-i; j>=0; j--){
                cout << " "; 
            } 
            for (int k=i; k>=0; k--){
                cout << " #"; 
            }
            cout << endl; 
        }
return 0; 
}




 
        
       
