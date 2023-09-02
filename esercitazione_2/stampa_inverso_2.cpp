/*leggere da stdin un numero intero positivo, che si assume non essere multiplo di 10 ed essere compreso tra 101 e 999 (senza effettuare controlli), e memorizzare in una variabile intera un numero intero le cui cifre siano in ordine inverso rispetto al numeor letto da stadin; stampare infine il numero ottenuto. */
#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Inserisci un numero intero: ";
    cin >> a;
    int u = (a % 10);
    int d = ((a % 100) / 10);
    int c = ((a % 1000) / 100);
    // voglio memorizzare le mie cifre all'interno di una sola variabile.
    // moltiplico le unità per 100, u *100
    // moltiplico le decine per 10 d *10
    // le centinaia vanno bene così.
    int inverso = (u * 100) + (d * 10) + c;
    cout << inverso << endl;

    return 0;
}
