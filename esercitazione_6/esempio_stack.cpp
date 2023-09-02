#include <iostream>
using namespace std; 
bool Divisible(int a, int b) {
    int remainder = a % b; // Calculate the remainder of a and b.

    if(remainder == 0) {
        return true; //If the remainder is 0, the numbers are divisible.
    } else {
        return false; // Otherwise, they aren't.
    }
}

int main(){
    Divisible(3, 5); 
    cout << Divisible (3,5) << endl; 
}