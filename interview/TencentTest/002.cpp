#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), cmp);

    int sum_1 = 0, sum_2 = 0, num = 1;
    for (int i = 0; i < n; i++)
    {
        if (num % 2 == 1)
            sum_1 += arr[i];
        else
            sum_2 += arr[i];
        num++;
    }

    cout << sum_1 - sum_2 << endl;

    return 0;
}
