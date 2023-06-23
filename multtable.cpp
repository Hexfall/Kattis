#include "iostream"
#include "vector"
#include "cmath"

#define ll long long
#define vll vector<long long>

using namespace std;

int main() {
    ll dim, n;
    cin >> dim >> n;

    int prods = 0;
    ll sq = sqrt((long double) n);
    for (ll i = 1; i <= sq + 1; i++) {
        if (n % i == 0) {
            ll inv = n / i;
            if (i <= dim && inv <= dim) {
                if (i == inv)
                    prods++;
                else
                    prods += 2;
            }
        }
    }

    cout << prods << endl;
}