// per un numero intero, per sapere quanti byte vengono utilizzati bisogna fare size of. 
#include <iostream>
using namespace std; 
int main(){
    int N; //numero che devo leggere in ingresso da Stdin
    int b = 2; // base. 
    int i = 32; // 32 bit sono l'equivalente di 4 byte. 
    
    int t; 
    int tb = 1; // contenitore
   do{
    cout<<"Inserisci un numero intero non negativo da scrivere in base 2 \n"; 
    cin>>N;
    }
    while (N<=0); 
    for (int j = 0; j<i; j++){  // ciclo che mi va da 0 a 32, quindi tutta la lunghezza della mia rappresentazione in memoria. Quando j = 0, b^i è 1 e quindi tb (dentro l'if non ci vado neanche). Qundo la mia j è maggiore di 0 invece vado dentro l'if. 
        if (j>0){
            for (int x = 0; x < j; x++){ // con questo for interno mi calcolo b^i e x parte sempre da 0 perchè il suo scopo e limitato a quel ciclo lì, quindi ogni giro mi parte sempre da zero. 
                tb*= b; 
            }
        }
     cout << (N/tb)%b; 
     tb = 1; // così si azzera sempre a 1 alla fine di ogni ciclo e mi permette di fare l'elevamento a potenza.  
    }
    return 0; 
}
