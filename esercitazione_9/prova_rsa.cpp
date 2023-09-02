#include <iostream>
#include <cstring>
using namespace std; 

int e = 5, d = 173, r = 323; 

int cifra(int N, int e, int r){
    int cont  = 1; 
    for (int i = e; i>0; i--){
        cont = (cont*N)%r;
	}   
    return cont; 
}

int main(){
    
    char messaggio [] = "Ciao mondo"; 
    const int lunghezza = strlen(messaggio); 
   
    int messaggio_ASCII[lunghezza]; 

    cout << "Il messaggio da cifrare: " << endl; 
    cout << messaggio << endl; 

    // scorro il vettore contenente tutti i caratteri, ogni carattere lo trasformo nel codice ASCII e lo metto dentro un altro vettore. 
    for (int i = 0 ; messaggio[i] != '\0'; i++){
        messaggio_ASCII[i] = messaggio[i]; 
    }

    cout << "Ecco il messaggio in codice ASCII: " << endl; 
    for (int i = 0; i < lunghezza; i++){
        cout << messaggio_ASCII[i] << " "; 
    }
    cout << endl;

    // cifriamo il messaggio, passando ogni elemento del vettore alla funzione cifra. 
    /*for (int i = 0; i < lunghezza; i++){
	    messaggio_ASCII[i] = cifra(messaggio_ASCII[i], e, r); 
    }

    cout << "Ecco il messaggio cifrato: " << endl; 

    for (int i = 0; i < lunghezza; i++){
        cout << messaggio_ASCII[i] << " "; 
    }
    cout << endl; */
    return 0; 
}