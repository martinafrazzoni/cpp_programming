/*
 * I parte
 *
 * Partendo dal frammento di programma di seguito fornito, scrivere un
 * programma che faccia apparire e permetta di spostare un puntatore,
 * denotato dal carattere X, all'interno di una tavola di caratteri
 * quadrata e costituita da spazi. Il puntatore, che all'inizio si
 * trova al centro della tavola, si sposta nelle quattro possibili
 * direzioni alla pressione di uno di quattro tasti predefiniti. Ad
 * esempio, nel caso di tavola di dimensioni 6x6, l'output iniziale
 * sarebbe il seguente:
 *
 * j->sinistra, l->destra, i->alto, k->basso
 * q->esci
 *
 *      
 *     
 *   X  
 *     
 *
 *
 * Se si premesse il tasto l, il nuovo output sarebbe:
 *
 * j->sinistra, l->destra, i->alto, k->basso
 * q->esci
 *
 *      
 *     
 *    X  
 *     
 *
 *
 * Per far si che nel terminale appaia solo l'output del programma, si
 * puo' cancellare il contenuto del terminale stesso prima di
 * ristampare il nuovo output. Per farlo si puo' utilizzare, ad
 * esempio, la funzione:
 * system("clear") ;
 * che invoca semplicemente il comando clear.
 * 
 * Il puntatore puo' spostarsi solo all'interno della tavola, quindi
 * per esempio, una volta raggiunto il bordo destro, non e' possibile
 * farlo spostare ancora piu' a destra.
 *
 * Il ridisegno della tavola e l'aggiornamento del suo contenuto
 * devono essere realizzati all'interno di due funzioni.
 *
 *
 * II parte
 *
 * Aggiungere altre due modalita' del puntatore rispetto a quella di
 * semplice spostamento. La prima delle due nuove modalita' sia quella
 * di disegno, e la seconda quella di cancellazione. Definire il tasto
 * da premere per passare in ciascuna delle tremodalita'.
 * 
 * Nella modalita' di disegno il simbolo del puntatore deve diventare
 * un +. Inoltre, in ogni posizione da esso occupato, il puntatore
 * deve disegnare un *.  Ad esempio, supponiamo che il puntatore si
 * trovi al centro della tavola e sia in modalita' di solo
 * spostamento. Se lo si fa passare in modalita' disegno e lo si sposta
 * verso sinistra si ottiene:
 *
 * j->sinistra, l->destra, i->alto, k->basso
 * u->disegna, o->cancella, n->solo sposta
 * q->esci
 *
 *      
 *     
 *  +*  
 *     
 *
 *
 * Se poi lo si sposta ad esempio verso l'alto, si ottiene:
 *
 * j->sinistra, l->destra, i->alto, k->basso
 * u->disegna, o->cancella, n->solo sposta
 * q->esci
 *
 *      
 *  +   
 *  **  
 *     
 *
 *
 * E cosi' via. Infine, nella modalita' di cancellazione il simbolo
 * del puntatore deve divenire un -. Nella modalita' di cancellazione
 * il puntatore ritrasforma in uno spazio l'eventuale * presente nella
 * posizione da esso occupata.
 *
 * La soluzione dell'esercizio e' nel file sol_car_codici_immediato.cc
 *
 *
 * Estensioni:
 *. salvataggio e caricamento disegno
 *. spostamento puntatore mediante tasti cursore
 *. stampa di una cornice attorno all'area di disegno
*/

/*
 * Segue il frammento di programma da cui partire
 *
 * Per lo svolgimento dell'esercizio non e' di nessuna importanza
 * capire come si ottiene il cambio di modalita' del terminale.  I
 * dettagli su tali operazioni si vedranno in corsi futuri. Quello che
 * va fatto e' solo scrivere le righe mancanti!
 *
 */

#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std ;

  /*definisco le righe e le colonne della mia matrice */
    const int righe = 25; 
    const int col = 50; 

/*
 * Configura il terminale in modo non canonico
 */
void vai_in_modo_non_canonico() 
{
    struct termios nuovo ;
    if (tcgetattr(STDIN_FILENO, &nuovo) < 0) {
	cout<<"Salvataggio modo terminale fallito"<<endl ;
	exit(1) ;
    }

    nuovo.c_lflag &= ~ICANON ;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &nuovo) < 0) {
	cout<<"Settaggio modo terminale fallito"<<endl ;
	exit(1) ;
    }

}

void salva_modo_terminale(termios &modo)
{
    if (tcgetattr(STDIN_FILENO,  &modo) < 0) {
	cout<<"Salvataggio modo terminale fallito" ;
	exit(1) ;
    }
}

void assegna_modo_terminale(termios &modo)
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &modo) < 0) {
	cout<<"Salvataggio modo terminale fallito" ;
	exit(1) ;
    }
}

void tavola_iniziale(char tavola [righe][col]){
    for (int i = 0; i < righe; i++){
        for (int j = 0; j < col; j++){
            tavola[i][j]  = ' '; 
        }
        cout << endl; 
    }
     tavola[righe/2][col/2] = 'X';  // ho messo la x nel centro della tavola. 
}

void stampa_tavola(char tavola[righe][col]){
    for (int o = 0; o < (righe*2); o++){
        cout << "—"; 
    }
    cout << endl; 
 
    for (int i = 0; i < (righe); i++){
        cout << "|"; 
        for (int j = 0; j < (col); j++){
            cout << tavola[i][j]; 
        }
        cout << " |" <<  endl; 
    }

    for (int o = 0; o < (righe*2); o++){
        cout << "—"; 
    }
    cout << endl; 
}

void sposta_puntatore(char tavola[righe][col], int &pos_x, int &pos_y, char &direzione, char &modalità){
    if (modalità == 'n'){
        tavola[pos_x][pos_y] = ' '; 

        if (direzione == 'j' && pos_y > 1){
            pos_y--; 
        }
        else if (direzione == 'l' && pos_y < col-1)
            pos_y++;
        else if (direzione == 'i' && pos_x < righe-1)
            pos_x++; 
        else if (direzione == 'k' && pos_x > 0 )
            pos_x--; 
        
        tavola[pos_x][pos_y] = 'X'; 
    }
    else if (modalità == 'u'){
        tavola[pos_x][pos_y] = '*'; 

        if (direzione == 'j' && pos_y > 1){
            pos_y--; 
        }
        else if (direzione == 'l' && pos_y < col-1)
            pos_y++;
        else if (direzione == 'i' && pos_x < righe-1)
            pos_x++; 
        else if (direzione == 'k' && pos_x > 0 )
            pos_x--; 
        
        tavola[pos_x][pos_y] = '+'; 
    }
    else if (modalità == 'o'){
        tavola[pos_x][pos_y] = ' '; 

        if (direzione == 'j' && pos_y > 1){
            pos_y--; 
        }
        else if (direzione == 'l' && pos_y < col-1)
            pos_y++;
        else if (direzione == 'i' && pos_x < righe-1)
            pos_x++; 
        else if (direzione == 'k' && pos_x > 0 )
            pos_x--; 
        
        tavola[pos_x][pos_y] = '-'; 
    }
    
}



int main()
{
     
    termios vecchio_modo_terminale ;
    // si salva la modalita' corrente per ripristinarla al termine del
    // programma
    salva_modo_terminale(vecchio_modo_terminale) ;

    vai_in_modo_non_canonico() ;

    char tavola [righe][col]; 
    int pos_y = col / 2; 
    int pos_x = righe / 2; 
    char direzione; 
    char modalità; 

    tavola_iniziale(tavola); 
    stampa_tavola(tavola); 

   while (true){
        do{
            cout << "Scegli la modalità: ";  
            cout << "Spostamento, tasto 'n': "; 
            cout << "Disegno, tasto 'u': "; 
            cout << "Cancella, tasto 'o': "; 
            cout << "Uscita, tasto 'q'" << endl; 
            cin >> modalità; 
        } while (modalità != 'n'&& modalità != 'u' && modalità != 'o' && modalità != 'q');
        
        cout << endl; 

        cout << "Inserisci 'j' per far spostare il puntatore a sinistra, 'l' a destra, 'i' in basso, e 'k' in alto, 'q' per uscire: \n"; 
        cin>>direzione; 
        if (direzione == 'q'){
            break;
            return 0; 
        }
        sposta_puntatore(tavola, pos_x, pos_y, direzione, modalità); 
        system("clear"); 
        stampa_tavola(tavola); 
    }

    // qui il terminale viene riportato nella modalita' precedente
    assegna_modo_terminale(vecchio_modo_terminale) ;

    return 0 ;
}
