/*Generazione chiavi RSA

Implementare l'algoritmo di generazione delle chiavi. In particolare
scrivere un programma che prende in ingresso il valore massimo e
minimo che possono assumere i due numeri primi iniziali.

Puo' tornarvi utile la funzione di libreria rand(), che genera un
numero casuale compreso tra 0 e RAND_MAX, ove RAND_MAX è una costante
predefinita (di cui quindi non si può cambiare il valore).  Essa
permette di generare una sequenza di numeri pseudocasuali.  Tali
numeri si definiscono pseudocasuali perche', fissato il primo valore
della sequenza (chiamato seme), e' fissata tutta la sequenza di valori
che saranno generati nelle successive invocazioni della funzione
rand().  Infatti i numeri sono generati mediante una certa funzione
f(x) che, dato l'ultimo valore x generato, genera il prossimo valore
random.  Facciamo un esempio: supponiamo di aver dato come seme il
valore 1. Allora il primo valore generato dalla funzione rand() sara†¢
41 (se la funzione rand() sulla vostra macchina e' basata sullo stesso
algoritmo della funzione sulla mia macchina). La prossima volta che
verra' invocata la funzione rand() si otterra' il valore f(41), che e'
pari a 18647. Alla successiva invocazione si otterra' il valore di
f(18647), che e' pari a 6334, e cosi' via.  Pertanto, per ottenere
sequenze diverse, bisogna cambiare il valore del seme. Per cambiare il
valore del seme, si utilizza la funzione srand(n), ove n e' il nuovo
valore che si vuol dare al seme.

Per utilizzare le funzioni rand() ed srand(n) (e la costante
RAND_MAX), bisogna includere il file di intestazione "cstdlib".*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std; 
bool primo(unsigned n){
    // prima funzione che, dato un numero intero n passato come parametro ritorna true se il numero è primo altrimenti false.
    if (n>=1 && n<=3) // guardo se il valore di i è compreso tra 1 e 3. 
        return true; 

    int res = (n%2); // guardo se i è pari, se è pari non è primo.
    if (n%2 == 0){
        return false; 
    }

    else {
        if (n%2==1 && n>3){
            unsigned rad = static_cast<unsigned>(sqrt(n)); 
            for (unsigned i = 3; i<=rad; i+=2){
                int resto = n%i; 
                if (resto == 0){
                    return false;
                }
            }
        }
    }
    return true; 
}

unsigned calcolo_r (unsigned r, unsigned p, unsigned q){
    r = p*q; 
    return r; 
}

unsigned calcolo_f(unsigned f, unsigned p, unsigned q){
    f = (p-1)*(q-1); 
    return f; 
}


int main(){
   /*algoritmo generazione delle chiavi: 
   1. generare due numeri primi distinti molto grandi p e q */
    unsigned p; // primo che verrà chiesto in input. 
    unsigned q; // primo che verrà chiesto in input. 

    unsigned r; // r = p*q
    unsigned f; //f =  (p-1)*(q-1)
    unsigned e; // e<f e primo con f. 
    unsigned d; // (d*e) mod f  = 1. 
    
    // controllo se i due numeri che vado a chiedere in input sono primi o no. 
    do{
        cout << "Inserisci due numeri primi: "; 
        cin>>p>>q; // visto che sono unsigned, mi dà errore se provo ad immettere numeri che sono minori di 0.  
        if (primo(p) && primo(q))
            cout << "i due numeri inseriti sono primi! " << endl; 
    }
    while (primo(p) == false || primo(q) == false); 

    // adesso che ho p e q posso fare il prodotto. 
    cout <<"r vale: " <<  calcolo_r(r, p, q) << endl; 

    // calcoliamo quando vale f. 
    cout << "f vale: " <<  calcolo_f(f, p, q)  << endl; 
    
    // adesso devo trovare e: e deve essere minore di f e primo con f.
    for (unsigned i = 2; i < calcolo_f(f, p, q); i++){
        unsigned resto = (calcolo_f(f, p, q) % i); 
        if (resto != 0){
            e = i; 
            break;
        }
    } 
    cout << "e vale: "<< e << endl; 


    // adesso calcolo d. 
    unsigned k = 1; // costante. 
    while (((k*calcolo_f(f, p, q))+1)%e != 0){
        k++; // incremento k quando non trovo un valore intero. 
    }
    d = ((k*calcolo_f(f, p, q))+1)/e; 
    cout <<"d vale: " <<  d << endl; 

    cout << "la chiave RSA è: " << e << ", " << d << ", " << calcolo_r(r, p, q) << endl; 

    return 0; 
}