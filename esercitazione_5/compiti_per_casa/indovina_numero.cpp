#include <iostream>
using namespace std;
int main(){
    int num_1; 
    int num_2; 
    int cont = 1; 
    cout << "Inserisci il numero che vuoi che venga indovinato: "; 
    cin>>num_1; 
    cout << "Prova ad indovinarlo: "; 
    cin>>num_2; 
    while (num_1 != num_2){
        if (num_1>num_2){
        cout << "il numero inserito è più piccolo del numero che devi trovare "<< endl; 
        cout << "Prova ad indovinarlo: " << endl; 
        cin>>num_2; 
        cont ++; 
        }
        if (num_1<num_2){
            cout << "il numero che hai inserito è più grande del numero da trovare " << endl; 
            cout << "Prova ad indovinarlo: " << endl; 
            cin>>num_2;
            cont ++; 
        }
    }
    if (num_1 == num_2){
        cout << "Hai indovinato il numero in " << cont << " tentativi !" << endl; 
    }
return 0; 
}
