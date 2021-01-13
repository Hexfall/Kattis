#include <iostream>
#include <vector>

using namespace std;

void reduce_fraction (int &num, int &den)
{
    for (int i = min(num, den); i > 1; i--)
        if ((den % i == 0) && (num % i == 0))
        {
            den /= i;
            num /= i;
        }
}

int main()
{
    int count, ring, cur, num;
    cin >> count >> ring;
    for (int i = 1; i < count; i++)
    {
        cin >> cur;
        num = ring;
        reduce_fraction(num, cur);
        cout << num << "/" << cur << " " << endl;
    }
}
