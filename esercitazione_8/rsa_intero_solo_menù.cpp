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
  cout << cont << endl;  
return cont; 
}


int main()
{
  int e = 5, d = 173, r = 323; // Chiave cifratura/decifratura
  while (true) {
    int scelta ;
    
    cout<<"\tChiave attualmente in uso: ("<<e<<", "<<d<<", "<<r<<")\n" ;
    cout<<"\n\t1 Cambiamento chiave RSA\n" ;
    cout<<"\t2 Cifratura di un numero\n" ;
    cout<<"\t3 Decifratura di un numero\n" ;
    cout<<"\t4 Uscita\n" ;
    cout<<"Scelta " ;
    cin>>scelta ;
    
    switch(scelta) {
      
      int N;
      
    case 1:
      cout<<"Inserisci e " ;
      cin>>e ;
      cout<<"Inserisci d " ;
      cin>>d ;
      cout<<"Inserisci r " ;
      cin>>r ;
      break;
    case 2:
      cout<<"Inserisci il numero da cifrare " ;
      cin>>N ;
      cout<<"Il numero cifrato e' "<<cifra(N, e , r)<<"\n\n" ;
      break;
    case 3:
      cout<<"Inserisci il numero da decifrare " ;
      cin>>N ;
      cout<<"Il numero decifrato e' "<< cifra(N, d, r)<<"\n\n" ;
      break;
    case 4:
      return 0;
    default:
      cout<<"Scelta non valida\n" ;
    }
  }
  return 0;
}
