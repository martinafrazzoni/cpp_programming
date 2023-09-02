/*
  Scrivere un programma contenente una funzione stampa_turno, che abbia 
  come parametro di ingresso un oggetto di tipo uguale al tipo di dato 
  rappresantante i giorni della settimana. Dato il giorno della settimana 
  passato in ingresso, la funzione stampa i turni di quel giorno. 
  Supporre che siano stati fissati i seguenti turni:
  Lunedi', Mercoledi' e Venerdi': mattina e pomeriggio
  Martedi' e Giovedi': solo mattina
  Sabato e Domenica: riposo.

  Nel main non si legge nulla da stdin, ma la funzione deve essere
  invocata per stampare i turni dei giorni di Lunedi', Giovedi',
  Domenica.

 */
#include <iostream>
using namespace std; 

enum giorni_settimana_t {lunedi, martedi, mercoledi, giovedi, venerdi, sabato, domenica}; 

void stampa_turno(giorni_settimana_t giorno){
    switch (giorno)
    {
    case lunedi: 
        cout << "Lunedi: Mattina e pomeriggio" << endl; 
        break;
    case martedi: 
        cout << "Martedì: solo mattina" << endl; 
        break;
    case mercoledi: 
        cout << "Mercoledi: Mattina e pomeriggio" << endl; 
        break;
    case giovedi: 
        cout << "Giovedi: solo mattina" << endl; 
        break;
    case venerdi: 
        cout << "Venerdi: Mattina e pomeriggio " << endl; 
        break;
    case sabato: 
        cout << "Sabato: riposo"<< endl; 
        break;
    case domenica: 
        cout << "Domenica: riposo"<< endl; 
        break;
    default:
        break;
    } 
}

int main(){ 
    giorni_settimana_t giorno; 
    stampa_turno(lunedi);     
    stampa_turno(giovedi);     
    stampa_turno(domenica);     
    return 0; 
}