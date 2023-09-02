/*#include <iostream>
using namespace std;
int main()
{
    int a, b;
    int max_int = 2147483647;
    cout << "Inserisci due numeri interi: \n";
    cin >> a >> b;

    if (a >= max_int || b >= max_int)
    {
        cout << (a + b) << endl;
        cout << "Attenzione!! il risultato non è attendibile perchè c'è stato overflow \n";
    }
    else
        cout << (a + b) << endl;
    return 0;
}
*/

#include <iostream>
using namespace std; 
int main (){
    int a,b; 
    int max_int = 2147483647; 
    int min_int = (-max_int - 1); 
    cout << "Inserisci due numeri da sommare: "; 
    cin>>a>>b; 
    cout << a << "+" << b << "=" << (a+b) << endl; 
    if ((a>0 && b>max_int - a) || (a<0 && b<min_int - a)){
        cout << "Attenzione: il risultato non è attendibile perchè c'è stato overflow \n"; 
    }
}