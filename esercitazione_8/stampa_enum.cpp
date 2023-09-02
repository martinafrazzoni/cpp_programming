/*
  Scrivere un programma in cui si dichiari un tipo enumerato giorno,
  rappresentante i giorni della settimana, e si stampino i valori
  dei 7 enumeratori (senza usare cicli). Quindi si definisca una
  variabile di tipo giorno, le si assegni uno degli enumeratori a
  piacere, e la si stampi.
 */
#include <iostream>
using namespace std; 
enum giorno_t {lunedì, martedì, mercoledì, giovedì, venerdì, sabato, domenica}; 
int main(){

    cout << lunedì << endl; 
    cout << martedì << endl;
    cout << mercoledì << endl; 
    cout << giovedì << endl; 
    cout << venerdì << endl; 
    cout << sabato << endl; 
    cout << domenica << endl; 

    giorno_t giorno; 
    giorno = martedì; 
    cout << giorno << endl;  
    return 0;
}
