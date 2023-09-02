/*facciamo una calcolatrice*/
#include <iostream>
using namespace std;

int main()
{
    int a, b, c, ris;
    cout << "Inserisci due operandi interi: \n";
    cin >> a >> b;
    cout << "Inserisci il numero corrispondente all'operazione che vuoi eseguire: \n";
    cout << "1 ----> + " << endl;
    cout << "2 ----> - " << endl;
    cout << "3 ----> * " << endl;
    cout << "4 ----> / " << endl;
    cout << "5 ----> % " << endl;
    cin >> c;
    switch (c)
    {
    case 1:
        ris = (a + b);
        cout << a << "+" << b << "=" << ris << endl;
        break;
    case 2:
        ris = (a - b);
        cout << a << "-" << b << "=" << ris << endl;
        break;
    case 3:
        ris = (a * b);
        cout << a << "*" << b << "=" << ris << endl;
        break;
    case 4:
        if (b > 0)
        {
            ris = (a / b);
            cout << a << "/" << b << "=" << ris << endl;
        }
        else
            cout << "Il divisiore non può essere uguale a 0 \n";
        break;
    case 5:
        ris = (a % b);
        cout << a << "%" << b << "=" << ris << endl;
        break;
    default:
        cout << "Non hai inserito un valore nell'intervallo. \n";
        break;
    }
    return 0;
}