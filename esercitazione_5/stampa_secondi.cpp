/*Se si inserisce la direttiva
#include <ctime>
si puÃ² utilizzare l'espressione time(0) nel proprio programma.

Ogni volta che viene valutata, tale espressione ritorna un
numero intero uguale al numero di secondi trascorsi dal 1 gennaio,
1970, GMT.

Quindi, per esempio, se si scrive l'istruzione
allora, ogni volta che viene eseguita tale istruzione, si stampa su stdout
il numero di secondi trascorsi da 1970, GMT.

Utilizzando questa informazione scrivere un programma, che stampa, ogni
secondo, il numero di secondi trascorsi da 1970, GMT. Il programma va
avanti all'infinito.

*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
int main (){ 
    while (true){ // la condizione è sempre vera e quindi il ciclo si ripete all'infinito
        cout<<time(0); 
        system ("sleep 1"); 
    }
    return 0; 
}