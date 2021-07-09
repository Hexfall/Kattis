#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

#define STATCOUNT 3
#define ll long long

using namespace std;

int main()
{
    // Set of indeces.
    set<int> chosen;
    // noms[stat] = <value, index>
    vector<priority_queue<pair<ll, int>>> noms;
    for (int i = 0; i < STATCOUNT; i++)
        noms.push_back(priority_queue<pair<ll, int>>());
    
    int nomCount, choose;
    cin >> nomCount >> choose;

    for (int i = 0; i < nomCount; i++)
    {
        for (int j = 0; j < STATCOUNT; j++)
        {
            ll stat;
            cin >> stat;
            noms[j].push(make_pair(stat, i));
        }
    }

    for (int i = 0; i < STATCOUNT; i++)
        for (int j = 0; j < choose; j++)
        {
            chosen.insert(noms[i].top().second);
            noms[i].pop();
        }

    cout << chosen.size() << endl;
}
