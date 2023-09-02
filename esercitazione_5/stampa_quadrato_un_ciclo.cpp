/* Scrivere un programma che richieda all'utente di inserire un numero intero positivo non maggiore di una costante positiva a scelta, e costruisce un quadrato pieno di lato pari al numero scelto e riempito con il carattere #. utilizzare un unico ciclo non nidificato. 
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
    while ((n<1) || (n>k)); // faccio il controllo dell'input

    for (int i = 0; i<(n*n); i++){
      cout << " # "; 
      //io voglio andare a capo quando finisco una riga, ovvero quando stampo n#, poi quando avrò stampato altri n# e così via. 
         if ((i+1)%n == 0) //aritmetica modulare. facendo i + 1 % n (il mio lato), il modulo verrà zero solo se i è un multiplo di n. se io ho n = 3, 3%3 = 0, ma anche se ho 6%3, oppure anche 9 etc.... 
            cout<<endl; 
    }  
    return 0; 
 }