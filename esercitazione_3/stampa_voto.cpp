/*Scrivere un programma che legge il voto preso in Programmazione ! e, se il voto è superiore a 27 stampa "Programmazione 1 è veramente uno dei migliori corsi di informatica" altrimenti stampa, "Quel def... di docente di quel noioso...." */
#include <iostream>
using namespace std; 
int main ()
{
    int a; 
    int b = 27; 
    cout << "Inserisci il voto che vorresti prendere all'esame di programmazione: " << endl; 
    cin >> a; 
    if (a>=b)
        cout << "Programmazione 1 è veramente uno dei migliori corsi di informatica!!\n"; 
    else 
        cout << "Prof, vada a casa!!" << endl; 
    return 0; 
}