#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;int k;
    cin >> n>>k;
    int count = 0;
    for(int i=k;i<=n;i++){
        count +=k;
    }
    cout<< count;
    return 0;
}
