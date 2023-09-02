/*La congettura di Goldbach è uno dei più vecchi problemi irrisolti
nella teoria dei numeri. Essa afferma che ogni numero pari maggiore di
2 può essere scritto come somma di due numeri primi (lo stesso numero
primo può essere usato due volte).  Nessuno finora e' riuscito a
dimostrare ne' che sia vera, ne' che sia falsa.

Scrivere un programma che, presi in ingresso due numeri interi
positivi maggiori di 2, verifica se vale la congettura di Goldbach per
tutti i numeri tra essi compresi. In altri termini, per ogni numero n
compreso in tale intervallo, il programma deve verificare se esistono
almeno due numeri primi p_1 e p_2 (con eventualmente p_1 = p_2) tali
che n = p_1 + p_2.

Il programma deve essere realizzato chiedendo i du e estremi
dell'intervallo all'utente nel main, e definendo/utilizzando due
ulteriori funzioni. La prima deve prendere in ingresso, come parametri
formali, gli estremi dell'intervallo e deve ritornare, se c'è, il
primo numero maggiore di 2 di tale intervallo che non rispetta la
congettura di Goldbach. La seconda funzione deve essere utilizzata per
realizzare la prima e, dato un numero n, deve ritornare vero se
rispetta la congettura di Goldbach e falso altrimenti.

Notare che ritornare un valore a chi chiama una funzione e' una cosa
diversa dallo stampare tale valore du stdout.  Riflettere sui modi
possibili per far ritornare, da parte della prima funzione,
l'indicazione che non ha trovato nessun numero che non verifichi la
congettura di Goldbach.*/

#include <iostream>
#include <cmath>
using namespace std; 
bool primo (int n){
    // prima funzione che, dato un numero intero n passato come parametro ritorna true se il numero è primo altrimenti false.
    if (n>=1 && n<=3) // guardo se il valore di i è compreso tra 1 e 3. 
        return true; 

    int res = (n%2); // guardo se i è pari, se è pari non è primo.
    if (n%2 == 0){
        return false; 
    }

    else {
        if (n%2==1 && n>3){
            int rad = static_cast<int>(sqrt(n)); 
            for (int i = 3; i<=rad; i+=2){
                int resto = n%i; 
                if (resto == 0){
                    return false;
                }
            }
        }
    }
    return true; 
}

int somma_primi(int primo_pari); 

int pari_in_intervallo(int minimo, int massimo){
    // ciclo for che mi trova i numeri pari nell'intervallo. 
    int primo_pari; 
    for (int i = minimo; i<=massimo; i++){
        int resto = (i%2); 
        if (resto == 0){
            primo_pari = i; 
            cout << "numero" << primo_pari << ": " << endl; 
            somma_primi(primo_pari); 
            cout << endl;
        }
   }
   return primo_pari; 
}


int somma_primi(int primo_pari){
   int somma; 
    // verifico per il primo numero pari che ho trovato con la funzione sopra, che la somma di due numeri primi mi dia quel numero pari. 
    for (int i = 2; i<=primo_pari; i++){
        primo(i); 
        if (primo(i)){
            int j = (primo_pari-i); 
            if (primo(j)){
                somma = (i+j); 
                cout << primo_pari << " è dato dalla somma di " << j << " + " << i << endl;  
            }
        }
   }
   return somma; 
}

int main(){
    int minimo, massimo; 
    do{
        cout << "Inserisci i due estremi dell'intervallo: "; 
        cin>>minimo>>massimo; 
    }
    while (minimo<2); 
    cout << pari_in_intervallo(minimo, massimo) << endl; 
    return 0; 
}




/*if (primo(i)){
            int somma = (i+i);
            if (somma == primo_pari){
                cout << "i vale "<< i << endl; 
                cout << "la somma di "<< i<< " + " << i <<  " é " << somma << " " << endl; 
                cout << somma << " è dato dalla somma dei numeri primi " << i << " + " << i << endl; 
                return 0; 
            }
        }*/