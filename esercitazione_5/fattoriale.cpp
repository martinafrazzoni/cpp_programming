  /* Calcolare il fattoriale di un numero naturale immesso da un utente.
   Il fattoriale di un numero naturale N è calcolabile come:
   N! = N *(N-1)*(N-2)*...*2*1
   inoltre, per definizione:
   1!=1
   0!=1

   Trascurare problemi di overflow.
*/
/*fattoriale: è il prodotto che otteniamo moltiplicando tale numero per tutti i numeri (interi, positivi, quindi maggiori di zero), che sono minori del numero stesso. */

#include <iostream>
using namespace std; 
int main (){
    int n; // numero naturale immesso 
    do {
        cout << "Inserisci un numero intero n: \n"; 
        cin>>n; 
        if (n<=0)
            cout << "Il numero n non può essere minore di zero \n"; 
    }
    while (n<=0);  
    int f=n; 
    int max_int = 2147483647; 
    int i = n-1; 
    for (i=n-1; i>1; i--){
        f *=i; //f=f*i
    }
    cout << "il fattoriale di " << n << " è " << f << endl; 
    if (i>(max_int/=f)){
        cout << "Attenzione il risultato non è attendibile perchè c'è stato overflow!\n"; // ho diviso per *=f
    }
return 0; 
}