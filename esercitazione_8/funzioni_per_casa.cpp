#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; 

void genera(int a [ ], int dim_a, int tot){
    // per generare numeri casuali da 0 a 100 utilizzo la funzione rand(), inizializzo srand() a time(0), 
    srand(time(0)); 
    for (int i = 0; i < dim_a; i++){
		a[i] = rand() % 101;  // genero numeri casuali da 0 a 100. 
	} 
} 

void leggi_ord (int b [ ], int dim_b){
    // leggiamo l'array da tastiera
    for (int i = 0; i < dim_b; i++){
        cout << "Inserisci un numero intero: "; 
        cin>>b[i]; 
        if (i != 0){
            while (b[i] < b[i-1]){
                cout << "Errore! l'array deve essere ordinato in senso crescente! \n"; 
                cout << "Inserisci un  numero intero: "; 
                cin>>b[i]; 
            }
        }
    }

}

int pos (int c[ ], int dim_c, int da_trovare){
    int j; 
    for (j = 0; j < dim_c; j++){
        cout << "Inserisci un intero: "; 
        cin>>c[j]; 
        if (c[j] == da_trovare)
            return j; 
    }
    return -1; 
}

int inserisci_elemento (int d[ ],  int dim_max, int &dim_d){
    int valore; 
    for (int i = 0; i < dim_d; i++){
	    cout << "Inserisci un valore: "; 
	    cin>>d[i]; 
        if (i != 0){
            while (d[i] < d[i-1]){
		    cout << "Inserimento errato: l'array deve essere ordinato in senso crescente!"; 
	        }
        }
    }

    // chiedo all'utente il valore dell'elemento che vuole inserire: 
    cout << "Inserisci il valore del nuovo elemento: \n"; 
    cin>>valore; 
    int index = 0;
    
    // scorro tutti gli elementi del vettore, appena trovo un elemento che ha valore minore o uguale all'elemento che devo inserire mi fermo e mi tengo da parte l'indice. quindi in questo caso mi fermo a 6 e l'indice è il 2 (index)
    // facendo così so, che l'elemento che devo inserire deve avere indice pari a index+1 = 3. 

    for (int i = 0; i < dim_d; i++){
	if (d[i] < valore)
		index = i+1; 
    }

    // con un ciclo parto dal fondo, da dim_d fino ad essere maggiore di index e sposto tutti gli elementi di uno verso destra. 
    // poi dentro la posizione di indice index ci vado a mettere il mio valore.  

    for (int i = dim_d; i > index; i--){
        d[i] = d[i - 1]; 
        //cout << "[inserisci_elemento] d[dim_d] " << d[dim_d] << ", d[dim_d -1] " << d[dim_d-1] << endl; 
    }
    d[index] = valore; 
    dim_d ++;
 
return dim_d; 
}

int estrai_elemento(int e[ ], int &dim_e, int dim_max_e){
    // chiedo in input gli elementi dell'array, verificando che siano ordinati in senso crescente. 
    for (int i = 0; i < dim_e; i++){
	    cout << "Inserisci un valore: ";
	    cin>>e[i]; 
	    if (i != 0){
            while (e[i] < e[i-1]){
                cout << "Inserimento errato l'array deve essere ordinato in senso crescente! \n"; 
                cout << "Inserisci un nuovo valore: "; 
                cin>>e[i]; 
            }
	    }
    } 

    // adesso che i valori sono stati inseriti in senso crescente, chiedo l'indice dell'elemento da togliere. 
    int da_togliere; 
    cout << "Immetti l'indice dell'elemento che vuoi estrarre: "; 
    cin>>da_togliere; 

    // a partire da da_togliere, tutti gli elementi si devono muovere di 1 verso sx. 
    for (int i = da_togliere; i < dim_e; i++){
	    e[i] = e[i+1]; 
    }
    dim_e --; 
return dim_e; 
}

void stampa_vettore (int f [ ], int dim_f) {
    for (int i = 0; i < dim_f; i++){
        cout << "Inserisci un valore: "; 
	    cin>>dim_f; 
    }

    for (int i = 0; i < dim_f; i++){
        cout << f[i] << endl; 
    }
}

int ord (int g [ ], int dim_g){
    for (int i = 0; i < dim_g; i++){
        cout << "Inserisci un valore: "; 
        cin>>g[i]; 
        if ((i != 0) && (g[i] < g[i-1]))
            return 0;  
    }
    return 1; 
}

void fusione (int v1[ ], int dim_v1, int v2[ ], int dim_v2, int v3[ ], int dim_v3){
    for (int i = 0; i < (dim_v1 + dim_v2); i++){
        v3[i] = v1[i]; 
        for (int j = dim_v1; j < (dim_v1+dim_v2); j++){
            v3[j] = v2[j-dim_v1]; 
        }
    }
}


int main(){
    while(true){
        cout << "1. Creazione di un vettore di interi riempito con un numero casuale da 0 a TOT, per N elementi. \n";  
        cout << "2. Lettura di un vettore di interi letto da tastiera per N elementi, valutando che il vettore sia inserito ordinatamente. \n"; 
        cout <<  "3. Ricerca sequenziale di un elemento E in un vettore V di N elementi" << endl;
        cout << "4. Inserimento di un elemento nella posizione corretta in un vettore ordinato di N elementi con al massimo dim elementi \n"; 
        cout << "5. cancellazione di un elemento in un vettore ordinato di n elementi. \n";
        cout << "6. Stampa di un vettore v di n elementi!" << endl; 
        cout << "7. verifica che sia ordinato: " << endl; ; 
        cout << "8. Fonde i due vettori ordinati nel terzo vettore: " << endl; 

        cout << endl; 
        cout << "Scegli il numero dell'operazione che vuoi eseguire: \n"; 
        int scelta; 
        cin>>scelta; 

        switch (scelta)
        {
        case 1:
        {
            const int tot = 100; // massimo valore che può andare dentro ad ogni elemento dell'array 
            const int dim_a = 8; // dimensione_array
            int a [dim_a]; 

            genera(a, dim_a, tot); 

            // stampo l'array
            for (int i = 0; i < dim_a; i++){
                cout << a[i] << " "; 
            }

            cout << endl; 
            break;
        }
        case 2: 
        {
            const int dim_b = 4; // dimensioni del vettore. 
            int b [dim_b]; // array di interi.
            leggi_ord(b, dim_b); 
            for (int j = 0; j < dim_b; j++){
                cout << b[j] << " "; 
            }
            cout << endl; 
            break;
        }
        case 3:
        { 
            const int dim_c = 6; 
            int c[dim_c]; 
            int da_trovare = 2; 
            cout << da_trovare << " si trova in posizione " << pos(c, dim_c, da_trovare) << endl; 
            cout << endl; 
            break;
        }
        case 4:
        { 
            int dim_d = 6; 
            const int dim_max = 10; 
            int d [dim_max]; 
        
            inserisci_elemento(d, dim_max, dim_d); 
            cout << "Ecco il vettore con il nuovo elemento inserito: \n"; 
            for (int k = 0; k < dim_d; k++){
                cout << d[k] << " "; 
            }
            cout << endl; 
            break;
        }
        case 5:
        { 
            const int dim_max_e = 10; 
            int dim_e = 5;  
            int e [dim_max_e]; 

            estrai_elemento(e, dim_e, dim_max_e); 

            for (int y = 0; y < dim_e; y++){
                cout << e[y] << " "; 
            }
            cout << endl; 
            break;
        }
        case 6: 
        {
            cout << "6. Stampa di un vettore v di n elementi!" << endl; 
            const int dim_f = 7; 
            int f[dim_f]; 
            stampa_vettore(f, dim_f); 
            cout << endl; 
            break;
        } 
        case 7:{ 
            const int dim_g = 5; 
            int g[dim_g]; 
            cout << ord(g, dim_g) << endl;  
            cout << endl; 
            break;
        }
        case 8:
        { 
            const int dim_v1 = 5;  
            const int dim_v2 = 3; 
            const int dim_v3 = dim_v1 + dim_v2; 
        
            
            int v1[dim_v1]; 
            int v2[dim_v2]; 
            int v3[dim_v3]; 

            if (ord(v1, dim_v1) && ord(v2, dim_v2)){
                cout << "I due vettori sono ordinati!"; 
                fusione(v1, dim_v1, v2, dim_v2, v3, dim_v3); 
            }
                
            for (int q = 0; q < (dim_v1 + dim_v2); q++){
                cout << v3[q] << " "; 
            }
        }
            break; 
        default:
            break;
    }    
    return 0; 
    }
}
