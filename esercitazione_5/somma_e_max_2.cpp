/*scrivere un programma che legga un numero intero n. il numero viene di nuovo richiesto finchè non è compreso tra 0 e 10. Successivamente si chiede l'immissione di n numeri interi strettamente positivi e se ne calcola e srampa la somma ed il valore massimo. L'inserimento di un zero interrompe la sequenza degli inserimenti anche se non stono stati raggiunti gli n numeri. Invece l'inserimento di un numero negativo è semplicemente trascurato, come se non fosse stato inserito nessun numero. Realizzare il calcolo senza utilizzare l'istruzione for (altrimenti è più difficile). Trascurare problemi di overflow. 
*/
#include <iostream>
using namespace std; 
int main (){
    int n; 
    const int max = 10; 
    int numero; 
    int somma = 0; 
    int massimo = 0; 
    int i = 0; 
    /*leggi n finchè non è compreso tra 0 e max = 10. */
    do {
        cout << "Inserisci un numero intero n: \n"; 
        cin>>n; 
    }
    while (n<0 || n>max);
    /*immissione n numeri interi positivi e calcolo somma e valore massimo. */
    /*for (int i = 0; i<n; i++){
        cout << "Inserisci " << n <<  " numeri interi: "; 
        cin>>numero; 
            if (numero == 0)
                break;
            if (numero < 0)
                continue;
        somma += numero; 
            if (numero>massimo)
                massimo = numero; 
    }*/
    while (i < n){
        cout << "Inserisici" << n << "numeri interi: "; 
        cin>>numero; 
        if (numero == 0)
            break; 
        if (numero < 0)
            continue;
        somma += numero; 
        if (numero>massimo)
            massimo = numero; 
        i++; 
    }; 
    cout << " la somma dei numeri inseriti è: " << somma << ",  mentre il valore massimo è " << massimo << endl; 
    return 0; 
}
