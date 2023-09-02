#include <iostream>
using namespace std;
int main()
{
    int a = 2, n, b = 1;
    cout << "Inserire un numero intero compreso tra 0 e 3 \n";
    cin >> n;
    switch (2 - n)
    {
    case 0:
        b *= a;
    case 1:
        b *= a;
    case 2:
        break;

    default:
        cout << "Valore non valido per n\n";
        break;
    }
    cout << b << endl;
    return 0;
}
