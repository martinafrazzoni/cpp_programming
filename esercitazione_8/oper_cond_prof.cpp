#include <iostream>

using namespace std ;

main()
{
	int n ;
	cin>>n ;
	n = n >= 0 ? n : 0 ;
	n = n <= 10 ? n : 10 ;
	cout<<n<<endl ;
}