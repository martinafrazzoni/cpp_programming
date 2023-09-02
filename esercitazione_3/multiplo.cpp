#include <iostream>
using namespace std;
int main()
{
    int a; // numero che dò in ingresso
    cout << "Inserisci un numero intero: \n";
    cin >> a;
    int b;
    cout << "Inserisci un numero intero: \n"; // chiedo in ingresso un numero
    cin >> b;
    int ris = (a / b);
    int resto = (a % b);
    if (resto == 0)
        cout << "Il numero inserito è multiplo di " << a << endl;
    else
        cout << "il numero inserito non è multiplo di " << a << endl;
    return 0;
}