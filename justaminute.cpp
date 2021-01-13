#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t, mins, secs;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int minin, secin;
        cin >> minin >> secin;
        mins += minin;
        secs += secin;
    }
    double avg = (double)secs/(double)(mins*60);
    if (avg <= 1)
        cout << "measurement error" << endl;
    else
        cout << setprecision(10) << fixed << avg << endl;
}
