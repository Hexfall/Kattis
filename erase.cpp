#include <iostream>
#include <string>

using namespace std;

int main()
{
    int inv;
    cin >> inv;
    bool opposite = inv % 2 == 1;

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++)
    {
        if (!((s1[i] == s2[i])^opposite))
        {
            cout << "Deletion failed" << endl;
            return 0;
        }
    }
    cout << "Deletion succeeded" << endl;
}
