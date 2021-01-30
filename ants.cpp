#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        int len, size, hi = -1, lo = -1, ant;
        scanf("%d %d", &len, &size);
        while (size--)
        {
            scanf("%d", &ant);
            lo = max(lo, min(ant, len - ant));
            hi = max(hi, max(ant, len - ant));
        }
        printf("%d %d\n", lo, hi);
    }
}
