/*numeri primi gemelli, soluzione fornita dal prof. */
#include <iostream>
#include <cmath>
using namespace std; 
int main(){
    int n1, n2; 
    cin>>n1>>n2; 
    /*ciascuna delle seguenti variabili ha valore true se e solo se il corrispondente valore intero (n1 o n2) è primo. 
    Le inizializziamo a false e lasciamo ai seguenti pezzi di codice il compito di assegnare a ciascuna di loro il valore true quando il corrispondebte valore intero è primo. */
    bool n1_is_prime = false; 
    bool n2_is_prime = false; 
    /*determino se n1 è primo, e nel caso, setto n1_is_prime a true. */
    if (n1>=1 && n1<=3)
        n1_is_prime = true; 
        else if (n1%2 != 0){ // se sono dispari. 
            int i, max_div = static_cast<int>(sqrt(n1)); 
            for (i = 3; i<= max_div; i +=2)
                if (n1%i == 0)
                    break;
            if (i>max_div)
                n1_is_prime = true; 
        }
        /*determino se n2 è primo e, ne caso, setto n2_is_prime a true*/
    if (n2>=1 && n2<=3)
        n2_is_prime = true; 
    else if (n2%2 != 0){
        int i, max_div = static_cast<int>(sqrt(n2)); 
        for (i = 3; i <=max_div; i+=2)
        if (n1%1 == 0)
            break;
        if (i>max_div)
            n2_is_prime = true; 
    }
    if (n2_is_prime && n2_is_prime){
        if (n1 == n2-2 || n2 == n1-2)
            cout << "n1 ed n2 sono due primi"
                 << "gemelli"; 
    }
return 0; 
}