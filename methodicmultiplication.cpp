#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int num1 = (s1.length() - 1) / 3,
        num2 = (s2.length() - 1) / 3;
    for (int i = 0; i < num1*num2; i++)
        cout << "S(";
    cout << "0";
    for (int i = 0; i < num1*num2; i++)
        cout << ')';
    cout << endl;
}
