/*
  Scrivere un programma che stampi i limiti dei tipi char, int, float e double.
  
  Esempio di output:

  int limits:
        dimensioni in byte: 4
        min: -2147483648
        max: 2147483647
        max cifre base 2: 31
        max cifre base 10: 9
        ha segno: 1
        e' intero: 1
        epsilon: 0
        errore arrotondamento: 0

  float limits:
        dimensioni in byte: 4
        min: 1.17549e-38
        max: 3.40282e+38
        max cifre base 2: 24
        max cifre base 10: 6
        ha segno: 1
        e' intero: 0
        epsilon: 1.19209e-07
        errore arrotondamento: 0.5
        esponente minimo in base 2: -125
        esponente minimo in base 10: -37
        esponente massimo in base 2: 128
        esponente massimo in base 10: 38

  double limits:
        dimensioni in bytes: 8
        min: 2.22507e-308
        max: 1.79769e+308
        max cifre base 2: 53
        max cifre base 10: 15
        ha segno: 1
        e' intero: 0
        epsilon: 2.22045e-16
        errore arrotondamento: 0.5
        esponente minimo in base 2: -1021
        esponente minimo in base 10: -307
        esponente massimo in base 2: 1024
        esponente massimo in base 10: 308
  char limits:
        dimensioni in bytes: 1
        min: -128
        max: 127
        max cifre base 2: 7
        max cifre base 10: 2
        ha segno: 1
        e' intero: 1
        epsilon: 
        errore arrotondamento: 
*/


#include <iostream>
#include <limits>
using namespace std; 
int main(){
    cout << "\t limiti interi" << endl;  
        // dimensione du 4 byte
        cout << "la dimensione di un intero in byte è " << sizeof(int) << endl; 

        // valore massimo per il tipo int
        int max_int = numeric_limits<int>::max(); 
        cout << "il valore massimo per il tipo int è: " <<  max_int << endl; 

        // valore minimo per il tiro int
        int min_int = numeric_limits<int>::min(); 
        cout << "il valore minimo per il tipo int è: " << min_int << endl; 

        // numero di cifre in base 2 per gli int. 
        cout <<"il numero massimo di cifre in base 2 è: " << numeric_limits<int>::digits << endl; 

        // numero massimo cdi cifre in base 10 per gli int. 
        cout << "il numero massimo di cifre in base 10 è " << numeric_limits<int>::digits10 << endl; 

        // true (1) se int ammette valori negativi
        cout << "int ammette dei valori negativi: " << numeric_limits<int>::is_signed << endl; 
        
        // truse se nome_tièp è discreto (int, char, bool, enum); 
        cout << "è intero: " <<  numeric_limits<int>::is_integer << endl; 

        // valore minimo tale che 1 + epsylon != 1
        cout << "epsylon: " << numeric_limits<int>::epsilon() << endl; 

        // errore di arrotondamento
        cout << "arrotondamento: " << numeric_limits<int>::round_error() << endl;   

    cout << "\t float limits: " << endl; 

        // dimensione du 4 byte
        cout << "la dimensione di un float in byte è " << sizeof(float) << endl; 

        // valore massimo per il tipo float
        float max_float = numeric_limits<float>::max(); 
        cout << "il valore massimo per il tipo float è: " <<  max_float << endl; 

        // valore minimo per il tiro float
        float min_float = numeric_limits<float>::min(); 
        cout << "il valore minimo per il tipo float è: " << min_float << endl; 

        // numero di cifre in base 2 per i float. 
        cout <<"il numero massimo di cifre in base 2 è: " << numeric_limits<float>::digits << endl; 

        // numero massimo cdi cifre in base 10 per i float. 
        cout << "il numero massimo di cifre in base 10 è " << numeric_limits<float>::digits10 << endl; 

        // true (1) se float ammette valori negativi
        cout << "float ammette dei valori negativi: " << numeric_limits<float>::is_signed << endl; 
        
        // truse se nome_tièp è discreto (int, char, bool, enum); 
        cout << "è intero: " <<  numeric_limits<float>::is_integer << endl; 

        // valore minimo tale che 1 + epsylon != 1
        cout << "epsylon: " << numeric_limits<float>::epsilon() << endl; 

        // errore di arrotondamento
        cout << "arrotondamento: " << numeric_limits<float>::round_error() << endl;  

    cout << "\t double limits: " << endl; 

        // dimensione du 4 byte
        cout << "la dimensione di un double in byte è " << sizeof(double)<< endl; 

        // valore massimo per il tipo double
        double max_double = numeric_limits<double>::max(); 
        cout << "il valore massimo per il tipo float è: " <<  max_double << endl; 

        // valore minimo per il tipo double
        float min_double = numeric_limits<double>::min(); 
        cout << "il valore minimo per il tipo float è: " << min_double << endl; 

        // numero di cifre in base 2 per i double. 
        cout <<"il numero massimo di cifre in base 2 è: " << numeric_limits<double>::digits << endl; 

        // numero massimo cdi cifre in base 10 per i double. 
        cout << "il numero massimo di cifre in base 10 è " << numeric_limits<double>::digits10 << endl; 

        // true (1) se double ammette valori negativi
        cout << "float ammette dei valori negativi: " << numeric_limits<double>::is_signed << endl; 
        
        // truse se nome_tièp è discreto (int, char, bool, enum); 
        cout << "è intero: " <<  numeric_limits<double>::is_integer << endl; 

        // valore minimo tale che 1 + epsylon != 1
        cout << "epsylon: " << numeric_limits<double>::epsilon()<< endl; 

        // errore di arrotondamento
        cout << "arrotondamento: " << numeric_limits<double>::round_error() << endl; 

    cout << "\t char limits: " << endl; 

        // dimensione du 4 byte
        cout << "la dimensione di un carattere  in byte è " << sizeof(char) << endl; 

        // valore massimo per il tipo char
        char max_char = numeric_limits<char>::max(); 
        cout << "il valore massimo per il tipo char è: " <<  max_char << endl; 

        // valore minimo per il tiro char
        char min_char = numeric_limits<char>::min(); 
        cout << "il valore minimo per il tipo char è: " << min_char << endl; 

        // numero di cifre in base 2 per i char. 
        cout <<"il numero massimo di cifre in base 2 è: " << numeric_limits<char>::digits << endl; 

        // numero massimo cdi cifre in base 10 per i char. 
        cout << "il numero massimo di cifre in base 10 è " << numeric_limits<char>::digits10 << endl; 

        // true (1) se char ammette valori negativi
        cout << "float ammette dei valori negativi: " << numeric_limits<char>::is_signed << endl; 
        
        // truse se nome_tipo è discreto (int, char, bool, enum); 
        cout << "è intero: " <<  numeric_limits<char>::is_integer << endl; 
 
    return 0; 
}