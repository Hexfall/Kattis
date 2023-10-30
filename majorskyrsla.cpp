#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    int pointer = n - 2;
    int insert = n - 1;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    while (target > 0 && pointer >= 0) {
        if (target >= pointer + 1) {
            arr.insert(arr.begin() + insert, arr[pointer]);
            arr.erase(arr.begin() + pointer);
            target -= (pointer + 1);
        } else {
            insert = pointer;
        }

        pointer -= 1;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}