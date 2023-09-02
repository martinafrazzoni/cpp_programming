/*RSA messaggio

Traccia: Scrivere un programma che fornisca il seguente menu e implementi le 
funzioni in esso elencate

	
	Chiave attualmente in uso: (5, 173, 323)
	Messaggio attuale: Ciao mondo!
	1 Inserimento nuova chiave RSA
	2 Cifratura messaggio
	3 Decifratura messaggio
	4 Uscita

Il programma contiene al suo interno un messaggio in codice ASCII. 
Se si sceglie l'opzione 2, il messaggio viene cifrato 
(si perde pertanto il contenuto precedente). Se si sceglie l'opzione 3, il
messaggio viene decifrato (se tutto e' andato bene, si e' recuperato il
contenuto precedente). 
Il programma parte con la chiave predefinita (5, 173, 323). Se scegliamo di 
modificarla, il programma ci chiede di inserire una nuova terna di numeri.
Il programma non controlla se la nuova terna e' corretta o meno, ma siamo noi 
che dobbiamo assicurarci di fornire tre numeri corretti. 
Se la chiave RSA e' corretta, il programma permette di cifrare/decifrare un 
numero. Gestire le situazioni di errore, tranne, ovviamente, il controllo della
correttezza delle chiavi inserite.
Attenzione: 
. e' sbagliato lavorare su un vettore di caratteri, perche' la 
  versione cifrata potrebbe contenere dei numeri che non stanno su un byte
. l'ultimo carattere del messaggio deve essere seguito dal carattere nullo

Soluzione: Nel file rsa_messaggio.cc
*/

#include <iostream>
#include <cstring>

using namespace std ;

int e = 5, d = 173, r = 323; // Chiave cifratura/decifratura

int cifra(int N, int e, int r){
    int cont  = 1; 
    for (int i = e; i>0; i--){
        cont = (cont*N)%r;
	}   
    return cont; 
}


void cifra_vettore(int messaggio_cifrato[ ], int lunghezza){
    for (int i = 0; i < lunghezza; i++){
	    messaggio_cifrato[i] = cifra(messaggio_cifrato[i], e, r); 
    }

    for (int i = 0; i < lunghezza; i++){
        cout << messaggio_cifrato[i] << " "; 
    }
    cout << endl;
}

void decifra_vettore(int messaggio_cifrato[ ], int lunghezza, char messaggio_char []){
    for (int i = 0; i < lunghezza; i++){
	    messaggio_cifrato[i] = cifra(messaggio_cifrato[i], d, r); 
    }

    for (int i = 0; i < lunghezza; i++){
        messaggio_char[i] = static_cast<char>(messaggio_cifrato[i]); 
    }

    int i; 
    for ( i = 0; i < lunghezza; i++){
        cout << messaggio_char[i]; 
    }
    messaggio_char[i] = '\0'; 
    cout << endl;
    
}


int main()
{
    char messaggio[] = "Ciao Mondo";    
    int lunghezza = strlen(messaggio); 
   
    int messaggio_cifrato[lunghezza];

    char messaggio_char [lunghezza]; 
    int i ;

    int messaggio_criptato[] = {
        193, 87, 131, 271, 42, 104, 230, 42, 223, 53, 230, 241, 223, 190, 22, 131, 190,
        271, 131, 241, 223, 115, 42, 169, 165, 109, 241, 223, 22, 230, 223, 53, 230,
        241, 223, 53, 169, 22, 230, 22, 115, 271, 190, 165, 241, 286, 223, 22, 241,
        165, 22, 109, 241, 230, 241, 176, 223, 230, 42, 230, 223, 168, 241, 223, 22,
        6, 181, 42, 165, 190, 107, 241, 230, 241, 193, 22, 230, 223, 265, 241, 109,
        53, 271, 223, 42, 104, 190, 230, 22, 271, 223, 109, 271, 223, 109, 165, 271,
        165, 190, 271, 271, 223, 115, 230, 42, 42, 223, 104, 115, 22, 42, 6, 165,
        115, 271, 223, 22, 230, 223, 53, 230, 241, 223, 6, 190, 42, 241, 109, 241,
        223, 109, 286, 53, 131, 22, 230, 241, 223, 131, 115, 42, 241, 223, 193, 22,
        6, 181, 42, 165, 190, 241, 165, 230, 271, 223, 271, 286, 223, 131, 168, 271,
        223, 109, 241, 223, 6, 181, 22, 190, 241, 223, 271, 223, 109, 286, 53, 165,
        109, 181, 22, 241, 223, 109, 165, 271, 190, 271, 165, 241, 223, 115, 241, 230,
        22, 42, 223, 241, 109, 223, 6, 115, 42, 165, 42, 223, 69, 53, 115, 165,
        22, 42, 88, 223, 193, 99, 109, 223, 190, 115, 271, 165, 42, 223, 6, 53,
        42, 286, 223, 271, 115, 190, 271, 115, 271, 223, 53, 230, 241, 223, 165, 241,
        109, 42, 165, 271, 223, 131, 230, 68, 42, 115, 42, 53, 230, 22, 271, 223,
        271, 104, 223, 271, 115, 190, 271, 115, 271, 223, 241, 131, 230, 190, 42, 241,
        223, 131, 181, 6, 42, 109, 165, 271, 241, 230, 271, 181, 165, 271, 193, 131,
        181, 6, 190, 42, 115, 230, 271, 22, 109, 22, 319, 271, 88, 193, 47, 271,
        53, 165, 115, 42, 223, 6, 190, 271, 168, 131, 271, 286, 223, 230, 42, 230,
        223, 109, 69, 271, 69, 241, 181, 22, 42, 223, 42, 230, 69, 22, 223, 115,
        230, 22, 42, 109, 69, 241, 223, 109, 165, 271, 190, 165, 271, 241, 223, 181,
        241, 223, 109, 241, 223, 6, 190, 241, 109, 42, 241, 223, 230, 109, 271, 109,
        241, 223, 115, 53, 241, 193, 22, 165, 230, 271, 107, 190, 271, 107, 241, 88,
        193, 206, 169, 190, 241, 22, 176, 223, 115, 271, 165, 22, 271, 223, 190, 115,
        22, 53, 22, 131, 165, 22, 223, 241, 223, 104, 131, 271, 68, 190, 22, 241,
        190, 271, 223, 22, 109, 223, 181, 271, 115, 69, 241, 115, 69, 22, 42, 88,
        223, 87, 131, 115, 53, 241, 165, 271, 176, 223, 181, 241, 223, 230, 42, 230,
        223, 168, 42, 223, 190, 115, 271, 22, 165, 115, 165, 22, 42, 193, 241, 109,
        109, 241, 223, 165, 230, 271, 165, 241, 22, 107, 42, 230, 271, 223, 104, 22,
        223, 68, 190, 241, 169, 22, 223, 6, 190, 271, 104, 230, 190, 271, 271, 223,
        53, 230, 223, 6, 22, 131, 42, 131, 109, 42, 223, 115, 6, 169, 241, 271,
        165, 230, 42, 176, 223, 115, 6, 115, 42, 165, 241, 104, 230, 42, 223, 109,
        271, 223, 109, 165, 271, 165, 190, 271, 271, 193, 230, 109, 271, 109, 271, 223,
        6, 190, 241, 42, 109, 271, 96, 163, 300, 193, 0 } ;

        int lunghezza_prof = sizeof(messaggio_criptato) / sizeof(messaggio_criptato[0]); 
    
    // scorro il vettore contenente tutti i caratteri, ogni carattere lo trasformo nel codice ASCII e lo metto dentro un altro vettore. 
    for (int i = 0 ; messaggio[i] != '\0'; i++){
        messaggio_cifrato[i] = messaggio[i]; 
    }

    while (1) {
        int scelta ;

	cout<<"\tChiave attualmente in uso: ("<<e<<", "<<d<<", "<<r<<")\n" ;
	cout<<"\tMessaggio attuale: " ;
	cout << messaggio << endl; 
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
        cout << "Ecco il messaggio cifrato: " << endl; 
        cifra_vettore(messaggio_cifrato, lunghezza); 
	    break;
    }    
	case 3:
    {
        cout << "Il vettore è stato decriptato \n"; 
        decifra_vettore(messaggio_criptato, lunghezza_prof, messaggio_char); 
    }
    break;
	case 4:
	    return 0;
	default:
	    cout<<"Scelta non valida\n" ;
	}
    }
    
    return 0;
}