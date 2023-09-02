/*solo la parte sotto, triangolo rovesciato*/
#include <iostream>
using namespace std; 
int main (){
    int lato = 5; 
        for (int i = lato; i>=0; i--){
            for (int j = lato-i; j>=0; j--){
                cout << "."; 
            } 

            for (int k=i; k>=0; k--){
                    cout << " #"; 
            }
            cout << endl; 
        }
        
        return 0;
}
    

