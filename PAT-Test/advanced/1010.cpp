#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

long long convert(string n, long long radix)
{
    long long sum = 0;
    int temp = 0;
    int index = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++)
    {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}
int findRadix(string n, long long m)
{
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;

    long long high = max(low, m);

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long temp = convert(n, mid);
        if (temp > m || temp < 0)
            high = mid - 1;
        else if (temp == m)
            return mid;

        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    string n1, n2;
    long long tag = 0, radix = 0;
    long long resultRadix;

    cin >> n1 >> n2 >> tag >> radix;
    resultRadix = tag == 1 ? findRadix(n2, convert(n1, radix)) : findRadix(n1, convert(n2, radix));
    if (resultRadix != -1)
    {
        printf("%lld", resultRadix);
    }
    else
    {
        cout << "Impossible";
    }

    return 0;
}
