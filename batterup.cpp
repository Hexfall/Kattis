#include <iostream>

using namespace std;

int main()
{
    int size, score, total = 0;
    scanf("%d", &size);
    for (int i = size; i > 0; i--)
    {
        scanf("%d", &score);
        if (score == -1)
            size--;
        else
            total += score;
    }
    printf("%f\n", (double)total/(double)size);
}
