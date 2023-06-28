#include <iostream>
#include <vector>

#define vi vector<int>

using namespace std;

int main() {
    int n, k, r;
    cin >> n >> k >> r;

    vi dna(n), balance(k, 0);
    for (int i = 0; i < n; i++)
        cin >> dna[i];

    int index, count;
    for (int i = 0; i < r; ++i) {
        cin >> index >> count;
        balance[index] -= count;
    }

    int i = 0, j = 0, m = -1;
    while (j < n && r > 0) {
        if (++balance[dna[j]] == 0)
            if (--r == 0)
                m = j + 1;

        j++;
    }

    while (r == 0 || j < n) {
        if (r == 0) {
            m = min(m, j-i);
            if (--balance[dna[i]] == -1)
                r++;
            i++;
        } else {
            if (++balance[dna[j]] == 0)
                r--;
            j++;
        }
    }

    if (m == -1)
        cout << "impossible" << endl;
    else
        cout << m << endl;
}