/*
 * Realizzare una variante del gioco verbosity in cui due squadre A e
 * B, di almeno due giocatori ciascuna, si alternano nel pensare ad
 * una parola segreta o nell'indovinare la parola segreta pensata
 * dall'altra squadra. Per parola si intende una sequenza di caratteri
 * non separati da spazi.
 *
 * Supponiamo che tocchi dapprima alla squadra A pensare alla parola
 * segreta: i giocatori della squadra hanno due minuti a disposizione
 * per decidere la parola segreta e scriverla in un file di testo. Nel
 * frattempo la squadra B decide quali dei propri giocatori si
 * occuperanno di indovinare la parola segreta, chiamiamoli la
 * (sotto)squadra B1, e quali giocatori, chiamiamoli la (sotto)squadra
 * B2, leggeranno subito la parola segreta ed avranno il compito di
 * scrivere piu' indizi possibili per aiutare i compagni ad indovinare
 * la parola segreta.
 *
 * In particolare, la squadra A ha due minuti per pensare alla parola
 * segreta e scriverla nel file, dopodiché la squadra B2 ha due minuti
 * di tempo per scrivere, nello stesso file, e di seguito alla parola
 * segreta, tutti gli indizi a cui riesce a pensare. Per esempio, se
 * la squadra A avesse pensato alla parola albero, e la squadra B1
 * agli indizi fusto, foglie e radici, allora il contenuto finale del
 * file sarebbe:
 *
 * albero
 * fusto
 * foglie
 * radici
 *
 * Una volta compilato il file, si fa partire il programma del gioco,
 * che legge il file e mostra alla squadra B1 solo gli indizi ed il
 * punteggio iniziale (50 punti). Il programma chiede ripetutamente di
 * immettere la parola segreta, finche' non viene indovinata. Ogni
 * volta che si immette una parola tentativo sbagliata si perde un
 * punto. La squadra B1 ha due minuti di tempo per indovinare la
 * parola segreta, altrimenti perde e le viene assegnato un punteggio
 * di -10. Il tempo trascorso non e' controllato dal programma, ma dai
 * giocatori stessi.
 *
 * Come aiuto, ogni volta che viene immessa una parola tentativo
 * sbagliata il programma mostra quali lettere della parola immessa
 * appaiono NELLO STESSO ORDINE nella parola segreta. Se la parola
 * segreta fosse albero, seguono alcuni esempi di quali lettere
 * verrebbero ristampate dal programma in funzione della parola
 * tentativo immessa:
 *
 * pianta -> a
 * platano -> lo
 * ulivo -> lo
 * arbusto -> abo
 *
 * In altri termini, data ciascuna lettera della parola tentativo, il
 * programma cerca tale lettera nella parola segreta; ma non la cerca
 * partire dall'inizio della parola segreta, bensi' a partire dalla
 * posizione, nella parola segreta, in cui era stata eventualmente
 * trovata la precedente lettera. Ovviamente, finché non e' ancora
 * stata trovata nessuna lettera a comune, la ricerca inizia sempre
 * dall'inizio della parola segreta. Per esempio, quando si immette
 * platano, si controlla se ciascuna lettera della parola tentativo
 * appare in albero e si scopre che che c'e' la l. Da quel momento in
 * poi, ciascuna delle successive lettere di platano, ossia 'a', 't',
 * 'a', 'n', ed 'o', non verranno cercate in tutta la stringa albero,
 * ma nella sottostringa bero.
 *
 * Una volta indovinata la parola segreta o scaduto il tempo, le
 * squadre si invertono. Supponendo che prima di iniziare il gioco le
 * squadre abbiano deciso il numero totale di parole segrete da
 * indovinare (e quindi il numero totale di turni di gioco), vince la
 * squadra che alla fine di tutti i turni ha totalizzato il punteggio
 * piu' alto.
 *
 * --------------------
 *
 * Realizzare il programma di supporto del gioco precedentemente
 * descritto. In aggiunta alle specifiche fornite finora, il programma
 * deve salvare separatamente la parola segreta e gli indizi in due
 * file di testo distinti. Questo permette per esempio alla squadra B2
 * di leggere gli indizi con un editor o un visualizzatore di file di
 * testo nel caso siano per esempio spariti dal terminale su cui sta
 * giocando.
 *
 * Le funzionalità di lettura del file di input e creazione dei due
 * file devono essere realizzate in una funzione che non legge nulla
 * da stdin.  Lo stesso vale per la funzionalità di stampa delle
 * parole indizio.  Decidere a tempo di scrittura del programma i nomi
 * di tutti i file letti o scritti. Bisogna infine gestire
 * opportunamente tutte le situazioni di errore, ed applicare tutti i
 * principi di ingegneria del codice visti a lezione.
 *
 * Non appena si finisce la scrittura ed il collaudo del proprio
 * programma, ci si sposta verso il collega o gruppo di colleghi che
 * si preferisce, e si collabora con loro nel completamento del loro
 * programma. Quindi, se si e' gia' in numero sufficiente per iniziare
 * una partita (ossia si e' almeno in quattro), si inizia a giocare,
 * altrimenti ci si sposta verso un nuovo collega o gruppo di
 * collleghi, e cosi' via.  Ogni turno deve essere giocato utilizzando
 * un programma diverso tra tutti quelli realizzati dai componenti
 * delle due squadre.
 *
 * -----------------------------------------------------------------
 *
 * Ulteriori estensioni (meglio realizzarle dopo aver visto il
 * costrutto struct a lezione)
 *
 * . Aggiungere tutto quello che e' necessario per gestire una intera
 *   partita, ossia tutti i turni decisi dalle squadre
 *
 * . Fare scegliere casualmente al programma la parola segreta, tra
 *   quelle memorizzate in un file di testo dato
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std; 

void crea_file_parola_segreta(char parola_segreta[ ]){
    ofstream file_parola; 
    file_parola.open("parola_segreta.txt");
    if (!file_parola)
        cerr<< "Errore! Impossibile aprire il file in scrittura!"; 
    /*la squadra A sceglie la parola*/
    file_parola<<parola_segreta << endl;  
    int lunghezza = strlen(parola_segreta); 
    // ho aggiunto il terminatore. 
    parola_segreta[lunghezza] = '\0';
    file_parola.close(); 
}

void crea_file_indizi(char indizio[], int numero_indizi){
    // creo un altro file dove memorizzare gli indizi
    ofstream file_indizi_clean; 
    file_indizi_clean.open("indizi.txt"); 
    if (!file_indizi_clean)
        cerr << "Errrore nell'apertura!"; 
    file_indizi_clean.close(); 

    ofstream file_indizi; 
    file_indizi.open("indizi.txt", ios_base::app); 
    if (!file_indizi)
        cerr << "Errore nell'apertura del file in scrittura!"; 
    else{
        for (int i = 1; i <= numero_indizi; i++){
            cout << "Inserisci indizio  ("<< i << " / " << numero_indizi << "): ";
            cin>>indizio;
            file_indizi << indizio << endl; 
        }
    }
    file_indizi.close(); 

}

void trova_lettere_comuni(char parola_segreta[ ], char parola_tentativo [ ], int dim_parola, int lunghezza_tent, string &lettere_trovate){

  
    int indice = 0; 
    for (int j = 0; j < dim_parola; j++){
        for(int i = indice; i < lunghezza_tent; i++){
            if (parola_segreta[j] == parola_tentativo[i]){
                lettere_trovate += parola_segreta[j]; 
                indice = i + 1; 
                break;
            }
        }   
    }
}


int main(){
   /* le funzioni che mi servono: 
   - scrive la parola segreta nel file
   - scrive gli indizi dentro il file e li stampa a schermo
    - chiedo in input la parola segreta, se è diversa la squadra perde un punto. 
   */

    // chiedo in input la parola segreta e la chiedo in input. 

    const int dim_parola = 20; 
    char parola_segreta[dim_parola]; 
    cout << "Inserici una parola: "; 
    cin>>parola_segreta; 

    crea_file_parola_segreta(parola_segreta); 

    // chiedo il numero di indizi e li metto dentro il file indizi.txt

    int numero_indizi; 
    cout << "Quanti indizi vuoi immettere: "; 
    cin>>numero_indizi; 
    char indizio[dim_parola];
    
    crea_file_indizi(indizio, numero_indizi); 

    //cout << "Puoi trovare gli indizi anche qu: indizi.txt " << endl; 

    // punteggio
    int punteggio = 50; 
    const int dim_parola_tentativo = 20; 
    char parola_tentativo [dim_parola_tentativo]; 

    
    do{
        cout << "Inserisci la parola tentativo: " << endl; 
        cin>>parola_tentativo; 

        int lunghezza_tent = strlen(parola_tentativo); 
        parola_tentativo[lunghezza_tent] = '\0'; 

        if (strcmp(parola_tentativo, parola_segreta) == 0){
            cout << "Hai indovinato la parola segreta!"<< endl; 
            cout << "Punteggio: " << punteggio << endl; 
            break;
        }
        else{
            cout << "Parola non trovata, rirpova di nuovo!" << endl; 
            punteggio--; 
            cout << "Punteggio: " << punteggio << endl; 
            string lettere_trovate = "";  

            trova_lettere_comuni(parola_segreta, parola_tentativo, dim_parola, lunghezza_tent, lettere_trovate); 
            cout << endl; 

            cout << "Ecco le lettere in comune che sono state trovate: " << endl; 
            cout << lettere_trovate << endl; 
            cout << endl; 
        }
    }
    while(strcmp(parola_tentativo, parola_segreta) != 0); 
    return 0; 
}
