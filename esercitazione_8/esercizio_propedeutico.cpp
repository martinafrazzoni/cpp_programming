/*Scrivere un programma che: 
-	Legga da stdin tutti i caratteri che l’utente inserisce, fino al raggiungimento dell’end of file, ossia alla comunicazione dell’EOF da parte dell’utente. 
-	Subito dopo ogni lettura di un carattere, ristampi lo stesso carattere su stdout. 
Realizzare il programma prima senza preoccuparsi degli spazi bianchi, e poi assicurandosi che vengano stampati anche gli spazi bianchi. Per il corretto funzionamento del programma, è necessario che l’utente prima invio dopo ogni carattere da passare al programma?
*/
#include <iostream>
using namespace std; 
int main(){
    char n; 
    cout << "Inserisci n: \n";
    while (cin>>noskipws>>n){ 
        cout<< n;
    }
    return 0; 
}

