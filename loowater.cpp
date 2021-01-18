#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int headCount, knightCount;
    cin >> headCount >> knightCount;
    while (headCount != 0 && knightCount != 0)
    {
        vector<int> heads, knights;
        int total = 0;
        for (int i = 0; i < headCount; i++)
        {
            int head;
            cin >> head;
            heads.push_back(head);
        }
        for (int i = 0; i < knightCount; i++)
        {
            int knight;
            cin >> knight;
            knights.push_back(knight);
        }
               
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());
        int h = 0;
        bool slain = false;
        
        for (int k = 0; k < knightCount; k++)
        {
            if (knights[k] < heads[h])
                continue;
            total += knights[k];
            h++;
            if (h == headCount)
            {
                slain = true;
                break;
            }
        }

        if (slain)
            cout << total << endl;
        else
            cout << "Loowater is doomed!" << endl;

        cin >> headCount >> knightCount;
    }
}
