#include <iostream>
#include <vector>

#define TARGET 1000

using namespace std;

vector<int> arr;
int closest;

// recursively attempt all (reasonable) combinations.
void rec(int index, int total)
{
    if (abs(closest - TARGET) == abs(total - TARGET) && total > closest)
        closest = total;
    else if (abs(closest - TARGET) > abs(total - TARGET))
        closest = total;
    else if (total > closest)
        // No point in adding more weights if we're already heavier.
        return;
    if (index == arr.size())
        // Base case.
        return;
    rec(index + 1, total + arr[index]); // Try with this weight.
    rec(index + 1, total); // Try without this weight.
}

int main()
{
    int size, num;
    scanf("%d", &size);
    while (size--)
    {
        scanf("%d", &num);
        arr.push_back(num);
    }
    closest = arr[0];
    rec(0, 0);
    printf("%d\n", closest);
}
