/**scrivere un programma che legge un numero intero da standard input (cin, stdin) che rappresenta il voto presto in Programmazione 1 e, se il voto è superiore a 27, stampa  "Programmazione 1 è veramente uno dei migliori corsi di informatica!!" altrimenti non stampa nulla ed esce. */
#include <iostream>
using namespace std; 
int main ()
{
    int a; 
    int b = 27; 
    cout << "Inserisci il voto che vorresti prendere all'esame di programmazione: " << endl; 
    cin >> a; 
    if (a>b)
        cout << "Programmazione 1 è veramente uno dei migliori corsi di informatica!!" << endl; 
    return 0; 
}