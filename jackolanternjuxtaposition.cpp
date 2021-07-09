#include <iostream>

using namespace std;

int main()
{
    int x, total;
    cin >> total;
    while (cin >> x)
        total *= x;
    cout << total << endl;
}
