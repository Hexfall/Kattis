#include <iostream>
#include <tuple>

using namespace std;

int inp()
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    return sum;
}

int main()
{
    int gunnar = inp(),
        emma = inp();
    if (emma == gunnar)
        cout << "Tie";
    else if (emma > gunnar)
        cout << "Emma";
    else
        cout << "Gunnar";
    cout << endl;
}
