#include <iostream>
using namespace std; 
int main(){
	string nome; 
	double età;  
	cout << "Inserisci il tuo nome e l'età: \n ";
	cin>>nome>>età; 
	double età_mesi = (età * 12);
	cout << "Ciao, " << nome << "(" << "età, " << età_mesi << ")\n"; 
	return 0; 
}
