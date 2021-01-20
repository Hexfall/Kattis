#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int fizz, buzz, upto;
    cin >> fizz >> buzz >> upto;
    map<int, string> wordMap = {
        {fizz, "Fizz"},
        {buzz, "Buzz"}
    };
    vector<int> keys = {fizz, buzz};
    for (int i = 1; i < upto + 1; i++)
    {
        bool clear = true;
        for (auto k : keys)
            if (i % k == 0)
            {
                cout << wordMap[k];
                clear = false;
            }
        cout << (clear ? to_string(i) : "") << endl;
    }
}
