#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void getTwoByTwo(char* pointer, string* lines, int x, int y)
{
    pointer[0] = lines[x][y];
    pointer[1] = lines[x+1][y];
    pointer[2] = lines[x][y+1];
    pointer[3] = lines[x+1][y+1];
}

bool hasBuilding(char* space)
{
    for (int i = 0; i < strlen(space); i++)
        if (space[i] == '#')
            return true;
    return false;
}

int countCars(char* space)
{
    int sum = 0;
    for (int i = 0; i < strlen(space); i++)
        if (space[i] == 'X')
            sum++;
    return sum;
}

int main()
{
    int r, c;
    cin >> r >> c;
    string lines[r];
    for (int i = 0; i < r; i++)
        cin >> lines[i];
    
    char space[4];
    int cars[5] = {0,0,0,0,0};
    for (int x = 0; x < r - 1; x++)
    {
        for (int y = 0; y < c - 1; y++)
        {
            getTwoByTwo(space, lines, x, y);
            if (!hasBuilding(space))
                cars[countCars(space)]++;
        }
    }
    for (int i = 0; i < 5; i++)
        cout << cars[i] << endl;
}
