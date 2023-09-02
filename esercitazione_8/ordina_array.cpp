/*
Scrivere un programma che chieda all'utente di inserire un numero di
valori interi prefissato (a tempo di scrittura del programma),
li inserisca in un vettore, stampi il vettore risultante, lo ordini poi in
senso crescente, e lo stampi nuovamente.
Implementare l'ordinamento all'interno di una funzione a cui viene passato
sia l'array che le sue dimensioni.
*/

void selection_sort (int a [ ], int n){ // la funzione ha come tipo di ritorno void perchè non deve ritornare nessun valore ma deve solo modificare l'array. 
    int minimo;
    int temp; 
    for(int i=0; i<(n-1); i++){  // mi scansiona l'array un indice alla volta, partendo dal primo che è 0. La condizione è n-1 perchè esamina l'array non fino all'ultimo indice ma fino al penultimo indice. 
    // dobbiamo trovare sempre qual'è l'elemento più piccolo nella parte di array che non è ancora stata ordinata, e scambieremo quel valore con l'indice di posto i. 
	minimo=i; // assumiamo che il valore più piccolo sia dentro l'elemento di indice i.  
        for(int j = (i+1); j<n; j++) // usiamo un altro for per guardare ai valori memorizzati nella parte non ordinata dell'array. i+1 guarda alla parte rimanente dell'array, e non appena trova un elemento più piccolo dell'elemento in posizione minimo, quindi aggiorna minimo e lo setta all'indice dell'elemento più piccolo che trova, che sarebbe j. 
        	if (a[j] < a[minimo])
        	     minimo = j; // minimo conterrà l'indice dell'elemento più piccolo nella parte non ordinata dell'array. 
        // per fare lo scambio: ovvero devo mettere il valore più piccolo che ho trovato all'inizio dell'array, in posizione a[i]. Quindi ho bisogno di una variabile temporanea che chiamo temp. La procedura è sempre la stessa che abbiamo usato per scambiare le variabili. 
        temp = a[minimo]; // dentro temp, la mia variabile di appoggio ci vado a mettere il valore minimo che ho trovato dentro l'array che è 2. 
        a[minimo] = a[i]; // dentro l'elemento a[minimo] ci vado a mettere il valore che è contenuto in a[i] con i = 0, quindi nella prima cella del mio array. 
        a[i] = temp;  // poi dentro a[i] ci metto il valore minimo che ho trovato dentro l'arrat, che l'avevo messo nella variabile temporanea temp. 
    }
}  


#include <iostream>
using namespace std; 
int main(){
    const int n = 4; 
    int a [n]; 

    for (int i = 0, y=1; i < n; i++, y++){
        cout << "Inserisci un valore (Elemento: " << y << "/" << n << "): "; 
        cin>>a[i]; 
    }

    cout << endl; 

    for (int i = 0, y = 1; i<n; i++, y++){
        cout << "Elemento " << y << "/" << n << ": "; 
        cout << a[i] << endl; 
    }

    cout << endl; 

    selection_sort(a, n); 
    
    cout << "Array ordinato con selection sort: " << endl; 
    for (int i = 0; i < n; i++){
        cout << "a[" << i << "] = " << a[i] << endl; 
    }

    return 0; 
}

