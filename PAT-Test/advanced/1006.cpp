#include <iostream>
#include <string>

using namespace std;

main(int argc, char const *argv[])
{
    int max = INT16_MIN;
    int min = INT16_MAX;
    int h1, m1, s1, h2, m2, s2;
    int n;
    string unlock,lock;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        scanf("%d:%d:%d %d:%d:%d:", &h1, &m1, &s1, &h2, &m2, &s2);
        int t1 = h1 * 60 * 60 + m1 * 60 + s1;
        int t2 = h2 * 60 * 60 + m2 * 60 + s2;

        if(t1 < min){
            min = t1;
            unlock = s;
        }
        if(t2>max){
            max = t2;
            lock = s;
        }
    }
    cout<<unlock<<" "<<lock;

    return 0;
}
