#include <iostream>

using namespace std;

#define EARTHDAYS 365
#define MARSDAYS 687

void boundedAdd(int *num, int add, int bounds)
{
    *num = (*num + add) % bounds;
}

int main()
{
    int earth, mars, cases = 0;
    while (cin >> earth && cin >> mars)
    {
        cases++;
        int days = 0;
        if (mars != 0)
        {
            days = MARSDAYS - mars;
            boundedAdd(&earth, MARSDAYS - mars, EARTHDAYS);
            boundedAdd(&mars, MARSDAYS - mars, MARSDAYS);
        }
        while (earth != 0)
        {
            days += MARSDAYS;
            boundedAdd(&earth, MARSDAYS, EARTHDAYS);
        }
        cout << "Case " << cases << ": " << days << endl;
    }
}
