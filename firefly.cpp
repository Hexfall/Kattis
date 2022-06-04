#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int n, h;
    cin >> n >> h;
    int ups[h], dos[h];
    memset(ups, 0, sizeof ups);
    memset(dos, 0, sizeof dos);
    while ((n--))
    {
        int s;
        cin >> s;
        s--;
        if (n & 1)
            ups[s]++;
        else
            dos[s]++;
    }
    for (int i = h - 1; i > 0; i--)
    {
        ups[i-1] += ups[i];
        dos[i-1] += dos[i];
    }
    for (int i = 0; i < h; i++)
        ups[i] += dos[h - 1 - i];
    int m = *min_element(ups, ups + h);
    int count = 0;
    for (int el : ups)
        if (el == m)
            count++;
    cout << m << " " << count << endl;
}
