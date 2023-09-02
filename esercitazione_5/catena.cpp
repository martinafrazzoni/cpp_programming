/* Programma per la gestione di una Catena di Anelli.
   Gli anelli della catena possono essere di RAME o di FERRO.
   Possono essere presenti al piu' due anelli di RAME, mentre non
   esiste un limite al numero di anelli di FERRO. All'inizio la 
   catena e vuota.
   Gli anelli della catena sono numerati a partire da 1.
   Il programma deve fornire un menu con le seguenti operazioni:
   1) inserire un anello di RAME o di FERRO in posizione j (uno alla volta)
      Le posizioni ammissibili vanno dalla prima a quella immediatamente 
      successiva all'ultima. Il programma da un messaggio di notifica nel caso
      in cui non sia possibile effettuare l'inserimento.
      Quando un anello è inserito nella posizione j, tutti quelli che si 
      trovano nelle posizioni da j in poi si spostano in avanti di una 
      posizione. Il numero totale di anelli aumenta ovviamente di una unitaÕ.
   2) eliminare l'anello in posizione j (uno alla volta)
      Il programma da un messaggio di notifica nel caso in cui non sia
      possibile effettuare l'estrazione.
      Cosa succede agli anelli dalla posizione j+1 in poi?
   3) stampare la catena nel seguente formato:
       FFRFR
       dove F indica un anello di FERRO; R indica un anello di RAME.
       La catena precedente ha 5 anelli; gli in posizione 1, 2 e 4 sono di 
       ferro, mentre gli anelli in posizione 3 e 5 sono di RAME.
   4) Terminare
*/

#include <iostream>
using namespace std;
int main(){

    int max_rame = 0;  // numero massimo di anelli di rame che devono essere presenti all'interno della catena. 
    int totale_anelli = 0; // numero di anelli presenti all'interno della catena. All'inizio è vuota. rame + ferro. 
    int scegli_operazione;
    int max_operazioni = 4; 
    int materiale; 
    int posizione; 
    int posR1 = 0; // posizione del mio primo anello di rame. 
    int posR2 = 0; // posizione del secondo anello di rame.
    // pr1 e pr2 mantengono zero se non indicano nessun anello nella catena. 
    while (true){
        cout<<"Gestione di una catena: \n"
        <<"Inserisci il numero dell'operazione che vuoi eseguire: \n"
        <<"1. Inserire un anello di rame o di ferro in posizione j\n"
        <<"2. Eliminare l'anello in posizione j\n"
        <<"3. Stampare la catena nel seguente formato: FRFRFF \n"
        <<"4. terminare \n";
        cin>>scegli_operazione; 

        switch (scegli_operazione)
        {
        case 1:
            cout<<"Vuoi inserire un anello di rame o di ferro? (1-rame, 2-ferro)\n"; 
            cin>>materiale; 
            cout<<"In che posizione vuoi inserire l'anello?\n"; 
            cin>>posizione; 
            if ((posizione<=0 || posizione>totale_anelli+1) || (materiale==1 && max_rame == 2)){
                cout<<"Attenzione: non è stato possibile effettuare l'inserimento.\n"; 
                break;
            }
            
            // quando un anello viene inserito in pR1 ed è più grande di posizione (quindi della posizione di tutti gli altri anelli), pr1 aumenta, quindi si sposta in avanti. 

            if (posR1>= posizione){
                posR1++; 
            }
            if (posR2>= posizione){
                posR2++; 
            }
            totale_anelli++; 

            // se viene inserito un anello di rame la sua posizione viene memorizzata dentro pr1. 
            if (materiale == 1){
                max_rame++; 
                if(posR1 == 0){
                    posR2= posizione; 
                }
                else{
                    posR2= posizione; 
                }
            }
            break;
    
        case 2: 
            cout<<"In quale posizione vuoi effettuare l'estrazione dell'anello? \n"; 
            cin>>posizione; 
            cout<<"Vuoi estrarre un anello di rame o o ferro (1, rame - 2, ferro)?\n"; 
            cin>>materiale; 
            if (posizione<0 || posizione>totale_anelli+1){
                cout<< "Attenzione: non è possibile effettuare l'estrazione! \n"; 
            break;
            }

            // se si vuole estrarre un anello di rame, se pr1 era occupata da un anello, pr1 viene messa a zero quindi dentro non c'è nessun anello, stessa cosa per pr2. e viene decrementato il numero di anelli di rame all'interno della catena. 
            if (posR1 == posizione){
                posR2 = 0;
                max_rame--;  
            }
            if (posR2 == posizione){
                posR2 = 0; 
                max_rame--;
            }
            // se la posizione dove c'è ilprimo anello di rame, è maggiore della posizione dove ci sono gli alti anelli, pr1 viene decrementata, quindi viene tolto un buco all'interno della catena, stessa cosa per pr2, e il numero totale di anelli della catena decrementa. 

            if (posR1>posizione){
                posR1--;
            }
            if (posR2>posizione){
                posR2--;  
            }
            totale_anelli--; 
            break;

        case 3: 
            cout << "catena: "; 
            for (int i = 1; i<=totale_anelli; i++){
            if(i == posR1 || i == posR2){
                cout<< "R"; 
            }
            else{
                cout<<"F"; 
            }
            }
            cout<<endl;
            break;

        case 4: 
            return 0; 
            break;

        default:
            break;
        }
    }
    return 0; 
}


