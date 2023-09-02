#include <iostream>
#include <cstring>
using namespace std; 
/* se io volessi rappresentare uno studente, lui raggruppa una serie di informazioni come: 
studenti: 
- name (stringa)
-id (stringa)
- age (int)
- grades (int array) */

struct student{
    char name [50]; 
    char id [10]; 
    int age; 
    int grades [5]; 
}; 

void stampa_studente(student studente){
    cout << "Name: " << studente.name << endl; 
    cout << "Id: " << studente.id << endl; 
    cout << "Età: " << studente.age << endl; 
    cout << "Ecco i voti: " << endl; 
    for (int i = 0; i < 5; i++){
        cout << studente.grades[i] << " "; // stiamo accedendo all'oggetto di tipo studente che si chiama martina, stiamoa accedendo ai membri della struct, e alla posizione di indice i all'interno dell'arry grades. 
    }
    cout << endl; 
}

struct point {
    int x; 
    int y; 
}; 

void stampa_punti(point punti[ ]){
    for (int i = 0; i < 10; i++){
        cout << "(" <<  punti[i].x << " , " << punti[i].y << ")"<< endl; 
    }
}

// adesso che ho definito un nuovo tipo struttura posso dichiarare poi anche delle variabiili. 

int main(){
    student martina; // variabile che si chiama martina e ha come tipo di dato student. e per accedere ai membri della struct userò i punti. 
    martina.age = 23; // alla mia variabile age dentor la struct gli sto dando valore 23. 
    // con martina, io sto raggruppando tutti i membri della struct sotto un'unico nome comune che è martina. 
    // è uno strumento la struct con cui possiamo memorizzare grandi quantità di dati, come ad esempio un database. 
    strcpy(martina.name , "Martina"); 
    strcpy(martina.id, "349274"); 

    martina.grades[0] = 1; 
    martina.grades[1] = 1; 
    martina.grades[2] = 3; 
    martina.grades[3] = 7; 
    martina.grades[4] = 5; 
    martina.grades[5] = 9; 
    // passare una struct ad una funzione. scriviamo una funzione che si chiama stampa_Studente. 
    stampa_studente(martina); // passo alla funzione come parametro attuale l'oggetto martina di di tipo student. 

    point p1, p2, p3; // ho creato tre struct, tre oggetti di tipo point. 
    p1.x = 4; // sto accedendo all'elemento p1, e al suo membro x. 
    p1.y = 7; 

    cout << "p1.x = " << p1.x << endl; 
    cout << "p1.y = " << p1.y << endl;

    // posso anche inizializzare in un altro modo 
    p1 = {5, 8}; // assegna questi due valori ai membri della struct, nell'ordine in cui compaiono, 5 alla x e 8 alla y. 
    cout << "p1.x: " << p1.x << " p1.y: " << p1.y << endl; 

    p2 = {.x = 6, .y = 9}; 
    cout << "p2.x: " << p2.x << " p2.y: " << p2.y << endl; 

    p3 = {.x = 8, .y = 3}; 
    cout << "p3.x: " << p3.x << " p3.y: " << p3.y << endl; 

    // assegnamento con le struct
    p1 = p2; // dentro p1 ci abbiamo messo p2. viene fatta una copia in memoria, dove p1 viene rimpiazzato con la copia di p2. 
    cout << "p1.x: " << p1.x << " p1.y: " << p1.y << endl; 

    // array di struct e passaro ad una funzione. 
    point punti [10]; // array di 10 punti di tipo point. 
    // inizializziamo i 10 punti. 
    
    for (int i = 0; i < 10; i++){
        punti[i].x = i; // i punti che hanno come membro x verranno inizializzati a i. 
        punti[i].y = 10 - i; // i punti che hanno come membro y vengono inizializzati a 10 - i. 
    } // inzializzo i punti da 0 a 9. 

    // funzione che accetta un array come parametro
    stampa_punti(punti); 

    return 0; 
}