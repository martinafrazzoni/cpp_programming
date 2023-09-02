#include <iostream>
using namespace std; 

int somma(int v1[ ], int v2[ ], int v3[ ], int N){
    int cont = 0; 
    for (int i = 0; i < N; i++){
        if (v1[i] > v2[i]){
            v3[i] = v1[i]; 
            cont ++; 
        }
        else  
            v3[i] = v2[i]; 
    }
    return cont; 
}

int conta(int a[ ], int dim, int e){
    int conta = 0; 
    for (int i = 0; i < dim; i++){
        if (a[i] == e){
            conta++; 
        }
    }
    return conta; 
}

int creaunici(int v1[ ], int dim_v1, int v2[ ]){
    int dim_v2 = 0; 
    for(int i = 0; i < dim_v1; i++){
        if(conta(v1, dim_v1, v1[i]) == 1){
            v2[dim_v2] = v1[i]; 
            dim_v2++; 
        }
    }
    return dim_v2; 
}
int main(){

    cout << "1.  Si scriva una funzione somma() che riceve come parametri 3 vettori v1, v2, v3 di dimensione N. La funzione confronta il primo elemento di v1 e il primo elemento di v2 e copia il maggiore in v3 come primo elemento; \n";  
    cout << endl; 
    cout << "2. Funzione conta che riceve in ingresso un vettore V di interi e un elemento e e restituisce quante volte e è ripetuto in V. Nel main, chiedo in input i valori del vettore fino a quando non viene inserito il numero sentinella 999. Stampa il numero che ha avuto più ripetizioni all'interno del vettore. \n"; 
    cout << endl; 
    cout << "3. scrivere una funzione contavolte, che conta quante volte un elemento x è presente in un vettore v di n elementi. Utilizzare contavolte dentro un'altra funzione, creaunici, per costruire partendo dal vettore v1 un secondo vettore v2 che contiene solo gli elementi unici di v1. "; 
    cout << endl; 
    

    int scelta; 
    cout << "Scegliere l'operazione che si vuole eseguire: "; 
    cin >> scelta; 

    switch (scelta)
    {
    case 1:
    {
        const int N = 5; 

        int v1[N];  
        int v2[N]; 
        int v3[N]; 

        // chiedo in input i valori del primo e del secondo vettore. 
        for (int i = 0; i < N; i++){
            cout << "Inserisci un valore per il primo vettore: "; 
            cin>>v1[i]; 
        }
        cout << endl; 
        for (int i = 0; i < N; i++){
            cout << "Inserisci un valore per il secondo vettore: "; 
            cin>>v2[i]; 
        }

        somma(v1, v2, v3, N); 

        for (int i = 0; i < N; i++){
            cout << v3[i] << " "; 
        }

        cout << endl; 
        cout << "Il numero di volte che un elemento di v1 è risultato maggiore di v2 è " << somma(v1, v2, v3, N) << endl; 
    }
        break;
    case 2: 
    {
        const int max_dim_vett = 15; 
        int a [max_dim_vett]; 
        int e = 3; 
        int dim = 0; 
        int max_occorrenze; 
        int valore_max; 

        for (int i = 0; ; i++){
            cout << "Inserisci un valore (per fermarti inserisci 999): ";
            cin>>a[i]; 
            if (a[i] == 999)
                break; 
            dim ++;   
        }
        conta(a, dim, e);  
       
        for (int j = 0; j < dim; j++){
            int conta_volte; 
            int da_trovare = a[j]; 
            for (int i = 0; i < dim; i++){
                conta_volte = conta(a, dim, da_trovare); 
            }

            if (conta_volte > max_occorrenze){
                max_occorrenze = conta_volte; 
                valore_max = a[j]; 
            }
        }  
        cout << "Il valore massimo è " << valore_max << " ripetuto " << max_occorrenze << " volte!" << endl;
    }
        break; 
    case 3: 
    {
        const int dim_v1 = 11; 
        int v1 [dim_v1] = { 2, 4, 3, 2, 7, 1, 3, 5, 1, 8, 9}; 
        int v2[dim_v1]; // setto v2 alla stessa lunghezza di v1 ma non so ancora quanti elementi contiene, perchè deve contenere solo i pari di v1. 
        int lungh_v2 = creaunici(v1, dim_v1, v2); 

        // stampiamo il vettore

        for (int i = 0; i < lungh_v2; i++){
            cout << v2[i] << " "; 
        }
    }
    break; 
    default:
        break;
    }

    return 0; 
}