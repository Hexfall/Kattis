#include <iostream>

using namespace std;

int bat[4200];

int getBat(int num)
{
    if (bat[num] != 0 || num == 1)
        return bat[num];
    int val = 1000000000;
    for (int i = 1; i < num; i++)
    {
        val = min(
            val,
            max(i, getBat(num - i) + 1)
        );
    }
    return bat[num] = val;
}

int main()
{
    int num;
    while (scanf("%d", &num), num != 0)
    {
        printf("%d\n", getBat(num));
    }
}
