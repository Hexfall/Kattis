#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++)
    {
        int head, days;
        cin >> head >> days;
        int candles = days * (days + 1);
        candles /= 2;
        candles += days;
        cout << head << " " << candles << endl;
    }
}
