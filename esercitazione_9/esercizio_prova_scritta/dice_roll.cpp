#include <iostream>
#include <cstdlib>
#include <ctime>
 
using namespace std; 
 // implementiamo il lancio del dado, che genera dei numeri da 1 e 6. 
// generiamo numeri random dalla lbreria cstdlib

int lancia_dado(){
    srand((unsigned int)time(0)); // la funzione time ritorna un valore di tipo time_t. ma la funzione srand prende come parametro un unsigned int. 
    int roll = 0; // memorizza il numero di lanci. 
    roll = (rand() % 6) + 1; 
    return roll; 
}
int main(){
    int dado = lancia_dado(); 
    cout << "Dado: " << dado << endl; 
    return 0; 
}
