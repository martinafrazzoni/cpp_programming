#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

/*Le matrici, ovvero gli array bidimensionali, sono accessibili attraverso dei puntatori, e possiamo avere una funzione che ritorna un puntatore all'array bidimensionale.

la sintassi char** dichiara un puntatore ad un altro puntatore che punta ad un valore di tipo char. */

// ritorna un puntatore ad una matrice, che ha num_sez colonne, e num_nastri righe. La matrice viene allocata dinamicamente e inizializzata.
char **alloca_matrice(int &num_sez, const int num_nastri)
{ // la funzione ritorna una matrice dinamica di char.
    // inizializzo a zero il numero di sezioni di ogni nastro.

    // un puntatore ad un puntatore che punta a un char è utilizzato per memorizzare il puntatore alla nostra matrice dinamica
    char **nastri; // contiene l'indirizzo in memoria della nostra matrice.

    nastri = new char *[num_nastri]; // uso la new per allocare spazio per memorizzare un array di puntatori a carattere di lunghezza num_nastri. ogni elemento di questo array, punta ad una delle num_nastri righe della matrice. Array di puntatori alle righe della matrice.

    // dobbiamo allocare spazio per ogni riga di dati della matrice. per ogni puntatore a char che abbiamo dentro l'array di puntatori, abbiamo un puntatore ad un array di char, che ha lunghezza num_sez. Per ogni riga, io devo allocare un array di char di dimensione num_sez.
    for (int i = 0; i < num_nastri; i++)
    {
        nastri[i] = new char[num_sez];
    }
    return nastri;
}

void delete_matrice(char **&nastri_appoggio, const int num_nastri)
{
    for (int i = 0; i < num_nastri; i++)
    {
        delete[] nastri_appoggio[i];
    }
    delete[] nastri_appoggio;
}

// funzione che alloca spazio per i nastri nuovi.
bool rialloca_matrice(char **&nastri, char **&nastri_appoggio, int &N, int &num_sez_app, const int num_nastri)
{
    // se il numero di sezioni è minore di zero allora non posso inizializzare i nastri.
    if (N <= 0)
    {
        cout << "Il numero di sezioni non è valido!\n";
        return false;
    }
    // se invece il numero di sezioni è valido, ad esempio 7, allora posso inizializzare i nastri. allora dealloco i nastri esistenti con dimensione 0 e gli rialloco con le nuove dimensioni.
    delete_matrice(nastri_appoggio, num_nastri);

    // inizializzo il numero di sezioni.
    num_sez_app = N;
    /*cout << "[rialloca_matrice]: Num_sez_app: " << num_sez_app << endl;*/
    //  rialloco
    // nastri = alloca_matrice(num_sez, num_nastri);
    nastri_appoggio = alloca_matrice(num_sez_app, num_nastri);
    if (nastri_appoggio != nullptr)
    {
        cout << "matrice appoggio allocata con successo!\n";
    }
    return true;
}

// creo una funzione che verifica che i caratteri inseriti siano corretti.
bool leggi_verifica_caratteri(char **&nastri_appoggio, const int num_nastri, int &num_sez_app)
{
    int r = 0;
    bool inizializzato_correttamente = false;
    while (r < num_nastri)
    {
        cout << "stiamo inizializzando la riga " << r << ": \n";
        string c;
        cout << "Inserisci i caratteri: \n";
        cin >> c;
        int lungh = c.length();
        if (lungh != num_sez_app)
        {
            cout << "Errore! La stringa inserita non è lunga " << num_sez_app << "caratteri." << endl;
            inizializzato_correttamente = false;
            r++;
            continue;
        }
        else
        {
            // read the stirng into a an array of char.
            for (int i = 0; i < num_sez_app; i++)
            {
                nastri_appoggio[r][i] = c[i];
            }
            cout << endl;
            inizializzato_correttamente = true;
        }
        r++;
    }

    if (inizializzato_correttamente)
    {
        // verifico che i caratteri inseriti siano corretti.
        for (int i = 0; i < num_nastri; i++)
        {
            for (int j = 0; j < num_sez_app; j++)
            {
                if (nastri_appoggio[i][j] != '<' && nastri_appoggio[i][j] != '>' && nastri_appoggio[i][j] != '^' && nastri_appoggio[i][j] != 'v')
                {
                    cout << "CArattere inserito non valido!\n";
                    return false;
                }
            }
        }
    }
    return true;
}

bool inizializza_nastri(char **&nastri, int &num_sez, const int num_nastri, char **&nastri_appoggio, int &N, int &num_sez_app)
{
    /*cout << "[inizializza_nastri PRIMA]: num_nastri: " << num_nastri << " num_sez_app: " << num_sez_app << endl;*/
    if (rialloca_matrice(nastri, nastri_appoggio, N, num_sez_app, num_nastri) && leggi_verifica_caratteri(nastri_appoggio, num_nastri, num_sez_app))
    {
        // se la matrice di appoggio è stata iniazilizzata correttamente, posso riallocarla con le dimensioni nuove e copiarci dentro i valori corretti.

        num_sez = num_sez_app;
        nastri = alloca_matrice(num_sez, num_nastri);
        for (int i = 0; i < num_nastri; i++)
        {
            for (int j = 0; j < num_sez; j++)
            {
                nastri[i][j] = nastri_appoggio[i][j];
            }
        }
        return true;
    }
    return false;
}

void stampa_composizione_nastri(char **&nastri, char **&nastri_appoggio, const int num_nastri, int &num_sez)
{
    /*cout << "[stampa_composizione_nastri]: num_nastri: " << num_nastri << " num_sez: " << num_sez << endl;*/
    cout << "Ecco stampati i nastri: \n";
    for (int i = 0; i < num_nastri; i++)
    {
        for (int j = 0; j < num_sez; j++)
        {
            cout << nastri[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool salva_nastri(char **&nastri, const int num_nastri, int &num_sez)
{
    ofstream file_nastri;
    file_nastri.open("nastri.txt");
    if (!file_nastri)
    {
        cerr << "Errore impossibile aprire il file in scrittura!";
        return false;
    }
    int i, j;
    file_nastri << num_nastri << " " << num_sez << endl;
    for (i = 0; i < num_nastri; i++)
    {
        for (j = 0; j < num_sez; j++)
        {
            file_nastri << nastri[i][j];
        }
        file_nastri << endl;
    }
    file_nastri.close();
    return true;
}

bool carica_controllo(char **&nastri, const int num_nastri, int &num_sez)
{
    ifstream file_nastri_lett;
    file_nastri_lett.open("nastri.txt");
    if (!file_nastri_lett)
    {
        cerr << "Impossibile aprire il file in lettura!";
        return false;
    }

    // dichiaro un'altra variabile èper leggere il numero dei nastri, perchè num_nastri è una costante. Poi leggo le righe e le colonne da file, e poi alloco nastri con le nuove dimensioni.

    int num_nastri_lett = 0;
    file_nastri_lett >> num_nastri_lett >> num_sez;
    cout << "num_nastri_lett: " << num_nastri_lett << " num_sez: " << num_sez << endl;
    nastri = alloca_matrice(num_sez, num_nastri_lett);
    if (nastri == nullptr)
    {
        cout << "Errore nell'allocazione della matrice!\n";
        return false;
    }
    if (num_sez == 0)
    {
        return false;
    }
    while (!file_nastri_lett.eof())
    {
        int i, j;
        for (i = 0; i < num_nastri; i++)
        {
            for (j = 0; j < num_sez; j++)
            {
                file_nastri_lett >> nastri[i][j];
            }
        }
    }
    file_nastri_lett.close();
    return true;
}

bool stampa_nuova_posizione(int n, int s, char **&nastri, const int num_nastri, int &num_sez)
{
    cout << "Il carattere corrispondente alle coordinate inserite è: " << nastri[n][s] << endl;
    char pos = nastri[n][s];
    switch (pos)
    {
    case '<':
    {
        pos = nastri[n][s -= 1];
        if (s < 0)
        {
            cout << "fuori" << endl;
            break;
        }
        // cout << "Le coordinate della nuova posizione sono (" << n << "," << s << ")" << endl;
        cout << n << " " << s << endl;
        break;
    }
    case '>':
    {
        pos = nastri[n][s += 1];
        if (s >= num_sez)
        {
            cout << "Fuori" << endl;
            break;
        }
        // cout << "Le coordinate della nuova posizione sono (" << n << "," << s << ")" << endl;
        cout << n << " " << s << endl;
        break;
    }
    case '^':
    {
        if (nastri[n] == 0)
        {
            cout << "fuori" << endl;
            break;
        }
        pos = nastri[n -= 1][s];
        // cout << "Le coordinate della nuova posizione sono (" << n << "," << s << ")" << endl;
        cout << n << " " << s << endl;
        break;
    }
    case 'v':
    {
        if (n == 1)
        {
            cout << "fuori" << endl;
            break;
        }
        pos = nastri[n += 1][s];
        // cout << "Le coordinate della nuova posizione sono (" << n << "," << s << ")" << endl;
        cout << n << " " << s << endl;
        break;
    }
    default:
    {
        cout << "errore" << endl;
        break;
    }
    }
    return true;
}

int main()
{
    const char menu[] =
        "1. Inizializza nastri\n"
        "2. Stampa composizione nastri\n"
        "3. Salva sequenza\n"
        "4. Carica sequenza\n"
        "5. Stampa nuova posizione\n"
        "6. Trasporta oggetto\n"
        "7. Esci\n";

    int num_sez = 0;
    int num_sez_app = 0;
    int N = 0;
    const int num_nastri = 2;

    char **nastri;
    char **nastri_appoggio = alloca_matrice(num_sez_app, num_nastri);

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
            cout << "Inserisci il numero di sezioni di ogni nastro: \n";
            cin >> N;
            if (inizializza_nastri(nastri, num_sez, num_nastri, nastri_appoggio, N, num_sez_app))
            {
                cout << "Nastri inizializzati con successo!" << endl;
            }
            else

            {
                cout << "Errore nell'inizializzazione dei nastri!" << endl;
            }
            break;
        }
        case 2:
        {
            stampa_composizione_nastri(nastri, nastri_appoggio, num_nastri, num_sez);
            break;
        }
        case 3:
        {
            if (salva_nastri(nastri, num_nastri, num_sez))
            {
                cout << "Nastri salvati con successo!" << endl;
            }
            break;
        }
        case 4:
        {
            if (carica_controllo(nastri, num_nastri, num_sez))
            {
                cout << "Sequenza caricata con successo!" << endl;
            }
            break;
        }
        case 5:
        {
            // facciamo il controllo sugli indici che siano corretti.
            int n, s;
            do
            {
                cout << "Inserisci indice nastro: \n";
                cin >> n;
                cout << "Inserisci indice sezione: \n";
                cin >> s;
            } while ((n < 0 || n > num_nastri) || (s < 0 || s > num_sez));
            stampa_nuova_posizione(n, s, nastri, num_nastri, num_sez);
            break;
        }
        case 6:
            break;
        case 7:
            delete_matrice(nastri_appoggio, num_nastri);
            delete_matrice(nastri, num_nastri);
            return 0;
        default:
            cout << "Scelta errata" << endl;
        }
    }
    return 1;
}