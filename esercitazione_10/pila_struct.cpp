/*fare pila di struct con due campi, uno di tipo intero e l'altro di tipo stringa. Facciamo poi una versione con inserimento ordinato ed una con ordinamento a posteriori in base alla stringa e al valore numerico. eventualmente guardiamo la soluzione di lista esami ordinata. */

#include <iostream>
#include <cstring>
using namespace std; 

struct info_t{
    int numero; 
    char stringa[50]; 
}; 


// ho creato la struct con i due campi, uno di tipo intero e l'altro di tipo stringa. 
// adesso creo una pila. 

struct pila_t{
    info_t *p; // puntatore che punta ad una struct di tipo pila_info
    int capacita_max; 
    int tot_elem; 
}; 

void crea_pila(pila_t &pila){
    // prendo in ingresso le dimensioni della pila
    do{
        cout << "Inserisci le dimensioni della pila: \n"; 
        cin>>pila.capacita_max; 
    }
    while (pila.capacita_max <= 0); 
    pila.p = new info_t [pila.capacita_max]; 
    pila.tot_elem = 0; 
}

bool controlla_se_piena(pila_t &pila){
    if(pila.tot_elem == pila.capacita_max){
        cerr << "La pila è piena! " << endl; 
        return true; 
    }   
    else
        return false; 
}

bool controlla_se_vuota(pila_t &pila){
    if(pila.tot_elem == 0){
        cerr << "La pila è vuota! " << endl; 
        return true; 
    }
    else
        return false; 
}

bool push(pila_t &pila, info_t &pila_info){
    if ((controlla_se_piena(pila)) == true ){
        cerr << "Impossibile fare l'inserimento! " << endl;
        return false; 
    }

    if (pila.tot_elem > 1 && pila_info.numero > pila.p[pila.tot_elem-1].numero){
        //cout << "Pila_info numero: " << pila_info.numero << endl; 
        //cout << "Numero del primo elemento pila: " << pila.p[pila.tot_elem-1].numero << endl; 
        cerr << "Impossibile effettuare l'inserimento\n"; 
        return false; 
    }
    pila.p[pila.tot_elem] = pila_info; 
    pila.tot_elem++; 
    cout << endl;

    return true; 
}

bool pop(pila_t &pila, info_t &pila_info){
    if (controlla_se_vuota(pila) == true){
        cout << "Impossibile fare l'estrazione! " << endl; 
        return false; 
    }
    pila.tot_elem--; 
    pila_info = pila.p[pila.tot_elem]; 
    cout << endl; 
    return true; 
}

void stampa_pila(pila_t &pila, info_t&pila_info){
    for (int i = (pila.tot_elem-1); i >= 0; i--){
        cout << pila.p[i].numero << " " << pila.p[i].stringa << endl; 
    }
    cout << endl;
}

void ordina_pila(pila_t &pila, info_t&pila_info){
    int min_index; 
    info_t temp; 
    for (int i = 0; (i < pila.tot_elem - 1); i++){
        min_index = i; 
        for (int j = (i+1); j < pila.tot_elem; j++){
            if (pila.p[j].numero < pila.p[min_index].numero){
                min_index = j; 
            }
        }
        temp = pila.p[min_index]; 
        pila.p[min_index] = pila.p[i]; 
        pila.p[i] = temp; 
    }
}

void dealloca_pila(pila_t &pila){
    delete[] pila.p; 
}

void ordina_pila_alfabetico(pila_t &pila, info_t &pila_info){
    info_t temp; 
    for (int i = 0; i < (pila.tot_elem -1); i++){ 
        for (int j = i+1; j < pila.tot_elem; j++){
            if (strcmp(pila.p[i].stringa, pila.p[j].stringa) > 0){
                temp = pila.p[i]; 
                pila.p[i] = pila.p[j]; 
                pila.p[j] = temp; 
            }
        }
    }
}

int main(){
    pila_t pila; 
    info_t pila_info; 

    int scelta; 
	while (true){
	cout << "Gestione pila\n"; 
	cout << "Menu\n"; 
	cout << "1. crea pila \n";
    cout << "2. Inserimento di un nuovo elemento nella pila. \n"; 
	cout << "3. Togli elemento dalla pila \n"; 
    cout << "4. stampa pila\n"; 
    cout << "5. Dealloca pila\n"; 
	cout << "6. Ordina pila\n";
    cout << "7. Ordina pila alfabeticamente\n";
    cout << "8. Uscita\n";   
	cin>>scelta;
	switch(scelta){
	 case 1: {
		crea_pila(pila); 
        cout << "Hai creato una pila di " << pila.capacita_max << " elementi!" << endl; 
		break; 
	}
	case 2: {
		cout << "Inserisci il numero dell'elemento: \n"; 
        cin>>pila_info.numero; 

        cout << "Inserisci la stringa dell'elemento: \n"; 
        cin>>pila_info.stringa; 
        push(pila, pila_info); 
        cout << "Dimensione pila: " << pila.tot_elem << endl; 
		break; 
	}
	case 3: {
        pop(pila, pila_info); 
        cout << "Dimensione pila: " << pila.tot_elem << endl; 
		break;
	}
	case 4: {
        cout << "Ecco la pila di struct: \n"; 
        stampa_pila(pila, pila_info);  
		break; 
	}
    case 5: {
        dealloca_pila(pila); 
    }
    case 6: {
        ordina_pila(pila, pila_info); 
        for (int i = 0; i < pila.tot_elem; i++){
            cout << pila.p[i].numero << " " << pila.p[i].stringa << endl; 
        }
        cout << endl; 
        break;
    }
    case 7: {
       ordina_pila_alfabetico(pila, pila_info); 
        for (int i = 0; i < pila.tot_elem; i++){
            cout << pila.p[i].numero << " " << pila.p[i].stringa << endl; 
        }
        cout << endl; 
       break;
    }
    case 8: {
        return 0; 
    }
	default:
		continue; 
 	} // fine switch
    } // fine while

    return 0; 
}