#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

int distsq(tuple<int, int> p1, tuple<int, int> p2)
{
    int x = pow(get<0>(p1) - get<0>(p2), 2);
    int y = pow(get<1>(p1) - get<1>(p2), 2);
    return x + y;
}

double distToEdge(int size, tuple<int, int> point)
{
    int x = get<0>(point),
        y = get<1>(point);
    tuple<int, int> p;
    p = make_tuple(0, y);
    int dist = distsq(point, p);
    p = make_tuple(size, y);
    dist = min(dist, distsq(point, p));
    p = make_tuple(x, 0);
    dist = min(dist, distsq(point, p));
    p = make_tuple(x, size);
    dist = min(dist, distsq(point, p));
    return dist;
}

bool allInRange(int size, tuple<int, int> point, vector<tuple<int, int>> points)
{
    int range = distToEdge(size, point);
    for (auto p : points)
        if (distsq(point, p) > range)
            return false;
    return true;
}

int main()
{
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++)
    {
        int size, hatchcount;
        vector<tuple<int, int>> cords;
        cin >> size >> hatchcount;
        for (int i = 0; i < hatchcount; i++)
        {
            int x, y;
            cin >> x >> y;
            tuple<int, int> cord;
            cord = make_tuple(x, y);
            cords.push_back(cord);
        }
        bool noprint = true;
        for (int x = 1; x < size - 1; x++)
        {
            for (int y = 1; y < size - 1; y++)
            {
                bool inHatch = false;
                for (auto p : cords)
                    if ((get<0>(p) == x) && (get<1>(p) == y))
                    {
                        inHatch = true;
                        break;
                    }
                if (inHatch)
                    continue;
                tuple<int, int> p = make_tuple(x, y);
                if (allInRange(size, p, cords))
                {
                    noprint = false;
                    cout << x << " " << y << endl;
                    break;
                }
            }
            if (!noprint)
                break;
        }
        if (noprint)
            cout << "poodle" << endl;
    }
}
