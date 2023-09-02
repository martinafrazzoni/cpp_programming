#include <iostream>
using namespace std; 

bool inserisci_in_fondo(int a[ ], int&lungh_a, int&quanti_elem, int&fine, int&inizio){

    if(quanti_elem == lungh_a){
        cout << "Non si può fare l'inserimento" << endl; 
        return false; // non si può fare l'inserimento
    }
        
    else{
            // chiedo all'utente il valore del nuovo elemento
            int valore = 0; 

            cout << "Inserisci valore che vuoi inserire in coda: "; 
            cin>>valore; 

            fine = (fine+1) % lungh_a; 
            cout << "Fine: " << fine << endl; 
            a[fine] = valore; 
            quanti_elem++; 
    }
    return true; 
} 

bool estrai_dalla_testa(int a [ ], int&lungh_a, int&quanti_elem, int&fine, int&inizio){
    if (quanti_elem == 0){
        cout << "Non si può estrarre, non ci sono elementi! \n"; 
        return false; 
    }
        
    else{
        a[inizio] = 0; 
        inizio = (inizio+1) % lungh_a; 
        quanti_elem--; 
    }
    return true; 
}

bool inserisci_dalla_testa(int a[ ], int&lungh_a, int&quanti_elem, int&inizio){
    int valore = 0; 

    cout << "Inserisci valore che vuoi inserire in testa: "; 
    cin>>valore; 

    if (quanti_elem == lungh_a){
        cout << "Non è possibile effettuare l'inserimento!" << endl; 
        return false; 
    }
    else{
        inizio = (inizio-1) % lungh_a; 
        a[inizio] = valore; 
        quanti_elem++; 
    }
    return true; 
}

bool estrai_in_fondo(int a[ ], int&lungh_a, int&quanti_elem, int&fine){
    if (quanti_elem == 0){
        cout << "Non si può fare l'estrazione!"; 
        return false; 
    }
    else{
        a[fine] = 0; 
        fine = (fine-1) % lungh_a; 
        quanti_elem--; 
    }
    return true; 
}


int main(){

    // implementiamo l'inserimento in coda tramite l'array circolare. 
    // l'array circolare si implementa tramite un array lineare, quindi lo vado a definire. 

    //inizializzo l'array
    int a [] = {0, 0, 3, 6, 2, 1, 4, 2, 7, 6}; 

    // trovo quanto è grande l'array: 
    int lungh_a = sizeof(a) / sizeof(a[0]); 

    // devo trovare il primo elemento occupato. 
    int inizio = 0; 
    int fine = 0;

    for (int i = 0; i < lungh_a; i++){
        if (a[i] != 0){
            inizio = i; 
            break;
        }        
    }

    // trovo l'ultimo elemento occupato
    for (int i = (lungh_a-1); i >= 0; i--){
        if (a[i] != 0){
            fine = i; 
            break;
        }        
    }

    // guardo quanti elementi ci sono nella mia coda
    int quanti_elem = 0; 
    for (int i = inizio; i <= fine; i++){
        quanti_elem++; 
    }


    while (true){
        int scelta; 
        cout << "Inserisci 1 per inserire dal fondo: \n" ; 
        cout << "Inserisci 2 per estrarlo dalla testa: \n"; 
        cout << "Inserisci 3 per inserire dalla testa: \n"; 
        cout << "Inserisci 4 per estrarlo dal fondo: \n "; 
        cin>>scelta; 
        switch (scelta)
        {
        case 1:
            inserisci_in_fondo(a, lungh_a, quanti_elem, fine, inizio); 
            for (int i = 0; i < lungh_a; i++){
                cout << a[i] << " "; 
            }
            cout << endl; 
            break;
        case 2:
            estrai_dalla_testa(a, lungh_a, quanti_elem, fine, inizio); 
            for (int i = 0; i < lungh_a; i++){
                cout << a[i] << " "; 
            }
            cout << endl; 
            break; 
        case 3: 
            inserisci_dalla_testa(a, lungh_a, quanti_elem, inizio); 
            for (int i = 0; i < lungh_a; i++){
                cout << a[i] << " "; 
            }
            cout << endl; 
            break;
        case 4: 
            estrai_in_fondo(a, lungh_a, quanti_elem, fine); 
            for (int i = 0; i < lungh_a; i++){
                cout << a[i] << " "; 
            }
            cout << endl;
        default:
            break;
        }
    }
      
    /*cout << endl; 
    cout << "Inizio: " << "indice - > " << inizio << " Valore - > " << a[inizio] <<  endl; 
    cout << "Fine: " << "indice -> " << fine << " Valore - > " <<  a[fine] << endl;*/ 

    return 0; 
}

