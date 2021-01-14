#include <iostream>

using namespace std;

int main()
{
    long long nodeCount, denom;
    cin >> nodeCount >> denom;
    if (nodeCount <= 2*denom)
    {
        // Denom-highway doesn't exist, just go straight.
        cout << nodeCount - 1 << endl;
        return 0;
    }
    // Jumps needed to reach denom-highway.
    long long jumps = denom;
    // Jump from using denom-highway.
    jumps++;
    // Jumps from highway to end.
    jumps += (nodeCount - 1) % denom;
    cout << jumps << endl;
}
