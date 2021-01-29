#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > heap;
    int days;
    scanf("%d", &days);
    for (int d = 0; d < days; d++)
    {
        int junk;
        scanf("%d", &junk);
        heap.push(make_pair(junk, d));
    }
    printf("%d\n", heap.top().second);
}
