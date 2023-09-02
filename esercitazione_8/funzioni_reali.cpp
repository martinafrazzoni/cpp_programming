/*
 Includendo il file di intestazione <cmath>, si posso utilizzare una
 serie di funzioni matematiche. Le seguenti tre funzioni sono tra queste

 // Ritorna il valore assoluto di x
 double fabs(double x) ;

 // Ritorna il valore del minimo numero intero maggiore o uguale ad x
 // (il tipo di ritorno e' pero' double)
 double ceil(double x) ;

 // Ritorna il valore del massimo numero intero minore o uguale ad x
 // (il tipo di ritorno e' pero' double)
 double floor(double x) ;

 Per esercizio, realizzare una propria versione di ciascuna di queste
 funzioni, con nome modificato per evitare conflitti di nome.
*/
#include <iostream>
#include <cmath>
using namespace std; 
double assoluto(double x){
    double ris = (x>=0) ? x : -x; 
    return ris; 
}

double min_int (double x){
    int y = static_cast<int>(x); 
    double num = static_cast<double>(y); 
    return num; 
}


double max_int (double x){
    double y = x - 1; 
    int y_int = static_cast<int>(y); 
    double num = static_cast<double>(y_int); 
    return num; 
}

int main(){
    double x; 
    cout << "Inserisci un numero double: "; 
    cin>>x; 
    // calcolo il valore assoluto di x
    cout << "Il valore assoluto di " << x << " è: " << assoluto(x) << endl; 

    // minimo numero intero minore o uguale a x
    cout << "il valore del minimo numero intero minore o uguale a " <<  x <<  " è: " << min_int (x) << endl; 

    // massimo numero intero maggiore o uguale a x
    cout << "il valore del massimo numero intero maggiore o uguale a " << x << " è: " << max_int(x) << endl; 
}
 
