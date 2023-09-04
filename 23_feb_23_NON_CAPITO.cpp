#include <iostream>
using namespace std;

void esegui_controllo_vuoto(double controllo [ ], int &n, double &d0, const double k, const double v ){
	//calcoliamo d al primo secondo. 
    double d; 
    controllo[0] = k * v + d0; // differenza di velocità. 
    //cout << "Secondo 1: d = " << d << endl; 
    // calcoliamo la variazione di velocità per  n intervalli di tempo. 
    for (int i = 1; i < n; i++){
		controllo[i] = d = k*v + d; 
        //cout << "secondo " << i << " : d = " << d << endl; 
    }
}

void stampa_controllo(double controllo [ ], int &n){
	for (int i = 1; i < n; i++){
		cout << controllo[i] << " "; 
	}
	cout << endl; 
}


int main()
{
	const double k = 0.5; 
    const double v = 10; 
	int n; 
    double d0; 
	double controllo[n]; 

	const char menu[] =
		"1. Esegui controllo vuoto\n"
		"2. Stampa controllo\n"
		"3. Esegui controllo\n"
		"4. Salva sequenza\n"
		"5. Carica sequenza\n"
		"6. Esegui controllo 2\n"
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
		case 1: 
        {
            do{
                cout << "Inserisci intervallo: \n"; 
                cin>>n;
            }
            while(n<0); 

            do{
                cout << "Inserisci d0: \n"; 
                cin>>d0; // differenza di velocità iniziale. 
            }
            while (d0 > 100); 
            esegui_controllo_vuoto(controllo, n, d0, k, v); 
            break;
        }
		case 2:
		{
			stampa_controllo(controllo, n); 
			break;
		}
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}