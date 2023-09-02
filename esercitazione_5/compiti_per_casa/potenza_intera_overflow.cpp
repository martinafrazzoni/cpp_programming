/*Scrivere un programma che legga in ingresso un numero intero a ed un 
 * esponente intero non negativo i, e stampi il valore di a^i.
 * Il programma controlla anche che l'operazione richiesta non generi overflow.
 * Se l'esponente immesso dall'utente non fosse positivo il programma stampa 
 * un messaggio d'errore ed esce.
 * 
 *
 * Esempi:
 *
 * Immettere un numero intero: 3
 * Immettere un esponente non negativo: 2
 * 3 ^ 2 = 9
 * Non c'è stato overflow
 *
 * Immettere un numero intero: 5
 * Immettere un esponente non negativo: 213
 * Risultato non esprimibile su un oggetto di tipo int
 *
 * Ottenete la soluzione combinando le soluzioni dell'esercizio sulla
 * somma di due interi visto in laboratorio e dell'esercizio potenza_intera.c
 */

#include <iostream>
using namespace std; 
int main(){
    int a; // numero intero 
    int i; // esponente di a
    int cont = 1; // contatore, dove accumulo il risultato di a^i
    int max_int = 2147483647; 
    int min_int = (-max_int -1); 

    cout << "inserisci un numero intero \n";
    cin>>a; 
    cout << "Inserisci un numero intero non negativo \n"; 
    cin>>i; 
    if (i<0){
        cout << "hai inserito un numero negativo \n"; 
        return 1; 
    }         
    for (int j = 0; j<i; j++){
        cont*=a; 
        cout<<cont; 
    }
    
    if ((cont>(max_int/=a)) || (cont<(min_int/=a))){
        cout << "Attenzione: il risultato non è esprimibile su un oggetto di tipo int"<< endl; 
    }
    else{
        cout << a << "^" << i << "=" << cont << endl;
        cout<< "il risultato non ha generato overflow" << endl; 
    }
        
        
    return 0; 
}