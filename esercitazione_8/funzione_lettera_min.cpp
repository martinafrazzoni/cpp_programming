/*Scrivere una funzione che, dato un carattere passato in ingresso (come parametro formale) restituisca il carattere stesso se non è una lettera minuscola, altrimenti restituisca il corrispondente carattere maiuscolo. (Quando abbiamo fatto le operazioni con i char, abbiamo visto che aggiungendo e sottraendo io mi muovo in avanti e indietro tra i codici carattere)
Adottiamo un approccio top-down: scriviamo solo l’interfaccia, nome, valore di ritorno, parametri in ingresso, ci sarà solo il programma che la usa. Sappiamo che c’è una funzione che so che mi fa quella cosa lì e la uso nel programma. Il programma legge un carattere da stdinput, e se è una lettera minuscola la ristampa in maiuscolo, altrimenti comunichi che il carattere non è una lettera minuscola. 
*/
#include <iostream>
using namespace std; 
char da_minuscolo_a_maiuscolo (char carattere){
    // ciclo che mi calcola in che posizione si trova la lettera all'interno dell'alfabeto. 
    int posizione = 1;
    for (char i = 'a'; i < carattere; i++){
        posizione ++; 
        if (i == carattere){
            break; 
        }
    }
    
    // int maiuscolo = posizione + ('A' - 1);  // altro modo. 

    //int maiuscolo = carattere - 'a' + 'A'; // facendo carattere - 'a' trovo la posizione del carattere all'interno dell'alfabeto, e ppi lo vado a sommare alla 'A' maiuscola, fatto così mi sposto nell'alfabeto maiuscolo fino a quando non trovo il carattere in quella stessa posizione. 
   
    int caratteri_speciali = 6; 
    int tot_lettere_alfabeto = 26; 
    int pos_alfabeto_maiusc = tot_lettere_alfabeto - (posizione-1); 
    char maiuscolo = (((carattere - (posizione-1)-caratteri_speciali) - pos_alfabeto_maiusc));
    return maiuscolo;

}
// la funzione prende in ingresso il carattere immesso da stdin. 
// presumo che sia una lettera minuscola perchè ho già fatto il controllo nel main. 
// mi muovo all'interno della tabella ASCII per andare a cercare qual'è il corrispondente carattere maiuscioilo. utilizzo la proprietà di ordinamento dei caratteri. 

int main(){
    char carattere; 
    cout << "Inserisci un carattere: "; 
    cin>>carattere; 
    if (carattere < 'a' || carattere > 'z')
        cout << "il carattere inserito " << carattere << " non è una lettera minuscola." << endl;   
    else
        cout << "Il corrispondente valore maiuscolo è: " << da_minuscolo_a_maiuscolo (carattere) << endl;       
    return 0; 
}