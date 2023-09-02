/*scrivere un programma che legga da stdin un numero intero n, poi stampi sullo schermo n asterischi.
Ad esempio: inserire un numero intero : 5 
*****
 */
#include <iostream>
using namespace std; 
int main (){
    int n; 
    cout << "Inserisci un numero intero: \n"; 
    cin>>n; 
    for (int i = 0; i<= n; i ++){
        cout << "# "; 
    }
    cout << endl; 
    return 0; 
}