#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num, maxunder = 0, minover = 11;
    string waste, line;
    while (scanf("%d", &num), num != 0)
    {
        cin >> waste >> line;
        if (line == "high")
            minover = min(minover, num);
        else if (line == "low")
            maxunder = max(maxunder, num);
        else
        {
            if (minover <= num || maxunder >= num)
                printf("Stan is dishonest\n");
            else
                printf("Stan may be honest\n");
            maxunder = 0;
            minover = 11;
        }
    }
}
