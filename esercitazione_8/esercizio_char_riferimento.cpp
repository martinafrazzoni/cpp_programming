/*Definire una funzione che prenda in ingresso un oggetto di tipo carattere e, se si trattad i una lettera minuscola, lo trasformi nella corrispondente lettera maiuscola. La funzione deve ritornare vero se la conversione è avvenuta, falso altrimenti.   
-	Tipo del parametro? il parametro formale passato per riferimento alla funzione è di tipo char. 
-	Tipo del valore di ritorno? il valore di ritorno della funzione è di tipo bool. 
-	Direzione del parametro? è un parametro sia di ingresso che di uscita. 
*/
#include <iostream>
using namespace std; 
bool trasforma_lettera(char &c){ 
    if (c>='a' && c<='z'){
        int posizione = 1; 
        for (char i = 'a'; i < c ; i++){
            posizione ++; 
            if (i == c)
                break;
        }
        c = ('A' + posizione -1); 
        return true; 
    }
    else 
        return false; 
}
int main(){
    char c; 
    cout << "Inserisci una lettera miniscola: "; 
    cin>>c; 
    if (trasforma_lettera(c))
        cout << "la corrispondente lettera maiuscola è: " << c << endl; 
    else
        cout << "Il carattere inserito non è una lettera minuscola!" << endl; 
    return 0; 
}