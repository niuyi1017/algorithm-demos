#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int m, n;
    double arr[1001] = {0.0};
    double ans[2001] = {0.0};

    cin >> m;
    int ex = 0;
    double co = 0.0;
    for (int i = 0; i < m; i++)
    {
        cin >> ex;
        cin >> arr[ex];
    }
    ex = 0;
    co = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ex;
        cin >> co;

        for (int j = 0; j < 1001; j++)
        {
            ans[j + ex] += arr[j] * co;
        }
    }

    int count = 0;
    for (int i = 0; i < 2001; i++)
    {
        if (ans[i] != 0.0)
        {
            count++;
        }
    }
    cout << count;
    for (int i = 2000; i >= 0; i--)
    {
        if (ans[i] != 0.0)
        {

            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}
