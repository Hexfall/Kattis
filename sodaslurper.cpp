#include <iostream>

using namespace std;

int main()
{
    int drunk,
        empty,
        price;
    cin >> drunk >> empty >> price;
    empty += drunk;
    drunk = 0;
    while (empty >= price)
    {
        empty -= (price - 1);
        drunk++;
    }
    cout << drunk << endl;
}
