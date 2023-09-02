#include <iostream>
using namespace std;
int main()
{
    const int indice_server_1 = 1;                                                    /* stampa 1 se si sceglie il primo server*/
    const int indice_server_2 = 2;                                                    /* stampa 2 se si sceglie il secondo server*/
    const int tempo_veloce_server_1 = 3600;                                           /*per quanti secondi scarica a 200kb/s (ovvero la prima ora)*/
    const int velocità_max_server_1 = 200;                                            /*velocità massima del server 1*/
    const int velocità_min_server_1 = 50;                                             /*velocità minima del server 1*/
    const int velocità_server_2 = 100;                                                /*velocità costante del secondo server*/
    const int download_server_1_1h = (velocità_max_server_1 * tempo_veloce_server_1); /*kb download 1h*/
    int peso_film;                                                                    /* peso del film in kb*/
    cout << "quanto è pesante il file in kb? \n";                                     /*chiedo in input la grandezza del film*/
    cin >> peso_film;

    int tempo_minimo, indice_da_usare; /*definisco le mie due variabili da usare: il tempo minimo che impiega il 1° server per scaricare il film e e quale dei due server devo usare*/
    if (download_server_1_1h >= peso_film)
    {
        tempo_minimo = (peso_film / velocità_max_server_1);
        indice_da_usare = indice_server_1;
    }
    else
    {
        // calcolo il tempo per il primo server
        int lungh_residua = (peso_film - download_server_1_1h);
        /* asseegno il tempo del server 1 al tempo minimo, così non definisco un'altra variabile tempo_server_1*/
        tempo_minimo = (lungh_residua / velocità_min_server_1) + tempo_veloce_server_1; /*quanto ci metto per scaricare la parte residua a 50 kb/s* e lo sommo ai 60 minuti iniziali. */
    }
    /*devo sapere quanto ci mette il server 2 per scaricare tutto il film*/
    int tempo_server_2 = (peso_film / velocità_server_2);
    if (tempo_minimo < tempo_server_2) /*se il tempo minimo del server 1 è minore de server 2, allora il server da utilizzare + il 1*/
        indice_da_usare = indice_server_1;
    else 
    {
        tempo_minimo = tempo_server_2; /*se il tempo minimo + il tempo del secondo server utilizzo il secondo*/
        indice_da_usare = indice_server_2;
    }
    cout << "Tempo minimo: " << tempo_minimo / 60 << " min " << tempo_minimo % 60 << " sec "
         << "usando il server " << indice_da_usare << endl;
    return 0;
}
