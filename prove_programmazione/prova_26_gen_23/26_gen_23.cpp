#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct coord
{
    int x;
    int y;
};

char **crea_griglia(const int &righe, const int &colonne)
{
    char **griglia; // contiene l'indirizzo in memoria della griglia.
    // array di puntatori che mi contiene i puntatori alle righe.

    griglia = new char *[righe];
    for (int i = 0; i < righe; i++)
    {
        griglia[i] = new char[colonne];
    }
    return griglia;
}

void delete_griglia(char **&griglia, const int &righe, const int &colonne)
{
    for (int i = 0; i < righe; i++)
    {
        delete[] griglia[i];
    }
    delete[] griglia;
}

void alloca_array(char *&sequenza_app, int &n)
{
    sequenza_app = new char[n + 1];
    if (sequenza_app != nullptr)
    {
        cout << "Memoria allocata correttamente!" << endl;
    }
}

void dealloca_array(char *&sequenza_app)
{
    delete[] sequenza_app;
    sequenza_app = nullptr;
}

void griglia_vuota(char **&griglia, const int &righe, const int &colonne)
{
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            griglia[i][j] = ' ';
        }
    }
}

bool rialloca_sequenza(char *&sequenza_app, char *&sequenza, int &n_app, int &n, const int &colonne)
{
    cout << "Inserisci il numero di spostamenti: \n";
    cin >> n_app;

    if (n_app > 0)
    {
        dealloca_array(sequenza_app); // dealloco la sequenza_app
        //  array di char che mi contiene la sequenza di caratteri letta da stdin.
        alloca_array(sequenza_app, n_app);
    }
    else
    {
        cout << "Errore: numero di spostamenti non valido" << endl;
        return false;
    }
    return true;
}

bool leggi_verifica_sequenza(char *&sequenza_app, char *&sequenza, int &n, int &n_app, bool &inzializzata_correttamente)
{
    int i;
    cout << "n vale: " << n_app << endl;
    for (i = 0; i < n_app; i++)
    {

        cout << "Inserisci carattere per inizializzare la sequenza:\n";
        cin >> sequenza_app[i];
    }
    sequenza_app[i] = '\0';

    // verifico che la sequenza sia valida
    for (int i = 0; i < n_app; i++)
    {
        if (sequenza_app[i] != '<' && sequenza_app[i] != '>' && sequenza_app[i] != '^' && sequenza_app[i] != 'v')
        {
            cout << "Errore: carattere non valido" << endl;
            inzializzata_correttamente = false;
            return false;
        }
    }
    cout << endl;
    inzializzata_correttamente = true;
    return true;
}

bool inizializza_sequenza(char *&sequenza_app, char *&sequenza, int &n_app, int &n, const int &colonne, bool &inzializzata_correttamente)
{
    if (rialloca_sequenza(sequenza_app, sequenza, n_app, n, colonne) && leggi_verifica_sequenza(sequenza_app, sequenza, n, n_app, inzializzata_correttamente))
    {
        if (inzializzata_correttamente)
        {
            int i; // indice per il for
            n = n_app;
            alloca_array(sequenza, n);
            for (i = 0; i < n; i++)
            {
                // devo copiare i caratteri da dentro sequenza_app dentro sequenza
                sequenza[i] = sequenza_app[i];
            }
            sequenza[i] = '\0';
        }
        return true;
    }
    return false;
}

void stampa_sequenza(char *&sequenza, int &n)
{
    cout << "Ecco la sequenza di spostamenti che deve fare il robot: \n";
    for (int i = 0; i < n; i++)
    {
        cout << sequenza[i] << " ";
    }
    cout << endl;
}

void salva_sequenza(ofstream &file_sequenza, char *&sequenza, int &n)
{
    file_sequenza << n << endl;
    for (int i = 0; i < n; i++)
    {
        file_sequenza << sequenza[i] << " ";
    }
}

void carica_sequenza(ifstream &file_sequenza_lett, char *&sequenza, int &n)
{
    file_sequenza_lett >> n;
    if (sequenza != nullptr)
    {
        dealloca_array(sequenza);
    }
    alloca_array(sequenza, n);
    for (int i = 0; i < n; i++)
    {
        file_sequenza_lett >> sequenza[i];
    }
}

void stampa_sequenza_2(char *&sequenza, char **&griglia, const int &righe, const int &colonne, int &n, coord *&coordinata)
{
    // l'avevo allocato all'inizio del main ma siccome mi serve solo dentro questa funzione, lo alloco qui. ---- così gestisco anche meglio la memoria dinamica.
    coordinata = new coord[n];

    int r = 0;
    int col = 0;
    char direz;
    int j = 0;

    char pos = griglia[r][col]; // il robot si trova in posizione (0, 0);

    // leggo il primo carattere dall'array sequenza
    for (int i = 0; i < n; i++)
    {
        direz = sequenza[i];

        switch (direz)
        {
        case '<':
        {

            if (col < 0)
            {
                cout << "fuori" << endl;
                break;
            }
            pos = griglia[r][col -= 1];
            cout << "Pos: " << pos << endl;
            //  cout << "Le coordinate della nuova posizione sono (" << r << "," << col << ")" << endl;

            coordinata[j].x = r;
            coordinata[j].y = col;
            j++; // incremento l'array dove vado a mettere le coordinate.
            break;
        }
        case '>':
        {
            if (col >= colonne)
            {
                cout << "Fuori" << endl;
                break;
            }
            pos = griglia[r][col += 1];
            cout << "Pos: " << pos << endl;
            //  cout << "Le coordinate della nuova posizione sono (" << r << "," << col << ")" << endl;
            coordinata[j].x = r;
            coordinata[j].y = col;
            j++;
            break;
        }
        case '^':
        {
            if (r <= 0)
            {
                cout << "fuori" << endl;
                break;
            }
            pos = griglia[r -= 1][col];
            cout << "Pos: " << pos << endl;
            //  cout << "Le coordinate della nuova posizione sono (" << r << "," << col << ")" << endl;
            coordinata[j].x = r;
            coordinata[j].y = col;
            j++;
            break;
        }
        case 'v':
        {
            if (r > righe - 1)
            {
                cout << "fuori" << endl;
                break;
            }
            pos = griglia[r += 1][col];
            cout << "Pos: " << pos << endl;
            //  cout << "Le coordinate della nuova posizione sono (" << r << "," << col << ")" << endl;
            coordinata[j].x = r;
            coordinata[j].y = col;
            j++;
            break;
        }
        default:
        {
            cout << "errore" << endl;
            break;
        }
        }
    }
}

void stampa_traccia(coord *&coordinata, int &n, char **&griglia, const int &righe, const int &colonne, char *&sequenza)
{
    if (true)
    {
        stampa_sequenza_2(sequenza, griglia, righe, colonne, n, coordinata);
    }
    // leggo array di struct con le coordinate, e le assegno alla mia griglia.
    int r = 0, c = 0;
    griglia[0][0] = '*';
    for (int i = 0; i < n; i++)
    {
        r = coordinata[i].x;
        c = coordinata[i].y;
        griglia[r][c] = '*';
    }

    // proviamo a stampare la griglia
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            if (griglia[i][j] != '*')
            {
                griglia[i][j] = '-';
            }
            cout << griglia[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    const int righe = 2;
    const int colonne = 3;

    char **griglia = crea_griglia(righe, colonne);

    griglia_vuota(griglia, righe, colonne);

    int n;
    int n_app;
    char *sequenza;
    char *sequenza_app;
    bool inzializzata_correttamente = false;

    coord *coordinata; // creo un array di coordinate di lunghezza n, le coordinate sono uguali al numero di spostamenti.

    const char menu[] =
        "1. Inizializza sequenza\n"
        "2. Stampa sequenza\n"
        "3. Salva sequenza\n"
        "4. Carica sequenza\n"
        "5. Stampa sequenza 2\n"
        "6. Stampa traccia\n"
        "7. Esci\n";

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
            if (inizializza_sequenza(sequenza_app, sequenza, n_app, n, colonne, inzializzata_correttamente))
            {
                cout << "Sequenza inizializzata correttamente" << endl;
            }
            break;
        }
        case 2:
        {
            stampa_sequenza(sequenza, n);
            break;
        }

        case 3:
        {
            ofstream file_sequenza;
            file_sequenza.open("file_sequenza.txt");
            if (!file_sequenza)
            {
                cerr << "Errore! Impossibile aprire il file in scrittura!\n";
                break;
            }
            salva_sequenza(file_sequenza, sequenza, n);
            file_sequenza.close();
            break;
        }
        case 4:
        {
            cout << "Carico la sequenza dal file" << endl;
            ifstream file_sequenza_lett;
            file_sequenza_lett.open("file_sequenza.txt");
            if (!file_sequenza_lett)
            {
                cerr << "Errore! Impossibile aprire il file in lettura!\n";
                break;
            }
            carica_sequenza(file_sequenza_lett, sequenza, n);
            file_sequenza_lett.close();
            break;
        }
        case 5:
        {
            stampa_sequenza_2(sequenza, griglia, righe, colonne, n, coordinata);
            cout << "Ecco stampata la sequenza degli spostamenti e le nuove coordinate: \n";

            // stampo la sequenza
            for (int i = 0; i < n; i++)
            {
                cout << sequenza[i] << " " /*"\t\t"*/;
            }
            cout << endl;
            // stampo l'array di coordinate
            for (int i = 0; i < n; i++)
            {
                // cout << "(" << coordinata[i].x << " , " << coordinata[i].y << "); "
                //     << "\t";
                cout << "(" << coordinata[i].x << " " << coordinata[i].y << ") ";
            }
            cout << endl;
            break;
        }

        case 6:
        {
            stampa_traccia(coordinata, n, griglia, righe, colonne, sequenza);
            break;
        }

        case 7:
        {
            delete_griglia(griglia, righe, colonne);
            dealloca_array(sequenza);
            dealloca_array(sequenza_app);
            delete[] coordinata;
            return 0;
        }
        default:
            cout << "Scelta errata" << endl;
        }
    }

    return 1;
}