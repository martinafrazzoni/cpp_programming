#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

enum giorni_t
{
    lunedi,
    martedi,
    mercoledi,
    giovedi,
    venerdi,
    sabato,
    domenica
};
giorni_t giorno;

const int lung_nome = 11;
const int giorni_sett = 7;

struct lavoratore_t
{
    char nome_lavoratore[lung_nome];
    bool turni[giorni_sett + 1];
};

void crea_elenco(lavoratore_t *&elenco, int &N)
{
    N = 0;
    elenco = new lavoratore_t[N];
}

bool inizializza_elenco(lavoratore_t *&elenco, int &num_lav)
{

    if (num_lav < 0)
    {
        cout << "Numero lavoratori non valido!\n";
        return false;
    }

    if (true)
    {
        // voglio deallocare l'array di struct di dimensione N
        delete[] elenco;
        // alloco un nuovo array di struct di dimensione num_lav.
        elenco = new lavoratore_t[num_lav];
    }

    int conta = 0; // contatore che mi tiene traccia man mano di tutti i lavoratori che inserisco.
    for (int i = 0; i < num_lav; i++)
    {
        cout << "Inserisci nome lavoratore: \n";
        cin >> elenco[i].nome_lavoratore;
        conta++;
        // dobbiamo controllare che il nome di ogni lavoratore non sia doppio. per ogni lavoratore controllo i successivi che non siano uguali, ho un for con due indici.
        for (int j = 0; j < conta - 1; j++)
        {
            for (int y = j + 1; y < conta; y++)
            {
                if (strcmp(elenco[j].nome_lavoratore, elenco[y].nome_lavoratore) == 0)
                {
                    cout << "Non si possono inizializzare due lavoratori con lo stesso nome!\n";
                    return false;
                }
            }
        }
    }

    // metto l'array di bool a false, che vuol dire che sono tutti in riposo.
    for (int i = 0; i < num_lav; i++)
    {
        for (int j = 0; j < giorni_sett; j++)
        {
            elenco[i].turni[j] = false; // inizializzo tutti i turni a false, che vuol dire che sono tutti in riposo.
        }
    }
    return true;
}

void stampa_turni(lavoratore_t *&elenco, int &num_lav)
{
    cout << "LMMGVSD \n";
    for (int i = 0; i < num_lav; i++)
    {
        for (int j = 0; j < giorni_sett; j++)
        {
            if (elenco[i].turni[j] == false)
            {
                cout << "-";
            }
            else
            {
                cout << "*";
            }
        }
        cout << "\t" << elenco[i].nome_lavoratore;
        cout << endl;
    }
    cout << endl;
}

int trova_indice(lavoratore_t *&elenco, char trova_lavoratore[], int &num_lav)
{
    // scorro tutto l'array dei nomi dei lavoratori se ne trovo uno che combacia con la stringa trova_lavoratore, allora ritorna la sua posizione.
    for (int i = 0; i < num_lav; i++)
    {
        if (strcmp(elenco[i].nome_lavoratore, trova_lavoratore) == 0)
        {
            return i;
        }
    }
    return -1;
}

void aggiorna_turni(lavoratore_t *&elenco, char agg_turni[], int &index)
{
    // all'inizio i turni devono essere tutti a false
    for (int i = 0; i < giorni_sett; i++)
    {
        elenco[index].turni[i] = false;
    }
    // trovo il lavoratore di indice 'index', poi nell'array dei suoi turni lo metto a true se è di turno, oppure false se è a riposo.
    for (int i = 0; i < giorni_sett; i++)
    {
        if (agg_turni[i] == '*')
        {
            elenco[index].turni[i] = true;
        }
        else
        {
            elenco[index].turni[i] = false;
        }
    }
}

void salva_turni(ofstream &file_turni, lavoratore_t *&elenco, int &num_lav)
{
    file_turni << "LMMGVSD \n";
    file_turni << num_lav << endl;
    for (int i = 0; i < num_lav; i++)
    {
        for (int j = 0; j < giorni_sett; j++)
        {
            if (elenco[i].turni[j] == false)
            {
                file_turni << "-";
            }
            else
            {
                file_turni << "*";
            }
        }
        file_turni << "\t" << elenco[i].nome_lavoratore;
        file_turni << endl;
    }
    file_turni << endl;
}

void carica_turni(ifstream &leggi_turni, lavoratore_t *&elenco, int &num_lav)
{
    string giorni_settimana;
    leggi_turni >> giorni_settimana;

    leggi_turni >> num_lav;
    char c;

    delete[] elenco;
    elenco = new lavoratore_t[num_lav];

    for (int i = 0; i < num_lav; i++)
    {
        for (int j = 0; j < giorni_sett; j++)
        {
            leggi_turni >> c;
            c == '-' ? elenco[i].turni[j] = false : elenco[i].turni[j] = true;
        }
        leggi_turni >> elenco[i].nome_lavoratore;
    }
}

int main()
{

    int index;

    // alloco un array di struct di tipo lavoratore di dimensione num_lavoratori.
    int N;
    int num_lav;
    lavoratore_t *elenco;
    crea_elenco(elenco, N);

    char trova_lavoratore[lung_nome];
    char agg_turni[giorni_sett + 1];

    const char menu[] =
        "1. Inizializza elenco\n"
        "2. Stampa turni\n"
        "3. Trova indice\n"
        "4. Aggiorna turni\n"
        "5. Salva turni\n"
        "6. Carica turni\n"
        "7. Minimizza turni\n"
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

            cout << "Inserisci numero lavoratori: \n";
            cin >> num_lav;
            if (!inizializza_elenco(elenco, num_lav))
            {
                return 0;
            }
            break;
        }
        case 2:
        {
            stampa_turni(elenco, num_lav);
            break;
        }
        case 3:
        {
            cout << "Controlla se lavoratore è presente: \n";
            cin >> trova_lavoratore;
            index = trova_indice(elenco, trova_lavoratore, num_lav);
            cout << endl;
            cout << index << endl;
            break;
        }
        case 4:
        {
            // chiedo all'utente di inserire il nome del lavoratore di cui vuole aggiornare i turni.
            cout << "Inserisci il nome del lavoratore di cui vuoi aggiornare i turni: \n";
            cin >> trova_lavoratore;
            index = trova_indice(elenco, trova_lavoratore, num_lav);
            if (index == -1)
            {
                cout << "Indice non valido!\n";
                break;
            }
            // prendo in input i turni dei lavoratori aggiornati e li passo alla funzione aggiorna turni.
            bool input_valido;
            do
            {
                input_valido = true;
                cout << "Inserisci i turni aggiornati del lavoratore: \n";
                int i;
                for (i = 0; i < giorni_sett; i++)
                {
                    cin >> agg_turni[i];
                    if (agg_turni[i] != '*' && agg_turni[i] != '-')
                    {
                        input_valido = false;
                    }
                }
                agg_turni[i] = '\0';
            } while (!input_valido);
            aggiorna_turni(elenco, agg_turni, index);
            break;
        }
        case 5:
        {
            // devo scrivere su un file di testo. ù
            ofstream file_turni;
            file_turni.open("turni.txt");
            if (!file_turni)
            {
                cerr << "Errore! Impossibile effettuare la scrittura su file! \n";
                return 1;
            }
            salva_turni(file_turni, elenco, num_lav);
            cout << "Turni salvati con successo!\n";
            file_turni.close();
            break;
        }
        case 6:
        {
            ifstream leggi_turni;
            leggi_turni.open("turni.txt");
            if (!leggi_turni)
            {
                cerr << "Errore! Impossibile aprire il file in lettura!";
                return 1;
            }
            carica_turni(leggi_turni, elenco, num_lav);
            leggi_turni.close();
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