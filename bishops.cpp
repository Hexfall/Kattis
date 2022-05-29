#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n <= 2)
        {
            cout << n << endl;
            continue;
        }
        cout << 2*n - 2 << endl;
    }
}
