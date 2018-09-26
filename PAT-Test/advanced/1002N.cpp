#include <iostream>
using namespace std;

int main()
{

    int m, n, t;
    float num;
    float marr[1001] = {0};

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> t >> num;

        marr[t] += num;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> num;

        marr[t] += num;
    }

    int count = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (marr[i] != 0)
        {
            count++;
        }
    }
    cout << count;

    for (int i = 1000; i >= 0; i--)
    {
        if (marr[i] != 0)
        {
            cout << ' ' << i << ' ' << marr[i];
        }
    }
    return 0;
}