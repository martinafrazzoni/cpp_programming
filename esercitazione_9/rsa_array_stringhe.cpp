/*RSA array di interi

Traccia: Scrivere un programma che fornisca il seguente menu e implementi le 
funzioni in esso elencate

	
	Chiave attualmente in uso: (5, 173, 323)
	Contenuto attuale del vettore: 1 2 3 4 5
	1 Inserimento nuova chiave RSA
	2 Cifratura vettore
	3 Decifratura vettore
	4 Uscita

Il programma contiene al suo interno un vettore di 5 interi (nell'esempio il 
vettore contiene i numeri da 1 a 5). Se si sceglie l'opzione 2, il contenuto 
del vettore viene cifrato (si perde pertanto il contenuto precedente). Se si 
sceglie l'opzione 3, il contenuto del vettore viene decifrato (se tutto e' 
andato bene, si e' recuperato il contenuto precedente).
Il programma parte con la chiave predefinita (5, 173, 323). Se scegliamo di 
modificarla, il programma ci chiede di inserire una nuova terna di numeri.
Il programma non controlla se la nuova terna e' corretta o meno, ma siamo noi 
che dobbiamo assicurarci di fornire tre numeri corretti. 
Se la chiave RSA e' corretta, il programma permette di cifrare/decifrare un 
numero. Gestire le situazioni di errore, tranne, ovviamente, il controllo della
correttezza delle chiavi inserite.

-> Uno scheletro da cui partire e' nel file: rsa_array_scheletro.cc

Soluzione: Nel file rsa_array.cc

Esempio:
        Chiave attualmente in uso: (5, 173, 323)
        Contenuto attuale del vettore: 1 2 3 4 5 
        1 Cambiamento chiave RSA
        2 Cifratura vettore
        3 Decifratura vettore
        4 Uscita
Scelta 2
Il vettore e' stato criptato
        Chiave attualmente in uso: (5, 173, 323)
        Contenuto attuale del vettore: 1 32 243 55 218 
        1 Cambiamento chiave RSA
        2 Cifratura vettore
        3 Decifratura vettore
        4 Uscita
Scelta 3
Il vettore e' stato decriptato
        Chiave attualmente in uso: (5, 173, 323)
        Contenuto attuale del vettore: 1 2 3 4 5 
        1 Cambiamento chiave RSA
        2 Cifratura vettore
        3 Decifratura vettore
        4 Uscita
Scelta 4*/
#include <iostream>

using namespace std ;

int e = 5, d = 173, r = 323; // Chiave cifratura/decifratura

int cifra(int N, int e, int r){
    int cont  = 1; 
    for (int i = e; i>0; i--){
        cont = (cont*N)%r;
	}   
    return cont; 
}

void cifra_vettore(int vettore[ ], int NUM_ELEM){
    for (int i = 0; i < NUM_ELEM; i++){
        vettore[i] = cifra(vettore[i], e, r); 
    }
    for (int i = 0; i < NUM_ELEM; i++){
        cout << vettore[i] << " "; 
    }
    cout << endl; 
}

void decifra_vettore(int vettore[ ], int NUM_ELEM){
    for (int i = 0; i < NUM_ELEM; i++){
        vettore[i] = cifra(vettore[i], d, r); 
    }
    for (int i = 0; i < NUM_ELEM; i++){
        cout << vettore[i] << " "; 
    }
    cout << endl; 
}


int main()
{
    const int NUM_ELEM = 5 ;
    int vettore[5] = {1, 2, 3, 4, 5} ;
    int i ;

    while (1) {
        int scelta ;

	cout<<"\tChiave attualmente in uso: ("<<e<<", "<<d<<", "<<r<<")\n" ;
	cout<<"\tContenuto attuale del vettore: " ;
	for (i = 0 ; i < NUM_ELEM ; i++)
	    cout<<vettore[i]<<" " ;
	cout<<"\n\t1 Cambiamento chiave RSA\n" ;
	cout<<"\t2 Cifratura vettore\n" ;
	cout<<"\t3 Decifratura vettore\n" ;
	cout<<"\t4 Uscita\n" ;
	cout<<"Scelta " ;
	cin>>scelta ;
	
	switch(scelta) {
	case 1:
	    cout<<"Inserisci e " ;
	    cin>>e ;
	    cout<<"Inserisci d " ;
	    cin>>d ;
	    cout<<"Inserisci r " ;
	    cin>>r ;
	    break;
	case 2:
    {
        cout << "Il vettore è stato criptato\n"; 
        cout << "Ecco il contenuto attuale del vettore: " << " ";  
        cifra_vettore(vettore, NUM_ELEM); 
	    //cout<<"Attenzione: il vettore non e' stato criptato\n" ;
	    break;
    }
	case 3:
    {
        cout << "Il vettore è stato decriptato \n"; 
        cout << "Ecco il contenuto attuale del vettore: " << " ";  
        decifra_vettore(vettore, NUM_ELEM); 
        //cout<<"Attenzione: il vettore non e' stato decriptato\n" ;
	    break;
    }
	case 4:
	    return 0;
	default:
	    cout<<"Scelta non valida\n" ;
	}
    }
    
    return 0;
}
