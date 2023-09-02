/*
Realizzare un programma che legge in ingresso un intero e, se il
valore inserito appartiene all'insieme dei codici ASCII dei caratteri
stampabili, stampa il carattere corrispondente. Altrimenti stampa un
messaggio di errore.  Scrivere il programma supponendo, prima, di
conoscere i codici ASCII dei caratteri (potete trovare la tabella sul
WEB). 

Poi modificarlo in maniera tale da NON USARE esplicitamente i
codici dei caratteri, ma assumendo di sapere solo che i codici dei
caratteri stampabili appartengono all'intervallo che va dal codice del
carattere ' ' (spazio) al codice del carattere '~'. Ovviamente non
conosciamo neanche il codice dei due estremi, ossia dei caratteri ' '
e '~'.

Scrivere il programma utilizzando una variabile di tipo int per
memorizzare il codice. Per gestire il caso in cui si stampi
effettivamente il carattere, realizzare la stampa assegnando tale
codice ad una seconda variabile di tipo char e stampando tale
variabile.

Assumere che in un assegnamento in cui si ha come lvalue (ossia a
sinistra dell'assegnamento) l'indirizzo di una variabile di tipo char,
NON SI POSSA avere come rvalue (ossia a destra dell'assegnamento) un
valore di tipo int.

Un possibile output sullo schermo e' il seguente:
Inserisci il codice ASCII di un carattere: 77
Il carattere corrispondente e':	M
*/
#include <iostream>
using namespace std; 
int main(){
    // scrivo il programma supponendo di sapere solo gli estremi ' ' e '~'
    int n; 
    char char_min = ' '; 
    char char_max = '~'; 

    int cod_min = static_cast<int>(char_min); // codice che corrisponde allo spazio nella tabella ASCII
    int cod_max = static_cast<int>(char_max); // codice che corrisponde alla tilde nella tabella ASCII
    
    cout << "Inserisci il codice ASCII di un carattere che sia nell'intervallo tra ' ' e '~':  "; 
    cin>>n;
    char carattere = static_cast<char>(n); 
    if (carattere > char_min && carattere < char_max)
        cout << "Il carattere corrispondente è: " << carattere << endl; 
    else 
        cout << "hai inserito un codice che non corrisponde a nessun carattere. " << endl; 

    return 0; 
}

/*
Al posto dell'if si può anche fare: 
do {
    cout << "Inserisci il codice ASCII di un carattere che sia nell'intervallo tra ' ' e '~':  "; 
    cin>>n;
}
while (n<cod_min || n > cod_max)
char carattere = static_cast<char>(n); 
cout << "il carattere corrispondente è " << carattere << endl;*/



/* scrivo il programma supponendo di conoscere il codice ASCII
    int n; 
    const int min_char = 32; 
    const int max_char = 126; 
    do{
        cout << "Inserisci un numero intero compreso tra 33 e 126: "; 
        cin>>n;
    }
    while (n<min_char || n>max_char); 
    char carattere = static_cast<char>(n); 
    cout << "Il carattere corrispondente è: " << carattere << endl; */