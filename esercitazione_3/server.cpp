#include <iostream>
using namespace std;

int main()
{
    const int indice_server_1 = 1;                                                   /*stampa 1 se si sceglie il primo server*/
    const int indice_server_2 = 2;                                                   /*stampa 2 se si sceglie il secondo server*/
    const int tempo_veloce_server1 = 3600;                                           /*per quanti secondi scarica a 200 kb/s (cioè la prima ora)*/
    const int velocità_max_server_1 = 200;                                           /* velocità massima del server 1 */
    const int velocità_min_server_1 = 50;                                            /*velocità minima server 1*/
    const int velocità_server_2 = 100;                                               /*velocità costante server 2*/
    const int download_server_1_1h = (velocità_max_server_1 * tempo_veloce_server1); /*quanti kb di film ha scaricato in 1h.*/
    int peso_film;                                                                   /*peso film in KB*/
    cout << "quanto è pesante il file in KB/s? \n";                                  /*chiedo in input la grandezza del film*/
    cin >> peso_film;

    int tempo_minimo, indice_server_da_usare; /*definisco le mie due variabili da usare: il tempo minimo che impiega il 1 server per scaricare il film, e quale dei due server bisona usare*/

    if (download_server_1_1h >= peso_film)
    {
        tempo_minimo = peso_film / velocità_max_server_1;
        indice_server_da_usare = indice_server_1;
    }
    else
    {
        // calcolo il tempo per il primo server
        int lungh_residua = (peso_film / download_server_1_1h);
        /*assegno il tempo del server 1 al tempo minimo, così non definisco un'altra variabile tempo_server_1*/
        tempo_minimo = (lungh_residua / velocità_min_server_1) + tempo_veloce_server1; /*quanto ci metto per scaricare la parte residua a 50kb/s? e lo sommo ai 60 minuti iniziali. */
    }

    /*devo sapere quanto ci mette il server 2 per scaricare tutto il film*/
    int tempo_server_2 = (peso_film / velocità_server_2);
    if
    {
        tempo_minimo < tempo_server_2
                           indice_server_da_usare = indice_server_1;
        else
        {
        }
    }

    // int peso_film;
    int v1s = 200;
    int v2s = 100;

    cout << "Quanti KB trasferisce il primo server in 1h? \n";
    int v1s_1ora = (v1s * 3600);

    cout << "il primo server trasferisce " << v1s_1ora << " kb/s " << endl;
    if (v1s_1ora > peso_film)
    {
        cout << "Utilizza il primo server!!" << endl;
        cout << "Adesso calcola quanto tempo ci vuole per scaricare il film" << endl;
        cout << (peso_film / v1s) << " sec "
             << "che equivalgono a " << ((peso_film / v1s) / 60) << " min " << endl;
    }
    else
    {
        int lungh_residua = (peso_film - v1s_1ora);
        cout << "quanto ci metto per scaricare la parte residua a 50 kb/s? \n";
        cout << (lungh_residua / 50) << " sec "
             << "che equivalgono a " << ((lungh_residua / 50) / 60) << " min " << endl;
        int t_lungh_residua = ((lungh_residua / 50) / 60) + 60;
        cout << "calcolo il tempo  che ci mette il secondo server: " << ((peso_film / v2s) / 60) << " sec " << endl;
        cout << "il server da utilizzare è il secondo che ci mette: " << (peso_film / v2s / 60) << " sec " << endl;
    }
    return 0;
}