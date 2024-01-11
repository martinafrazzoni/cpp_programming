#include <iostream>
#include <fstream>
using namespace std;

// per specificare il tipo dell'operaione mi serve un enum
enum operazioni_t
{
    addizione = '+',
    sottrazione = '-'
};

struct elemento_t
{
    operazioni_t tipo_operazione; // + o -
    int valore;                   // valore da sottrarre o sommare.
};

struct coda_t
{
    elemento_t *coda_operazioni; // puntatore che sta puntando alla zona di memoria dove inizia l'array di struct.
    int capacita_coda;           // quanti elementi può contenere al massimo la mia coda.
    int fondo = 0;
    int testa = 0;
    int dimensioni_coda; // dimensioni effettive della coda;
};

void crea_coda(coda_t &coda)
{
    coda.capacita_coda = 0;                                    // all'inizio la coda ha capacità pari a zero. non contiene nessun elemento.
    coda.coda_operazioni = new elemento_t[coda.capacita_coda]; // ho allocato un array di dimensioni nulle.
}

bool inizializza_coda(coda_t &coda, int &N)
{
    if (N < 0)
    {
        cout << "La capacità della coda non è valida!\n";
        return false;
    }

    // cout << "[inizializza_coda] Capacità coda iniziale: " << coda.capacita_coda << endl;
    if (/*N != coda.capacita_coda*/ true)
    { // se N è diverso da zero, dealloco la coda iniziale e ne alloco un'altra con le dimensioni di N.
        delete[] coda.coda_operazioni;
        coda.fondo = 0;
        coda.coda_operazioni = new elemento_t[N];
        coda.capacita_coda = N; // se l'utente mi inserisce 3 come valore di N, vuol dire che la mia coda potrà contenere al massimo 3 elementi e non di più.
        coda.dimensioni_coda = 0;
    }
    // cout << "[inizializza_coda] Capacità coda finale: " << coda.capacita_coda << endl;
    return true;
}

bool accoda_operazioni(coda_t &coda, char &c, int &val)
{
    // controllo di non essere arrivata alla fine della coda
    // cout << "[accoda_operazioni] Testa prima di accodare: " << coda.testa << endl; // stampa "0"
    // cout << "[accoda_operazioni] Fondo prima di accodare: " << coda.fondo << endl;
    // cout << endl;
    if (coda.dimensioni_coda == coda.capacita_coda)
    {
        cout << "La coda è piena!\n";
        return false;
    }
    // devo assegnare c e val ai campi tipo operazione e valore, di posto 0 nell'array e poi man mano incrementare l'indice.
    coda.coda_operazioni[coda.fondo].tipo_operazione = static_cast<operazioni_t>(c);
    coda.coda_operazioni[coda.fondo].valore = val;
    coda.fondo++;
    coda.dimensioni_coda = coda.fondo - coda.testa;
    // cout << "[accoda_operazioni] Testa dopo accodamento: " << coda.testa << endl; // stampa "0"
    // cout << "[accoda_operazioni] Fondo dopo accodamento: " << coda.fondo << endl;
    // cout << endl;
    // cout << "Le dimensioni della coda sono pari a: " << coda.dimensioni_coda << endl;
    // cout << "La capacità della coda è pari a: " << coda.capacita_coda << endl;
    return true;
}

void stampa_operazioni(coda_t &coda)
{
    for (int i = coda.testa; i < coda.fondo; i++)
    {
        cout << "(" << static_cast<char>(coda.coda_operazioni[i].tipo_operazione) << " " << coda.coda_operazioni[i].valore << ") ";
    }
    cout << endl;
}

bool salva_operazioni(ofstream &scrivi_operazioni, coda_t &coda)
{
    if (!scrivi_operazioni)
    {
        cerr << "Errore durante la scrittura!\n";
        return false;
    }
    scrivi_operazioni << coda.fondo << endl;
    scrivi_operazioni << coda.testa << endl;
    for (int i = coda.testa; i < coda.fondo; i++)
    {
        scrivi_operazioni << static_cast<char>(coda.coda_operazioni[i].tipo_operazione) << " " << coda.coda_operazioni[i].valore << " ";
    }
    scrivi_operazioni << endl;
    return true;
}

bool carica_operazioni(ifstream &leggi_operazioni, coda_t &coda)
{
    if (!leggi_operazioni)
    {
        cerr << "Errore durante la lettura!\n";
        return false;
    }
    delete[] coda.coda_operazioni;
    char c;
    leggi_operazioni >> coda.capacita_coda;
    // cout << "[carica_operazioni] Dimensioni coda: " << coda.capacita_coda << endl;
    //  adesso devo allocare l'array con le dimensioni lette dal file.
    coda.coda_operazioni = new elemento_t[coda.capacita_coda];
    // le dimensioni della coda coincidono anche con il fondo della coda.
    coda.fondo = coda.capacita_coda;
    leggi_operazioni >> coda.testa;
    // cout << "[carica_operazioni] Testa: " << coda.testa << endl;
    // cout << "[carica_operazioni] Fondo: " << coda.fondo << endl;

    for (int i = coda.testa; i < coda.fondo; i++)
    {
        leggi_operazioni >> c;
        coda.coda_operazioni[i].tipo_operazione = static_cast<operazioni_t>(c);
        leggi_operazioni >> coda.coda_operazioni[i].valore;
    }
    return true;
}

bool elimina_operazione(coda_t &coda)
{
    // cout << "[elimina_operazione] Dimensioni coda prima di eliminare operazione: " << coda.dimensioni_coda << endl;
    //  devo controllare che la codda non sia vuota.
    if (coda.fondo == coda.testa)
    {
        cout << "La pila è vuota!\n";
        return false;
    }
    // se la coda non è vuota, devo eliminare l'operazione nell'elemento di indice testa, non l'elemento in sé.
    coda.coda_operazioni[coda.testa].tipo_operazione = static_cast<operazioni_t>(0);
    coda.coda_operazioni[coda.testa].valore = 0;
    // a questo punto le dimensioni della coda sono diminuite di uno.
    coda.dimensioni_coda--;
    // devo incrementare l'indice della testa.
    coda.testa++;
    // cout << "[elimina_operazione] Dimensioni coda dopo eliminazione operazione: " << coda.dimensioni_coda << endl;
    return true;
}

int main()
{
    coda_t coda;
    int N;

    crea_coda(coda);
    const char menu[] =
        "1. Inizializza coda\n"
        "2. Accoda operazione\n"
        "3. Stampa operazioni\n"
        "4. Salva operazioni\n"
        "5. Carica operazioni\n"
        "6. Elimina operazione\n"
        "7. Unisci operazioni\n"
        "8. Esci\n";

    while (true)
    {
        cout << menu << endl;
        int scelta = 0;
        if (!(cin >> scelta))
        {
            cout << "Esco: input in stato d'errore o finito" << endl;
            return 1;
        }

        cout << endl; // per il corretto funzionamento del tester

        switch (scelta)
        {
        case 1:
        {
            cout << "Inserisci la capacità della coda: ";
            cin >> N;
            if (inizializza_coda(coda, N))
            {
                cout << "La coda è stata inizializzata con successo! \n";
            }
            break;
        }
        case 2:
        {
            char c;
            int val;
            do
            {
                cout << "Inserisci il tipo dell'operazione '+' o '-':  ";
                cin >> c;
            } while (c != '+' && c != '-');

            cout << "Inserisci il valore: ";
            cin >> val;
            if (accoda_operazioni(coda, c, val))
            {
                cout << "Accodamento effettuato con successo!\n";
            }
            break;
        }
        case 3:
        {
            stampa_operazioni(coda);
            break;
        }
        case 4:
        {
            ofstream scrivi_operazioni;
            scrivi_operazioni.open("operazioni.txt");
            if (!scrivi_operazioni)
            {
                cerr << "Errore! Impossibile aprire il file in scrittura!\n";
                return 1;
            }
            if (salva_operazioni(scrivi_operazioni, coda))
            {
                cout << "Salvataggio su file eseguito con successo!\n";
            }
            scrivi_operazioni.close();
            break;
        }
        case 5:
        {
            ifstream leggi_operazioni;
            leggi_operazioni.open("operazioni.txt");
            if (!leggi_operazioni)
            {
                cerr << "Errore! Impossibile aprire il file in lettura!";
                return 2;
            }
            if (carica_operazioni(leggi_operazioni, coda))
            {
                cout << "Caricamento da file eseguito con successo!\n";
            }
            leggi_operazioni.close();
            break;
        }
        case 6:
        {
            elimina_operazione(coda);
            break;
        }
        case 7:
            break;
        case 8:
            return 0;
        default:
            cout << "Scelta errata" << endl;
        }
    }

    return 1;
}