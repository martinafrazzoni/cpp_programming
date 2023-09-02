#include <iostream>
using namespace std; 

int main(){while (true){
	int *p = new int [100000]; 
	for (int i = 0; i < 100000; i++){
			p[i] = i;
		}
	} 
	return 0; 
}
