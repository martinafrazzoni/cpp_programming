/*stampare un rombo vuoto di lato n*/
#include <iostream>
using namespace std; 
int main(){
    int lato; 
    const int lato_max = 10; 
    do {
        cout << "Inserisci il valore del lato del rombo: \n"; 
        cin>>lato; 
    }
    while (lato<=0 || lato>lato_max); 
    for (int i = 0; i<=lato; i++){
        for (int j = 0; j<=lato-i; j++){
            cout << " "; 
        }
        for (int k = 0; k<=i; k++){
            if ((k == 0 || k == i)){
                cout << " #"; 
            }
            else {
                cout << "  "; 
            }
        }
        cout << endl; 
    }

    for (int i = lato-1; i>=0; i--){
        for (int j = lato-i; j>=0; j--){
            cout<< " "; 
        }
        for (int k = i; k>=0; k--){
            if (k==i || k==0){
                cout << " #";
            }
            else {
                cout << "  "; 
            }
        }
        cout << endl; 
    }
    return 0; 
}