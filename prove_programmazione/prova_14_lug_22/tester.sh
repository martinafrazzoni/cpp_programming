#!/bin/bash

# ISTRUZIONI PER L'ESECUZIONE DI QUESTO SCRIPT
# bash prova-sorgente-spedisci-data_esame.sh nome_vostro_file_sorgente

crea_tester ()
{
    cat <<- EOF > righe_da_ultima_stampa.cc
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

void turn_lowercase(string &s)
{
	for (unsigned int i = 0 ; i < s.size() ; i++)
		s[i] = tolower(s[i]);
}

bool confronta_contenuto_linee(string linea1, string linea2)
{
	turn_lowercase(linea1);
	turn_lowercase(linea2);

	string buf1, buf2;
	stringstream stream1(linea1), stream2(linea2);

	// controllo prima riga della stampa
	while (true) {
		stream1>>buf1;
		stream2>>buf2;

		if (!stream1 || !stream2 || buf1 != buf2)
			break;
	}

	if (stream1 || stream2)
		return false;

	return true;
}

int main(int argc, char** argv)
{
	if (argc < 3) {
		cout<<"Argomenti mancanti"<<endl;
		return 1;
	}

	int num_linee = atoi(argv[1]);

	string linea;
	int indice_linea_corretta = 0;

	vector<string> linee_output;
	bool buffering = false;

	while (getline( cin, linea ) && indice_linea_corretta < num_linee) {
		string linea_corretta(argv[indice_linea_corretta+2]);

		if (confronta_contenuto_linee(linea, linea_corretta) ) {
		    if (buffering && indice_linea_corretta == 0) {
		       // found a new beginning, restart
		       linee_output.clear();
		    }
		    buffering = true;
		} else if (buffering && indice_linea_corretta < num_linee) {
		     buffering = false;
		     linee_output.clear();
		     indice_linea_corretta = 0;
		}

		if (buffering) {
		     linee_output.push_back(linea);
		     indice_linea_corretta++;
		}
	}

	// stampa le ultime linee a partire dall'ultima stampa
	for (std::vector<string>::const_iterator i = linee_output.begin();
	     i != linee_output.end(); ++i)
		std::cout << *i<<endl;

	return 0;
}
EOF

    g++ -Wall righe_da_ultima_stampa.cc -o righe_da_ultima_stampa

    if [ $? -ne 0 ]; then
	echo Compilazione del filtro delle righe di output fallita
	exit 1
    fi

    cat <<- EOF > controlla_output.cc
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

void turn_lowercase(string &s)
{
	for (unsigned int i = 0 ; i < s.size() ; i++)
		s[i] = tolower(s[i]);
}

bool confronta_contenuto_linee(string linea1, string linea2)
{
	turn_lowercase(linea1);
	turn_lowercase(linea2);

	string buf1, buf2;
	stringstream stream1(linea1), stream2(linea2);

	// controllo prima riga della stampa
	while (true) {
		stream1>>buf1;
		stream2>>buf2;

		if (!stream1 || !stream2 || buf1 != buf2)
			break;
	}

	if (stream1 || stream2)
		return false;

	return true;
}

int main(int argc, char** argv)
{
	if (argc < 3) {
		cout<<"Argomenti mancanti"<<endl;
		return 1;
	}

	int num_linee = atoi(argv[1]);

	cout<<"Ora leggo l'output del programma, e come parte finale di stampa dello stato"
	    <<endl<<"mi aspetto:"<<endl;

	for (int i = 0 ; i < num_linee ; i++)
		cout<<argv[i+2]<<endl;

	string linea;
	bool letta_una_linea = false;
	int indice_linea_corretta = 0;

	while (getline( cin, linea ) && indice_linea_corretta < num_linee) {
		letta_una_linea = true;
		string linea_corretta(argv[indice_linea_corretta+2]);

		if (!confronta_contenuto_linee(linea, linea_corretta)) {
			cout<<"La seguente riga:"<<endl;
			cout<<linea<<endl;
			cout<<"Non coincide con la riga attesa, ossia con:"
			    <<endl;
			cout<<linea_corretta<<endl;
		cout<<"Se ti sembra che invece la riga coincida e non riesci a"<<endl;
		cout<<"capire perche' venga ritenuta diversa, allora controlla"<<endl;
		cout<<"attentamente la presenza di eventuali spazi in piu' o in"<<endl;
		cout<<"meno nella tua riga, o di caratteri di punteggiatura in"<<endl;
		cout<<"piu' o in meno (tipo : ; , . accapo e cosÃ¬ via)."<<endl;
		cout<<endl;
		cout<<"Un altro errore comune e' il non aver inserito un accapo PRIMA"<<endl;
		cout<<"della prima riga che mi aspetto di trovare. In tal caso, tale prima"<<endl;
		cout<<"prima riga non e' effettivamente una riga a se stante, ma risulta attaccata"<<endl;
		cout<<"alla riga precedente. Quando tu inserisci l'input manualmente, non ti accorgi"<<endl;
		cout<<"di questo errore, perchÃ© inserisci tu i newline nel terminale. Ma tali newline"<<endl;
		cout<<"non ci sono nell'output del programma."<<endl;
		cout<<endl;

			return 1;
		}
		indice_linea_corretta++;
	}

	cout<<endl;

	if (!letta_una_linea) {
		cout<<"Non ho trovato la prima tra le righe di stampa da controllare!"
		    <<endl;
		cout<<"Verifica la presenza di tale riga nell'output del tuo programma"<<endl
		    <<"e la correttezza del formato di tale riga."<<endl;
		cout<<"Se ti sembra che la riga ci sia, controlla attentamente,"<<endl;
		cout<<"nella tua riga di stampa, la presenza di eventuali spazi"<<endl;
		cout<<"in piu' o in meno, o di caratteri di punteggiatura in piu'"<<endl;
		cout<<"o in meno (tipo : ; , . accapo e cosÃ¬ via)."<<endl;
		cout<<endl;
		cout<<"Un altro errore comune e' il non aver inserito un accapo PRIMA"<<endl;
		cout<<"della prima riga che mi aspetto di trovare. In tal caso, tale prima"<<endl;
		cout<<"prima riga non e' effettivamente una riga a se stante, ma risulta attaccata"<<endl;
		cout<<"alla riga precedente. Quando tu inserisci l'input manualmente, non ti accorgi"<<endl;
		cout<<"di questo errore, perchÃ© inserisci tu i newline nel terminale. Ma tali newline"<<endl;
		cout<<"non ci sono nell'output del programma."<<endl;
		cout<<endl;

		return 1;
	}

	cout<<"Test superato!!!"<<endl;
	cout<<"-------------------------------------------------------------"
	    <<endl;

	return 0;
}
EOF

    g++ -Wall controlla_output.cc -o controlla_output

    if [ $? -ne 0 ]; then
	echo Compilazione del controllore dell\'output fallita
	exit 1
    fi
}

# se il parametro $1 e' vuoto, allora non si e' superato il compito
stampa_msg_punto_insufficiente ()
{
    if [ "$1" != "" ]; then
	punto=$1
	echo Il tuo programma ha superato tutti i test relativi ai punti che
	echo precedono il punto $punto, ma non ha superato un test relativo al
	echo "punto $punto (ossia l'ultimo test effettuato finora)."
	echo
	echo "Il test del punto $punto potrebbe essere fallito semplicemente perche'"
	echo non hai ancora implementato il punto $punto.
	echo
	echo Per poter accedere alla correzione anche del $punto,
	echo "devi prima aver implementato il punto $punto ed aver corretto"
	echo "gli errori che fanno fallire l'ultimo test."
	echo
	echo "I docenti correggeranno SOLO i punti PRECEDENTI al punto $punto"
	echo
	if ! command -v sender &> /dev/null
	then
	    echo "Sono eseguito su un PC personale, non spedisco nulla."
	    rm controlla_output* righe_da_ultima_stampa*
	    exit
	else
		retval=$(sender $sorgente `whoami` | grep "moved successfully")
		if ! echo $retval | grep "not"
		then
			echo Ho spedito quindi il tuo compito per la correzione.
			echo Invocami di nuovo se vuoi fare spedire una nuova versione del tuo compito.
		else
			echo Non sono riuscito a spedire il file per la correzione.
			echo Contatta il docente del corso per chiarimenti se necessario.
		fi
	fi
	echo In ogni caso, hai superato abbastanza punti da poter accedere
	echo alla correzione del compito. Ho spedito quindi il compito
	echo per la correzione. Invocami di nuovo se vuoi fare
	echo spedire una nuova versione del tuo compito.
    else
	echo
	echo Per poter accedere alla correzione del compito,
	echo "devi prima correggere gli errori che fanno fallire l'ultimo test."
	echo
	echo Quindi NON ho spedito il tuo compito per la correzione.
    fi

    echo
    echo "Scorri in alto fino all'inizio dell'ultimo test, se vuoi controllare "
    echo "di che test si tratta e qual'e' stato l'input dato al tuo programma."
    echo
    echo Se il tuo programma ha stampato troppe righe, perche\' e\' entrato in
    echo un ciclo infinito, allora potrebbe tornarti utile redirezionare l\'output
    echo su un file, e poi analizzare il contenuto del file.
    echo Ad esempio, puoi eseguire
    echo "$0 <nome_tuo_file_sorgente.cc> > output_file.txt"
    echo ed aspettare che il test termini. Non vedrai nessun output, perche\'
    echo sta andando tutto dentro al file output_file.txt. Se il test impiega troppo
    echo a terminare, allora puoi fermarlo manualmente.
    echo Successivamente, apri il file output_file.txt e cerchi il test fallito.
    echo
    echo Un volta trovato il test fallito, un modo per riuscire a correggere gli errori
    echo nel tuo programma e\' provare ad eseguire il tuo programma manualmente,
    echo dando lo stesso input provato da me.
    echo
    echo Quando il tuo programma superera\' questo test, eseguiro\' anche i successivi.
    echo

    rm controlla_output* righe_da_ultima_stampa*

    exit 1
}

esegui_test ()
{
    if [ $# -le 3 ]; then
	echo
	echo !! Troppo pochi parametri passati alla funzione esegui_test !!
	echo Per il test "$1"
	echo Test successivi cancellati
	echo

	exit 1
    fi

    nome_test="$1"
    punto=$2
    input_test="$3"
    num_linee_da_controllare=$4
    prima_linea_stampa="$5"

    if [ $4 -gt 5 ]; then
	echo Numero di righe da controllare maggiore del massimo supportato

	exit 1
    fi

    if [ $# -le $(($num_linee_da_controllare + 3)) ]; then
	echo Troppo pochi parametri passati alla funzione esegui_test
	echo $#

	exit 1
    fi

    echo
    echo ==== Inizio test $nome_test ====
    echo
    echo Eseguo il programma fornendo il seguente input: "$input_test"
    echo

    echo Ecco l\'output del programma, in cui non vedrai l\'input:
    echo

    dim_iniziali=$(wc -l < output_eseguibile.txt)
    dim_massime=$(($dim_iniziali + 500))
    ( while true; do \
	  if [[ "$(wc -l < output_eseguibile.txt)" -gt $dim_massime ]]; \
		     then killall -17 $eseguibile; touch infinite_loop ; killall -9 $eseguibile; break; fi \
      done ) &
    CHECK_PID=$!
    disown

    # il comando echo DEVE supportare l\'opzione -e
    echo -e "$input_test" | ./$eseguibile | tee output_eseguibile.txt

    if [ -f infinite_loop  ]; then
	rm infinite_loop
	echo
	echo -n "Purtroppo il tuo programma sembra entrare in un ciclo infinito"
	echo " con l'ultimo test."
	stampa_msg_punto_insufficiente $punto
	return
    else
	kill -9 $CHECK_PID 2>&1 > /dev/null
    fi

    if [ $num_linee_da_controllare -ne 0 ]; then
	cat output_eseguibile.txt | \
	    ./righe_da_ultima_stampa $num_linee_da_controllare \
				 "$prima_linea_stampa" \
				 "$6" "$7" "$8" "$9" \
	    | ./controlla_output $num_linee_da_controllare \
				 "$prima_linea_stampa" \
				 "$6" "$7" "$8" "$9"
    else
	echo In questo test non controllo l\'output del programma
	echo
    fi

    if [ $? -ne 0 ]; then
	stampa_msg_punto_insufficiente $punto
    fi
}

# - inserire sempre la scelta di uscire dal programma a fine input
esegui_tutti_test ()
{
    # se, per un dato test, il programma legge in input una o piÃ¹
    # righe (cioe' sequenze di caratteri che possono contenere anche
    # spazi), incluso eventuali righe vuote, oltre ad altri elementi
    # (caratteri, numeri, parole) per qualche funzionalita', allora,
    # per passare anche tali righe in input al programma, bisogna
    # inserire un \n alla fine delle righe, nella stringa completa
    # dell'input

    # reinizializzazione a vuoto senza stampa
    esegui_test "reinizializzazione a vuoto senza stampa" "" "1 0 8" 0

    esegui_test "stampa senza reinizializzazione" "" "3 8" 0

    # "reinizializzazione non corretta a vuoto, senza stampa"

    # reinizializzazione senza stampa
    esegui_test "reinizializzazione a dimensione uno, senza stampa" "" "1 1 8" 0

    # "reinizializzazione a dimensione uno, con stampa" ""

    # reinizializzazione a molti elementi

    esegui_test "reinizializzazione a dimensione maggiore di uno, senza stampa" "" "1 2 8" 0

    # "reinizializzazione a dimensione maggiore di uno" ""

    # "reinizializzazione a dimensione piÃ¹ grande maggiore di uno" ""

    # reinizializzazione con carattere non valido
    # reinizializzazione a 4 elementi
    # reinizializzazione a 4 elementi con carattere non valido

    # doppia reinizializzazione con seconda a vuoto
    esegui_test "doppia reinizializzazione con seconda a vuoto" "" "1 3 1 0 8" 0

    # doppia reinizializzazione con seconda a un elemento
    esegui_test "doppia reinizializzazione con seconda a un elemento" "" "1 3 1 1 8" 0

    # doppia reinizializzazione con seconda a stesso numero di elementi
    # "reinizializzazione a dimensione maggiore di uno" ""

    # doppia reinizializzazione con prima a vuoto e seconda a molti elementi

    # doppia reinizializzazione con prima a vuoto e seconda a 16 elementi

    # "reinizializzazione a lunghezza massima uno"
    # "reinizializzazione a lunghezza massima due"
    # "reinizializzazione a una operazione"


    # ricerca di elemento presente

    # inserimento di un oggetto
    esegui_test "accodamento di una operazione" "" "1 3 2 + 1 3 8" 1 "(+ 1)"

    esegui_test "accodamento di una operazione in coda vuota" "" "1 0 2 + 1 3 8" 0

    # TEST indiretto: aggiornamento di un oggetto in insieme prima
    # vuoto e poi non vuoto: il secondo inserimento permette poi di
    # controllare la stampa, e quindi di controllare implicitamente se
    # il primo inserimento ha provocato un fallimento del programma

    esegui_test "accodamento di una operazione in coda prima vuota poi non vuota" "" "1 0 2 + 1 1 1 2 - 3 3 8" 1 "(- 3)"

    # inserimento di due oggetti
    esegui_test "accodamento di due operazioni" "" "1 3 2 + 1 2 - 3 3 8" 1 "(+ 1) (- 3)"

    # aggiornamento di un oggetto con una stringa troppo lunga

    # "aggiornamento di un oggetto non presente" ""

    # inserimento di un oggetto all'inizio

    # inserimento di un oggetto alla fine
    # inserimento di un oggetto di lunghezza uno nel mezzo con spazio prima

    # inserimento di un oggetto di lunghezza uno nel mezzo, con spazio al limite

    # inserimento di un oggetto troppo grande

    # inserimento di un oggetto sovrapposto

    # "sostituzione di due parole nella stessa riga"
    # "sostituzione di due parole in righe diverse"
    # "doppia sostituzione di una parola corta-lunga"
    # "doppia sostituzione di una parola lunga-corta"
    # "tentativo sostituzione fuori matrice"
    # reinizializzazione a due elementi piÃ¹ complessi, se ha senso per questo compito
    # reinizializzazione ad un elemento inconsistente
    # esegui_test "reinizializzazione a una operazione con indice uguale a 0" "" "1 1 A 0\n 3 8" 0
    # esegui_test "reinizializzazione a una operazione con indice troppo alto" "" "1 1 A 2\n 3 8" 0

    # inserimento di un oggetto nel mezzo con spazio insufficiente
    esegui_test "accodamento in coda nulla" "" "2 + 1 8" 0

    # inserimento di troppi elementi
    esegui_test "accodamento di troppe operazioni" "" "1 2 2 + 1 2 + 3 2 - 5 3 8" 1 "(+ 1) (+ 3)"

    # reinizializzazione a meno elementi dopo inserimento
    esegui_test "reinizializzazione a lunghezza minore dopo accodamenti" "" "1 3 2 + 1 2 + 3 1 2 2 - 7 3 8" 1 "(- 7)"


    # reinizializzazione a piÃ¹ elementi dopo inserimento
    esegui_test "reinizializzazione a lunghezza maggiore dopo accodamenti" "" "1 3 2 + 1 2 + 3 1 5 2 - 7 3 8" 1 "(- 7)"

    # reinizializzazione a stessa lunghezza dopo inserimento, e nuovo inserimento
    esegui_test "reinizializzazione a lunghezza maggiore dopo accodamenti" "" "1 3 2 + 1 2 + 3 1 3 2 - 7 3 8" 1 "(- 7)"

    # "salvataggio"
    esegui_test "salvataggio" 4 "1 3 2 + 3 4 3 8" 1 "(+ 3)"

    # "salvataggio e aggiunta di un elemento"

    esegui_test "salvataggio e aggiunta di una operazione" 4 "1 3 2 + 3 4 2 - 7 3 8" 1 "(+ 3) (- 7)"

    # "salvataggio e reinizializzazione a stesso numero di elementi"
    esegui_test "salvataggio e reinizializzazione a stessa lunghezza" 4 "1 3 2 + 3 4 1 3 2 - 7 3 8" 1 "(- 7)"

    # "salvataggio, aggiunta di un elemento e nuovo salvataggio"
    esegui_test "salvataggio, aggiunta di un elemento e nuovo salvataggio" 4 "1 3 2 + 3 4 2 - 7 4 3 8" 1 "(+ 3) (- 7)"

    # "caricamento"

    esegui_test "preparazione caricamento coda vuota" 5 "4 3 8" 0
    esegui_test "caricamento coda vuota" 5 "5 8" 0

    esegui_test "salvataggio per preparazione prossimi test" 5 "1 4 2 + 3 2 + 2 2 - 6 2 + 4 4 3 8" 1 "(+ 3) (+ 2) (- 6) (+ 4)"

    esegui_test "caricamento" 5 "5 3 8" 1 "(+ 3) (+ 2) (- 6) (+ 4)"

    # reinizializzazione a meno elementi dopo caricamento
    esegui_test "reinizializzazione a meno elementi dopo caricamento" 5 "5 1 3 2 + 12 3 8" 1 "(+ 12)"

    # "reinizializzazione a zero elementi dopo caricamento"
    esegui_test "reinizializzazione a zero elementi dopo caricamento" 5 "5 3 1 0 8" 0

    esegui_test "reinizializzazione a stesso numero di elementi dopo caricamento" 5 "5 1 4 2 + 12 3 8" 1 "(+ 12)"

    # caricamento dopo reinizializzazione
    esegui_test "caricamento dopo reinizializzazione" 5 "1 2 2 + 15 5 3 8" 1 "(+ 3) (+ 2) (- 6) (+ 4)"


    # "cerca riga 1"

    # "inserimento dopo caricamento"

    # "salvataggio e caricamento dopo inserimento di meno elementi"

    # "solo caricamento dopo inserimento di meno elementi"

    # "elimina elemento da insieme vuoto"
    esegui_test "elimina operazione da coda vuota" 6 "6 8" 0

    # "elimina elemento da insieme con un elemento"
    esegui_test "elimina operazione da coda con una operazione" 6 "1 1 jb2 + 3 6 8" 0

    # "elimina due elementi da insieme con un elemento"
    esegui_test "elimina due operazione da coda con una operazione" 6 "1 1 2 + 3 6 6 8" 0

    # "elimina tre elementi da insieme vuoto"

    # "elimina due elementi da insieme con un elemento"

    # eliminazione di un elemento
    esegui_test "elimina operazione" 6 "5 6 3 8" 1 "(+ 2) (- 6) (+ 4)"

    # "elimina due elementi in un colpo"


    # "elimina due elementi in un colpo, poi un altro"

    # eliminazione di due elementi
    esegui_test "elimina due operazioni" 6 "5 6 6 3 8" 1 "(- 6) (+ 4)"


    # eliminazione di tutti gli elementi

    # eliminazione di troppi elementi

    # accodamento di due utenti dopo eliminazione
    esegui_test "accoda operazione dopo eliminazione di tutte le altre" 6 "5 6 6 6 6 2 + 9 3 8" 1 "(+ 9)"

    esegui_test "nuovo riempimento coda dopo eliminazioni" 6 "1 3 2 + 3 2 + 6 6 2 + 9 2 + 12 3 8" 1 "(+ 6) (+ 9) (+ 12)"


    esegui_test "unisci operazioni uguali" 7 "5 7 3 8" 1 "(+ 5) (- 6) (+ 4)"

    esegui_test "unisci operazioni inverse con seconda a valore minore" 7 "1 3 2 + 4 2 - 3 2 + 10 7 3 8" 1 "(+ 1) (+ 10)"

    esegui_test "unisci operazioni inverse con seconda a valore maggiore" 7 "1 3 2 - 3 2 + 5 2 + 10 7 3 8" 1 "(+ 2) (+ 10)"

    esegui_test "unisci operazioni inverse con seconda a valore uguale" 7 "1 3 2 - 3 2 + 3 2 + 10 7 3 8" 1 "(+ 10)"

    return

    # "scambia su matrice vuota"

    # "scambia tra due parole non vuote"

    # "scambia con una parola vuota"

    # esegui_test "tentativo di scambio con una parola fuori matrice" 5 "4 5 0 0 3 0 5 0 0 3 10 3 8" 3 "Paperino" "Minnie" "Pippo Quo"

    # esegui_test "scambia con minima su matrice vuota" 6 "6 0 0 3 8" 3 "" "" ""

    #Â esegui_test "scambia parola non vuota con minima non vuota" 6 "4 3 6 0 0 3 8" 3 "Quo Paperino" "Minnie" "Pippo"

    # esegui_test "scambia parola vuota con minima non vuota" 6 "4 6 1 1 3 8" 3 "Pippo Paperino" "Minnie Quo" ""

    # esegui_test "tentativo di scambio con una parola fuori matrice" 6 "4 6 3 5 3 8" 3 "Pippo Paperino" "Minnie" "Quo"

    # prova funzionalitÃ  con contenuto inferiore al massimo possibile
    # prova funzionalitÃ  con contenuto inferiore al massimo possibile
    # assegnamento con piÃ¹ docenti che corsi: implicito nel test con caricamento
    # prova funzionalitÃ  con successo
    # prova funzionalitÃ  con fallimento
}

# MAIN

sorgente=$1
eseguibile=a.out

if [ "$(echo -e)" != "" ]; then
    echo "In questa shell il comando echo non rispetta l'opzione -e"
    echo "Devi eseguirmi con una shell che rispetti tale opzione"
    echo "Una tale shell e' bash"
    exit
fi

if [ "$sorgente" = "" ]; then
    echo
    echo Devi fornirmi il nome del file sorgente da collaudare.
    echo
    echo Ossia devi invocarmi cosi\':
    echo bash $0 nome_tuo_file_sorgente.cc
    echo

    exit 1
fi

if command -v sender &> /dev/null; then
   spedisci-sorgente $sorgente
fi

g++ -std=c++11 -Wall -Wsign-compare -Werror -pedantic-errors $sorgente

if [ $? -ne 0 ]; then
    echo Compilazione fallita.
    echo
    echo Il tuo programma deve almeno compilarsi per poter accedere alla correzione.
    exit 1
fi

if [ $? -ne 0 ]; then
    echo
    echo Compilazione del sorgente $sorgente fallita.
    echo Questo vuol dire che il file non e\' stato trovato dal compilatore,
    echo oppure che la compilazione ha generato degli errori o delle warning.
    echo Leggi le righe che precedono questo messaggio per vedere di che
    echo errore si tratta esattamente.
    echo
    echo Il tuo sorgente NON e\' stato spedito. Il sorgente deve compilarsi
    echo senza errori per poter essere spedito per la correzione.
    echo

    exit 1
fi

if [ ! -f $eseguibile ]; then
    echo Eseguibile $eseguibile non trovato
    exit 1
fi

crea_tester
rm output_eseguibile.txt
touch output_eseguibile.txt # per far funzionare wc al primo test

esegui_tutti_test

echo Complimenti, il tuo programma ha superato tutti i test!
echo
if ! command -v sender &> /dev/null
then
    echo "Sono eseguito su un PC personale, non spedisco nulla."
else
	retval=$(sender $sorgente `whoami` | grep "moved successfully")
	if ! echo $retval | grep "not"
	then
		echo Ho spedito quindi il tuo compito per la correzione.
		echo Invocami di nuovo se vuoi fare spedire una nuova versione del tuo compito.
	else
		echo Non sono riuscito a spedire il file per la correzione.
		echo Contatta il docente del corso per chiarimenti se necessario.
	fi
fi

rm controlla_output* righe_da_ultima_stampa*