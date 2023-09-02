#include <iostream>
#include <fstream>
using namespace std; 

struct pila_t{
    int *collezione; 
    int capacita_max; 
    int tot_elem; 
}; 

void crea_pila(pila_t &p){
    do{
        cout << "Inserisci lunghezza pila: \n"; 
        cin>>p.capacita_max; 
    }
    while(p.capacita_max < 0); 
    p.collezione = new int [p.capacita_max];
    p.tot_elem = 0; 
}

bool è_piena(pila_t &p){
    if (p.tot_elem == p.capacita_max){
        cout << "La pila è piena!\n"; 
        return true; 
    }
    return false; 
}

bool è_vuota(pila_t &p){
    if (p.tot_elem == 0){
        cout << "La pila è vuota!\n"; 
        return true; 
    }
    return false; 
}

bool push(pila_t &p, int &elem){
    if (p.tot_elem == p.capacita_max){
        cerr << "Impossibile fare la push\n"; 
        return false; 
    }
    p.collezione[p.tot_elem] = elem; 
    p.tot_elem++; 
    cout << endl; 
    
    return true; 
}

bool pop(pila_t &p, int &elem){
    if (è_vuota(p) == true){
        cout << "La pila è vuota non posso estrarre! "; 
        return false; 
    }
    p.tot_elem--; 
    elem = p.collezione[p.tot_elem]; 
    return true; 
}

void stampa_pila(pila_t &p){
    cout << "Ecco il contenuto della pila: \n"; 
    for (int i = 0; i < p.tot_elem; i++){
        cout << p.collezione[i] << " "; 
    }
    cout << endl; 
}

void scrivi_file(ofstream  &pila, const int *a, int elem_file){
    pila.write(reinterpret_cast<const char *>(a), sizeof(int)*elem_file); 
} 

void leggi_file(pila_t &p, ifstream &leggi_pila, int *a, int elem_file){
    leggi_pila.read(reinterpret_cast<char *>(a), sizeof(int)*elem_file);  
    for (int i = 0; i < elem_file; i++){
        int n = a[i]; 
        if (è_piena(p) == false){
            push(p, n); 
        }
   }
}


int main(){
    pila_t p; 
    crea_pila(p); 
    ofstream pila; 
    pila.open("pila.txt"); 
    if (!pila)
        cerr << "Errore, impossibile aprire il file in scrittura\n"; 

    int elem_file;  
    cout << "Quanti valori vuoi inserire nel file: \n"; 
    cin>>elem_file; 
    int *a = new int [elem_file]; 
    for (int i = 0; i < elem_file; i++){
        cout << "Inserisci valore: \n"; 
        cin>>a[i]; 
    }
    scrivi_file(pila, a, elem_file); 

    pila.close(); 

    // leggiamo i valori inseriti da file e facciamo la push. 
    ifstream leggi_pila; 
    leggi_pila.open("pila.txt"); 
    if(!leggi_pila)
        cerr << "Errore, impossibile aprire i file in lettura\n";  
    leggi_file(p, leggi_pila, a, elem_file); // ho letto il contenuto del file, e ho fatto la push degli elementi. 
    cout << endl; 
    stampa_pila(p); // ho stampato la pila.
    cout << endl;  
    è_piena(p); // ho controllato se è piena. 
    leggi_pila.close(); 

    // estrazione di elementi dalla pila.
    ofstream pop_val_file; 
    pop_val_file.open("estratti.txt"); 
    if(!pop_val_file){
        cerr << "Errore, impossibile aprire il file in scrittura!\n"; 
        return 1; 
    }
    int quanti_estrarre; 
    do{
        cout <<"Quanti elementi vuoi estrarre dalla pila: "; 
        cin>>quanti_estrarre;
    }
    while (quanti_estrarre <= 0 || quanti_estrarre > p.tot_elem); 
    int pop_val = 0; 
    for (int i = 0; i < quanti_estrarre; i++){
        pop(p, pop_val); 
        pop_val_file << pop_val << " "; 
    }
    pop_val_file.close(); 
    return 0; 
    }