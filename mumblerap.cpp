#include <iostream>

#define ll long long

using namespace std;

int main() {
    ll n = 0, m = 0, count;
    cin >> count;
    char c;
    while (count--) {
        cin >> c;
        if (isdigit(c))
            n = n*10 + (int) (c - '0');
        else
            n = 0;
        m = max(m, n);
    }
    cout << m << endl;
}