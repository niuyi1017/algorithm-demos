#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;

    string str = to_string(a + b);
    int leng = str.length();
    for (int i = 0; i < leng; i++)
    {
        cout << str[i];
        if (str[i] == '-')
        {
            continue;
        }
        if ((i + 1) % 3 == leng % 3 && i != leng - 1)
        {
            cout << ",";
        }
    }
    return 0;
}
