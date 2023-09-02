/*Definire una funzione che prenda in ingresso (parametro formale) un
oggetto di tipo carattere e, se si tratta di un carattere maiuscolo, lo
trasformi nel corrispondente carattere minuscolo. La funzione deve ritornare
vero se la conversione è avvenuta, falso altrimenti.
Scrivere quindi un main in cui si utilizzi tale funzione.*/

#include <iostream>
using namespace std; 

bool trasforma_maiuscolo(char c){
    int posizione = 0; 
    if (c >= 'a' && c <='z'){
        for (char i = 0; i < c; i++){
            posizione ++; 
            if (i == c)
                break;
        } 
        c = posizione + ('A'-1); 
        return true; 
    }
    else
        return false;   

}

int main(){
    char c; 
    cout << "Inserisci una costante carattere: "; 
    cin>>c; 

    cout << trasforma_maiuscolo(c) << endl;  

    return 0; 
}
