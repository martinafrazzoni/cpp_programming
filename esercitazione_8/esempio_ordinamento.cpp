#include<iostream>
using namespace std;

#define N 4

int main()
{
     int i, j, min, temp;
     int a[N];

     cout<<"Inserisci gli elementi:\n"; 
     for(i=0;i<N;i++)
	cin>>a[i];

    for(i=0;i<N-1;i++)
    {
	min=i;
        for(j=i+1;j<N;j++)
        	if (a[j]<a[min])
        	     min= j;

        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    
    cout<<"Array ordinato con selection sort:";
    for(i=0;i<N;i++)
	cout<<" "<<a[i];
		
	return 0;
}