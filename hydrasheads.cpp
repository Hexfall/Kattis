#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        int heads = 0,
            tails = 0,
            moves = 0;
        cin >> heads >> tails;
        if ((heads == 0) && (tails == 0))
            break;
        if ((tails == 0) && (heads % 2 == 1))
        {
            cout << -1 << endl;
            continue;
        }
        if (tails % 2 != 0)
        {
            tails++;
            moves++;
        }
        heads += tails / 2;
        moves += tails / 2;
        if (heads % 2 != 0)
        {
            heads++;
            moves += 3;
        }
        moves += heads / 2;
        cout << moves << endl;
    }
}
