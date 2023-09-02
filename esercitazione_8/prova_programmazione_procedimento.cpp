/*
Contenitore

Un Contenitore e' in grado di contenere elementi in numero limitato (la			// array 
capienza del contenitore). Ciascun elemento ha un nome che consiste in
una lettera (minuscola) dell'alfabeto. Piu' elementi di un contenitore
possono avere lo stesso nome. Le operazioni che possono essere effettuate
sul contenitore sono le seguenti:

.	Inizializza(N);
Inizializza il contenitore con capienza pari ad N elementi. Il
contenitore e' vuoto. L'eventuale contenuto precedente viene perso.

.	Inserisci(p)
Inserisce un elemento avente nome p.

.	Estrai(p)
Estrae dal contenitore tutti gli elementi aventi nome p.

.	Modifica(N)
Modifica la capienza del contenitore. Dopo la modifica il contenitore
ha capienza N e contenuto identico a quello originario. Affinche'
l'operazione abbia successo, il numero di elementi contenuti nel
contenitore deve essere minore od uguale ad N.

.	capienza()
Ritorna la capienza del contenitore.

.	quanti()
Ritorna il numero degli elementi presenti nel contenitore.

.	stampa()  
Stampa il contenuto del Contenitore. LŽ¢uscita ha la forma seguente:
		<a:3, d:1, s:5>
In questo esempio, nel contenitore sono presenti tre elementi di nome
'a', uno di nome 'd' e cinque di nome 's'.


Gestire opportunamente le condizioni di errore, tranne i problemi di
overflow e le condizioni di errore in lettura da stdin.

Nella soluzione e' contenuto anche un main, che potete eventualmente
utilizzare per testare le funzioni nella vostra soluzione. Svolgere
l'esercizio senza utilizzare il costrutto struct (non ancora visto a
lezione).
*/


-> io praticamente ho un array di caratteri. mettiamo che il mio array ha dimensione 3: 
const int n = 3
cons int capienza_max = 10; 
char a [capienza_max]; 


Le operazioni che posso fare sul contenitore sono: 
- > inizializza il contenitore con capienza n elementi. 
faccio un ciclo for, e chiedo in input all'utente un carattere, per la capienza del mio contenitore da 0 a n-1. 

-> posso inserire un elemento di nome (p)
chiedo all'utente in che indice vuole inserire l'elemento di nome p, e traslo tutti gli elementi successivi di 1. 
Se vuole inserire un elemento, prima devo controllare la grandezza del contenitore, se ha raggiunto la capienza massima. Se non l'ha raggiunta allora inserisco l'elemento. Se lo vuole mettere nella posizione di indice 2 vorrà dire che tutti gli elementi successivi si traslano di 1. e il contatore del numero di elementi aumenta. 

-> estraggo tutti gli elementi di nome (p)
chiedo all'utente qual'è l'elemento che vuole estrarre, e da quell'elemento in poi tutti gli altri si spostano di 1 verso sinistra e il contatore del numero di elementi diminuisce di 1. 

-> modifica la capienza (n)
dopo la modifica il contenitore ha capienza n e il contenuto è quello originario (presumo che torni tutto come all'inizio, la capienza è quella iniziale e ed è vuoto). 

-> ritorna la capienza del contenitore 
-> ritorna il numero di elementi presenti attualmente nel contenitore (che potrebbero essere meno di quelli cje può effettivamente contenere)

-> stampa il contenuto del contenitore
<a:3, d:1, s:5> -> ci sono 3 elementi, 'a' , 'd', 's'. 

Struttura dati: 

Costante intera che mi definisca la capienza massima del mio contenitore, e la definisco io a tempo di scrittura del programma. 
Const int capienza_max = 20; 

variabile che chiedo in input di quanti elementi si vogliono inserire all'interno del contenitore. 
int n; 

array di caratteri, che mi contiene i singoli elementi che hanno come nome una lettera minuscola. 
int a[capienza_max]; 

se voglio inizializzare il mio array, devo avere una variabile contatore all'interno del for, e per ogni indice ci va a mettere un carattere. 

variabile p, che contiene il nuovo elemento che l'utente vuole inserire (come al solito variabile contatore nel for). 
