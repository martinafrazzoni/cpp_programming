#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// creo la struct con le coppie di posizioni di ogni elemento del codice a barre.
struct elemento
{
    char pos_sx;
    char pos_dx;
};

elemento **crea_etichetta(int &righe, const int &col)
{
    elemento **etichetta; // contiene l'indirizzo dell'etichetta.

    // array di puntatori che mi contiene i puntatori alle righe.
    etichetta = new elemento *[righe];
    for (int i = 0; i < righe; i++)
    {
        etichetta[i] = new elemento[col];
    }
    return etichetta;
}

void dealloca_etichetta(elemento **&etichetta, int &righe)
{
    for (int i = 0; i < righe; i++)
    {
        delete[] etichetta[i];
    }
    delete[] etichetta;
}

int inizializza_etichetta(elemento bar_code[], const int &col, elemento **&etichetta, int &righe)
{
    bool inizializzato_correttamente = true;
    int r = 0;
    while (r < righe)
    {
        string c; // leggo l'input dentro una stringa.
        cout << "Inizializza codice a barre: '|' o '.' \n";
        cin >> c;
        int lungh = c.length(); // c.lenght restituisce la lunghezza della stringa. Non posos usare strlen() perhchè quella lì è una funzione che si usa solo con i c.style array.
        if (lungh != col * 2)
        {
            cout << "Errore! La stringa inserita non è lunga " << col * 2 << endl;
            inizializzato_correttamente = false;
        }
        else
        {
            // read the stirng into a struct array.
            for (int i = 0; i < col; i++)
            {
                bar_code[i].pos_sx = c[i * 2];
                bar_code[i].pos_dx = c[i * 2 + 1];
            }
            inizializzato_correttamente = true;
            cout << endl;
        }

        // abbiamo inizializzato l'array di struct a contenere . |, ma non sappiamo se la sequenza è corretta. Quindi per ogni elemento devo verificare che ci sia almeno un punto e una barra. Se non è inizializzato correttamente conterrà soltanto barre a sx.

        for (int i = 0; i < col; i++)
        {
            // se il codice a barre contiene lo stesos carattere sia a dx che a sx oppure se contiene qualcosa di diverso da un punto o da una barra a sx e a dx allora non è inizializzato correttamente.

            if (((bar_code[i].pos_dx == '|' && bar_code[i].pos_sx == '|') || (bar_code[i].pos_dx == '.' && bar_code[i].pos_sx == '.')) ||
                ((bar_code[i].pos_dx != '|' && bar_code[i].pos_dx != '.') || (bar_code[i].pos_sx != '|' && bar_code[i].pos_sx != '.')))
            {
                cout << "Il codice a barre non è inizializzato correttamente\n";
                inizializzato_correttamente = false;
                break;
            }
        }

        if (!inizializzato_correttamente)
        {
            for (int i = 0; i < col; i++)
            {
                etichetta[r][i].pos_sx = '|';
                etichetta[r][i].pos_dx = '.';
            }
            cout << "Riga " << r << " della matrice inizializzata con le barre tutte a sinistra!\n";
        }

        if (inizializzato_correttamente)
        {
            for (int i = 0; i < col; i++)
            {
                etichetta[r][i] = bar_code[i];
            }
            cout << "Riga " << r << " della matrice inizializzata correttamente\n";
        }
        r++;
    }
    return 0;
}

void stampa_etichette(elemento **&etichetta, const int &col, int &righe)
{
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << j << " ";
        }
        cout << '\t';
    }
    cout << endl;

    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << etichetta[i][j].pos_sx << etichetta[i][j].pos_dx;
        }
        cout << '\t';
    }
    cout << endl;
}

void salva_etichetta(ofstream &file_etichetta, elemento **&etichetta, const int &col, int &righe)
{
    // scrivo su file anche il numero di righe e di colonne
    file_etichetta.write(reinterpret_cast<char *>(&righe), sizeof(righe));
    file_etichetta.write(reinterpret_cast<const char *>(&col), sizeof(col));

    // scrivo la matrice su file
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < col; j++)
        {
            file_etichetta.write(reinterpret_cast<char *>(&etichetta[i][j]), sizeof(etichetta[i][j]));
        }
    }
}

void carica_etichetta(ifstream &file_etichetta_lett, elemento **&etichetta, const int &col, int &righe)
{
    int temp_col = col;
    dealloca_etichetta(etichetta, righe);

    file_etichetta_lett.read(reinterpret_cast<char *>(&righe), sizeof(righe));
    file_etichetta_lett.read(reinterpret_cast<char *>(&temp_col), sizeof(temp_col));
    // cout << "righe: " << righe << endl;
    // cout << "colonne: " << temp_col << endl;

    etichetta = crea_etichetta(righe, temp_col);

    // leggo il contenuto del file già direttamente dentro gli elementi della matrice.
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < temp_col; j++)
        {
            file_etichetta_lett.read(reinterpret_cast<char *>(&etichetta[i][j]), sizeof(etichetta[i][j]));
        }
    }
    cout << "Matrice caricata correttamente\n";
}

int main()
{
    int righe;
    const int col = 8;
    // creo l'array che mi contiene le posizioni destra e sinistra.
    elemento bar_code[col];
    elemento **etichetta;
    int R = 0; // all'inizio alloco una matrice con 0 righe.
    etichetta = crea_etichetta(R, col);

    const char menu[] =
        "1. Inizializza eitchetta\n"
        "2. Stampa etichetta\n"
        "3. Salva etichetta\n"
        "4. Carica etichetta\n"
        "5. Inizializza etichetta2\n"
        "6. Stampa etichetta2\n"
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
            // dealloca_etichetta(etichetta, righe);
            cout << "Inserisci il numero di codici a barre: \n";
            cin >> righe;

            if (righe != R && righe > 0)
            {
                dealloca_etichetta(etichetta, R);
                etichetta = crea_etichetta(righe, col);
                inizializza_etichetta(bar_code, col, etichetta, righe);
            }
            break;
        }
        case 2:
        {
            stampa_etichette(etichetta, col, righe);
            break;
        }
        case 3:
        {
            // devo creare il file di testo dove andare a scrivere la matrice.
            ofstream file_etichetta;
            file_etichetta.open("etichetta.dat");
            if (!file_etichetta)
            {
                cerr << "Errore! impossibile aprire il file in scrittura\n";
                return 1;
            }
            salva_etichetta(file_etichetta, etichetta, col, righe);
            file_etichetta.close();
            break;
        }
        case 4:
        {
            ifstream file_etichetta_lett;
            file_etichetta_lett.open("etichetta.dat");
            if (!file_etichetta_lett)
            {
                cerr << "Errore! impossibile aprire il file in scrittura\n";
                return 1;
            }
            carica_etichetta(file_etichetta_lett, etichetta, col, righe);
            file_etichetta_lett.close();
            break;
        }

        case 5:
            break;
        case 6:
            break;
        case 7:
            return 0;
        default:
            cout << "Scelta errata" << endl;
        }
    }

    return 1;
}