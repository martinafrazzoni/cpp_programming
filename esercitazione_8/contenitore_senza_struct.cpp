/*
Contenitore

Un Contenitore e' in grado di contenere elementi in numero limitato (la			
capienza del contenitore). Ciascun elemento ha un nome che consiste in
una lettera (minuscola) dell'alfabeto. Piu' elementi di un contenitore
possono avere lo stesso nome. Le operazioni che possono essere effettuate
sul contenitore sono le seguenti:

.	Inizializza(N);
Inizializza il contenitore con capienza pari ad N elementi. Il
contenitore e' vuoto. L'eventuale contenuto precedente viene perso.

.	Inserisci(p)
Inserisce un elemento avente nome p.

.	Estrai(p)
Estrae dal contenitore tutti gli elementi aventi nome p.

.	Modifica(N)
Modifica la capienza del contenitore. Dopo la modifica il contenitore
ha capienza N e contenuto identico a quello originario. Affinche'
l'operazione abbia successo, il numero di elementi contenuti nel
contenitore deve essere minore od uguale ad N.

.	capienza()
Ritorna la capienza del contenitore.

.	quanti()
Ritorna il numero degli elementi presenti nel contenitore.

.	stampa()  

Stampa il contenuto del Contenitore. LŽ¢uscita ha la forma seguente:
		<a:3, d:1, s:5>
In questo esempio, nel contenitore sono presenti tre elementi di nome
'a', uno di nome 'd' e cinque di nome 's'.


Gestire opportunamente le condizioni di errore, tranne i problemi di
overflow e le condizioni di errore in lettura da stdin.

Nella soluzione e' contenuto anche un main, che potete eventualmente
utilizzare per testare le funzioni nella vostra soluzione. Svolgere
l'esercizio senza utilizzare il costrutto struct (non ancora visto a
lezione).
*/

#include <iostream>
#include <cstring>
using namespace std; 

void inizializza_contenitore (char a [ ], int dim_a){
    for (int i = 0; i < dim_a; i++){
        do{
            cout << "Inserisci una lettera minuscola per inizializzare il contenitore: "; 
            cin>>a[i]; 
        }
        while (a[i] < 'a' || a[i] > 'z'); 
    }

}

void inserisci_elemento(char a [ ], int &dim_a, const int capienza_max){
    // controllo se il contenitore ha raggiunto la sua capienza massima, se il numero totale degli elementi presenti è minore della grandezza massima allora aggiungo un elemento. 
    char valore = 0; 
    int index = 0; 
    int lungh = strlen(a); 
    if (lungh < capienza_max){
        
        cout << "Inserisci il valore del nuovo elemento: "; 
        cin>>valore;
        cout << "Inserisci l'indice in cui inserire il valore: "; 
        cin>>index; 
        for (int i = dim_a; i > index; i--){
           //parto dall'indice dell'ultimo elemento, lì dentro ci devo mettere il contenuto dell'elemento precedente, quindi quello che ha indice i -1, e così via, fino a quando non arrivo all'indice index. 
           a[i] = a[i - 1]; 
        }
        a[index] = valore; // adesso metto dentro l'elemento ha indice index il valore che ho chiesto in input prima. 
        dim_a++; 
    }
    else  
        cout << "Non è possibile inserire un nuovo valore, hai raggiunto la capienza massima!" << endl; 
}

void estrai_elemento(char a [ ], int &dim_a){
    int index; 
    // chiedo all'utente a quale indice vuole estrarre l'elemento, prima controllo che l'array non sia vuoto, nel caso non si può estrarre niente. 
    int lungh = strlen(a);
    if (lungh == 0)
        cout << "L'array è vuoto, non si può estrarre niente!"; 

    cout << "Inserisci l'indice dell'elemento che vuoi estrarre: "; 
    cin>>index; 
    //ciclo for che parte da index e arriva fino alla fine, tutti gli elementi che si trovano dopo index si sposteranno di 1 verso sinistra. 
    for (int i = index; i < dim_a; i++){
        a[i] = a[i+1]; 
    } 
    dim_a--; 
}

int modifica_capienza(char a [ ], int &dim_a, int capienza_max){
    
   do{
        cout << "Inserisci il nuovo numero di elementi da inserire nel contenitore: "; 
        cin>>dim_a; 
    }
    while (dim_a < 0 || dim_a > capienza_max); 
    return dim_a; 
}

int quanti_elementi (char a [ ], int dim_a){
    int lungh = strlen(a); 
    return lungh; 
}

int capienza_cont ( int capienza_max){
    return capienza_max; 
}

void stampa_contenitore (char a [ ], int dim_a){
    cout << "Ecco gli elementi contenuti all'interno del contenitore: "; 
    for (int i = 0; i < dim_a; i++){
        cout << a[i] << " "; 
    }
    cout << endl; 
}

int main(){

    int scelta; 
    const int capienza_max = 10; 
    char a [capienza_max]; 
    int dim_a;

    do{
        cout << "Inserisci il numero di elementi da inserire nel contenitore: "; 
        cin>>dim_a; 
    }
    while (dim_a < 0 && dim_a > capienza_max);
       
    
    while (true){
        cout << "1 - Inizializza il contenitore: \n"; 
        cout << "2 - Inserisci un elemento: \n"; 
        cout << "3 - Estrai dal contenitore un elemento: \n"; 
        cout << "4 - Modifica la capienza del contenitore. \n"; 
        cout << "5 - Ritorna la capienza del contenitore \n"; 
        cout << "6 - Ritorna il numero di elementi presenti nel contenitore: \n"; 
        cout << "7 - Stampa il contenuto del contenitore: \n"; 
        cout << endl; 


        cout << "Inserisci il numero dell'operazione che vuoi eseguire: ";
        cin>>scelta; 

        // switch 
        switch (scelta){
        case 1:  
            inizializza_contenitore(a, dim_a); 
            break;
        case 2: 
            cout << "Hai scelto di inserire un nuovo elemento nel contenitore: " << endl; 
            inserisci_elemento(a, dim_a, capienza_max); 
            break;
        case 3:
            cout << "Hai scelto di estrarre un elemento da contenitore: " << endl; 
            estrai_elemento (a, dim_a); 
            break;
        case 4: 
            modifica_capienza(a, dim_a, capienza_max); 
            break;
        case 5: 
            cout << "Il contenitore ha capienza pari a " << capienza_cont(capienza_max) << " elementi" << endl; 
            break;
        case 6: 
            cout << "Il numero di elementi del contenitore è pari a " << quanti_elementi(a, dim_a) << endl; 
            break;
        case 7:
            cout << "Hai scelto di stampare il contenuto del contenitore: " << endl; 
            stampa_contenitore(a, dim_a); 
            break;
        default:
            break;
        }
    }
    return 0; 
}
