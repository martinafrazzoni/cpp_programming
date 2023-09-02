/* Scrivere un programma che richieda all'utente di inserire un numero intero positivo non maggiore di una costante positiva a scelta, e costruisce un quadrato pieno di lato pari al numero scelto e riempito con il carattere #. 
Lato: 3
***
***
***
Se abbiamo difficoltà partiamo dallo stampare solo una riga
 */
 #include <iostream>
 using namespace std; 
 int main (){
    int n; 
    const int k = 10;  //costante positiva a scelta
    do {
        cout << "Lato: "; 
        cin>>n; 
    }
    while ((n<1) || (n>k)); // il ciclo do while mi permette di sapere se lato viene sempre passato come valore coerente. 

    for (int j = 1; j <= n;  j ++) { // questo for qui mi stampa quante righe voglio. ripetendo n volte (lunghezza del lato) con j, riusciremo a stampare un quadrato. 
            for (int i = 1; i <= n; i++){ // il primo ciclo mi ha stampato la singola riga. 
               cout << " # ";} // non stampo l'andata a capo perchè quando ho finito una riga andrò a capo. 
            cout << endl; 
    }
    return 0; 
 }