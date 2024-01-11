#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

const char NOMEFILE[] = "etichetta.dat";

// descrittore della coppia di nastri
struct etichetta_t {
	unsigned char *codici;	// array dinamico di codici
	unsigned int N;		// numero codici
};

/*
 * Inizializza l'etichetta e a contenere 0 codici. Assume che la
 * coppia non sia mai stata inizializzata prima.
 */
void inizializza(etichetta_t &e)
{
	e.N = 0;
}

/*
 * Funzione di servizio che rialloca la memoria per l'etichetta e,
 * affinche' contenga N codici.
 */
void rialloca(etichetta_t &e, unsigned int N)
{
	if (e.N > 0 && e.N != N) {
		delete [] e.codici;
		e.N = 0;
	}

	if (e.N != N && N > 0) {
		e.codici= new unsigned char[N];
		e.N = N;
	}
}

/*
 * Ritorna vero solo se la stringa s rappresenta correttamente un
 * codice.
*/
bool controlla_stringa(const char *s)
{
	if (strlen(s) != 16)
		return false;

	for (unsigned int i = 0 ; i < 8 ; i++) {
		if ((s[2*i] != '.' && s[2*i] != '|') ||
		    (s[2*i+1] != '.' && s[2*i+1] != '|'))
			return false;

		if (s[2*i] == s[2*i+1])
			return false;
	}

	return true;
}

/*
 * Stampa il codice contenuto nel carattere c in forma binaria.
 */
void stampa_da_numero(unsigned char c)
{
	for (unsigned int i = 0 ; i < 8 ; i++) {
		unsigned int potenza = pow(2, 7 -i);

		if ((c / potenza) % 2 != 0)
			cout<<".|";
		else
			cout<<"|.";
	}
}

unsigned char converti_da_stringa(const char *s)
{
	unsigned char c = 0;

	for (unsigned int i = 0 ; i < 8 ; i++)
		if (s[2*i] == '.')
			c += pow(2, 7 - i);

	return c;
}

/*
 * Reinizializza l'etichetta e a contenere N codici che saranno letti
 * da stdin, assumendo che l'etichetta sia giÃ  stata inizializzata
 * almeno una volta. Legge i codici sotto forma di numeri se da_numeri
 * e' vero. Ritorna vero in caso di successo, falso in caso di
 * fallimento.
 */
void reinizializza(etichetta_t &e, unsigned int N, bool da_numeri)
{
	rialloca(e, N);

	cout<<"Inserisci codici: ";
	for (unsigned int i = 0 ; i < N ; i++) {
		if (da_numeri) {
			unsigned int valore;
			cin>>valore;
			e.codici[i] = valore;
		} else {
			char codice_str[17];
			cin>>codice_str;
			if (controlla_stringa(codice_str))
				e.codici[i] = converti_da_stringa(codice_str);
			else
				e.codici[i] = 0;
		}
	}
	cout<<endl;
}

/*
 * Stampa una sequenza di cifre 01234567 per ciascuno dei codici
 * contenuti nell'etichetta e.
 */
void stampa_intestazione(const etichetta_t &e)
{
	for (unsigned int i = 0 ; i < e.N ; i++) {
		if (i > 0)
			cout<<'\t';
		for (unsigned int j = 0 ; j < 8 ; j++)
			cout<<' '<<j;
	}
	cout<<endl;
}

/*
 * Stampa l'etichetta e su stdout. Stampa i codici sotto forma di
 * numeri se numerico e' vero.
 */
void stampa_etichetta(const etichetta_t &e, bool numerico)
{
	if (!numerico)
		stampa_intestazione(e);

	for (unsigned int i = 0 ; i < e.N ; i++) {
		if (i > 0)
			cout<<'\t';
		if (!numerico)
			stampa_da_numero(e.codici[i]);
		else
			cout<<static_cast<int>(e.codici[i]);

	}
	cout<<endl;
}

/*
 * Salva l'etichetta e su un file binario. Ritorna vero in caso di
 * successo, falso altrimenti.
 */
bool salva_etichetta(const etichetta_t &e)
{

	ofstream f(NOMEFILE);

	if (!f)
		return false;

	f.write(reinterpret_cast<const char *>(&e.N), sizeof(e.N));

	f.write(reinterpret_cast<const char *>(e.codici),
		e.N * sizeof(unsigned char));

	return static_cast<bool>(f);
}

/*
 * Carica il contenuto dell'etichetta e dal file. Ritorna vero in caso
 * di successo, falso in caso di fallimento.
 */
bool carica_etichetta(etichetta_t &e)
{

	ifstream f(NOMEFILE);

	if (!f)
		return false;

	unsigned int N;
	f.read(reinterpret_cast<char *>(&N), sizeof(N));

	rialloca(e, N);

	f.read(reinterpret_cast<char *>(e.codici),
	       N * sizeof(unsigned char));

	return static_cast<bool>(f);
}

int main()
{
	etichetta_t e;

	inizializza(e);

	const char menu[] =
		"1. Inizializza etichetta\n"
		"2. Stampa etichetta\n"
		"3. Salva etichetta su file binario\n"
		"4. Carica etichetta\n"
		"5. Inizializza etichetta 2\n"
		"6. Stampa etichetta 2\n"
		"7. Esci\n";

	while (true) {
		cout<<menu<<endl;
		int scelta = 0;
		if (!(cin>>scelta)) {
			cout<<"Esco: input in stato d'errore o finito"<<endl;
			return 1;
		}

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1: {
			unsigned int N;
			cout<<"Inserisci numero di codici: "
			    <<endl;
			cin>>N;
			reinizializza(e, N, false);
		}
			break;
		case 2:
			stampa_etichetta(e, false);
			break;
		case 3:
			if (!salva_etichetta(e))
				cout<<"Salvataggio fallito"<<endl;
			break;
		case 4:
			if (!carica_etichetta(e))
				cout<<"Caricamento fallito"<<endl;
			break;
		case 5: {
			unsigned int N;
			cout<<"Inserisci numero di codici: "
			    <<endl;
			cin>>N;
			reinizializza(e, N, true);
		}
			break;
		case 6:
			stampa_etichetta(e, true);
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}
	return 1;
}