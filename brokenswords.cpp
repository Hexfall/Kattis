#include <iostream>
#include <string>

using namespace std;

int main()
{
    int count, sides = 0, above = 0;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        string sword;
        cin >> sword;
        for (int j = 0; j < 4; j++)
        {
            if (sword[j] == '0')
            {
                if (j < 2)
                    above++;
                else
                    sides++;
            }
        }
    }
    int swords = min(sides, above) / 2;
    cout << swords << " " << above - 2*swords << " " << sides - 2*swords << endl;
}
