#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "inserisci un numero intero positivo: ";
    cin >> a;
    int u = a % 10; 
    int d = ((a % 100) / 10); 
    int c = ((a % 1000) / 100); 
    cout << u << ", " << d << ", " << c << endl; 
    return 0; 


    //  cout << a % 10 << " , " << a % 100 / 10 << ", " << a % 1000 / 100 << endl;
    //  cout << a % 10 << ", " << (a / 10) % 10 << ", " << (a / 100) % 10 << endl;
}