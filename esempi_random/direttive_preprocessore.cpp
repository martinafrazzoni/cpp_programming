#include <iostream>
// using namespace std;

const char *log(const char *messaggio); // scrivo la dichiarazione altrimenti, la funzione moltiplica non vede log nello scope.

int moltiplica(int a, int b)
{
    log("Moltiplicazione:");
    return (a * b);
}

const char *log(const char *messaggio)
{
    std::cout << messaggio << " ";
    return messaggio;
}

int main()
{
    std::cout << moltiplica(2, 5) << std::endl;
    return 0;
}