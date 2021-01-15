#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> bricks;
    int height, width, brickCount;
    cin >> height >> width >> brickCount;
    for (int i = 0; i < brickCount; i++)
    {
        int b;
        cin >> b;
        bricks.push_back(b);
    }
    int index = 0,
        sum = 0;
    for (int i = 0; i < height; i++)
    {
        while (sum < width)
        {
            // Lay bricks til width is reached.
            if (index == bricks.size())
                break;
            sum += bricks[index];
            index++;
        }
        if (sum != width)
        {
            // Did not finish width correctly.
            cout << "NO" << endl;
            return 0;
        }
        // Reset sum.
        sum -= width;
    }
    // Didn't fail.
    cout << "YES" << endl;
}
