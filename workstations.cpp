#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int resCount, lock, saves = 0;
    cin >> resCount >> lock;
    // pq<arrival, duration>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> researchers;
    // pq<time that pc becomes available>
    priority_queue<int, vector<int>, greater<int>> frees;
    // Put researchers into pq.
    while (resCount--)
    {
        int arrival, duration;
        cin >> arrival >> duration;
        researchers.push(make_pair(arrival, duration));
    }

    // Loop through researchers.
    while (!researchers.empty())
    {
        int arri = researchers.top().first,
            dur  = researchers.top().second;
        researchers.pop();
        
        // Remove computers that've been locked.
        while (!frees.empty() && frees.top() + lock < arri)
            frees.pop();
        // Some computer is still unlocked and is available.
        if (!frees.empty() && frees.top() <= arri)
        {
            saves++;
            frees.pop();
        }
        // Add time for when researcher leaves PC.
        frees.push(arri + dur);
    }

    cout << saves << endl;
}
