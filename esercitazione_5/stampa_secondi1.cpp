/*scrivere un programma, che stampa, ogni secondo, il numero di secondi trascorsii dal 1970. il programma va avanti all'infinito. */
#include <iostream>
#include <ctime>
using namespace std; 
int main () {
    while (true){
        cout<<time(0)<<endl; 
        system("sleep 1")<<endl;
    }
    return 0; 
}