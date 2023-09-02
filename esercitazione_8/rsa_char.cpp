#include <iostream>
#include <cmath>

using namespace std ;

int cifra(int N, int e, int r)
{
  // per cifrare c = (N^e)%r     
  // (N*((N^(e-1))%r))%r
  
  //(N^(e-1))%r)
  int cont = 1; 
  for (int i = e; i>0; i--){ // 123 lo devo moltiplicare per se stesso 5 volte, perchè (N^e)%r, poi ogni volta che lo moltiplico faccio anche il resto, per evitare che diventi un numero troppo grande. 
    cont = (cont * N)%r;  
  }  
return cont; 
}


int main()
{
  int e = 5, d = 173, r = 323; // Chiave cifratura/decifratura
  while (true) {
    int scelta ;
    
    cout<<"\tChiave attualmente in uso: ("<<e<<", "<<d<<", "<<r<<")\n" ;
    cout<<"\n\t1 Cambiamento chiave RSA\n" ;
    cout<<"\t2 Cifratura di un carattere\n" ;
    cout<<"\t3 Decifratura di un carattere\n" ;
    cout<<"\t4 Uscita\n" ;
    cout<<"Scelta " ;
    cin>>scelta ;
    
    switch(scelta) {
      
      char N;
      int cod; 
      int ris_int; 
      char ris_char; 
      
    case 1:
      cout<<"Inserisci e " ;
      cin>>e ;
      cout<<"Inserisci d " ;
      cin>>d ;
      cout<<"Inserisci r " ;
      cin>>r ;
      break;
    case 2:
      cout<<"Inserisci il carattere da cifrare " ;
      cin>>N ;
      cout<<"Il carattere cifrato e' "<<cifra(static_cast<int>(N), e , r)<<"\n\n" ;
      break;
    case 3:
      cout<<"Inserisci il codice del carattere da decifrare " ;
      cin>>cod;
      cifra(cod, d, r); 
      ris_int = cifra(cod, d, r); // la funzione mi restituisce il valore intero che lo memorizzo in un avariabile int.
      ris_char = static_cast<char>(ris_int); //per sapere a quale carattere ASCII corrisponde quel valore faccio lo static_cast. 
      cout << "il carattere decifrato è:  " << ris_char << endl; 
      break; 
    case 4:
      return 0;
    default:
      cout<<"Scelta non valida\n" ;
    }
  }
  return 0;
}
