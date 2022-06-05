#include <iostream>
#include <cstring>

using namespace std;

int find(int *arr, int index)
{
    if (*(arr + index) != -1)
        return *(arr + index);
    *(arr + index) = find(arr, index - 1) + find(arr, index - 2) + find(arr, index - 3);
    return *(arr + index);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    memset(arr, -1, sizeof arr);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    cout << find(arr, n - 1) << endl;
}
