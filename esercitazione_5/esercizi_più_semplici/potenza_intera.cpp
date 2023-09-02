/*Scrivere un programma che legga in ingresso un numero intero a. ed un numero esponente intero non negativo i, e stampi il valore di a ^ i. Se l'esponente immesso dall'utente non fosse positivo il programma stampa un messaggio di errore ed esce.  */
#include <iostream>
using namespace std; 
int main (){
    int max_int = 2147483647; 
    int min_int = (-max_int -1);
    int P = 1; 
    int a; 
    int i; 
    cout << "Immettere un numero intero: \n"; 
    cin>>a;
    do{
        cout << "Inserire un esponente intero non negativo: \n"; 
        cin>>i; 
        if (i <= 0){
            cout << "Il valore inserito non è corretto! \n"; 
            return 1;
        }
    }
    while (i < 0); 
    for (int j = 0; j < i; j++){
        P*=a; 
    }
    if ((P>max_int/a) || (P<min_int/a)){
            cout << "Attenzione il risultato non è attendibile perchè c'è stato overflow! \n"; 
    }
    else cout << a << " ^ " << i << " = " << P << endl; 
    return 0; 
}