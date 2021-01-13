#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        int good, bad;
        cin >> good >> bad;
        if (good == 0 && bad == 0)
            break;
        else if (good + bad == 13)
            cout << "Never speak again.";
        else if (good > bad)
            cout << "To the convention.";
        else if (good < bad)
            cout << "Left beehind.";
        else
            cout << "Undecided.";
        cout << endl;
    }
}
