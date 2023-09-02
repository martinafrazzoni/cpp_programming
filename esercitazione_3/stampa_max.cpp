/*Scrivere un programma che stampi il massimo tra due numeri interi letti dallo stdin. Ad esempio: "inserire i due numeri interi: 21 -3, il massimo tra 21 e -3 è 21. " */

#include <iostream>
using namespace std; 
int main ()
{
    int a; 
    int b; 
    cout << "Inserisci due numeri interi: \n"; 
    cin>>a>>b; 
    if (a>=b)
        cout << "il massimo tra a e b è: " << a << endl; 
    else 
        cout << "il massimo tra a e b è: " << b << endl; 
    return 0; 
}

/*#include <iostream>
using namespace std; 
int main ()
{
    int a; 
    int b; 
    cout << "Inserisci due numeri interi a e b: \n";
    cin >> a>>b; 
    cout << "Il massimo tra " << a << " e " << b << " è: " << endl; 
    if (a>b)
        cout << a<< endl; 
    else 
        cout << b << endl; 
    return 0; 
}*/